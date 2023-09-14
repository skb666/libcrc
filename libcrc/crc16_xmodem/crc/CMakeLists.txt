# crc16_xmodem
file(GLOB crc16_xmodem_srcs "*.c")
add_library(crc16_xmodem STATIC ${crc16_xmodem_srcs})
target_include_directories(crc16_xmodem PUBLIC .)
