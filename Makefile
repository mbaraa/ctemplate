ifndef PREFIX
   PREFIX=/usr
else
   PREFIX=/usr/local
endif

LIB_DIR=$(PREFIX)/lib
INCLUDE_DIR=$(PREFIX)/include

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
	mkdir -p $(LIB_DIR)
	mkdir -p $(INCLUDE_DIR)/ctemplate
	cp libctemplate.so $(LIB_DIR)
	cp ctemplate.h buffer.h $(INCLUDE_DIR)/ctemplate
	ldconfig

# Clean up
clean:
	rm -f ctemplate.o buffer.o libctemplate.so

# Uninstall the library and header files
uninstall:
	rm -f $(LIB_DIR)/libctemplate.so
	rm -rf $(INCLUDE_DIR)/ctemplate
	ldconfig
