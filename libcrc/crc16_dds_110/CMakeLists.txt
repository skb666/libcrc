# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_dds_110_srcs "*.c")
add_executable(test_crc16_dds_110 ${test_crc16_dds_110_srcs})
target_link_libraries(test_crc16_dds_110 PRIVATE crc16_dds_110)
add_dependencies(test_crc16_dds_110 crc16_dds_110)

# 单元测试
add_test(
    NAME test_crc16_dds_110
    COMMAND ./test_crc16_dds_110
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
