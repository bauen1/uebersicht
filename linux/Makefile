CFLAGS=`pkg-config --cflags gtk+-3.0 webkit2gtk-4.0`
LDFLAGS=`pkg-config --libs gtk+-3.0 webkit2gtk-4.0`

PREFIX?=/usr/local

.PHONY: all
all: uebersicht-linux

.PHONY: clean
clean:
	rm -rf *.o uebersicht-linux

uebersicht-linux: *.c
	gcc -o $@ $^ -Wall -Wextra $(LDFLAGS) $(CFLAGS)

.PHONY: install
install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp uebersicht-linux $(DESTDIR)$(PREFIX)/bin
