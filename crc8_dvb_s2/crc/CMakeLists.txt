# crc8_dvb_s2
file(GLOB crc8_dvb_s2_srcs "*.c")
add_library(crc8_dvb_s2 STATIC ${crc8_dvb_s2_srcs})
target_include_directories(crc8_dvb_s2 PUBLIC .)
