# crc8_wcdma
file(GLOB crc8_wcdma_srcs "*.c")
add_library(crc8_wcdma STATIC ${crc8_wcdma_srcs})
target_include_directories(crc8_wcdma PUBLIC .)
