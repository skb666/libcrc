# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_x25_srcs "*.c")
add_executable(test_crc16_x25 ${test_crc16_x25_srcs})
target_link_libraries(test_crc16_x25 PRIVATE crc16_x25)
add_dependencies(test_crc16_x25 crc16_x25)

# 单元测试
add_test(
    NAME test_crc16_x25
    COMMAND ./test_crc16_x25
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
