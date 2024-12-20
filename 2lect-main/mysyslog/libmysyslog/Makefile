CC = gcc
CFLAGS = -fPIC -Wall -Werror -I../include
LDFLAGS = -shared
AR = ar
ARFLAGS = rcs

LIB_SHARED = libmysyslog.so
LIB_STATIC = libmysyslog.a
SRC = src/mysyslog.c
OBJ = $(SRC:.c=.o)
DEB_DIR = libmysyslog_deb

all: $(LIB_SHARED) $(LIB_STATIC)

$(LIB_SHARED): $(OBJ)
	$(CC) -shared -o $@ $^

$(LIB_STATIC): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIB_SHARED) $(LIB_STATIC) $(OBJ)
	rm -f *.deb

deb: all
	mkdir -p $(DEB_DIR)/DEBIAN $(DEB_DIR)/usr/lib
	echo "Package: libmysyslog" > $(DEB_DIR)/DEBIAN/control
	echo "Version: 1.0" >> $(DEB_DIR)/DEBIAN/control
	echo "Section: libs" >> $(DEB_DIR)/DEBIAN/control
	echo "Priority: optional" >> $(DEB_DIR)/DEBIAN/control
	echo "Architecture: amd64" >> $(DEB_DIR)/DEBIAN/control
	echo "Maintainer: AACnotAliVe <mrlenorgenri@gmail.com>" >> $(DEB_DIR)/DEBIAN/control
	echo "Description: Logging library for mysyslog" >> $(DEB_DIR)/DEBIAN/control
	cp $(LIB_SHARED) $(DEB_DIR)/usr/lib/
	dpkg-deb --build $(DEB_DIR)
	rm -r $(DEB_DIR)


