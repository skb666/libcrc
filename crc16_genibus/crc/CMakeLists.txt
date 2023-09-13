# crc16_genibus
file(GLOB crc16_genibus_srcs "*.c")
add_library(crc16_genibus STATIC ${crc16_genibus_srcs})
target_include_directories(crc16_genibus PUBLIC .)
