/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "miniL.y" /* yacc.c:339  */

    #define YY_NO_UNPUT
    #include <stdio.h>
    #include <stdlib.h>
    #include <map>
    #include <string.h>
    #include <set>

    int tempCount = 0;
    int labelCount = 0;

    extern char* yytext;
    extern int currLine;
    extern int currPos; 

    std::map<std::string, std::string> varTemp;
    std::map<std::string, int> arrSize;
    bool mainFunc = false;
    std::set<std::string> funcs;
    std::set<std::string> reserved = {
        "FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", 
        "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "FOR", "DO", 
        "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "TRUE", "FALSE", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN", 
        "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN", "RETURN", "EQ", "NEQ", "IDENT", "NUMBER", "ASSIGN", "OR", "AND", "NOT",
        "LT", "LTE", "GT", "GTE", "ADD", "SUB", "MULT", "DIV", "MOD", "prog_start", "function", "declarations",
        "declaration", "identifiers", "ident", "statements", "statement", "bool_exp", "relation_and_expr", "relation_expr", "comp",
        "expressions", "expression", "multiplicative_expr", "term", "vars", "var", "func_ident"
    };

    void yyerror(const char *msg);
    int yylex();
    std::string new_temp();
    std::string new_label();

#line 101 "miniL-parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "miniL-parser.hpp".  */
#ifndef YY_YY_MINIL_PARSER_HPP_INCLUDED
# define YY_YY_MINIL_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    IDENT = 259,
    FUNCTION = 260,
    BEGIN_PARAMS = 261,
    END_PARAMS = 262,
    BEGIN_LOCALS = 263,
    END_LOCALS = 264,
    BEGIN_BODY = 265,
    END_BODY = 266,
    INTEGER = 267,
    ARRAY = 268,
    OF = 269,
    IF = 270,
    THEN = 271,
    ENDIF = 272,
    ELSE = 273,
    WHILE = 274,
    DO = 275,
    BEGINLOOP = 276,
    ENDLOOP = 277,
    CONTINUE = 278,
    READ = 279,
    WRITE = 280,
    TRUE = 281,
    FALSE = 282,
    SEMICOLON = 283,
    COLON = 284,
    COMMA = 285,
    L_PAREN = 286,
    R_PAREN = 287,
    L_SQUARE_BRACKET = 288,
    R_SQUARE_BRACKET = 289,
    ASSIGN = 290,
    RETURN = 291,
    FOR = 292,
    ENUM = 293,
    OR = 294,
    AND = 295,
    NOT = 296,
    LT = 297,
    LTE = 298,
    GT = 299,
    GTE = 300,
    EQ = 301,
    NEQ = 302,
    ADD = 303,
    SUB = 304,
    MULT = 305,
    DIV = 306,
    MOD = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 36 "miniL.y" /* yacc.c:355  */

    int     num_val;
    char*   id_val;
    struct S {
        char * code;
    } statement;
    struct E {
        char * place;
        char * code;
        bool arr;  
    } expression;

