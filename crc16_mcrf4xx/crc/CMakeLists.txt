# crc16_mcrf4xx
file(GLOB crc16_mcrf4xx_srcs "*.c")
add_library(crc16_mcrf4xx STATIC ${crc16_mcrf4xx_srcs})
target_include_directories(crc16_mcrf4xx PUBLIC .)
