# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc64_xz_srcs "*.c")
add_executable(test_crc64_xz ${test_crc64_xz_srcs})
target_link_libraries(test_crc64_xz PRIVATE crc64_xz)
add_dependencies(test_crc64_xz crc64_xz)

# 单元测试
add_test(
    NAME test_crc64_xz
    COMMAND ./test_crc64_xz
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
