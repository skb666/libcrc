# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc64_ecma_182_srcs "*.c")
add_executable(test_crc64_ecma_182 ${test_crc64_ecma_182_srcs})
target_link_libraries(test_crc64_ecma_182 PRIVATE crc64_ecma_182)
add_dependencies(test_crc64_ecma_182 crc64_ecma_182)

# 单元测试
add_test(
    NAME test_crc64_ecma_182
    COMMAND ./test_crc64_ecma_182
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
