# crc8_maxim
file(GLOB crc8_maxim_srcs "*.c")
add_library(crc8_maxim STATIC ${crc8_maxim_srcs})
target_include_directories(crc8_maxim PUBLIC .)
