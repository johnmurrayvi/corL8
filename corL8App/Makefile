CC = gcc
CXX = g++

DEF_CFLAGS ?= -g -Wall

GTK_CFLAGS ?= $(shell pkg-config --cflags gtk+-3.0)
GTK_LDFLAGS ?= $(shell pkg-config --libs gtk+-3.0)
GDK_CFLAGS ?= $(shell pkg-config --cflags gdk-3.0)
GDK_LDFLAGS ?= $(shell pkg-config --libs gdk-3.0)

CFLAGS = $(GTK_CFLAGS) $(GDK_CFLAGS) $(DEF_CFLAGS)
LDFLAGS = $(GTK_LDFLAGS) $(GDK_LDFLAGS)

GLIB_COMPILE_RESOURCES = glib-compile-resources
GLIB_COMPILE_SCHEMAS = glib-compile-schemas

SOURCES = corL8App.c corL8AppPrefs.c corL8AppWindow.c
GSCHEMAS = com.johnmurrayvi.corl8app.gschema.xml
GRESOURCES = corl8app.gresource.xml
EXECUTABLE = corL8App

all: $(EXECUTABLE) gschemas.compiled

clean:
	rm -f core $(EXECUTABLE) *.o resources.c gschemas.compiled


corL8AppPrefs.o: corL8AppPrefs.c corL8AppPrefs.h
	$(CC) $(CFLAGS) -c $< -o $@

corL8AppWindow.o: corL8AppWindow.c corL8AppWindow.h
	$(CC) $(CFLAGS) -c $< -o $@

corL8App.o: corL8App.c corL8App.h
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@


resources.o: resources.c
	$(CC) $(CFLAGS) -c $< -o $@

resources.c: $(GRESOURCES) $(shell $(GLIB_COMPILE_RESOURCES) --generate-dependencies $(GRESOURCES))
	$(GLIB_COMPILE_RESOURCES) $< --target=$@ --generate-source


%.gschema.valid: $(GSCHEMAS)
	$(GLIB_COMPILE_SCHEMAS) --strict --dry-run --schema-file=$< && touch $(GSCHEMAS:.xml=.valid)

gschemas.compiled: $(GSCHEMAS:.xml=.valid) $(GSCHEMAS)
	$(GLIB_COMPILE_SCHEMAS) . && rm $<

$(EXECUTABLE): main.o $(SOURCES:.c=.o) resources.o
	$(CC) -o $@ $^ $(LDFLAGS)
