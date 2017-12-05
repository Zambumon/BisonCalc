bison -d syntax.y
flex lex.l
cmake CMakeLists.txt
make
rm CMakeCache.txt
rm cmake_install.cmake
rm -rf CMakeFiles
