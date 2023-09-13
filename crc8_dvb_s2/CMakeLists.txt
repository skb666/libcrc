# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc8_dvb_s2_srcs "*.c")
add_executable(test_crc8_dvb_s2 ${test_crc8_dvb_s2_srcs})
target_link_libraries(test_crc8_dvb_s2 crc8_dvb_s2)

# 单元测试
add_test(
    NAME test_crc8_dvb_s2
    COMMAND ./test_crc8_dvb_s2
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
