# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_dect_x_srcs "*.c")
add_executable(test_crc16_dect_x ${test_crc16_dect_x_srcs})
target_link_libraries(test_crc16_dect_x PRIVATE crc16_dect_x)
add_dependencies(test_crc16_dect_x crc16_dect_x)

# 单元测试
add_test(
    NAME test_crc16_dect_x
    COMMAND ./test_crc16_dect_x
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
