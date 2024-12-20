.PHONY: all clean deb repo

SUBDIRS = libmysyslog libmysyslog-text libmysyslog-json mysyslog-client mysyslog-daemon mysyslog-meta

REPO_DIR = repo
PACKAGES_DIR = $(REPO_DIR)/packages

all:
	@echo "Сборка всех подпроектов..."
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir all || exit 1; \
	done

clean:
	@echo "Очистка всех подпроектов..."
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean || exit 1; \
	done
	rm -rf $(REPO_DIR)

deb:
	@echo "Создание deb-пакетов для всех подпроектов..."
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir deb || exit 1; \
	done

repo: deb
	@echo "Формирование репозитория..."
	mkdir -p $(PACKAGES_DIR)
	for dir in $(SUBDIRS); do \
		cp $$dir/*.deb $(PACKAGES_DIR) || exit 1; \
	done
	cd $(PACKAGES_DIR) && dpkg-scanpackages . /dev/null | gzip -9c > Packages.gz
	@echo "Репозиторий сформирован в $(REPO_DIR)"
