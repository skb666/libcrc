/** Genetrate from template/crc/crc.h
 * @param algorithm: crc24_flexray_b
 * @param algorithm_upper: CRC24_FLEXRAY_B
 * @param display_width: 6
 * @param data_width: 32
 * @param width: 24
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
#ifndef __CRC24_FLEXRAY_B_H__
#define __CRC24_FLEXRAY_B_H__

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CRC
#define CRC(ALG, OPT) ALG##_##OPT
#endif

#define CRC24_FLEXRAY_B_NUM_WIDTH "6"
#define CRC24_FLEXRAY_B_NUM_PRIx PRIx32
#define CRC24_FLEXRAY_B_NUM_PRIX PRIX32

#define CRC24_FLEXRAY_B_NUM_TYPE uint32_t
#define CRC24_FLEXRAY_B_DEFAULT_DATA "crc24_flexray_b.default"
#define CRC24_FLEXRAY_B_TABLE_DATA "crc24_flexray_b.table"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t width;
    uint8_t input_reflected;
    uint8_t result_reflected;
    // data
    CRC24_FLEXRAY_B_NUM_TYPE polynomial;
    CRC24_FLEXRAY_B_NUM_TYPE initial_value;
    CRC24_FLEXRAY_B_NUM_TYPE final_xor_value;
    CRC24_FLEXRAY_B_NUM_TYPE accumulate;
    CRC24_FLEXRAY_B_NUM_TYPE cast_mask;
} CRC24_FLEXRAY_B;

void crc24_flexray_b_init(CRC24_FLEXRAY_B *crc);
CRC24_FLEXRAY_B_NUM_TYPE crc24_flexray_b_calc(CRC24_FLEXRAY_B *crc, void *data, size_t length);
CRC24_FLEXRAY_B_NUM_TYPE crc24_flexray_b_accum(CRC24_FLEXRAY_B *crc, void *data, size_t length);
void crc24_flexray_b_reset(CRC24_FLEXRAY_B *crc);
CRC24_FLEXRAY_B_NUM_TYPE crc24_flexray_b_get(CRC24_FLEXRAY_B *crc);

#ifdef __cplusplus
}
#endif

#endif
