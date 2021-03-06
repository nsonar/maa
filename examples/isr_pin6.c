/*
 * Author: Brendan Le Foll
 * Copyright (c) 2014 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <unistd.h>

#include "maa.h"

static volatile int counter = 0;
static volatile int oldcounter = 0;

void interrupt (void * args) {
    ++counter;
}

int main ()
{
    maa_init();
    maa_gpio_context x;

    x = maa_gpio_init(6);
    if (x == NULL) {
        return 1;
    }

    maa_gpio_dir(x, MAA_GPIO_IN);

    gpio_edge_t edge = MAA_GPIO_EDGE_BOTH;
   
    maa_gpio_isr(x, edge, &interrupt, NULL);

    for(;;) {
        if(counter != oldcounter) {
          fprintf(stdout, "timeout counter == %d\n", counter);
          oldcounter = counter;
        }
        // got to relieve our poor CPU!
        sleep(1);
    }

    maa_gpio_close(x);

    return MAA_SUCCESS;
}
