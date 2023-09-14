# crc16_dds_110
file(GLOB crc16_dds_110_srcs "*.c")
add_library(crc16_dds_110 STATIC ${crc16_dds_110_srcs})
target_include_directories(crc16_dds_110 PUBLIC .)