#line 207 "miniL-parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINIL_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "miniL-parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    80,    85,   117,   131,   135,   144,   192,
     248,   260,   270,   276,   279,   287,   305,   317,   330,   360,
     382,   394,   405,   408,   418,   423,   439,   444,   461,   472,
     479,   489,   496,   503,   509,   514,   519,   523,   527,   532,
     538,   548,   561,   566,   581,   598,   602,   619,   635,   653,
     681,   710,   720,   731,   736,   747,   751,   769,   783,   801,
     821
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENT", "FUNCTION",
  "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY",
  "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE",
  "TRUE", "FALSE", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN", "RETURN", "FOR",
  "ENUM", "OR", "AND", "NOT", "LT", "LTE", "GT", "GTE", "EQ", "NEQ", "ADD",
  "SUB", "MULT", "DIV", "MOD", "$accept", "prog_start", "function",
  "func_ident", "declarations", "declaration", "identifiers", "ident",
  "statements", "statement", "bool_exp", "relation_and_expr",
  "relation_expr_inv", "relation_expr", "comp", "expressions",
  "expression", "multiplicative_expr", "term", "vars", "var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      19,    26,    32,    19,   -47,     7,   -47,   -47,    41,    59,
     -47,    45,    42,    40,    43,    69,    59,     2,    59,    59,
     -47,   -47,    47,   -47,    75,    82,    79,    44,    77,    76,
      68,    68,    70,   -47,    59,    59,    30,    65,    92,    80,
      71,    81,    93,   -47,   -47,   -47,    68,    68,    25,   -25,
      91,    94,    74,   -47,    84,     6,   -29,   -47,    95,    77,
     -47,   -47,    30,   -47,    30,   -47,    77,    30,    59,   -47,
      83,    78,   -47,   -47,    30,   -47,     9,    77,    68,    68,
     -47,   -47,   -47,   -47,   -47,   -47,    30,    30,    30,    30,
      30,    30,    77,    96,   100,   101,   -47,   -47,   -47,   -47,
     -47,   102,   -47,   104,   107,    48,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   116,   120,   -47,   -47,   -47,    30,
     -47,    77,   -47,    68,   -47,   123,   -47,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     2,     5,     0,     1,     3,     0,     6,
      12,     0,     0,     0,    10,     0,     6,     0,     0,     6,
       7,     8,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,    59,     0,     0,
       0,    57,     0,    51,    31,    32,     0,     0,     0,    59,
       0,    24,    26,    29,     0,    42,    45,    49,     0,     0,
      20,    21,     0,    23,     0,     4,    13,     0,     0,     9,
       0,     0,    28,    52,     0,    50,     0,     0,     0,     0,
      36,    38,    37,    39,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,    58,    33,
      53,     0,    55,     0,    40,     0,    25,    27,    30,    43,
      44,    46,    47,    48,     0,     0,    60,    54,    56,     0,
      16,     0,    18,     0,    41,     0,    19,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   138,   -47,   -47,   -14,   -47,   124,    -9,   -39,   -47,
     -30,    64,    97,   -47,   -47,    27,     0,   -46,   -47,   -31,
     -17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     5,    11,    12,    13,    49,    38,    39,
      50,    51,    52,    53,    86,   103,    54,    55,    56,    40,
      57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      14,    58,    20,    60,    61,    24,    76,    14,    64,    14,
      14,    41,    43,    10,    21,    22,    70,    41,    41,    37,
      93,    89,    90,    91,     1,    37,    37,    96,    73,    10,
       4,    75,     6,    43,    10,     8,    63,    98,   105,    37,
      62,   102,    41,   111,   112,   113,    71,     9,   106,    41,
      37,    41,    15,   114,    87,    88,    74,    37,    48,    37,
      41,    62,    94,    10,    95,   120,   121,    97,    37,    17,
      16,    43,    10,    18,   101,    41,   104,    19,    29,    48,
      25,    10,   125,    37,    26,    27,   108,   109,   110,    28,
      42,    59,    30,   126,    44,    45,    31,    32,    64,    46,
      33,    34,    35,    65,    41,    69,    67,    77,    66,    47,
     100,    68,    37,    36,    79,    99,    92,    48,   115,   104,
      80,    81,    82,    83,    84,    85,    80,    81,    82,    83,
      84,    85,   100,    78,   117,   116,   118,   119,   122,   123,
     127,     7,    23,   107,    72,     0,   124
};

