# crc16_aug_ccitt
file(GLOB crc16_aug_ccitt_srcs "*.c")
add_library(crc16_aug_ccitt STATIC ${crc16_aug_ccitt_srcs})
target_include_directories(crc16_aug_ccitt PUBLIC .)
