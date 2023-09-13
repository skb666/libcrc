/** Genetrate from template/crc/crc.h
 * @param algorithm: crc8_ebu
 * @param algorithm_upper: CRC8_EBU
 * @param display_width: 2
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
#ifndef __CRC8_EBU_H__
#define __CRC8_EBU_H__

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CRC
#define CRC(ALG, OPT) ALG##_##OPT
#endif

#define CRC8_EBU_NUM_WIDTH "2"
#define CRC8_EBU_NUM_PRIx PRIx8
#define CRC8_EBU_NUM_PRIX PRIX8

#define CRC8_EBU_NUM_TYPE uint8_t
#define CRC8_EBU_DEFAULT_DATA "crc8_ebu.default"
#define CRC8_EBU_TABLE_DATA "crc8_ebu.table"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t width;
    uint8_t input_reflected;
    uint8_t result_reflected;
    // data
    CRC8_EBU_NUM_TYPE polynomial;
    CRC8_EBU_NUM_TYPE initial_value;
    CRC8_EBU_NUM_TYPE final_xor_value;
    CRC8_EBU_NUM_TYPE accumulate;
} CRC8_EBU;

void crc8_ebu_init(CRC8_EBU *crc);
CRC8_EBU_NUM_TYPE crc8_ebu_calc(CRC8_EBU *crc, void *data, size_t length);
CRC8_EBU_NUM_TYPE crc8_ebu_accum(CRC8_EBU *crc, void *data, size_t length);
void crc8_ebu_reset(CRC8_EBU *crc);
CRC8_EBU_NUM_TYPE crc8_ebu_get(CRC8_EBU *crc);

#ifdef __cplusplus
}
#endif

#endif
