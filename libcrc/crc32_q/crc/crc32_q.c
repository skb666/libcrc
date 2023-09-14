/** Genetrate from template/crc/crc.c
 * @param algorithm: crc32_q
 * @param algorithm_upper: CRC32_Q
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
#include "crc32_q.h"

#include <stdio.h>
#include <string.h>

const static CRC32_Q crc32_q_default = {
#include CRC32_Q_DEFAULT_DATA
};

const static CRC32_Q_NUM_TYPE crc32_q_table[] = {
#include CRC32_Q_TABLE_DATA
};

static CRC32_Q_NUM_TYPE crc32_q_reverse_bits(CRC32_Q_NUM_TYPE data, uint8_t width) {
    CRC32_Q_NUM_TYPE result = 0;

    for (uint8_t i = 0; i < width; ++i) {
        result <<= 1;
        result |= data & 1;
        data >>= 1;
    }

    return result;
}

void crc32_q_init(CRC32_Q *crc) {
    memcpy(crc, &crc32_q_default, sizeof(CRC32_Q));
}

static CRC32_Q_NUM_TYPE crc32_q_calc_reflect(CRC32_Q *crc, void *data, size_t length) {
    uint8_t *value, index;
    CRC32_Q_NUM_TYPE crc_val;

    value = (uint8_t *)data;
    crc_val = crc->initial_value;

    for (size_t i = 0; i < length; ++value, ++i) {
        index = (crc_val & 0xFF) ^ (*value);
        crc_val = (crc_val >> 8) & crc->cast_mask;
        crc_val ^= crc32_q_table[index];
    }

    return crc_val ^ crc->final_xor_value;
}

CRC32_Q_NUM_TYPE crc32_q_calc(CRC32_Q *crc, void *data, size_t length) {
    uint8_t *value, index;
    CRC32_Q_NUM_TYPE crc_val, data_xor;

    if (crc->input_reflected && crc->result_reflected) {
        return crc32_q_calc_reflect(crc, data, length);
    }

    value = (uint8_t *)data;
    crc_val = crc->initial_value;

    for (size_t i = 0; i < length; ++value, ++i) {
        if (crc->input_reflected) {
            data_xor = crc32_q_reverse_bits(*value, 8) & 0xFF;
        } else {
            data_xor = *value;
        }

        crc_val = (crc_val ^ (data_xor << (crc->width - 8))) & crc->cast_mask;
        index = (uint8_t)((crc_val >> (crc->width - 8)) & 0xFF);
        crc_val = (crc_val << 8) & crc->cast_mask;
        crc_val ^= crc32_q_table[index];
    }

    if (crc->result_reflected) {
        crc_val = crc32_q_reverse_bits(crc_val, crc->width);
    }

    return crc_val ^ crc->final_xor_value;
}

static CRC32_Q_NUM_TYPE crc32_q_accum_reflect(CRC32_Q *crc, void *data, size_t length) {
    uint8_t *value, index;

    value = (uint8_t *)data;

    for (size_t i = 0; i < length; ++value, ++i) {
        index = (crc->accumulate & 0xFF) ^ (*value);
        crc->accumulate = (crc->accumulate >> 8) & crc->cast_mask;
        crc->accumulate ^= crc32_q_table[index];
    }

    return crc->accumulate ^ crc->final_xor_value;
}

CRC32_Q_NUM_TYPE crc32_q_accum(CRC32_Q *crc, void *data, size_t length) {
    uint8_t *value, index;
    CRC32_Q_NUM_TYPE data_xor;

    if (crc->input_reflected && crc->result_reflected) {
        return crc32_q_accum_reflect(crc, data, length);
    }

    value = (uint8_t *)data;

    for (size_t i = 0; i < length; ++value, ++i) {
        if (crc->input_reflected) {
            data_xor = crc32_q_reverse_bits(*value, 8) & 0xFF;
        } else {
            data_xor = *value;
        }

        crc->accumulate = (crc->accumulate ^ (data_xor << (crc->width - 8))) & crc->cast_mask;
        index = (uint8_t)((crc->accumulate >> (crc->width - 8)) & 0xFF);
        crc->accumulate = (crc->accumulate << 8) & crc->cast_mask;
        crc->accumulate ^= crc32_q_table[index];
    }

    if (crc->result_reflected) {
        crc->accumulate = crc32_q_reverse_bits(crc->accumulate, crc->width);
    }

    return crc->accumulate ^ crc->final_xor_value;
}

void crc32_q_reset(CRC32_Q *crc) {
    crc->accumulate = crc->initial_value;
}

CRC32_Q_NUM_TYPE crc32_q_get(CRC32_Q *crc) {
    CRC32_Q_NUM_TYPE crc_val;

    crc_val = crc->accumulate;
    // crc32_q_reset(crc);

    return crc_val ^ crc->final_xor_value;
}
