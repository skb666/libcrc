# crc8_ebu
file(GLOB crc8_ebu_srcs "*.c")
add_library(crc8_ebu STATIC ${crc8_ebu_srcs})
target_include_directories(crc8_ebu PUBLIC .)
