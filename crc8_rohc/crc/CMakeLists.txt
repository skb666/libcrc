# crc8_rohc
file(GLOB crc8_rohc_srcs "*.c")
add_library(crc8_rohc STATIC ${crc8_rohc_srcs})
target_include_directories(crc8_rohc PUBLIC .)
