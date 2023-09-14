/** Genetrate from template/crc/crc.h
 * @param algorithm: crc64_go_iso
 * @param algorithm_upper: CRC64_GO_ISO
 * @param display_width: 16
 * @param data_width: 64
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
#ifndef __CRC64_GO_ISO_H__
#define __CRC64_GO_ISO_H__

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef CRC
#define CRC(ALG, OPT) ALG##_##OPT
#endif

#define CRC64_GO_ISO_NUM_WIDTH "16"
#define CRC64_GO_ISO_NUM_PRIx PRIx64
#define CRC64_GO_ISO_NUM_PRIX PRIX64

#define CRC64_GO_ISO_NUM_TYPE uint64_t
#define CRC64_GO_ISO_DEFAULT_DATA "crc64_go_iso.default"
#define CRC64_GO_ISO_TABLE_DATA "crc64_go_iso.table"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t width;
    uint8_t input_reflected;
    uint8_t result_reflected;
    // data
    CRC64_GO_ISO_NUM_TYPE polynomial;
    CRC64_GO_ISO_NUM_TYPE initial_value;
    CRC64_GO_ISO_NUM_TYPE final_xor_value;
    CRC64_GO_ISO_NUM_TYPE accumulate;
    CRC64_GO_ISO_NUM_TYPE cast_mask;
} CRC64_GO_ISO;

void crc64_go_iso_init(CRC64_GO_ISO *crc);
CRC64_GO_ISO_NUM_TYPE crc64_go_iso_calc(CRC64_GO_ISO *crc, void *data, size_t length);
CRC64_GO_ISO_NUM_TYPE crc64_go_iso_accum(CRC64_GO_ISO *crc, void *data, size_t length);
void crc64_go_iso_reset(CRC64_GO_ISO *crc);
CRC64_GO_ISO_NUM_TYPE crc64_go_iso_get(CRC64_GO_ISO *crc);

#ifdef __cplusplus
}
#endif

#endif
