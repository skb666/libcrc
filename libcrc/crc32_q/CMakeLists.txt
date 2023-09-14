# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc32_q_srcs "*.c")
add_executable(test_crc32_q ${test_crc32_q_srcs})
target_link_libraries(test_crc32_q PRIVATE crc32_q)
add_dependencies(test_crc32_q crc32_q)

# 单元测试
add_test(
    NAME test_crc32_q
    COMMAND ./test_crc32_q
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
