/** Genetrate from template/crc/crc.h
 * @param algorithm: crc8_sae_j1850_zero
 * @param algorithm_upper: CRC8_SAE_J1850_ZERO
 * @param display_width: 2
 * @param data_width: 8
 * @param width: 8
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
#ifndef __CRC8_SAE_J1850_ZERO_H__
#define __CRC8_SAE_J1850_ZERO_H__

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CRC
#define CRC(ALG, OPT) ALG##_##OPT
#endif

#define CRC8_SAE_J1850_ZERO_NUM_WIDTH "2"
#define CRC8_SAE_J1850_ZERO_NUM_PRIx PRIx8
#define CRC8_SAE_J1850_ZERO_NUM_PRIX PRIX8

#define CRC8_SAE_J1850_ZERO_NUM_TYPE uint8_t
#define CRC8_SAE_J1850_ZERO_DEFAULT_DATA "crc8_sae_j1850_zero.default"
#define CRC8_SAE_J1850_ZERO_TABLE_DATA "crc8_sae_j1850_zero.table"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t width;
    uint8_t input_reflected;
    uint8_t result_reflected;
    // data
    CRC8_SAE_J1850_ZERO_NUM_TYPE polynomial;
    CRC8_SAE_J1850_ZERO_NUM_TYPE initial_value;
    CRC8_SAE_J1850_ZERO_NUM_TYPE final_xor_value;
    CRC8_SAE_J1850_ZERO_NUM_TYPE accumulate;
    CRC8_SAE_J1850_ZERO_NUM_TYPE cast_mask;
} CRC8_SAE_J1850_ZERO;

void crc8_sae_j1850_zero_init(CRC8_SAE_J1850_ZERO *crc);
CRC8_SAE_J1850_ZERO_NUM_TYPE crc8_sae_j1850_zero_calc(CRC8_SAE_J1850_ZERO *crc, void *data, size_t length);
CRC8_SAE_J1850_ZERO_NUM_TYPE crc8_sae_j1850_zero_accum(CRC8_SAE_J1850_ZERO *crc, void *data, size_t length);
void crc8_sae_j1850_zero_reset(CRC8_SAE_J1850_ZERO *crc);
CRC8_SAE_J1850_ZERO_NUM_TYPE crc8_sae_j1850_zero_get(CRC8_SAE_J1850_ZERO *crc);

#ifdef __cplusplus
}
#endif

#endif
