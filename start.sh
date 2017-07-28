gcc -fpic -shared \
-pedantic -Wall \
-I/usr/local/include \
-llua -L/usr/local/lib \
-o mylib.so *.c
lua test.lua
