# crc8_8h2f
file(GLOB crc8_8h2f_srcs "*.c")
add_library(crc8_8h2f STATIC ${crc8_8h2f_srcs})
target_include_directories(crc8_8h2f PUBLIC .)
