# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc64_we_srcs "*.c")
add_executable(test_crc64_we ${test_crc64_we_srcs})
target_link_libraries(test_crc64_we PRIVATE crc64_we)
add_dependencies(test_crc64_we crc64_we)

# 单元测试
add_test(
    NAME test_crc64_we
    COMMAND ./test_crc64_we
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
