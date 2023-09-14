# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_dect_r_srcs "*.c")
add_executable(test_crc16_dect_r ${test_crc16_dect_r_srcs})
target_link_libraries(test_crc16_dect_r PRIVATE crc16_dect_r)
add_dependencies(test_crc16_dect_r crc16_dect_r)

# 单元测试
add_test(
    NAME test_crc16_dect_r
    COMMAND ./test_crc16_dect_r
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
