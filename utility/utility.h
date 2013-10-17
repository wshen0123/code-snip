
#ifndef __UTILITY_H__
#define __UTILITY_H__
#include <stdint.h>
#include <stdio.h>
void print_hex(uint8_t * data, uint32_t len);
void print_offset_hex(uint8_t * data, uint32_t len);
void fprint_offset_hex(FILE * out_file, uint8_t * data, uint32_t len);
void fprint_hex(FILE * out_file, uint8_t * data, uint32_t len);

unsigned long calc_crc32(unsigned char *buf, int len);
int append_crc32(unsigned char *buf, int len);
int check_crc32(unsigned char *buf, int len);
int hex2bin(char *hex, uint8_t * byte);
#endif
