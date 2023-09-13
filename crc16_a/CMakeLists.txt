# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_a_srcs "*.c")
add_executable(test_crc16_a ${test_crc16_a_srcs})
target_link_libraries(test_crc16_a crc16_a)

# 单元测试
add_test(
    NAME test_crc16_a
    COMMAND ./test_crc16_a
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
