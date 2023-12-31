# libcrc

本仓库代码均由 [skb666/CRC](https://github.com/skb666/CRC) 生成

## 使用方法

**编译测试工程**

```bash
cmake -S. -Bbuild
# 构建所有目标
cmake --build build --target all -- -j${nproc}
# 执行单元测试
cmake --build build --target test
```

**接口举例**

crc32_mpeg 对外接口如下，不同的参数模型只需替换 CRC32_MPEG2、crc32_mpeg 即可

```c
// 创建 crc 变量
CRC32_MPEG2 crc;

// 初始化 crc
void CRC(crc32_mpeg, init)(CRC32_MPEG2 *crc);

// 重置分次校验值
void CRC(crc32_mpeg, reset)(CRC32_MPEG2 *crc);

// 分次校验
CRC32_MPEG2_NUM_TYPE CRC(crc32_mpeg, accum)(CRC32_MPEG2 *crc, void *data, size_t length);

// 获取分次校验值
CRC32_MPEG2_NUM_TYPE CRC(crc32_mpeg, get)(CRC32_MPEG2 *crc);

// 单次校验
CRC32_MPEG2_NUM_TYPE CRC(crc32_mpeg, calc)(CRC32_MPEG2 *crc, void *data, size_t length);
```

## 支持的 CRC 参数模型

| 算法名称            | 宽度  | 多项式             | 初始值             | 结果异或值         | 输入反转 | 输出反转 |
| :------------------ | :---: | :----------------- | :----------------- | :----------------- | -------: | -------: |
| crc8                |   8   | 0x07               | 0x00               | 0x00               |    False |    False |
| crc8_sae_j1850      |   8   | 0x1D               | 0xFF               | 0xFF               |    False |    False |
| crc8_sae_j1850_zero |   8   | 0x1D               | 0x00               | 0x00               |    False |    False |
| crc8_8h2f           |   8   | 0x2F               | 0xFF               | 0xFF               |    False |    False |
| crc8_cdma2000       |   8   | 0x9B               | 0xFF               | 0x00               |    False |    False |
| crc8_darc           |   8   | 0x39               | 0x00               | 0x00               |     True |     True |
| crc8_dvb_s2         |   8   | 0xD5               | 0x00               | 0x00               |    False |    False |
| crc8_ebu            |   8   | 0x1D               | 0xFF               | 0x00               |     True |     True |
| crc8_icode          |   8   | 0x1D               | 0xFD               | 0x00               |    False |    False |
| crc8_itu            |   8   | 0x07               | 0x00               | 0x55               |    False |    False |
| crc8_maxim          |   8   | 0x31               | 0x00               | 0x00               |     True |     True |
| crc8_rohc           |   8   | 0x07               | 0xFF               | 0x00               |     True |     True |
| crc8_wcdma          |   8   | 0x9B               | 0x00               | 0x00               |     True |     True |
| crc16_ccit_zero     |  16   | 0x1021             | 0x0000             | 0x0000             |    False |    False |
| crc16_arc           |  16   | 0x8005             | 0x0000             | 0x0000             |     True |     True |
| crc16_aug_ccitt     |  16   | 0x1021             | 0x1D0F             | 0x0000             |    False |    False |
| crc16_buypass       |  16   | 0x8005             | 0x0000             | 0x0000             |    False |    False |
| crc16_ccitt_false   |  16   | 0x1021             | 0xFFFF             | 0x0000             |    False |    False |
| crc16_cdma2000      |  16   | 0xC867             | 0xFFFF             | 0x0000             |    False |    False |
| crc16_dds_110       |  16   | 0x8005             | 0x800D             | 0x0000             |    False |    False |
| crc16_dect_r        |  16   | 0x0589             | 0x0000             | 0x0001             |    False |    False |
| crc16_dect_x        |  16   | 0x0589             | 0x0000             | 0x0000             |    False |    False |
| crc16_dnp           |  16   | 0x3D65             | 0x0000             | 0xFFFF             |     True |     True |
| crc16_en_13757      |  16   | 0x3D65             | 0x0000             | 0xFFFF             |    False |    False |
| crc16_genibus       |  16   | 0x1021             | 0xFFFF             | 0xFFFF             |    False |    False |
| crc16_ibm           |  16   | 0x8005             | 0x0000             | 0x0000             |     True |     True |
| crc16_maxim         |  16   | 0x8005             | 0x0000             | 0xFFFF             |     True |     True |
| crc16_mcrf4xx       |  16   | 0x1021             | 0xFFFF             | 0x0000             |     True |     True |
| crc16_riello        |  16   | 0x1021             | 0xB2AA             | 0x0000             |     True |     True |
| crc16_t10_dif       |  16   | 0x8BB7             | 0x0000             | 0x0000             |    False |    False |
| crc16_teledisk      |  16   | 0xA097             | 0x0000             | 0x0000             |    False |    False |
| crc16_tms37157      |  16   | 0x1021             | 0x89EC             | 0x0000             |     True |     True |
| crc16_usb           |  16   | 0x8005             | 0xFFFF             | 0xFFFF             |     True |     True |
| crc16_a             |  16   | 0x1021             | 0xC6C6             | 0x0000             |     True |     True |
| crc16_kermit        |  16   | 0x1021             | 0x0000             | 0x0000             |     True |     True |
| crc16_modbus        |  16   | 0x8005             | 0xFFFF             | 0x0000             |     True |     True |
| crc16_x25           |  16   | 0x1021             | 0xFFFF             | 0xFFFF             |     True |     True |
| crc16_xmodem        |  16   | 0x1021             | 0x0000             | 0x0000             |    False |    False |
| crc24_openpgp       |  24   | 0x864cfb           | 0xb704ce           | 0x000000           |    False |    False |
| crc24_flexray_a     |  24   | 0x5d6dcb           | 0xfedcba           | 0x000000           |    False |    False |
| crc24_flexray_b     |  24   | 0x5d6dcb           | 0xabcdef           | 0x000000           |    False |    False |
| crc32               |  32   | 0x04C11DB7         | 0xFFFFFFFF         | 0xFFFFFFFF         |     True |     True |
| crc32_bzip2         |  32   | 0x04C11DB7         | 0xFFFFFFFF         | 0xFFFFFFFF         |    False |    False |
| crc32_c             |  32   | 0x1EDC6F41         | 0xFFFFFFFF         | 0xFFFFFFFF         |     True |     True |
| crc32_d             |  32   | 0xA833982B         | 0xFFFFFFFF         | 0xFFFFFFFF         |     True |     True |
| crc32_mpeg2         |  32   | 0x04C11DB7         | 0xFFFFFFFF         | 0x00000000         |    False |    False |
| crc32_posix         |  32   | 0x04C11DB7         | 0x00000000         | 0xFFFFFFFF         |    False |    False |
| crc32_q             |  32   | 0x814141AB         | 0x00000000         | 0x00000000         |    False |    False |
| crc32_jamcrc        |  32   | 0x04C11DB7         | 0xFFFFFFFF         | 0x00000000         |     True |     True |
| crc32_xfer          |  32   | 0x000000AF         | 0x00000000         | 0x00000000         |    False |    False |
| crc64_ecma_182      |  64   | 0x42F0E1EBA9EA3693 | 0x0000000000000000 | 0x0000000000000000 |    False |    False |
| crc64_go_iso        |  64   | 0x000000000000001B | 0xFFFFFFFFFFFFFFFF | 0xFFFFFFFFFFFFFFFF |     True |     True |
| crc64_we            |  64   | 0x42F0E1EBA9EA3693 | 0xFFFFFFFFFFFFFFFF | 0xFFFFFFFFFFFFFFFF |    False |    False |
| crc64_xz            |  64   | 0x42F0E1EBA9EA3693 | 0xFFFFFFFFFFFFFFFF | 0xFFFFFFFFFFFFFFFF |     True |     True |

## 在线验证平台

1. [CRC（循环冗余校验）在线计算](http://www.ip33.com/crc.html)
2. [CRC Calculator (Javascript)](http://www.sunshine2k.de/coding/javascript/crc/crc_js.html)
3. [16进制(CRC24)(多项式异或,多种)校验](https://www.23bei.com/tool/825.html)
