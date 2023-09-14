# crc8_cdma2000
file(GLOB crc8_cdma2000_srcs "*.c")
add_library(crc8_cdma2000 STATIC ${crc8_cdma2000_srcs})
target_include_directories(crc8_cdma2000 PUBLIC .)
