# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_mcrf4xx_srcs "*.c")
add_executable(test_crc16_mcrf4xx ${test_crc16_mcrf4xx_srcs})
target_link_libraries(test_crc16_mcrf4xx PRIVATE crc16_mcrf4xx)
add_dependencies(test_crc16_mcrf4xx crc16_mcrf4xx)

# 单元测试
add_test(
    NAME test_crc16_mcrf4xx
    COMMAND ./test_crc16_mcrf4xx
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
