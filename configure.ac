AC_INIT(posh, 0.0.0)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE
LT_INIT

AC_LANG(C++)
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_17([noext], [mandatory])

AC_ARG_ENABLE(
    [asan],
    [AC_HELP_STRING([--enable-asan], [Enable address sanitizer])],
    [enable_asan=$enableval]
)
if test "x$enable_asan" = "xyes"
then
    CFLAGS="${CFLAGS} -fsanitize=address -fno-omit-frame-pointer"
    CXXFLAGS="${CXXFLAGS} -fsanitize=address -fno-omit-frame-pointer"

fi

AC_ARG_ENABLE(
    [debug],
    [AC_HELP_STRING([--enable-debug], [Enable debug])],
    [enable_debug=$enableval],
    [enable_debug=$enable_asan]
)
if test "x$enable_debug" = "xyes"
then
    CFLAGS="${CFLAGS} -Og -g"
    CXXFLAGS="${CXXFLAGS} -Og -g"
fi

AC_ARG_ENABLE(
    [shared],
    [AC_HELP_STRING([--disable-shared], [Don't build shared libraries])],
    [enable_shared=$enableval],
    [enable_shared=yes]
)
if test "x$enable_shared" = "xyes"
then
    AC_ENABLE_SHARED
else
    AC_DISABLE_SHARED
fi

PKG_CHECK_MODULES(SQLITE3, sqlite3)

AC_OUTPUT(Makefile)
