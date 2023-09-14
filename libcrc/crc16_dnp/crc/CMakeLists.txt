# crc16_dnp
file(GLOB crc16_dnp_srcs "*.c")
add_library(crc16_dnp STATIC ${crc16_dnp_srcs})
target_include_directories(crc16_dnp PUBLIC .)
