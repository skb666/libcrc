# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_genibus_srcs "*.c")
add_executable(test_crc16_genibus ${test_crc16_genibus_srcs})
target_link_libraries(test_crc16_genibus PRIVATE crc16_genibus)
add_dependencies(test_crc16_genibus crc16_genibus)

# 单元测试
add_test(
    NAME test_crc16_genibus
    COMMAND ./test_crc16_genibus
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
