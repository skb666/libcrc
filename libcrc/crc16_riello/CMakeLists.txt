# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_riello_srcs "*.c")
add_executable(test_crc16_riello ${test_crc16_riello_srcs})
target_link_libraries(test_crc16_riello PRIVATE crc16_riello)
add_dependencies(test_crc16_riello crc16_riello)

# 单元测试
add_test(
    NAME test_crc16_riello
    COMMAND ./test_crc16_riello
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
