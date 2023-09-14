# crc16_t10_dif
file(GLOB crc16_t10_dif_srcs "*.c")
add_library(crc16_t10_dif STATIC ${crc16_t10_dif_srcs})
target_include_directories(crc16_t10_dif PUBLIC .)
