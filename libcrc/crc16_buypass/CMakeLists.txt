# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_buypass_srcs "*.c")
add_executable(test_crc16_buypass ${test_crc16_buypass_srcs})
target_link_libraries(test_crc16_buypass PRIVATE crc16_buypass)
add_dependencies(test_crc16_buypass crc16_buypass)

# 单元测试
add_test(
    NAME test_crc16_buypass
    COMMAND ./test_crc16_buypass
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
