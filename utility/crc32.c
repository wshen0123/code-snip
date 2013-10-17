#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utility.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
		printf(" Usage: crc32 hexstream.\n");
	
	int bin_len = strlen(argv[1]) >> 1;
	char *buffer = malloc(bin_len + 4);
	hex2bin(argv[1], buffer);
	
	append_crc32(buffer, bin_len);
	print_hex(buffer + bin_len, 4);
	
	return 0;
}
