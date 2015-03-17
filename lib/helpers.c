#include "helpers.h"

ssize_t read_(int fd, void *buf, size_t count) {
	size_t res = 0;
	size_t len = 0;
	
	if (count == 0) 
		return read(fd, buf, 0);
	
	while(1) {
		len = read(fd, buf + res, count);
		if (len == 0)
			return res;
		if (len == -1)
			return -1;
		res += len;
		count -= len;
	}
}

ssize_t read_until(int fd, void *buf, size_t count, char delimeter) {
	size_t res = 0;
	size_t len = 0;
	int flag = 0;
	
	if (count == 0)
		return read(fd, buf, 0);
	
	while(1) {
		len = read(fd, buf + res, count);
		if (len == 0) 
			return res;
		if (len == -1)
			return -1;
		res += len;
		count -= len;
		
		int i;
		for (i = 0; i < len; i++) {
			if ((((char*)buf)[i + res]) == delimeter) {
				flag = 1;
				break;
			}
		}
		
		if (flag == 1) 
			return res;
	}
}

ssize_t write_(int fd, const void *buf, size_t count) {
	size_t res = 0;
	size_t len = 0;

	do {
		len = write(fd, buf + res, count);
		if (len == -1)
			return -1;
		res += len;
		count -= len;
	} while(len > 0 && count > 0); 
	
	return res;
}	
