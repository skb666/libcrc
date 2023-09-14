# crc8
file(GLOB crc8_srcs "*.c")
add_library(crc8 STATIC ${crc8_srcs})
target_include_directories(crc8 PUBLIC .)
