AUTOMAKE_OPTIONS = foreign subdir-objects
ACLOCAL_AMFLAGS = -I m4

# posh has a single entry point for users.  This is made availiable both as a
# binary (suitable for bash scripts) and a library (suitable for C++ programs).
bin_PROGRAMS = posh
posh_SOURCES = posh.c++
posh_LDADD = libposh.la @SQLITE3_LIBS@
posh_CXXFLAGS = @SQLITE3_CFLAGS@

lib_LTLIBRARIES = libposh.la
libposh_la_SOURCES = \
    libposh/bitp/channel_database.c++ \
    libposh/bitp/connection_database.c++ \
    libposh/database/connection.c++ \
    libposh/tty/display.c++ \
    libposh/tty/launch.c++
libposh_la_CXXFLAGS = @SQLITE3_CFLAGS@
libposh_la_LIBS = @SQLITE3_LIBS@

nobase_include_HEADERS = \
    libposh/bitp/channel_database.h++ \
    libposh/bitp/channel.h++ \
    libposh/bitp/connection_database.h++ \
    libposh/bitp/connection.h++ \
    libposh/database/connection.h++ \
    libposh/tty/display.h++ \
    libposh/tty/launch.h++
