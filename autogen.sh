test -n "$srcdir" || srcdir=$(dirname "$0")
test -n "$srcdir" || srcdir=.

(autoconf --version < /dev/null > /dev/null 2>&1) || {
	echo "autoconf is required on the system."
	exit 1
}

(automake --version < /dev/null > /dev/null 2>&1) || {
	echo "automake is required on the system."
	exit 1 
}

(autoreconf --version < /dev/null > /dev/null 2>&1) || {
	echo "autoreconf is required on the system."
	exit 1
}

olddir=$(pwd)
echo "$olddir"

cd $srcdir

(test -f configure.ac) || {
	echo "Error: Directory $topdir does not look like the top-level project directory."
	exit 1
}

PKG_NAME=$(autoconf --trace 'AC_INIT:$1' configure.ac)

if [ "$#" = 0 -a "x$NONCONFIGURE" = "x" ]; then
	echo "Warning: I'm going to run 'configure' without arguments." >&2
	echo "If you wish to pass any to it, please specify them on the." >&2
	echo "$0 command line" >&2
	echo " " >&2
fi

(autoreconf --verbose --install --symlink --force) || exit 1

cd "$olddir"

if [ "$NONCONFIGURE" = "" ]; then
	echo "Running configure ..."
	$srcdir/configure $@ || exit 1
	if [ "$1" = "--help" -o "$1" = "--version" ]; then
		exit 0;
	else
		echo "Now type 'make' to compile $PKG_NAME" || exit 1
	fi
else
	echo "Skipping configure process."
fi
