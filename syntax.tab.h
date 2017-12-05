/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     VARIABLE = 259,
     HELP = 260,
     CLEAR = 261,
     END = 262,
     PRINT = 263,
     PRINT_CONSTANTS = 264,
     PRINT_FUNCTIONS = 265,
     DROP_TABLE = 266,
     EVAL = 267,
     LEFT_PARENTHESIS = 268,
     RIGHT_PARENTHESIS = 269,
     EQUALS = 270,
     PLUS = 271,
     MINUS = 272,
     TIMES = 273,
     DIVISION = 274,
     NEGATIVE = 275,
     POWER = 276
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define VARIABLE 259
#define HELP 260
#define CLEAR 261
#define END 262
#define PRINT 263
#define PRINT_CONSTANTS 264
#define PRINT_FUNCTIONS 265
#define DROP_TABLE 266
#define EVAL 267
#define LEFT_PARENTHESIS 268
#define RIGHT_PARENTHESIS 269
#define EQUALS 270
#define PLUS 271
#define MINUS 272
#define TIMES 273
#define DIVISION 274
#define NEGATIVE 275
#define POWER 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "syntax.y"
{
float num;
char *id;
}
/* Line 1529 of yacc.c.  */
#line 96 "syntax.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

