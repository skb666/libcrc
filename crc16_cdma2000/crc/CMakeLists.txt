# crc16_cdma2000
file(GLOB crc16_cdma2000_srcs "*.c")
add_library(crc16_cdma2000 STATIC ${crc16_cdma2000_srcs})
target_include_directories(crc16_cdma2000 PUBLIC .)