static const yytype_int8 yycheck[] =
{
       9,    31,    16,    34,    35,    19,    31,    16,    33,    18,
      19,    28,     3,     4,    12,    13,    46,    34,    35,    28,
      59,    50,    51,    52,     5,    34,    35,    66,     3,     4,
       4,    48,     0,     3,     4,    28,    36,    68,    77,    48,
      31,    32,    59,    89,    90,    91,    46,     6,    78,    66,
      59,    68,     7,    92,    48,    49,    31,    66,    49,    68,
      77,    31,    62,     4,    64,    17,    18,    67,    77,    29,
      28,     3,     4,    30,    74,    92,    76,     8,    34,    49,
      33,     4,   121,    92,     9,     3,    86,    87,    88,    10,
      14,    21,    15,   123,    26,    27,    19,    20,    33,    31,
      23,    24,    25,    11,   121,    12,    35,    16,    28,    41,
      32,    30,   121,    36,    40,    32,    21,    49,    22,   119,
      42,    43,    44,    45,    46,    47,    42,    43,    44,    45,
      46,    47,    32,    39,    32,    34,    32,    30,    22,    19,
      17,     3,    18,    79,    47,    -1,   119
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    54,    55,     4,    56,     0,    54,    28,     6,
       4,    57,    58,    59,    60,     7,    28,    29,    30,     8,
      57,    12,    13,    59,    57,    33,     9,     3,    10,    34,
      15,    19,    20,    23,    24,    25,    36,    60,    61,    62,
      72,    73,    14,     3,    26,    27,    31,    41,    49,    60,
      63,    64,    65,    66,    69,    70,    71,    73,    63,    21,
      72,    72,    31,    69,    33,    11,    28,    35,    30,    12,
      63,    69,    65,     3,    31,    73,    31,    16,    39,    40,
      42,    43,    44,    45,    46,    47,    67,    48,    49,    50,
      51,    52,    21,    61,    69,    69,    61,    69,    72,    32,
      32,    69,    32,    68,    69,    61,    63,    64,    69,    69,
      69,    70,    70,    70,    61,    22,    34,    32,    32,    30,
      17,    18,    22,    19,    68,    61,    63,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    56,    57,    57,    58,    58,
      59,    59,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,    12,     1,     0,     3,     3,     8,
       1,     3,     1,     2,     3,     3,     5,     7,     5,     6,
       2,     2,     1,     2,     1,     3,     1,     3,     2,     1,
       3,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     1,     2,     3,     4,     3,     4,     1,     3,     1,
       4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 74 "miniL.y" /* yacc.c:1646  */
    {
                if (!mainFunc) {
                    printf("Error: No main function declared!\n");
                }

        }
#line 1400 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 80 "miniL.y" /* yacc.c:1646  */
    {

        }
#line 1408 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "miniL.y" /* yacc.c:1646  */
    {
        std::string temp = "func ";
        temp.append((yyvsp[-10].expression).place);
        temp.append("\n");
        std::string s = (yyvsp[-10].expression).place;
        if (s == "main") {
            mainFunc = true;
        }
        temp.append((yyvsp[-7].expression).code);
        std::string decs = (yyvsp[-7].expression).code;
        int decNum = 0;
        while (decs.find(".") != std::string::npos) {
            int pos = decs.find(".");
            decs.replace(pos, 1, "=");
            std::string part = ", $" + std::to_string(decNum) + "\n";
            decNum++;
            decs.replace(decs.find("\n", pos), 1, part);
        }
        temp.append(decs);
        temp.append((yyvsp[-4].expression).code);
        std::string statements = (yyvsp[-1].statement).code;
        if (statements.find("continue") != std::string::npos) {
            printf("Error: continue outside loop in function %s\n", (yyvsp[-10].expression).place);
        }
        temp.append(statements);
        temp.append("endfunc\n\n");
        printf(temp.c_str());
    }
#line 1441 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 119 "miniL.y" /* yacc.c:1646  */
    {
            if (funcs.find((yyvsp[0].id_val)) != funcs.end()) {
                printf("Error: Function %s already declared!\n", (yyvsp[0].id_val));
            } else {
                funcs.insert((yyvsp[0].id_val));
            }

            (yyval.expression).place = strdup((yyvsp[0].id_val));
            (yyval.expression).code = strdup("");
}
#line 1456 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 131 "miniL.y" /* yacc.c:1646  */
    {
                (yyval.expression).place = strdup("");
                (yyval.expression).code = strdup("");
            }
#line 1465 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 135 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp;
                temp.append((yyvsp[-2].expression).code);
                temp.append((yyvsp[0].expression).code);
                (yyval.expression).code = strdup(temp.c_str());
                (yyval.expression).place = strdup("");
            }
#line 1477 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 144 "miniL.y" /* yacc.c:1646  */
    {
        size_t left = 0;
        size_t right = 0;
        std::string parse((yyvsp[-2].expression).place);
        std::string temp;
        bool ex = false;
        while (!ex){
            right = parse.find("|", left);
            temp.append(".");
            if (right == std::string::npos){
                std::string ident = parse.substr(left, right);
                if (reserved.find(ident) != reserved.end()){
                    printf("Error: Identifier %s is a reserved word\n", ident.c_str());
                }
                if (funcs.find(ident) != funcs.end() && varTemp.find(ident) != varTemp.end()){
                    printf("Error 1: Identifier %s is already declared.\n", ident.c_str());
                }
                else
                 {
                    varTemp[ident] = ident;
                    arrSize[ident] = 1;
                }
                temp.append(ident);
                ex = true;
            }
            else
            {
                std::string ident = parse.substr(left, right - left);
                if (reserved.find(ident) != reserved.end())
                {
                    printf("Error: Identifier %s is a reserved word\n", ident.c_str());
                }
                if (funcs.find(ident) != funcs.end() && varTemp.find(ident) != varTemp.end()){
                    printf("Error: Identifier %s is already declared.\n", ident.c_str());
                }
                else {
                    varTemp[ident] = ident;
                    arrSize[ident] = 1;
                }
                temp.append(ident);
                left = right + 1;
            }
            temp.append("\n");
        }
        (yyval.expression).code = strdup(temp.c_str());
        (yyval.expression).place = strdup("");
    }
