# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc24_flexray_b_srcs "*.c")
add_executable(test_crc24_flexray_b ${test_crc24_flexray_b_srcs})
target_link_libraries(test_crc24_flexray_b PRIVATE crc24_flexray_b)
add_dependencies(test_crc24_flexray_b crc24_flexray_b)

# 单元测试
add_test(
    NAME test_crc24_flexray_b
    COMMAND ./test_crc24_flexray_b
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
