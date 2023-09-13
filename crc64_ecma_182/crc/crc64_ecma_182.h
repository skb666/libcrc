/** Genetrate from template/crc/crc.h
 * @param algorithm: crc64_ecma_182
 * @param algorithm_upper: CRC64_ECMA_182
 * @param display_width: 16
 * @param width: 64
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
#ifndef __CRC64_ECMA_182_H__
#define __CRC64_ECMA_182_H__

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CRC
#define CRC(ALG, OPT) ALG##_##OPT
#endif

#define CRC64_ECMA_182_NUM_WIDTH "16"
#define CRC64_ECMA_182_NUM_PRIx PRIx64
#define CRC64_ECMA_182_NUM_PRIX PRIX64

#define CRC64_ECMA_182_NUM_TYPE uint64_t
#define CRC64_ECMA_182_DEFAULT_DATA "crc64_ecma_182.default"
#define CRC64_ECMA_182_TABLE_DATA "crc64_ecma_182.table"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t width;
    uint8_t input_reflected;
    uint8_t result_reflected;
    // data
    CRC64_ECMA_182_NUM_TYPE polynomial;
    CRC64_ECMA_182_NUM_TYPE initial_value;
    CRC64_ECMA_182_NUM_TYPE final_xor_value;
    CRC64_ECMA_182_NUM_TYPE accumulate;
} CRC64_ECMA_182;

void crc64_ecma_182_init(CRC64_ECMA_182 *crc);
CRC64_ECMA_182_NUM_TYPE crc64_ecma_182_calc(CRC64_ECMA_182 *crc, void *data, size_t length);
CRC64_ECMA_182_NUM_TYPE crc64_ecma_182_accum(CRC64_ECMA_182 *crc, void *data, size_t length);
void crc64_ecma_182_reset(CRC64_ECMA_182 *crc);
CRC64_ECMA_182_NUM_TYPE crc64_ecma_182_get(CRC64_ECMA_182 *crc);

#ifdef __cplusplus
}
#endif

#endif
