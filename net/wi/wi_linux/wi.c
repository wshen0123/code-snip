#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "wi.h"

int wi_read(struct wif *wi, unsigned char *h80211, int len, struct rx_info *ri)
{
	assert(wi->wi_read);
	return wi->wi_read(wi, h80211, len, ri);
}

int wi_write(struct wif *wi, unsigned char *h80211, int len, struct tx_info *ti)
{
	assert(wi->wi_write);
	return wi->wi_write(wi, h80211, len, ti);
}

int wi_set_channel(struct wif *wi, int chan)
{
	assert(wi->wi_set_channel);
	return wi->wi_set_channel(wi, chan);
}

int wi_get_channel(struct wif *wi)
{
	assert(wi->wi_get_channel);
	return wi->wi_get_channel(wi);
}

int wi_set_freq(struct wif *wi, int freq)
{
	assert(wi->wi_set_freq);
	return wi->wi_set_freq(wi, freq);
}

int wi_get_freq(struct wif *wi)
{
	assert(wi->wi_get_freq);
	return wi->wi_get_freq(wi);
}

int wi_get_monitor(struct wif *wi)
{
	assert(wi->wi_get_monitor);
	return wi->wi_get_monitor(wi);
}

char *wi_get_ifname(struct wif *wi)
{
	return wi->wi_interface;
}

void wi_close(struct wif *wi)
{
	assert(wi->wi_close);
	wi->wi_close(wi);
}

int wi_fd(struct wif *wi)
{
	assert(wi->wi_fd);
	return wi->wi_fd(wi);
}

struct wif *wi_alloc(int sz)
{
	struct wif *wi;
	void *priv;

	/* Allocate wif & private state */
	wi = malloc(sizeof(*wi));
	if (!wi)
		return NULL;
	memset(wi, 0, sizeof(*wi));

	priv = malloc(sz);
	if (!priv) {
		free(wi);
		return NULL;
	}
	memset(priv, 0, sz);
	wi->wi_priv = priv;

	return wi;
}

void *wi_priv(struct wif *wi)
{
	return wi->wi_priv;
}

int wi_get_mac(struct wif *wi, unsigned char *mac)
{
	assert(wi->wi_get_mac);
	return wi->wi_get_mac(wi, mac);
}

int wi_set_mac(struct wif *wi, unsigned char *mac)
{
	assert(wi->wi_set_mac);
	return wi->wi_set_mac(wi, mac);
}

int wi_get_rate(struct wif *wi)
{
	assert(wi->wi_get_rate);
	return wi->wi_get_rate(wi);
}

int wi_set_rate(struct wif *wi, int rate)
{
	assert(wi->wi_set_rate);
	return wi->wi_set_rate(wi, rate);
}

int wi_get_mtu(struct wif *wi)
{
	assert(wi->wi_get_mtu);
	return wi->wi_get_mtu(wi);
}

int wi_set_mtu(struct wif *wi, int mtu)
{
	assert(wi->wi_set_mtu);
	return wi->wi_set_mtu(wi, mtu);
}

struct wif *wi_open(char *iface)
{
	struct wif *wi;

	wi = wi_open_osdep(iface);
	if (!wi)
		return NULL;

	strncpy(wi->wi_interface, iface, sizeof(wi->wi_interface) - 1);
	wi->wi_interface[sizeof(wi->wi_interface) - 1] = 0;

	return wi;
}
