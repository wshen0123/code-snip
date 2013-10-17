#include "utility.h"
#include "string.h"


int main(int argc, char *argv[])
{
	uint8_t buffer[1000];
	int bin_len;
	if (argc != 2 && argc != 3){
		printf("hex2bin hex_stream option(-o)\n");
		return 0;
	}
	
	bin_len = hex2bin(argv[1], buffer);
	
	if (argc == 3 && !strcmp(argv[2], "-o")) {
		print_offset_hex(buffer, bin_len);
	} else {
		printf("\n");
		print_hex(buffer, bin_len);
		printf("\n");
	}
	
	printf("\n");
	return 0;
}
		
	
