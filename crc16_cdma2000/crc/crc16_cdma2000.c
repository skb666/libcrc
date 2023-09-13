/** Genetrate from template/crc/crc.c
 * @param algorithm: crc16_cdma2000
 * @param algorithm_upper: CRC16_CDMA2000
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
#include "crc16_cdma2000.h"

#include <stdio.h>
#include <string.h>

const static CRC16_CDMA2000 crc16_cdma2000_default = {
#include CRC16_CDMA2000_DEFAULT_DATA
};

const static CRC16_CDMA2000_NUM_TYPE crc16_cdma2000_table[] = {
#include CRC16_CDMA2000_TABLE_DATA
};

static CRC16_CDMA2000_NUM_TYPE crc16_cdma2000_reverse_bits(CRC16_CDMA2000_NUM_TYPE data, uint8_t width) {
    CRC16_CDMA2000_NUM_TYPE result = 0;

    for (uint8_t i = 0; i < width; ++i) {
        result <<= 1;
        result |= data & 1;
        data >>= 1;
    }

    return result;
}

void crc16_cdma2000_init(CRC16_CDMA2000 *crc) {
    memcpy(crc, &crc16_cdma2000_default, sizeof(CRC16_CDMA2000));
}

static CRC16_CDMA2000_NUM_TYPE crc16_cdma2000_calc_reflect(CRC16_CDMA2000 *crc, void *data, size_t length) {
    uint8_t *value, index;
    CRC16_CDMA2000_NUM_TYPE crc_val;

    value = (uint8_t *)data;
    crc_val = crc->initial_value;

    for (size_t i = 0; i < length; ++value, ++i) {
        index = (crc_val & 0xFF) ^ (*value);
        crc_val >>= 8;
        crc_val ^= crc16_cdma2000_table[index];
    }

    return crc_val ^ crc->final_xor_value;
}

CRC16_CDMA2000_NUM_TYPE crc16_cdma2000_calc(CRC16_CDMA2000 *crc, void *data, size_t length) {
    uint8_t *value, index;
    CRC16_CDMA2000_NUM_TYPE crc_val, data_xor;

    if (crc->input_reflected && crc->result_reflected) {
        return crc16_cdma2000_calc_reflect(crc, data, length);
    }

    value = (uint8_t *)data;
    crc_val = crc->initial_value;

    for (size_t i = 0; i < length; ++value, ++i) {
        if (crc->input_reflected) {
            data_xor = crc16_cdma2000_reverse_bits(*value, 8) & 0xFF;
        } else {
            data_xor = *value;
        }

        crc_val ^= data_xor << (crc->width - 8);
        index = (uint8_t)((crc_val >> (crc->width - 8)) & 0xFF);
        crc_val <<= 8;
        crc_val ^= crc16_cdma2000_table[index];
    }

    if (crc->result_reflected) {
        crc_val = crc16_cdma2000_reverse_bits(crc_val, crc->width);
    }

    return crc_val ^ crc->final_xor_value;
}

static CRC16_CDMA2000_NUM_TYPE crc16_cdma2000_accum_reflect(CRC16_CDMA2000 *crc, void *data, size_t length) {
    uint8_t *value, index;

    value = (uint8_t *)data;

    for (size_t i = 0; i < length; ++value, ++i) {
        index = (crc->accumulate & 0xFF) ^ (*value);
        crc->accumulate >>= 8;
        crc->accumulate ^= crc16_cdma2000_table[index];
    }

    return crc->accumulate ^ crc->final_xor_value;
}

CRC16_CDMA2000_NUM_TYPE crc16_cdma2000_accum(CRC16_CDMA2000 *crc, void *data, size_t length) {
    uint8_t *value, index;
    CRC16_CDMA2000_NUM_TYPE data_xor;

    if (crc->input_reflected && crc->result_reflected) {
        return crc16_cdma2000_accum_reflect(crc, data, length);
    }

    value = (uint8_t *)data;

    for (size_t i = 0; i < length; ++value, ++i) {
        if (crc->input_reflected) {
            data_xor = crc16_cdma2000_reverse_bits(*value, 8) & 0xFF;
        } else {
            data_xor = *value;
        }

        crc->accumulate ^= data_xor << (crc->width - 8);
        index = (uint8_t)((crc->accumulate >> (crc->width - 8)) & 0xFF);
        crc->accumulate <<= 8;
        crc->accumulate ^= crc16_cdma2000_table[index];
    }

    if (crc->result_reflected) {
        crc->accumulate = crc16_cdma2000_reverse_bits(crc->accumulate, crc->width);
    }

    return crc->accumulate ^ crc->final_xor_value;
}

void crc16_cdma2000_reset(CRC16_CDMA2000 *crc) {
    crc->accumulate = crc->initial_value;
}

CRC16_CDMA2000_NUM_TYPE crc16_cdma2000_get(CRC16_CDMA2000 *crc) {
    CRC16_CDMA2000_NUM_TYPE crc_val;

    crc_val = crc->accumulate;
    // crc16_cdma2000_reset(crc);

    return crc_val ^ crc->final_xor_value;
}