#line 1529 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 192 "miniL.y" /* yacc.c:1646  */
    {
        
        size_t left = 0;
        size_t right = 0;
        std::string parse((yyvsp[-7].expression).place);
        std::string temp;
        bool ex = false;
        while (!ex){
            right = parse.find("|", left);
            temp.append(".[]");
            if (right == std::string::npos){
                std::string ident = parse.substr(left, right);
                if (reserved.find(ident) != reserved.end()){
                    printf("Error: Identifier %s is a reserved word\n", ident.c_str());
                }
                if (funcs.find(ident) != funcs.end() || varTemp.find(ident) != varTemp.end()){
                    printf("Error: Identifier %s is already declared.\n", ident.c_str());
                }
                else {
                        if ((yyvsp[-3].num_val) < 1){
                             printf("Error: Declaring array %s size is < 1.\n", ident.c_str());
                    }

                    varTemp[ident] = ident;
                    arrSize[ident] = (yyvsp[-3].num_val);
                }
                temp.append(ident);
                ex = true;
            }
            else
            {
                std::string ident = parse.substr(left, right - left);
                if (reserved.find(ident) != reserved.end()){
                    printf("Error: Identifier %s is a reserved word\n", ident.c_str());
                }
                if (funcs.find(ident) != funcs.end() || varTemp.find(ident) != varTemp.end()){
                    printf("Error: Identifier %s is already declared.\n", ident.c_str());
                }
                else 
                {
                        if ((yyvsp[-3].num_val) < 1){
                             printf("Error: Declaring array %s size is < 1.\n", ident.c_str());
                    }
                    varTemp[ident] = ident;
                    arrSize[ident] = (yyvsp[-3].num_val);
                }
                temp.append(ident);
                left = right + 1;
            }
            temp += ", " + std::to_string((yyvsp[-3].num_val)); + "\n";
        }
        (yyval.expression).code = strdup(temp.c_str());
        (yyval.expression).place = strdup("");
    }
#line 1588 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 248 "miniL.y" /* yacc.c:1646  */
    {

                std::string ident = (yyvsp[0].expression).place;
                // if (funcs.find(ident) == funcs.end() && varTemp.find(ident) == varTemp.end()) {
                //         printf("Error 1: Identifier %s is not declared\n", ident.c_str());
                //     } else if (arrSize[ident] > 1) {
                //         printf("Error: Did not provide index for array Identifier %s.\n", ident.c_str());
                //     }
                (yyval.expression).code = strdup((yyvsp[0].expression).code);
                (yyval.expression).place = strdup((yyvsp[0].expression).place); 
                
            }
#line 1605 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 260 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp;
                temp.append((yyvsp[-2].expression).code);
                temp.append("|");
                temp.append((yyvsp[0].expression).code);
                (yyval.expression).code = strdup(temp.c_str());
                (yyval.expression).place = strdup("");
            }
#line 1618 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 270 "miniL.y" /* yacc.c:1646  */
    {   
                    (yyval.expression).place = strdup((yyvsp[0].id_val));
                    (yyval.expression).code = strdup("");      
            }
#line 1627 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 276 "miniL.y" /* yacc.c:1646  */
    {
                (yyval.statement).code = strdup((yyvsp[-1].statement).code);
            }
#line 1635 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 279 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp;
                temp.append((yyvsp[-2].statement).code);
                temp.append((yyvsp[0].statement).code);
                (yyval.statement).code = strdup(temp.c_str());
            }
#line 1646 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 287 "miniL.y" /* yacc.c:1646  */
    {

                std::string temp;
                temp.append((yyvsp[-2].expression).code);
                temp.append((yyvsp[0].expression).code);
                if((yyvsp[-2].expression).arr || (yyvsp[0].expression).arr){
                    temp += "[]= ";
                }
                else{
                    temp += "= ";
                }
                temp.append((yyvsp[-2].expression).place);
                temp.append(", ");
                temp.append((yyvsp[0].expression).place);
                temp += "\n";
                (yyval.statement).code = strdup(temp.c_str());
    
            }
#line 1669 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 305 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp;
                std::string dst1 = new_label();
                std::string dst2 = new_label();
                temp.append((yyvsp[-3].expression).code);
                temp = temp + "?:= " + dst1 + ", " + (yyvsp[-3].expression).place + "\n";
                temp = temp + ":= " + dst2 + "\n";
                temp = temp + ": " + dst1 + "\n";
                temp.append((yyvsp[-1].statement).code);
                temp = temp + ": " + dst2 + "\n";
                (yyval.statement).code = strdup(temp.c_str());
            }
#line 1686 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 317 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp;
                std::string dst1 = new_label();
                std::string dst2 = new_label();
                temp.append((yyvsp[-5].expression).code);
                temp = temp + "?:= " + dst1 + ", " + (yyvsp[-5].expression).place + "\n";
                temp.append((yyvsp[-1].statement).code);
                temp = temp + ":= " + dst2 + "\n";
                temp = temp + ": " + dst1 + "\n";
                temp.append((yyvsp[-3].statement).code);
                temp = temp + ": " + dst2 + "\n";
                (yyval.statement).code = strdup(temp.c_str());
            }
