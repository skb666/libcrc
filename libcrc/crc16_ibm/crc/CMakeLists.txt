# crc16_ibm
file(GLOB crc16_ibm_srcs "*.c")
add_library(crc16_ibm STATIC ${crc16_ibm_srcs})
target_include_directories(crc16_ibm PUBLIC .)
