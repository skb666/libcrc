# crc16_usb
file(GLOB crc16_usb_srcs "*.c")
add_library(crc16_usb STATIC ${crc16_usb_srcs})
target_include_directories(crc16_usb PUBLIC .)
