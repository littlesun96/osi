all: ../lib/libhelpers.so
	gcc delwords.c -I../lib/ -L../lib/ -lhelpers -o delwords
../lib/libhelpers.so:
	$(MAKE) -C ../lib