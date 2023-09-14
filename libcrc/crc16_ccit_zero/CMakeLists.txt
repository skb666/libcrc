# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_ccit_zero_srcs "*.c")
add_executable(test_crc16_ccit_zero ${test_crc16_ccit_zero_srcs})
target_link_libraries(test_crc16_ccit_zero PRIVATE crc16_ccit_zero)
add_dependencies(test_crc16_ccit_zero crc16_ccit_zero)

# 单元测试
add_test(
    NAME test_crc16_ccit_zero
    COMMAND ./test_crc16_ccit_zero
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
