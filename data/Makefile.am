imagedir = $(pkgdatadir)/images
image_DATA = images/hello-world.png \
             images/goodbye.png

EXTRA_DIST = $(image_DATA)

UI_FILES = ui/hello.ui
ICON_FILES = icons/hello.png

RESOURCES_HEADER = $(top_builddir)/src/resources.h
RESOURCES_SOURCE = $(top_builddir)/src/resources.c

BUILT_SOURCES = $(RESOURCES_HEADER) \
                $(RESOURCES_SOURCE)

$(RESOURCES_HEADER): resources-gresources.xml $(UI_FILES) $(ICON_FILES)
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES) $(srcdir)/resources-gresources.xml \
    --target=$@ --sourcedir=$(srcdir) --generate-header

$(RESOURCES_SOURCE): resources-gresources.xml $(UI_FILES) $(ICON_FILES)
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES) $(srcdir)/resources-gresources.xml \
    --target=$@ --sourcedir=$(srcdir) --generate-source

CLEANFILES = $(BUILD_RESOURCES)
