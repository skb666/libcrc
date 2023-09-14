# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_en_13757_srcs "*.c")
add_executable(test_crc16_en_13757 ${test_crc16_en_13757_srcs})
target_link_libraries(test_crc16_en_13757 PRIVATE crc16_en_13757)
add_dependencies(test_crc16_en_13757 crc16_en_13757)

# 单元测试
add_test(
    NAME test_crc16_en_13757
    COMMAND ./test_crc16_en_13757
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
