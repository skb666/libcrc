/** Genetrate from template/crc/crc.h
 * @param algorithm: crc32
 * @param algorithm_upper: CRC32
 * @param display_width: 8
 * @param width: 32
 * 
 * Copyright (c) 2023-present SKB(skb666@qq.com)
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __CRC32_H__
#define __CRC32_H__

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CRC
#define CRC(ALG, OPT) ALG##_##OPT
#endif

#define CRC32_NUM_WIDTH "8"
#define CRC32_NUM_PRIx PRIx32
#define CRC32_NUM_PRIX PRIX32

#define CRC32_NUM_TYPE uint32_t
#define CRC32_DEFAULT_DATA "crc32.default"
#define CRC32_TABLE_DATA "crc32.table"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t width;
    uint8_t input_reflected;
    uint8_t result_reflected;
    // data
    CRC32_NUM_TYPE polynomial;
    CRC32_NUM_TYPE initial_value;
    CRC32_NUM_TYPE final_xor_value;
    CRC32_NUM_TYPE accumulate;
} CRC32;

void crc32_init(CRC32 *crc);
CRC32_NUM_TYPE crc32_calc(CRC32 *crc, void *data, size_t length);
CRC32_NUM_TYPE crc32_accum(CRC32 *crc, void *data, size_t length);
void crc32_reset(CRC32 *crc);
CRC32_NUM_TYPE crc32_get(CRC32 *crc);

#ifdef __cplusplus
}
#endif

#endif
