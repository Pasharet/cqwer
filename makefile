CC = gcc
RC = windres
CFLAGS = -O0

cqwer.o: cqwer.rc
	$(RC) cqwer.rc -o cqwer.o

cqwer: cqwer.o cqwer.c
	$(CC) $(CFLAGS) cqwer.c cqwer.o -o cqwer.exe

clean:
	del cqwer.o cqwer.exe
