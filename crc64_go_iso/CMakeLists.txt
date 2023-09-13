# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc64_go_iso_srcs "*.c")
add_executable(test_crc64_go_iso ${test_crc64_go_iso_srcs})
target_link_libraries(test_crc64_go_iso crc64_go_iso)

# 单元测试
add_test(
    NAME test_crc64_go_iso
    COMMAND ./test_crc64_go_iso
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
