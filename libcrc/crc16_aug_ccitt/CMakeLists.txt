# 递归调用子文件的 CMakeLists.txt
add_subdirectory(crc)

# test
file(GLOB test_crc16_aug_ccitt_srcs "*.c")
add_executable(test_crc16_aug_ccitt ${test_crc16_aug_ccitt_srcs})
target_link_libraries(test_crc16_aug_ccitt PRIVATE crc16_aug_ccitt)
add_dependencies(test_crc16_aug_ccitt crc16_aug_ccitt)

# 单元测试
add_test(
    NAME test_crc16_aug_ccitt
    COMMAND ./test_crc16_aug_ccitt
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
