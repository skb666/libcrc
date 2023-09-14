#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif

int test_crc8(void);
int test_crc16_kermit(void);
int test_crc24_openpgp(void);
int test_crc32(void);
int test_crc64_go_iso(void);

#ifdef __cplusplus
}
#endif

#endif
