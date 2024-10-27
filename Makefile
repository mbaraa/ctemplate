CFLAGS = "-Wall -fPIC -I ."

all: libctemplate.so

libctemplate.so: ctemplate.c
	gcc -shared -o libctemplate.so ctemplate.c

install: libctemplate.so
	install -m 0755 libctemplate.so /usr/lib
	install -d /usr/include/ctemplate
	install -m 0644 ctemplate.h /usr/include/ctemplate/ctemplate.h

uninstall:
	rm -f /usr/lib/libctemplate.so
	rm -f /usr/include/ctemplate/ctemplate.h
	rmdir /usr/include/ctemplate

clean:
	rm -f *.o libctemplate.so
