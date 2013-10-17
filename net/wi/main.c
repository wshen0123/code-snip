#include <stdlib.h>
#include <stdio.h>
#include "utility.h"
#include "wi_linux/wi.h"

char* interface = "mon0";

uint8_t buffer[2000];
int caplen;

int main()
{
	struct wif *wi;
	
	wi = wi_open(interface);
	if (!wi) {
		printf("%s failed", interface);
	}
	printf("%s\n", wi_get_ifname(wi));
	printf("%d\n", wi_get_channel(wi));
	
	caplen = wi_read(wi, buffer, 1000, 0);
	
	print_offset_hex(buffer, caplen);
	
	return 0;
}
