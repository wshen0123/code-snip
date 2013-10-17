#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <assert.h>
#include <linux/if_tun.h>

int tun_create(char *dev, int flags)
{
	struct ifreq ifr;
	int fd, err;

	assert(dev != NULL);

	if ((fd = open("/dev/net/tun", O_RDWR)) < 0)
		return fd;

	memset(&ifr, 0, sizeof(ifr));
	ifr.ifr_flags |= flags;
	if (*dev != '\0')
		strncpy(ifr.ifr_name, dev, IFNAMSIZ);

	if ((err = ioctl(fd, TUNSETIFF, (void *)&ifr)) < 0) {
		close(fd);
		return err;
	}
	strcpy(dev, ifr.ifr_name);

	return fd;
}

int main(int argc, char *argv[])
{
	int tun, ret;
	char tun_name[IFNAMSIZ];
	unsigned char buf[4096];

	tun_name[0] = '\0';
	tun = tun_create(tun_name, IFF_TAP | IFF_NO_PI);
	if (tun < 0) {
		perror("tun_create");
		return 1;
	}
	printf("TUN name is %s\n", tun_name);

	while (1) {

		unsigned char ip[4];

		ret = read(tun, buf, sizeof(buf));
		if (ret < 0)
			break;
		printf("read %d bytes\n", ret);
		
		
		memcpy(ip, &buf[12+14], 4);
		memcpy(&buf[12+14], &buf[16+14], 4);
		memcpy(&buf[16+14], ip, 4);
		buf[20+14] = 0;
		*((unsigned short *) & buf[22+14]) += 8;
		ret = write(tun, buf, ret);
		printf("write %d bytes\n", ret);
	}

	return 0;
}
