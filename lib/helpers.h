#ifndef helpers_h
#define helpers_h

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int spawn (const char * file, char * const argv[]);
ssize_t read_until(int fd, void *buf, size_t count, char delimeter);
ssize_t read_(int fd, void *buf, size_t count);
ssize_t write_(int fd, const void *buf, size_t count);

#endif
