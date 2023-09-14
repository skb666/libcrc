# crc16_maxim
file(GLOB crc16_maxim_srcs "*.c")
add_library(crc16_maxim STATIC ${crc16_maxim_srcs})
target_include_directories(crc16_maxim PUBLIC .)
