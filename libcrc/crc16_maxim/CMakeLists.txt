# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_maxim_srcs "*.c")
add_executable(test_crc16_maxim ${test_crc16_maxim_srcs})
target_link_libraries(test_crc16_maxim PRIVATE crc16_maxim)
add_dependencies(test_crc16_maxim crc16_maxim)

# 单元测试
add_test(
    NAME test_crc16_maxim
    COMMAND ./test_crc16_maxim
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
