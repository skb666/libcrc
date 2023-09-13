# crc16_ccit_zero
file(GLOB crc16_ccit_zero_srcs "*.c")
add_library(crc16_ccit_zero STATIC ${crc16_ccit_zero_srcs})
target_include_directories(crc16_ccit_zero PUBLIC .)
