/** Genetrate from template/example.c
 * @param algorithm: crc24_openpgp
 * @param algorithm_upper: CRC24_OPENPGP
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
#include <stdio.h>
#include <string.h>

#include "crc24_openpgp.h"

int main() {
    CRC24_OPENPGP crc;
    CRC24_OPENPGP_NUM_TYPE crc_val, crc1, crc2;

    char *data[] = {
        "hello ",
        "world",
        "!!!",
    };

    CRC(crc24_openpgp, init)(&crc);

    printf("\nCRC24_OPENPGP Test Start\n\n");

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        crc_val = CRC(crc24_openpgp, calc)(&crc, data[i], strlen(data[i]));
        printf("0x%0" CRC24_OPENPGP_NUM_WIDTH CRC24_OPENPGP_NUM_PRIx " ", crc_val);
    }
    crc1 = CRC(crc24_openpgp, calc)(&crc, "hello world!!!", 14);
    printf("0x%0" CRC24_OPENPGP_NUM_WIDTH CRC24_OPENPGP_NUM_PRIx "\n", crc1);

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        crc_val = CRC(crc24_openpgp, accum)(&crc, data[i], strlen(data[i]));
        printf("0x%0" CRC24_OPENPGP_NUM_WIDTH CRC24_OPENPGP_NUM_PRIx " ", crc_val);
    }
    crc2 = CRC(crc24_openpgp, get)(&crc);
    printf("0x%0" CRC24_OPENPGP_NUM_WIDTH CRC24_OPENPGP_NUM_PRIx "\n", crc2);

    if (crc1 == crc2) {
        printf("\nTest crc24_openpgp succeeded!!!\n\n");
        return 0;
    } else {
        printf("\nTest crc24_openpgp failed!!!\n\n");
        return -1;
    }
}
