# crc8_darc
file(GLOB crc8_darc_srcs "*.c")
add_library(crc8_darc STATIC ${crc8_darc_srcs})
target_include_directories(crc8_darc PUBLIC .)
