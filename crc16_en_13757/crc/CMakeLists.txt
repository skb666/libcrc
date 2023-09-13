# crc16_en_13757
file(GLOB crc16_en_13757_srcs "*.c")
add_library(crc16_en_13757 STATIC ${crc16_en_13757_srcs})
target_include_directories(crc16_en_13757 PUBLIC .)
