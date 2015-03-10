#include <helpers.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

void error_(const char * error) {
	//perror(errno);
	//write_(STDERR_FILENO, stderror(errno), sizeof(char)*stderror(errno));
	fprintf(stderr, "%s\n", error);
}

int main() {
	char buf[4096];
	size_t len = 0;
	size_t len1 = 0;
	size_t count = sizeof(buf);

	do {
		len = read_(STDIN_FILENO, buf, count);
		if (len == -1) {
			error_(strerror(errno));
			exit(1);
		}
		len1 = write_(STDOUT_FILENO, buf, len);
		if (len1 < len) {
			error_(strerror(errno));
			exit(1);	
		}
	} while (len == count); 
	
	return 0;	
}
