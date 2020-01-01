AM_CFLAGS = -export-dynamic -I$(top_srcdir)/include
common_defines = -DHELLO_IMAGEDIR="\"$(pkgdatadir)/images\""

bin_PROGRAMS = hello
hello_SOURCES = main.c hello.c resources.c
hello_CFLAGS = $(GTK_CFLAGS) \
               $(AM_CFLAGS) \
               $(common_defines) \
               $(INCLUDES)

hello_LDFLAGS = $(GTK_LIBS)
