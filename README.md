# BISONCALC

Simple calculator done for "Compiladores e Intérpretes" using flex & bison

## BUILD

Compile the program going to the src directory and using `build.sh`, which internally does:

```
bison -d syntax.y
flex lex.l
cmake CMakeLists.txt
make
```

## USAGE

```
./BisonCalc
./BisonCalc --help
./BisonCalc nameOfAFile
```
