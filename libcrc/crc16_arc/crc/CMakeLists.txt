# crc16_arc
file(GLOB crc16_arc_srcs "*.c")
add_library(crc16_arc STATIC ${crc16_arc_srcs})
target_include_directories(crc16_arc PUBLIC .)
