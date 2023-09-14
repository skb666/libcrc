# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_cdma2000_srcs "*.c")
add_executable(test_crc16_cdma2000 ${test_crc16_cdma2000_srcs})
target_link_libraries(test_crc16_cdma2000 PRIVATE crc16_cdma2000)
add_dependencies(test_crc16_cdma2000 crc16_cdma2000)

# 单元测试
add_test(
    NAME test_crc16_cdma2000
    COMMAND ./test_crc16_cdma2000
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
