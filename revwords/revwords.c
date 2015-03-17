#include <stdlib.h>
#include <helpers.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

void error_(const char *error) {
	fprintf(stderr, "%s\n", error);
	exit(1);
}

void reverse(char* word, int pos) {
	int i;
	for (i = 0; i < pos/2; i++) {
		char c = word[i];
		word[i] = word[pos - i - 1];
		word[pos - i - 1] = c;
	}
	
	write_(STDOUT_FILENO, word, pos);
}

int main() {

	char buf[4096];
	char word[4096];
	int len = 0;
	int pos = 0;
	
	do {
		len = read_until(STDIN_FILENO, buf, sizeof(buf), ' ');
		if (len == -1) {
			error_(strerror(errno));
		}
		
		int i;
		for (i = 0; i < len; i++) {
			if (buf[i] == ' ') {
				if (pos != 0) 
					reverse(word, pos);
				pos = 0;
				char c = ' ';
				write_(STDOUT_FILENO, &c, 1);
			} else {
				word[pos] = buf[i];
				pos++;
			}
		
		}

	} while (len > 0);
	
	if (pos != 0) 
		reverse(word, pos);

	return 0;
}
