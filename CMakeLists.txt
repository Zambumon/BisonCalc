cmake_minimum_required(VERSION 3.9)
project(BisonCalc C)

set(CMAKE_C_STANDARD 99)

add_executable(BisonCalc
        utils.c
        utils.h
        tree.c
        tree.h
        symbolsTable.c
        symbolsTable.h
        lex.yy.c
        lex.yy.h
        syntax.tab.c
        syntax.tab.h
        definitions.h
        main.c
        )
