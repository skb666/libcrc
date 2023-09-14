# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc32_d_srcs "*.c")
add_executable(test_crc32_d ${test_crc32_d_srcs})
target_link_libraries(test_crc32_d PRIVATE crc32_d)
add_dependencies(test_crc32_d crc32_d)

# 单元测试
add_test(
    NAME test_crc32_d
    COMMAND ./test_crc32_d
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
