#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([hello], [1.0.0], [eudien@hotmail.com])
AC_CONFIG_SRCDIR([src/hello.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
#PKG_CHECK_MODULES([GTK], [gtk+-3.0 >= 3.16.0])
AC_PATH_TOOL(PKG_CONFIG, pkg-config)

AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

if $PKG_CONFIG --atleast-version=3.16.0 gtk+-3.0; then
	GTK_CFLAGS=$($PKG_CONFIG --cflags gtk+-3.0)
	GTK_LIBS=$($PKG_CONFIG --libs gtk+-3.0)
else
	AC_MSG_ERROR("gtk+-3.0 at least verion 3.16.0 is required.")
fi

AC_PATH_PROG(GLIB_COMPILE_RESOURCES, glib-compile-resources)
# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 data/Makefile])

AC_OUTPUT
