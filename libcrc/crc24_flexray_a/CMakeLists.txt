# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc24_flexray_a_srcs "*.c")
add_executable(test_crc24_flexray_a ${test_crc24_flexray_a_srcs})
target_link_libraries(test_crc24_flexray_a PRIVATE crc24_flexray_a)
add_dependencies(test_crc24_flexray_a crc24_flexray_a)

# 单元测试
add_test(
    NAME test_crc24_flexray_a
    COMMAND ./test_crc24_flexray_a
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
