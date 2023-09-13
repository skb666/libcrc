# crc8_itu
file(GLOB crc8_itu_srcs "*.c")
add_library(crc8_itu STATIC ${crc8_itu_srcs})
target_include_directories(crc8_itu PUBLIC .)
