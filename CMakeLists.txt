cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(pico-sdk/pico_sdk_init.cmake)

project(datn)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(datn
    datn.c
    adc.c
    cluster.c
    key.c
    com.c
)
# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(datn pico_stdlib hardware_adc hardware_i2c)

# enable usb output, disable uart output
pico_enable_stdio_usb(datn 1)
pico_enable_stdio_uart(datn 0)


# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(datn)

# Generate from build with: cmake -LA .. -DCMAKE_CXX_FLAGS_RELEASE="-O3 -DNDEBUG"
