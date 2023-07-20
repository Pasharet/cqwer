CC = gcc
RC = windres
CFLAGS = -O0

icon: cqwer.rc
	$(RC) cqwer.rc -o cqwer.o

cqwer: cqwer.o cqwer.c
	$(CC) $(CFLAGS) cqwer.c cqwer.o -o cqwer.exe

cqwer-gui: cqwer-gui.c
	$(CC) $(CFLAGS) cqwer-gui.c -o cqwer-gui.exe

clean:
	del cqwer.o cqwer.exe

clean2:
	del cqwer-gui.exe