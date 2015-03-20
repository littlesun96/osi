#include <stdlib.h>
#include <helpers.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

void error_(const char *error) {
	fprintf(stderr, "%s\n", error);
	exit(1);
}

int main(int argc, char *argv[]) {

	char buf[4096];
	char word[4096];
	int len = 0;
	int pos = 0;
	
    //int n = argv[1].size;
    int n = strlen(argv[1]);

	do {
		len = read_until(STDIN_FILENO, buf, sizeof(buf), argv[1][0]);
		if (len == -1) {
			error_(strerror(errno));
		}

        int f = 0;
        int i = 0;
        for (i = 0; i < len; i++) {
            if (buf[i] == argv[1][0]) {
                f = 0;
                write_(STDOUT_FILENO, word, pos);
                pos = 0;
                word[pos] = buf[i];
                pos++;
                int k;
                for (k = 1; k < n; k++) {
                        if (buf[i + k] != argv[1][k]) {
                            f = 1;
                            break;
                        }
                }
                if (f == 0) {
                    i += n - 1;
                    pos = 0;
                }
            } else {
                word[pos] = buf[i];
                pos++;
            }
        }

	} while (len > 0);

    if (pos > 0) {
        write_(STDOUT_FILENO, word, pos);
    }

	return 0;
}
