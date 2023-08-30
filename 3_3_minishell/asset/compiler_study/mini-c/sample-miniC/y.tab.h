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
     IDENTIFIER = 258,
     INTIGER = 259,
     INT_CONSTANT = 260,
     CHAR_CONSTANT = 261,
     STRING_CONSTANT = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LE_OP = 265,
     GE_OP = 266,
     EQ_OP = 267,
     NE_OP = 268,
     AND_OP = 269,
     OR_OP = 270,
     MUL_ASSIGN = 271,
     DIV_ASSIGN = 272,
     MOD_ASSIGN = 273,
     ADD_ASSIGN = 274,
     SUB_ASSIGN = 275,
     TYPE_NAME = 276,
     TYPEDEF = 277,
     CHAR = 278,
     INT = 279,
     VOID = 280,
     ELIPSIS = 281,
     IF = 282,
     ELSE = 283,
     WHILE = 284,
     DO = 285,
     FOR = 286,
     CONTINUE = 287,
     BREAK = 288,
     RETURN = 289
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTIGER 259
#define INT_CONSTANT 260
#define CHAR_CONSTANT 261
#define STRING_CONSTANT 262
#define INC_OP 263
#define DEC_OP 264
#define LE_OP 265
#define GE_OP 266
#define EQ_OP 267
#define NE_OP 268
#define AND_OP 269
#define OR_OP 270
#define MUL_ASSIGN 271
#define DIV_ASSIGN 272
#define MOD_ASSIGN 273
#define ADD_ASSIGN 274
#define SUB_ASSIGN 275
#define TYPE_NAME 276
#define TYPEDEF 277
#define CHAR 278
#define INT 279
#define VOID 280
#define ELIPSIS 281
#define IF 282
#define ELSE 283
#define WHILE 284
#define DO 285
#define FOR 286
#define CONTINUE 287
#define BREAK 288
#define RETURN 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

