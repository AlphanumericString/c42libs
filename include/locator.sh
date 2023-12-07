grep "^[a-Z]" $(find -depth -print -name "*.c" ) | sed "s/$/;/" | sed "s/\(\.\/\)\([a-Z1-9 _]*.c:\)\(.*\)/\/\/ file::	.\/src\/\2
\3/" | sed "s/\([a-Z _]*\)\([a-Z*]*\)\(.*\)/\1	\2\3/"
