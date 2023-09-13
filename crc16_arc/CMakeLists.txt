# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_arc_srcs "*.c")
add_executable(test_crc16_arc ${test_crc16_arc_srcs})
target_link_libraries(test_crc16_arc crc16_arc)

# 单元测试
add_test(
    NAME test_crc16_arc
    COMMAND ./test_crc16_arc
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
