DEB_DIR = mysyslog-meta_deb

all: deb

deb:
	mkdir -p $(DEB_DIR)/DEBIAN
	echo "Package: mysyslog-meta" > $(DEB_DIR)/DEBIAN/control
	echo "Version: 1.0" >> $(DEB_DIR)/DEBIAN/control
	echo "Section: metapackage" >> $(DEB_DIR)/DEBIAN/control
	echo "Priority: optional" >> $(DEB_DIR)/DEBIAN/control
	echo "Architecture: all" >> $(DEB_DIR)/DEBIAN/control
	echo "Maintainer: 12345 <12345@gmail.com>" >> $(DEB_DIR)/DEBIAN/control
	echo "Depends: libmysyslog, libmysyslog-json, libmysyslog-text, mysyslog-client, mysyslog-daemon" >> $(DEB_DIR)/DEBIAN/control
	echo "Description: Metapackage to install all mysyslog components" >> $(DEB_DIR)/DEBIAN/control
	echo " This metapackage installs all components of the mysyslog system,	including libraries and applications." >> $(DEB_DIR)/DEBIAN/control
	dpkg-deb --build $(DEB_DIR)
	rm -r $(DEB_DIR)

clean:
	rm -f *.deb
