CFLAGS = -I .

all: libctemplate.so libctemplate_buffer.so

libctemplate.so: ctemplate.c
	gcc $(CFLAGS) -Wall -fPIC -g -shared -o libctemplate.so ctemplate.c

libctemplate_buffer.so: buffer.c
	gcc $(CFLAGS) -Wall -fPIC -g -shared -o libctemplate_buffer.so buffer.c

install: libctemplate.so libctemplate_buffer.so
	install -m 0755 libctemplate.so /usr/lib
	install -m 0755 libctemplate_buffer.so /usr/lib
	install -d /usr/include/ctemplate
	install -m 0644 ctemplate.h /usr/include/ctemplate/ctemplate.h
	install -m 0644 buffer.h /usr/include/ctemplate/buffer.h

uninstall:
	rm -f /usr/lib/libctemplate.so
	rm -f /usr/lib/libctemplate_buffer.so
	rm -f /usr/include/ctemplate/ctemplate.h
	rm -f /usr/include/ctemplate/buffer.h
	rmdir /usr/include/ctemplate

clean:
	rm -f *.o *.so
