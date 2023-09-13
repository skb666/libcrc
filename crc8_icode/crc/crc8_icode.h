/** Genetrate from template/crc/crc.h
 * @param algorithm: crc8_icode
 * @param algorithm_upper: CRC8_ICODE
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
#ifndef __CRC8_ICODE_H__
#define __CRC8_ICODE_H__

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CRC
#define CRC(ALG, OPT) ALG##_##OPT
#endif

#define CRC8_ICODE_NUM_WIDTH "2"
#define CRC8_ICODE_NUM_PRIx PRIx8
#define CRC8_ICODE_NUM_PRIX PRIX8

#define CRC8_ICODE_NUM_TYPE uint8_t
#define CRC8_ICODE_DEFAULT_DATA "crc8_icode.default"
#define CRC8_ICODE_TABLE_DATA "crc8_icode.table"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t width;
    uint8_t input_reflected;
    uint8_t result_reflected;
    // data
    CRC8_ICODE_NUM_TYPE polynomial;
    CRC8_ICODE_NUM_TYPE initial_value;
    CRC8_ICODE_NUM_TYPE final_xor_value;
    CRC8_ICODE_NUM_TYPE accumulate;
} CRC8_ICODE;

void crc8_icode_init(CRC8_ICODE *crc);
CRC8_ICODE_NUM_TYPE crc8_icode_calc(CRC8_ICODE *crc, void *data, size_t length);
CRC8_ICODE_NUM_TYPE crc8_icode_accum(CRC8_ICODE *crc, void *data, size_t length);
void crc8_icode_reset(CRC8_ICODE *crc);
CRC8_ICODE_NUM_TYPE crc8_icode_get(CRC8_ICODE *crc);

#ifdef __cplusplus
}
#endif

#endif