#line 1704 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 330 "miniL.y" /* yacc.c:1646  */
    {

                std::string dst1 = new_label();
                std::string dst2 = new_label();
                std::string dst3 = new_label();
                std::string temp1;
                std::string temp2;

                temp1.append((yyvsp[-1].statement).code);
                size_t pos;
                while ((temp1.find("continue")) != std::string::npos) {
                    pos = temp1.find("continue");
                    temp1.replace(pos, 8, ":= " + dst1);
                }

                
                temp2 += ": " + dst1 + "\n";
                temp2.append((yyvsp[-3].expression).code);
                temp2 += "?: " + dst2 + ", ";
                temp2.append((yyvsp[-3].expression).place);
                temp2.append("\n");
                temp2 += ":= " + dst3 + "\n";
                temp2 += ": " + dst2 + "\n";
                temp2.append(temp1);
                temp2 += ":= " + dst1 + "\n";
                temp2 += ": " + dst2 + "\n";
                (yyval.statement).code = strdup(temp2.c_str());
                
                
            }
#line 1739 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 360 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp1;
                std::string temp2;
                std::string dst1 = new_label();
                std::string dst2 = new_label();
                temp1.append((yyvsp[-3].statement).code);
                size_t pos;
                while ((temp1.find("continue")) != std::string::npos) {
                    pos = temp1.find("continue");
                    temp1.replace(pos, 8 , ":= " + dst2);
                }

                temp2.append(": ");
                temp2.append("\n");
                temp2.append(temp1);
                temp2 += ": " + dst2 + "\n";
                temp2.append((yyvsp[0].expression).code);
                temp2 += "?:= " + dst1 + ", ";
                temp2.append((yyvsp[0].expression).place);
                temp2.append("\n");
                (yyval.statement).code = strdup(temp1.c_str());
            }
#line 1766 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 382 "miniL.y" /* yacc.c:1646  */
    {

                std::string temp;
                temp.append((yyvsp[0].expression).code);
                size_t pos = temp.find("|", 0);
                while (pos != std::string::npos) {
                    temp.replace(pos, 1, "<");
                    pos = temp.find("|", pos);
                }

                (yyval.statement).code = strdup(temp.c_str());
            }
#line 1783 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 394 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp;
                temp.append((yyvsp[0].expression).code);
                size_t pos = temp.find("|", 0);
                while (pos != std::string::npos) {
                    temp.replace(pos, 1, ">");
                    pos = temp.find("|", pos);
                }

                (yyval.statement).code = strdup(temp.c_str());
            }
#line 1799 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 405 "miniL.y" /* yacc.c:1646  */
    {
                (yyval.statement).code = strdup("continue\n");
            }
#line 1807 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 408 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp; 
                temp.append((yyvsp[0].expression).code);
                temp.append("ret ");
                temp.append((yyvsp[0].expression).place);
                temp.append("\n");
                (yyval.statement).code = strdup(temp.c_str());
            }
#line 1820 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 418 "miniL.y" /* yacc.c:1646  */
    {

                (yyval.expression).code = strdup((yyvsp[0].expression).code);
                (yyval.expression).place = strdup((yyvsp[0].expression).place);
                }
#line 1830 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 423 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp; 
                std::string dst = new_temp();
                temp.append((yyvsp[-2].expression).code);
                temp.append((yyvsp[0].expression).code);
                temp += ". " + dst + "\n";
                temp += "|| " + dst + ", ";
                temp.append((yyvsp[-2].expression).place);
                temp.append(", ");
                temp.append((yyvsp[0].expression).place);
                temp.append("\n");
                (yyval.expression).code = strdup(temp.c_str());
                (yyval.expression).place = strdup(dst.c_str());    
            }
#line 1849 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 439 "miniL.y" /* yacc.c:1646  */
    {

                (yyval.expression).code = strdup((yyvsp[0].expression).code);
                (yyval.expression).place = strdup((yyvsp[0].expression).place);
            }
#line 1859 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 444 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp; 
                std::string dst = new_temp();
                temp.append((yyvsp[-2].expression).code);
                temp.append((yyvsp[0].expression).code);
                temp += ". " + dst + "\n";
                temp += "&& " + dst + ", ";
                temp.append((yyvsp[-2].expression).place);
                temp.append(", ");
                temp.append((yyvsp[0].expression).place);
                temp.append("\n");
                (yyval.expression).code = strdup(temp.c_str());
                (yyval.expression).place = strdup(dst.c_str());
            }
#line 1878 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 461 "miniL.y" /* yacc.c:1646  */
    {
                    std::string temp;
                    std::string dst = new_temp();
                    temp.append((yyvsp[0].expression).code);
                    temp += ". " + dst + "\n";
                    temp += "! " + dst + ", ";
                    temp.append((yyvsp[0].expression).place);
                    temp.append("\n");
                    (yyval.expression).code = strdup(temp.c_str());
                    (yyval.expression).place = strdup(dst.c_str());
                }
