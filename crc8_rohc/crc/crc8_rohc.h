/** Genetrate from template/crc/crc.h
 * @param algorithm: crc8_rohc
 * @param algorithm_upper: CRC8_ROHC
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
#ifndef __CRC8_ROHC_H__
#define __CRC8_ROHC_H__

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CRC
#define CRC(ALG, OPT) ALG##_##OPT
#endif

#define CRC8_ROHC_NUM_WIDTH "2"
#define CRC8_ROHC_NUM_PRIx PRIx8
#define CRC8_ROHC_NUM_PRIX PRIX8

#define CRC8_ROHC_NUM_TYPE uint8_t
#define CRC8_ROHC_DEFAULT_DATA "crc8_rohc.default"
#define CRC8_ROHC_TABLE_DATA "crc8_rohc.table"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t width;
    uint8_t input_reflected;
    uint8_t result_reflected;
    // data
    CRC8_ROHC_NUM_TYPE polynomial;
    CRC8_ROHC_NUM_TYPE initial_value;
    CRC8_ROHC_NUM_TYPE final_xor_value;
    CRC8_ROHC_NUM_TYPE accumulate;
    CRC8_ROHC_NUM_TYPE cast_mask;
} CRC8_ROHC;

void crc8_rohc_init(CRC8_ROHC *crc);
CRC8_ROHC_NUM_TYPE crc8_rohc_calc(CRC8_ROHC *crc, void *data, size_t length);
CRC8_ROHC_NUM_TYPE crc8_rohc_accum(CRC8_ROHC *crc, void *data, size_t length);
void crc8_rohc_reset(CRC8_ROHC *crc);
CRC8_ROHC_NUM_TYPE crc8_rohc_get(CRC8_ROHC *crc);

#ifdef __cplusplus
}
#endif

#endif
