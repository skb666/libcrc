#include "main.h"

int main() {
    test_crc8();
    test_crc16_kermit();
    test_crc24_openpgp();
    test_crc32();
    test_crc64_go_iso();

    return 0;
}