#line 1894 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 472 "miniL.y" /* yacc.c:1646  */
    {
                    (yyval.expression).code = strdup((yyvsp[0].expression).code);
                    (yyval.expression).place = strdup((yyvsp[0].expression).place);
                }
#line 1903 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 479 "miniL.y" /* yacc.c:1646  */
    {
                std::string dst = new_temp();
                std::string temp;
                temp.append((yyvsp[-2].expression).code);
                temp.append((yyvsp[0].expression).code);
                temp = temp + ". " + dst + "\n" + (yyvsp[-1].expression).place + dst + ", " + (yyvsp[-2].expression).place + ", " + (yyvsp[0].expression).place + "\n";
                (yyval.expression).code = strdup(temp.c_str());
                (yyval.expression).place = strdup(dst.c_str());
                
            }
#line 1918 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 489 "miniL.y" /* yacc.c:1646  */
    {
   
                std::string temp;
                temp.append("1");
                (yyval.expression).code = strdup("");
                (yyval.expression).place = strdup(temp.c_str());
            }
#line 1930 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 496 "miniL.y" /* yacc.c:1646  */
    {

                std::string temp;
                temp.append("0");
                (yyval.expression).code = strdup("");
                (yyval.expression).place = strdup(temp.c_str());
            }
#line 1942 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 503 "miniL.y" /* yacc.c:1646  */
    {
                (yyval.expression).code = strdup((yyvsp[-1].expression).code);
                (yyval.expression).place = strdup((yyvsp[-1].expression).place);
            }
#line 1951 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 509 "miniL.y" /* yacc.c:1646  */
    {

            (yyval.expression).code = strdup("");
            (yyval.expression).place = strdup("== ");
            }
#line 1961 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 514 "miniL.y" /* yacc.c:1646  */
    {
            
            (yyval.expression).code = strdup("");
            (yyval.expression).place = strdup("!= ");
            }
#line 1971 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 519 "miniL.y" /* yacc.c:1646  */
    {            
            (yyval.expression).code = strdup("");
            (yyval.expression).place = strdup("< ");
            }
#line 1980 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 523 "miniL.y" /* yacc.c:1646  */
    {           
            (yyval.expression).code = strdup("");
            (yyval.expression).place = strdup("> ");
            }
#line 1989 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 527 "miniL.y" /* yacc.c:1646  */
    {

            (yyval.expression).code = strdup("");
            (yyval.expression).place = strdup("<= ");
            }
#line 1999 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 532 "miniL.y" /* yacc.c:1646  */
    {
            (yyval.expression).code = strdup("");
            (yyval.expression).place = strdup(">= ");
            }
#line 2008 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 538 "miniL.y" /* yacc.c:1646  */
    {

        std::string temp;
        temp.append((yyvsp[0].expression).code);
        temp.append("param ");
        temp.append((yyvsp[0].expression).place);
        temp.append("\n");
        (yyval.expression).code = strdup(temp.c_str());
        (yyval.expression).place = strdup("");
        }
#line 2023 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 548 "miniL.y" /* yacc.c:1646  */
    {

        std::string temp;
        temp.append((yyvsp[-2].expression).code);
        temp.append("param ");
        temp.append((yyvsp[-2].expression).place);
        temp.append("\n");
        temp.append((yyvsp[0].expression).code);
        (yyval.expression).code = strdup(temp.c_str());
        (yyval.expression).place = strdup("");
        }
#line 2039 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 561 "miniL.y" /* yacc.c:1646  */
    { 
                (yyval.expression).code = strdup((yyvsp[0].expression).code);
                (yyval.expression).place = strdup((yyvsp[0].expression).place);
            }
#line 2048 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 566 "miniL.y" /* yacc.c:1646  */
    { 

                std::string temp;
                std::string dst = new_temp();
                temp.append((yyvsp[-2].expression).code);
                temp.append((yyvsp[0].expression).code);
                temp += ". " + dst + "\n";
                temp += "+ " + dst + ", ";
                temp.append((yyvsp[-2].expression).place);
                temp += ", ";
                temp.append((yyvsp[0].expression).place);
                temp += "\n";
                (yyval.expression).code = strdup(temp.c_str());
                (yyval.expression).place = strdup(dst.c_str());
            }
#line 2068 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 581 "miniL.y" /* yacc.c:1646  */
    { 
                std::string temp;
                std::string dst = new_temp();
                temp.append((yyvsp[-2].expression).code);
                temp.append((yyvsp[0].expression).code);
                temp += ". " + dst + "\n";
                temp += "- " + dst + ", ";
                temp.append((yyvsp[-2].expression).place);
                temp += ", ";
                temp.append((yyvsp[0].expression).place);
                temp += "\n";
                (yyval.expression).code = strdup(temp.c_str());
                (yyval.expression).place = strdup(dst.c_str());
            }
