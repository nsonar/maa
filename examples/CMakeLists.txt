add_executable (i2c_HMC5883L i2c_HMC5883L.c)
add_executable (hellomaa hellomaa.c)
add_executable (cycle-pwm3 cycle-pwm3.c)
add_executable (blink-io blink-io.c)
add_executable (analogin_a0 analogin_a0.c)
add_executable (isr_pin6 isr_pin6.c)
add_executable (gpio_read6 gpio_read6.c)
add_executable (spi_mcp4261 spi_mcp4261.c)
add_executable (mmap-io2 mmap-io2.c)
add_executable (blink_onboard blink_onboard.c)

include_directories(${PROJECT_SOURCE_DIR}/api)

target_link_libraries (hellomaa maa)
target_link_libraries (i2c_HMC5883L maa m)
target_link_libraries (cycle-pwm3 maa)
target_link_libraries (blink-io maa)
target_link_libraries (analogin_a0 maa)
target_link_libraries (isr_pin6 maa)
target_link_libraries (gpio_read6 maa)
target_link_libraries (spi_mcp4261 maa)
target_link_libraries (mmap-io2 maa)
target_link_libraries (blink_onboard maa)

add_subdirectory (c++)

install (DIRECTORY ${PROJECT_SOURCE_DIR}/examples/ DESTINATION share/maa/examples)
