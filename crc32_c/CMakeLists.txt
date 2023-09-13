# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc32_c_srcs "*.c")
add_executable(test_crc32_c ${test_crc32_c_srcs})
target_link_libraries(test_crc32_c crc32_c)

# 单元测试
add_test(
    NAME test_crc32_c
    COMMAND ./test_crc32_c
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
