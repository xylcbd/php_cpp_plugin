PHP_ARG_ENABLE(allen, whether to enable say support,
[ --enable-allen Enable say support])

if test "$PHP_ALLEN" = "yes"; then
    CXXFLAGS="-std=c++0x -I./src -I/usr/local/include/"
    LDFLAGS="-L/path/to/link -lstdc++"
    PHP_REQUIRE_CXX()
    PHP_SUBST(VEHICLE_SHARED_LIBADD)
    PHP_ADD_LIBRARY(stdc++, 1, VEHICLE_SHARED_LIBADD)
    AC_DEFINE(HAVE_ALLEN, 1, [Whether you have say])
    PHP_NEW_EXTENSION(allen, php_allen.cpp src/allen.cpp, $ext_shared)
fi
