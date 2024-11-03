all: libctemplate.so

# Compile source files to object files
ctemplate.o: ctemplate.c ctemplate.h
	gcc -Wall -fPIC -g -c ctemplate.c -o ctemplate.o

buffer.o: buffer.c buffer.h
	gcc -Wall -fPIC -g -c buffer.c -o buffer.o

# Create the shared library
libctemplate.so: ctemplate.o buffer.o
	gcc -shared -o libctemplate.so ctemplate.o buffer.o

# Install the library and header files
install: libctemplate.so
	mkdir -p /usr/lib
	mkdir -p /usr/include/ctemplate
	cp libctemplate.so /usr/lib
	cp ctemplate.h buffer.h /usr/include/ctemplate
	ldconfig

# Clean up
clean:
	rm -f ctemplate.o buffer.o libctemplate.so

# Uninstall the library and header files
uninstall:
	rm -f /usr/lib/libctemplate.so
	rm -rf /usr/include/ctemplate
	ldconfig