#line 2087 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 598 "miniL.y" /* yacc.c:1646  */
    {
                    (yyval.expression).code = strdup((yyvsp[0].expression).code);
                    (yyval.expression).place = strdup((yyvsp[0].expression).place);        
            }
#line 2096 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 603 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp;
                std::string dst = new_temp();
                temp.append((yyvsp[-2].expression).code);
                temp.append((yyvsp[0].expression).code);
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "* " + dst + ", ";
                temp.append((yyvsp[-2].expression).place);
                temp += ", ";
                temp.append((yyvsp[0].expression).place);
                temp += "\n";
                (yyval.expression).code = strdup(temp.c_str());
                (yyval.expression).place = strdup(dst.c_str());    
            }
#line 2117 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 619 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp;
                std::string dst = new_temp();
                temp.append((yyvsp[-2].expression).code);
                temp.append((yyvsp[0].expression).code);
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "/ " + dst + ", ";
                temp.append((yyvsp[-2].expression).place);
                temp += ", ";
                temp.append((yyvsp[0].expression).place);
                temp += "\n";
                (yyval.expression).code = strdup(temp.c_str());
                (yyval.expression).place = strdup(dst.c_str());
            }
#line 2138 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 635 "miniL.y" /* yacc.c:1646  */
    {
                std::string temp;
                std::string dst = new_temp();
                temp.append((yyvsp[-2].expression).code);
                temp.append((yyvsp[0].expression).code);
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "% " + dst + ", ";
                temp.append((yyvsp[-2].expression).place);
                temp += ", ";
                temp.append((yyvsp[0].expression).place);
                temp += "\n";
                (yyval.expression).code = strdup(temp.c_str());
                (yyval.expression).place = strdup(dst.c_str());
            }
#line 2159 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 653 "miniL.y" /* yacc.c:1646  */
    { 
            std::string dst = new_temp();
            std::string temp;
            if ((yyvsp[0].expression).arr) {
                temp.append((yyvsp[0].expression).code);
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "=[] " + dst + ", ";
                temp.append((yyvsp[0].expression).place);
                temp.append("\n");
            }
            else {
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp = temp + "= " + dst + ", ";
                temp.append((yyvsp[0].expression).place);
                temp.append("\n");
                temp.append((yyvsp[0].expression).code);
            }

            if (varTemp.find((yyvsp[0].expression).place) != varTemp.end()) {
                varTemp[(yyvsp[0].expression).place] = dst;
            }
            (yyval.expression).code = strdup(temp.c_str());
            (yyval.expression).place = strdup(dst.c_str());       
        }
#line 2192 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 681 "miniL.y" /* yacc.c:1646  */
    { 
            std::string dst = new_temp();
            std::string temp;
            if ((yyvsp[0].expression).arr) {
                temp.append((yyvsp[0].expression).code);
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "=[] " + dst + ", ";
                temp.append((yyvsp[0].expression).place);
                temp.append("\n");
            }
            else {
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "= " + dst + ", ";
                temp.append((yyvsp[0].expression).place);
                temp.append("\n");
                temp.append((yyvsp[0].expression).code);
            }

            if (varTemp.find((yyvsp[0].expression).place) != varTemp.end()) {
                varTemp[(yyvsp[0].expression).place] = dst;
            }
            
            (yyval.expression).code = strdup(temp.c_str());
            (yyval.expression).place = strdup(dst.c_str());
        }
#line 2226 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 710 "miniL.y" /* yacc.c:1646  */
    { 
            std::string dst = new_temp();
            std::string temp;
            temp.append(". ");
            temp.append(dst);
            temp.append("\n");
            temp = temp + "= " + dst + ", " + std::to_string((yyvsp[0].num_val)) + "\n";
            (yyval.expression).code = strdup(temp.c_str());
            (yyval.expression).place = strdup(dst.c_str());
        }
#line 2241 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 720 "miniL.y" /* yacc.c:1646  */
    { 

            std::string dst = new_temp();
            std::string temp;
            temp.append(". ");
            temp.append(dst);
            temp.append("\n");
            temp = temp + "= " + dst + ", -" + std::to_string((yyvsp[0].num_val)) + "\n";
            (yyval.expression).code = strdup(temp.c_str());
            (yyval.expression).place = strdup(dst.c_str());
         }
#line 2257 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 731 "miniL.y" /* yacc.c:1646  */
    { 
            (yyval.expression).code = strdup((yyvsp[-1].expression).code);
            (yyval.expression).place = strdup((yyvsp[-1].expression).place);

        }
