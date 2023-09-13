/** Genetrate from template/crc/crc.h
 * @param algorithm: crc64_xz
 * @param algorithm_upper: CRC64_XZ
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
#ifndef __CRC64_XZ_H__
#define __CRC64_XZ_H__

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CRC
#define CRC(ALG, OPT) ALG##_##OPT
#endif

#define CRC64_XZ_NUM_WIDTH "16"
#define CRC64_XZ_NUM_PRIx PRIx64
#define CRC64_XZ_NUM_PRIX PRIX64

#define CRC64_XZ_NUM_TYPE uint64_t
#define CRC64_XZ_DEFAULT_DATA "crc64_xz.default"
#define CRC64_XZ_TABLE_DATA "crc64_xz.table"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t width;
    uint8_t input_reflected;
    uint8_t result_reflected;
    // data
    CRC64_XZ_NUM_TYPE polynomial;
    CRC64_XZ_NUM_TYPE initial_value;
    CRC64_XZ_NUM_TYPE final_xor_value;
    CRC64_XZ_NUM_TYPE accumulate;
} CRC64_XZ;

void crc64_xz_init(CRC64_XZ *crc);
CRC64_XZ_NUM_TYPE crc64_xz_calc(CRC64_XZ *crc, void *data, size_t length);
CRC64_XZ_NUM_TYPE crc64_xz_accum(CRC64_XZ *crc, void *data, size_t length);
void crc64_xz_reset(CRC64_XZ *crc);
CRC64_XZ_NUM_TYPE crc64_xz_get(CRC64_XZ *crc);

#ifdef __cplusplus
}
#endif

#endif
