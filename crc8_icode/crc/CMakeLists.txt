# crc8_icode
file(GLOB crc8_icode_srcs "*.c")
add_library(crc8_icode STATIC ${crc8_icode_srcs})
target_include_directories(crc8_icode PUBLIC .)