#line 2267 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 736 "miniL.y" /* yacc.c:1646  */
    { 
            std::string temp;
            temp.append((yyvsp[-1].expression).code);
            temp.append("* ");
            temp.append((yyvsp[-1].expression).place);
            temp.append(", ");
            temp.append((yyvsp[-1].expression).place);
            temp.append(", -1\n");
            (yyval.expression).code = strdup(temp.c_str());
            (yyval.expression).place = strdup((yyvsp[-1].expression).place);
         }
#line 2283 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 747 "miniL.y" /* yacc.c:1646  */
    { 
             (yyval.expression).place = strdup("");
             (yyval.expression).code = strdup("");   
            }
#line 2292 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 751 "miniL.y" /* yacc.c:1646  */
    {
            std::string func = (yyvsp[-3].expression).place;
            std::string temp;
            if (funcs.find(func) == funcs.end()) {
                
                printf("Calling undeclared function %s.\n", func.c_str());
            }
            std::string dst = new_temp();
            temp.append((yyvsp[-1].expression).code);
            temp += ". " + dst + "\ncall ";
            temp.append((yyvsp[-3].expression).place);
            temp += ", " + dst + "\n";
            (yyval.expression).code = strdup(temp.c_str());
            (yyval.expression).place = strdup(dst.c_str());

         }
#line 2313 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 769 "miniL.y" /* yacc.c:1646  */
    {
            std::string temp;
            temp.append((yyvsp[0].expression).code);
            if((yyvsp[0].expression).arr){
                temp.append(".[]| ");
            }
            else{
                temp.append(".| ");
            }
            temp.append((yyvsp[0].expression).place);
            temp.append("\n");
            (yyval.expression).code = strdup(temp.c_str());
            (yyval.expression).place = strdup("");
        }
#line 2332 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 784 "miniL.y" /* yacc.c:1646  */
    {
            std::string temp;
            temp.append((yyvsp[-2].expression).code);
            if((yyvsp[-2].expression).arr){
                temp.append(".[]| ");
            }
            else{
                temp.append(".| ");
            }
            temp.append((yyvsp[-2].expression).place);
            temp.append("\n");
            temp.append((yyvsp[0].expression).code);
            (yyval.expression).code = strdup(temp.c_str());
            (yyval.expression).place = strdup("");
        }
#line 2352 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 801 "miniL.y" /* yacc.c:1646  */
    {

                    std::string temp;
                    std::string ident = (yyvsp[0].expression).place;

                    // builds bottom was always coming undeclared variable error
                    if (funcs.find((yyvsp[0].expression).place) == funcs.end()) {
                        funcs.insert((yyvsp[0].expression).place);
                    }


                    if (funcs.find(ident) == funcs.end() && varTemp.find(ident) == varTemp.end()) {
                        printf("Error: Identifier %s is not declared\n", ident.c_str());
                    } else if (arrSize[ident] > 1) {
                        printf("Error: Did not provide index for array Identifier %s.\n", ident.c_str());
                    }
                    (yyval.expression).code = strdup("");
                    (yyval.expression).place = strdup(ident.c_str());
                    (yyval.expression).arr = false;
                }
#line 2377 "miniL-parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 821 "miniL.y" /* yacc.c:1646  */
    {
                    
                    std::string temp;
                    std::string ident = (yyvsp[-3].expression).place;
                    if (funcs.find(ident) == funcs.end() && varTemp.find(ident) == varTemp.end()) {
                        printf("Error: Identifier %s is not declared\n", ident.c_str());
                    } else if (arrSize[ident] == 1) {
                        printf("Error: Provided index for non-array Identifier %s.\n", ident.c_str());
                    }
                    temp.append((yyvsp[-3].expression).place);
                    temp.append(",");
                    temp.append((yyvsp[-1].expression).place);
                    (yyval.expression).code = strdup((yyvsp[-1].expression).code);
                    (yyval.expression).place = strdup(temp.c_str());
                    (yyval.expression).arr = true;
                }
#line 2398 "miniL-parser.cpp" /* yacc.c:1646  */
    break;


#line 2402 "miniL-parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 839 "miniL.y" /* yacc.c:1906  */


/* int main(int argc, char ** argv){
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(yyin == NULL){
            printf("syntax: %s filename", argv[0]);
        }
    }
    yyparse();
    return 0; 
} */

void yyerror(const char *msg){
    extern int yylineno;
    extern char *yytext;
    printf("Error: Line %d, position %d: %s \n", yylineno, currPos, yytext);
    exit(1);
}

std::string new_temp() {
    std::string t = "t" + std::to_string(tempCount);
    tempCount++;
    return t;
}

std::string new_label() {
    std::string l = "L" + std::to_string(labelCount);
    labelCount++;
    return l;
}
