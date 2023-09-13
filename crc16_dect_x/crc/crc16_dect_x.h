/** Genetrate from template/crc/crc.h
 * @param algorithm: crc16_dect_x
 * @param algorithm_upper: CRC16_DECT_X
 * @param display_width: 4
 * @param width: 16
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
#ifndef __CRC16_DECT_X_H__
#define __CRC16_DECT_X_H__

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CRC
#define CRC(ALG, OPT) ALG##_##OPT
#endif

#define CRC16_DECT_X_NUM_WIDTH "4"
#define CRC16_DECT_X_NUM_PRIx PRIx16
#define CRC16_DECT_X_NUM_PRIX PRIX16

#define CRC16_DECT_X_NUM_TYPE uint16_t
#define CRC16_DECT_X_DEFAULT_DATA "crc16_dect_x.default"
#define CRC16_DECT_X_TABLE_DATA "crc16_dect_x.table"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t width;
    uint8_t input_reflected;
    uint8_t result_reflected;
    // data
    CRC16_DECT_X_NUM_TYPE polynomial;
    CRC16_DECT_X_NUM_TYPE initial_value;
    CRC16_DECT_X_NUM_TYPE final_xor_value;
    CRC16_DECT_X_NUM_TYPE accumulate;
} CRC16_DECT_X;

void crc16_dect_x_init(CRC16_DECT_X *crc);
CRC16_DECT_X_NUM_TYPE crc16_dect_x_calc(CRC16_DECT_X *crc, void *data, size_t length);
CRC16_DECT_X_NUM_TYPE crc16_dect_x_accum(CRC16_DECT_X *crc, void *data, size_t length);
void crc16_dect_x_reset(CRC16_DECT_X *crc);
CRC16_DECT_X_NUM_TYPE crc16_dect_x_get(CRC16_DECT_X *crc);

#ifdef __cplusplus
}
#endif

#endif
