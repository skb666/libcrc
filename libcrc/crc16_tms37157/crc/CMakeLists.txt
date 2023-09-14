# crc16_tms37157
file(GLOB crc16_tms37157_srcs "*.c")
add_library(crc16_tms37157 STATIC ${crc16_tms37157_srcs})
target_include_directories(crc16_tms37157 PUBLIC .)
