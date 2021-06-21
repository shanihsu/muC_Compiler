/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "compiler_hw3.y"

    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    #define codegen(...) \
        do { \
            for (int i = 0; i < INDENT; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    
    /* Other global variables */
    FILE *fout = NULL;
    bool HAS_ERROR = false;
    int INDENT = 0;
    
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol();
    static int insert_symbol(char *name, char *typename, int judge);
    static int lookup_symbol(char *name, int ty);
    static void dump_symbol(/* ... */);
    static char* lookup_type(char *name); 
    static int lookup_table(char *name);

    scope t[50];
    int scope_num = 0;
    int addr = 0;
    int once = -1;

#line 111 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    BOOL = 260,
    STRING = 261,
    ASSIGN = 262,
    ADD_ASSIGN = 263,
    SUB_ASSIGN = 264,
    MUL_ASSIGN = 265,
    QUO_ASSIGN = 266,
    REM_ASSIGN = 267,
    SEMICOLON = 268,
    LPAREN = 269,
    RPAREN = 270,
    LBRACK = 271,
    RBRACK = 272,
    LBRACE = 273,
    RBRACE = 274,
    OR = 275,
    AND = 276,
    EQL = 277,
    NEQ = 278,
    LEQ = 279,
    GEQ = 280,
    LSS = 281,
    GTR = 282,
    NOT = 283,
    IF = 284,
    ELSE = 285,
    FOR = 286,
    WHILE = 287,
    TRUE = 288,
    FALSE = 289,
    RETURN = 290,
    INT_LIT = 291,
    FLOAT_LIT = 292,
    STRING_LIT = 293,
    BOOL_LIT = 294,
    IDENT = 295,
    INC = 296,
    DEC = 297,
    ADD = 298,
    SUB = 299,
    MUL = 300,
    QUO = 301,
    REM = 302,
    PRINT = 303
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define BOOL 260
#define STRING 261
#define ASSIGN 262
#define ADD_ASSIGN 263
#define SUB_ASSIGN 264
#define MUL_ASSIGN 265
#define QUO_ASSIGN 266
#define REM_ASSIGN 267
#define SEMICOLON 268
#define LPAREN 269
#define RPAREN 270
#define LBRACK 271
#define RBRACK 272
#define LBRACE 273
#define RBRACE 274
#define OR 275
#define AND 276
#define EQL 277
#define NEQ 278
#define LEQ 279
#define GEQ 280
#define LSS 281
#define GTR 282
#define NOT 283
#define IF 284
#define ELSE 285
#define FOR 286
#define WHILE 287
#define TRUE 288
#define FALSE 289
#define RETURN 290
#define INT_LIT 291
#define FLOAT_LIT 292
#define STRING_LIT 293
#define BOOL_LIT 294
#define IDENT 295
#define INC 296
#define DEC 297
#define ADD 298
#define SUB 299
#define MUL 300
#define QUO 301
#define REM 302
#define PRINT 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "compiler_hw3.y"

    int i_val;
    float f_val;
    char *s_val;
    char *ident_val;
    char *type_val;
    /* ... */

#line 268 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    49,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    85,    86,    90,    94,    95,    96,    97,
     101,   106,   110,   114,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   133,   140,   155,   160,   175,   180,   195,
     200,   215,   219,   234,   238,   244,   245,   252,   253,   254,
     255,   256,   260,   264,   268,   269,   270,   271,   272,   273,
     277,   278,   282,   283,   284,   288,   289,   290,   294,   295,
     296,   300,   301,   302,   313,   320,   326,   335,   343,   348,
     356,   371,   375,   376,   377,   378,   379,   380,   384,   385,
     389,   393,   393,   401,   402,   403,   407,   416,   426,   430,
     434,   438,   442,   446,   447,   448
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "BOOL", "STRING",
  "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN",
  "REM_ASSIGN", "SEMICOLON", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "OR", "AND", "EQL", "NEQ", "LEQ", "GEQ", "LSS",
  "GTR", "NOT", "IF", "ELSE", "FOR", "WHILE", "TRUE", "FALSE", "RETURN",
  "INT_LIT", "FLOAT_LIT", "STRING_LIT", "BOOL_LIT", "IDENT", "INC", "DEC",
  "ADD", "SUB", "MUL", "QUO", "REM", "PRINT", "'\"'", "$accept", "Program",
  "StatementList", "Type", "TypeName", "Literal", "Statement", "PrintStmt",
  "Expression", "Expression1", "Expression2", "Expression3", "Expression4",
  "Expression5", "UnaryExpr", "binary_op", "or_op", "and_op", "cmp_op",
  "add_op", "mul_op", "unary_op", "PrimaryExpr", "Operand", "IndexExpr",
  "ConversionExpr", "DeclarationStmt", "AssignmentExpr", "AssignmentStmt",
  "assign_op", "IncDecExpr", "IncDecStmt", "Block", "$@1", "IfStmt",
  "Condition", "WhileStmt", "ForStmt", "ForClause", "InitStmt", "PostStmt",
  "SimpleExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    34
};
# endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -108,     3,    82,  -108,  -108,  -108,  -108,  -108,   101,  -108,
    -108,    30,    32,    40,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,    41,   127,   -25,  -108,  -108,  -108,  -108,     1,    14,
      49,    23,    48,  -108,  -108,   118,    64,  -108,  -108,  -108,
    -108,    68,  -108,    70,  -108,  -108,  -108,  -108,  -108,    69,
      12,  -108,   118,   118,   118,   118,    52,    15,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,   118,   118,
    -108,   118,  -108,  -108,  -108,  -108,  -108,  -108,   118,  -108,
    -108,   118,  -108,  -108,  -108,   118,  -108,   118,  -108,  -108,
     118,  -108,    20,  -108,   168,    74,   161,  -108,  -108,    83,
      89,  -108,    88,    21,  -108,   118,  -108,   118,    14,    92,
      49,    23,    48,  -108,    33,    92,  -108,   138,  -108,  -108,
    -108,  -108,  -108,    90,    90,   118,    90,    96,    17,    45,
    -108,   118,  -108,    86,  -108,   104,  -108,  -108,  -108,   111,
      11,   118,  -108,  -108,  -108,  -108,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     6,     7,     9,     8,     0,    81,
      57,     0,     0,     0,    10,    11,    12,    13,    63,    55,
      56,     0,     0,     0,     5,    62,     3,    21,     0,    25,
      27,    29,    31,    33,    34,     0,    35,    58,    59,    60,
      14,     0,    15,     0,    16,    17,    18,    19,    20,     0,
       0,     4,     0,     0,     0,     0,     0,     0,    72,    73,
      74,    75,    76,    77,    22,    42,    78,    79,     0,     0,
      43,     0,    44,    45,    46,    47,    48,    49,     0,    50,
      51,     0,    52,    53,    54,     0,    36,     0,    71,    80,
       0,    64,     0,    87,    58,     0,    94,    93,    95,     0,
       0,    91,     0,     0,    61,     0,    67,     0,    24,    70,
      26,    28,    30,    32,     0,    66,    82,     0,    37,    38,
      39,    40,    41,     0,     0,     0,     0,     0,     0,     0,
      65,     0,    86,    83,    89,     0,    88,    23,    68,     0,
       0,     0,    69,    85,    84,    90,    92
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -108,  -108,    76,   120,  -108,   112,  -108,  -108,    -8,    67,
      65,    71,    61,    58,   -34,  -108,    53,    54,    57,    59,
      66,  -108,  -108,   -47,  -108,  -108,  -108,   -51,  -108,  -108,
     -49,  -108,  -107,  -108,    19,   -48,  -108,  -108,  -108,  -108,
    -108,    38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,   117,    68,    71,    78,    81,
      85,    35,    36,    37,    38,    39,    40,    41,    42,    69,
      43,    44,    45,    51,    46,    95,    47,    48,    99,   100,
     145,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    86,    97,     3,    98,    94,   102,    94,    58,    59,
      60,    61,    62,    63,    64,    57,   133,   134,    93,   136,
      93,    65,   105,     4,     5,     6,     7,    91,   106,     9,
     138,   107,    65,   143,     8,    70,   127,    65,     9,   116,
      11,    65,    66,    67,    52,    96,    53,   103,    10,    11,
     130,    12,    13,    65,    54,    55,    14,    15,    16,    17,
      18,   109,   139,    19,    20,    65,    79,    80,    21,    22,
     132,    72,    73,    74,    75,    76,    77,   135,    94,   114,
      87,    88,   115,    89,    90,     4,     5,     6,     7,   123,
      97,    93,    98,    82,    83,    84,     8,   128,   124,   129,
       9,   104,   125,   126,     4,     5,     6,     7,     9,   137,
      10,    11,    65,    12,    13,     8,   140,   141,    14,    15,
      16,    17,    18,    50,   142,    19,    20,    92,    49,    10,
      21,    22,     8,    96,    56,   108,   110,    14,    15,    16,
      17,    18,   112,   113,    19,    20,    10,   118,   119,   111,
      22,   120,   131,   121,    14,    15,    16,    17,    18,   144,
     122,    19,    20,    14,    15,    16,    17,    22,    58,    59,
      60,    61,    62,    63,    14,    15,    16,    17,    18,   146,
       0,    65,     0,     0,     0,     0,     0,    22,    65,    70,
      72,    73,    74,    75,    76,    77,     0,     0,     0,     0,
       0,     0,    66,    67,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
       8,    35,    53,     0,    53,    52,    54,    54,     7,     8,
       9,    10,    11,    12,    13,    40,   123,   124,    52,   126,
      54,    20,     7,     3,     4,     5,     6,    15,    13,    18,
      13,    16,    20,   140,    14,    21,    15,    20,    18,    19,
      29,    20,    41,    42,    14,    53,    14,    55,    28,    29,
      17,    31,    32,    20,    14,    14,    36,    37,    38,    39,
      40,    69,    17,    43,    44,    20,    43,    44,    48,    49,
     117,    22,    23,    24,    25,    26,    27,   125,   125,    87,
      16,    13,    90,    13,    15,     3,     4,     5,     6,    15,
     141,   125,   141,    45,    46,    47,    14,   105,    15,   107,
      18,    49,    13,    15,     3,     4,     5,     6,    18,    13,
      28,    29,    20,    31,    32,    14,    30,    13,    36,    37,
      38,    39,    40,   131,    13,    43,    44,    51,     8,    28,
      48,    49,    14,   141,    22,    68,    71,    36,    37,    38,
      39,    40,    81,    85,    43,    44,    28,    94,    94,    78,
      49,    94,    14,    94,    36,    37,    38,    39,    40,   140,
      94,    43,    44,    36,    37,    38,    39,    49,     7,     8,
       9,    10,    11,    12,    36,    37,    38,    39,    40,   141,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    49,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,     3,     4,     5,     6,    14,    18,
      28,    29,    31,    32,    36,    37,    38,    39,    40,    43,
      44,    48,    49,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    71,    72,    73,    74,    75,
      76,    77,    78,    80,    81,    82,    84,    86,    87,    53,
      58,    83,    14,    14,    14,    14,    55,    40,     7,     8,
       9,    10,    11,    12,    13,    20,    41,    42,    66,    79,
      21,    67,    22,    23,    24,    25,    26,    27,    68,    43,
      44,    69,    45,    46,    47,    70,    64,    16,    13,    13,
      15,    15,    52,    64,    73,    85,    58,    77,    80,    88,
      89,    91,    85,    58,    49,     7,    13,    16,    59,    58,
      60,    61,    62,    63,    58,    58,    19,    65,    66,    67,
      68,    69,    70,    15,    15,    13,    15,    15,    58,    58,
      17,    14,    73,    82,    82,    85,    82,    13,    13,    17,
      30,    13,    13,    82,    84,    90,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    54,    54,    54,    54,
      55,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    64,    64,    65,    65,    65,
      65,    65,    66,    67,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    71,    71,    71,    72,    72,
      72,    73,    73,    73,    73,    74,    75,    76,    76,    76,
      77,    78,    79,    79,    79,    79,    79,    79,    80,    80,
      81,    83,    82,    84,    84,    84,    85,    85,    86,    87,
      88,    89,    90,    91,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     3,     4,     4,     3,     5,     6,
       3,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     0,     4,     5,     7,     7,     3,     1,     5,     5,
       5,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 81 "compiler_hw3.y"
                    {dump_symbol();}
#line 1571 "y.tab.c"
    break;

  case 5:
#line 90 "compiler_hw3.y"
               {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1577 "y.tab.c"
    break;

  case 10:
#line 101 "compiler_hw3.y"
              {
        (yyval.type_val)="int";
        fprintf(fout, "ldc %d\n", (yyvsp[0].i_val));
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
    }
#line 1587 "y.tab.c"
    break;

  case 11:
#line 106 "compiler_hw3.y"
                {
        (yyval.type_val)="float";
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
    }
#line 1596 "y.tab.c"
    break;

  case 12:
#line 110 "compiler_hw3.y"
                 {
        (yyval.type_val)="string";
        printf("STRING_LIT %s\n", (yyvsp[0].s_val));
    }
#line 1605 "y.tab.c"
    break;

  case 13:
#line 114 "compiler_hw3.y"
               {
        (yyval.type_val)="bool";
        printf("%s\n", (yyvsp[0].s_val));
    }
#line 1614 "y.tab.c"
    break;

  case 23:
#line 133 "compiler_hw3.y"
                                               {
        printf("%s %s\n", (yyvsp[-4].type_val), lookup_type((yyvsp[-2].type_val)));
        fprintf(fout, "%s %s\n", (yyvsp[-4].type_val), lookup_type((yyvsp[-2].type_val)));
    }
#line 1623 "y.tab.c"
    break;

  case 24:
#line 140 "compiler_hw3.y"
                                   {
        char *first = lookup_type((yyvsp[-2].type_val));
        char *third = lookup_type((yyvsp[0].type_val));
        char *rem = "REM", *f = "float", *a = "AND", *o = "OR", *b = "bool";
        if(strcmp((yyvsp[-1].type_val), rem) == 0 && (strcmp(first, f) == 0 || strcmp(third, f) == 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on float)\n", yylineno, (yyvsp[-1].type_val));
        }else if((strcmp((yyvsp[-1].type_val), a) == 0 || strcmp((yyvsp[-1].type_val), o) == 0) && (strcmp(first, b) != 0 || strcmp(third, b) != 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on int)\n", yylineno, (yyvsp[-1].type_val));
        }else if(strcmp(first, third) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, (yyvsp[-1].type_val), first, third);
        }else if(strcmp(first, third) == 0){
            (yyval.type_val)=first;
        }
        printf("%s\n", (yyvsp[-1].type_val));
    }
#line 1643 "y.tab.c"
    break;

  case 25:
#line 155 "compiler_hw3.y"
                 {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1649 "y.tab.c"
    break;

  case 26:
#line 160 "compiler_hw3.y"
                                     {
        char *first = lookup_type((yyvsp[-2].type_val));
        char *third = lookup_type((yyvsp[0].type_val));
        char *rem = "REM", *f = "float", *a = "AND", *o = "OR", *b = "bool";
        if(strcmp((yyvsp[-1].type_val), rem) == 0 && (strcmp(first, f) == 0 || strcmp(third, f) == 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on float)\n", yylineno, (yyvsp[-1].type_val));
        }else if((strcmp((yyvsp[-1].type_val), a) == 0 || strcmp((yyvsp[-1].type_val), o) == 0) && (strcmp(first, b) != 0 || strcmp(third, b) != 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on int)\n", yylineno, (yyvsp[-1].type_val));
        }else if(strcmp(first, third) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, (yyvsp[-1].type_val), first, third);
        }else if(strcmp(first, third) == 0){
            (yyval.type_val)=first;
        }
        printf("%s\n", (yyvsp[-1].type_val));
    }
#line 1669 "y.tab.c"
    break;

  case 27:
#line 175 "compiler_hw3.y"
                 {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1675 "y.tab.c"
    break;

  case 28:
#line 180 "compiler_hw3.y"
                                     {
        char *first = lookup_type((yyvsp[-2].type_val));
        char *third = lookup_type((yyvsp[0].type_val));
        char *rem = "REM", *f = "float", *a = "AND", *o = "OR", *b = "bool";
        if(strcmp((yyvsp[-1].type_val), rem) == 0 && (strcmp(first, f) == 0 || strcmp(third, f) == 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on float)\n", yylineno, (yyvsp[-1].type_val));
        }else if((strcmp((yyvsp[-1].type_val), a) == 0 || strcmp((yyvsp[-1].type_val), o) == 0) && (strcmp(first, b) != 0 || strcmp(third, b) != 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on int)\n", yylineno, (yyvsp[-1].type_val));
        }else if(strcmp(first, third) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, (yyvsp[-1].type_val), first, third);
        }else if(strcmp(first, third) == 0){
            (yyval.type_val)="bool";
        }
        printf("%s\n", (yyvsp[-1].type_val));
    }
#line 1695 "y.tab.c"
    break;

  case 29:
#line 195 "compiler_hw3.y"
                 {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1701 "y.tab.c"
    break;

  case 30:
#line 200 "compiler_hw3.y"
                                     {
        char *first = lookup_type((yyvsp[-2].type_val));
        char *third = lookup_type((yyvsp[0].type_val));
        char *rem = "REM", *f = "float", *a = "AND", *o = "OR", *b = "bool";
        if(strcmp((yyvsp[-1].type_val), rem) == 0 && (strcmp(first, f) == 0 || strcmp(third, f) == 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on float)\n", yylineno, (yyvsp[-1].type_val));
        }else if((strcmp((yyvsp[-1].type_val), a) == 0 || strcmp((yyvsp[-1].type_val), o) == 0) && (strcmp(first, b) != 0 || strcmp(third, b) != 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on int)\n", yylineno, (yyvsp[-1].type_val));
        }else if(strcmp(first, third) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, (yyvsp[-1].type_val), first, third);
        }else if(strcmp(first, third) == 0){
            (yyval.type_val)=first;
        }
        printf("%s\n", (yyvsp[-1].type_val));
    }
#line 1721 "y.tab.c"
    break;

  case 31:
#line 215 "compiler_hw3.y"
                 {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1727 "y.tab.c"
    break;

  case 32:
#line 219 "compiler_hw3.y"
                                     {
        char *first = lookup_type((yyvsp[-2].type_val));
        char *third = lookup_type((yyvsp[0].type_val));
        char *rem = "REM", *f = "float", *a = "AND", *o = "OR", *b = "bool";
        if(strcmp((yyvsp[-1].type_val), rem) == 0 && (strcmp(first, f) == 0 || strcmp(third, f) == 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on float)\n", yylineno, (yyvsp[-1].type_val));
        }else if((strcmp((yyvsp[-1].type_val), a) == 0 || strcmp((yyvsp[-1].type_val), o) == 0) && (strcmp(first, b) != 0 || strcmp(third, b) != 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on int)\n", yylineno, (yyvsp[-1].type_val));
        }else if(strcmp(first, third) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, (yyvsp[-1].type_val), first, third);
        }else if(strcmp(first, third) == 0){
            (yyval.type_val)=first;
        }
        printf("%s\n", (yyvsp[-1].type_val));
    }
#line 1747 "y.tab.c"
    break;

  case 33:
#line 234 "compiler_hw3.y"
                 {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1753 "y.tab.c"
    break;

  case 34:
#line 238 "compiler_hw3.y"
                {
        (yyval.type_val)=(yyvsp[0].type_val);
    }
#line 1761 "y.tab.c"
    break;

  case 35:
#line 244 "compiler_hw3.y"
                  {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1767 "y.tab.c"
    break;

  case 36:
#line 245 "compiler_hw3.y"
                         {
        (yyval.type_val)=(yyvsp[0].type_val);
        printf("%s\n", (yyvsp[-1].type_val));
    }
#line 1776 "y.tab.c"
    break;

  case 37:
#line 252 "compiler_hw3.y"
             {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1782 "y.tab.c"
    break;

  case 38:
#line 253 "compiler_hw3.y"
              {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1788 "y.tab.c"
    break;

  case 39:
#line 254 "compiler_hw3.y"
             {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1794 "y.tab.c"
    break;

  case 40:
#line 255 "compiler_hw3.y"
             {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1800 "y.tab.c"
    break;

  case 41:
#line 256 "compiler_hw3.y"
             {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1806 "y.tab.c"
    break;

  case 55:
#line 288 "compiler_hw3.y"
          {(yyval.type_val)="POS";}
#line 1812 "y.tab.c"
    break;

  case 56:
#line 289 "compiler_hw3.y"
          {(yyval.type_val)="NEG";}
#line 1818 "y.tab.c"
    break;

  case 58:
#line 294 "compiler_hw3.y"
              {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1824 "y.tab.c"
    break;

  case 59:
#line 295 "compiler_hw3.y"
                {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1830 "y.tab.c"
    break;

  case 60:
#line 296 "compiler_hw3.y"
                     {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1836 "y.tab.c"
    break;

  case 61:
#line 300 "compiler_hw3.y"
                     {(yyval.type_val)=(yyvsp[-1].type_val);}
#line 1842 "y.tab.c"
    break;

  case 62:
#line 301 "compiler_hw3.y"
             {(yyval.type_val)=(yyvsp[0].type_val);}
#line 1848 "y.tab.c"
    break;

  case 63:
#line 302 "compiler_hw3.y"
            { 
        (yyval.type_val) = (yyvsp[0].ident_val);
        int addr = lookup_symbol((yyvsp[0].ident_val), 0);
        if(addr == -1){
            printf("error\:%d\: undefined\: %s\n",yylineno,(yyvsp[0].ident_val));
            (yyval.type_val)="er";
        }else{
            printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].ident_val), addr); 
        }
        
    }
#line 1864 "y.tab.c"
    break;

  case 64:
#line 313 "compiler_hw3.y"
                              {
        (yyval.type_val)=(yyvsp[-1].type_val);

    }
#line 1873 "y.tab.c"
    break;

  case 65:
#line 320 "compiler_hw3.y"
                                          {
        (yyval.type_val)=(yyvsp[-3].type_val);
    }
#line 1881 "y.tab.c"
    break;

  case 66:
#line 326 "compiler_hw3.y"
                                    {
        char *type1 = (yyvsp[-2].type_val);
        char *type2 = lookup_type((yyvsp[0].type_val));
        (yyval.type_val)=(yyvsp[-2].type_val);
        printf("%c to %c\n", toupper(type2[0]), toupper(type1[0]));
    }
#line 1892 "y.tab.c"
    break;

  case 67:
#line 335 "compiler_hw3.y"
                           {
        if(insert_symbol((yyvsp[-1].ident_val), (yyvsp[-2].type_val), 0) == -1){
            printf("error\:%d\: %s redeclared in this block. previous declaration at line %d\n", yylineno, (yyvsp[-1].ident_val), lookup_symbol((yyvsp[-1].ident_val), 1));
        }else{
            int row_num = t[scope_num-1].row_num-1;
            printf("> Insert {%s} into symbol table (scope level\: %d)\n", t[scope_num-1].c[row_num].name, t[scope_num-1].scope_level);
        }
    }
#line 1905 "y.tab.c"
    break;

  case 68:
#line 343 "compiler_hw3.y"
                                             {
        insert_symbol((yyvsp[-3].ident_val), (yyvsp[-4].type_val), 0);
        int row_num = t[scope_num-1].row_num-1;
        printf("> Insert {%s} into symbol table (scope level\: %d)\n", t[scope_num-1].c[row_num].name, t[scope_num-1].scope_level);
    }
#line 1915 "y.tab.c"
    break;

  case 69:
#line 348 "compiler_hw3.y"
                                                    {
        insert_symbol((yyvsp[-4].ident_val), (yyvsp[-5].type_val), 1);
        int row_num = t[scope_num-1].row_num-1;
        printf("> Insert {%s} into symbol table (scope level\: %d)\n", t[scope_num-1].c[row_num].name, t[scope_num-1].scope_level);
    }
#line 1925 "y.tab.c"
    break;

  case 70:
#line 356 "compiler_hw3.y"
                                      {
        char *first = lookup_type((yyvsp[-2].type_val));
        char *third = lookup_type((yyvsp[0].type_val));
        char *er = "er";
        char *i = "int";
        if(strcmp(first, third) != 0 && strcmp(er, (yyvsp[-2].type_val)) != 0 && strcmp((yyvsp[0].type_val), er) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, (yyvsp[-1].type_val), first, third);
        }else if(strcmp(i, (yyvsp[-2].type_val)) == 0){
            printf("error\:%d\: cannot assign to int\n", yylineno);
        }
        printf("%s\n", (yyvsp[-1].type_val));
    }
#line 1942 "y.tab.c"
    break;

  case 78:
#line 384 "compiler_hw3.y"
                     {printf("INC\n");}
#line 1948 "y.tab.c"
    break;

  case 79:
#line 385 "compiler_hw3.y"
                     {printf("DEC\n");}
#line 1954 "y.tab.c"
    break;

  case 81:
#line 393 "compiler_hw3.y"
             {
        create_symbol();
    }
#line 1962 "y.tab.c"
    break;

  case 82:
#line 395 "compiler_hw3.y"
                          {
        dump_symbol();
    }
#line 1970 "y.tab.c"
    break;

  case 86:
#line 407 "compiler_hw3.y"
                               {
        printf("%s\n", (yyvsp[-1].type_val));
        char *a = "ADD", *s = "SUB", *m = "MUL", *q = "QUO", *r = "REM";
        char *first = lookup_type((yyvsp[-2].type_val));
        char *third = lookup_type((yyvsp[0].type_val));
        if((strcmp((yyvsp[-1].type_val), a)==0 || strcmp((yyvsp[-1].type_val), s)==0 || strcmp((yyvsp[-1].type_val), m)==0 || strcmp((yyvsp[-1].type_val), q)==0 || strcmp((yyvsp[-1].type_val), r)==0) && strcmp(first, third) == 0){
            printf("error\:%d\: non-bool (type %s) used as for condition\n", yylineno+1,first);
        }
    }
#line 1984 "y.tab.c"
    break;

  case 87:
#line 416 "compiler_hw3.y"
               {
        char *b = "bool";
        char *t = lookup_type((yyvsp[0].type_val));
        if(strcmp(b, t) != 0){
            printf("error\:%d\: non-bool (type %s) used as for condition\n", yylineno+1,t);
        }
    }
#line 1996 "y.tab.c"
    break;


#line 2000 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 452 "compiler_hw3.y"


/* C code section */

static void create_symbol(){
    t[scope_num].row_num = 0;
    t[scope_num].scope_level = scope_num;
    scope_num++;
}

static int insert_symbol(char *name, char *typename, int judge){
    if(lookup_table(name) != -1){
        return -1;
    }
    if(once == -1){
        create_symbol();
        once = 0;
    }
    int row_num = t[scope_num-1].row_num;
    t[scope_num-1].c[row_num].index = t[scope_num-1].row_num;
    t[scope_num-1].c[row_num].name = name;
    t[scope_num-1].c[row_num].type_name = typename;
    t[scope_num-1].c[row_num].addr = addr;
    t[scope_num-1].c[row_num].lineno = yylineno;
    if(judge == 1){
        char *tmp = "array";
        t[scope_num-1].c[row_num].type_name = strdup(tmp);
        t[scope_num-1].c[row_num].element_type = typename;
    }else{
        char *tmp = "-";
        t[scope_num-1].c[row_num].element_type = strdup(tmp);
    }
    t[scope_num-1].row_num++;
    addr++;
}

static int lookup_symbol(char * name, int ty){
    int not_find = 0;
    for(int i = scope_num - 1; i >= 0; i--){
        for(int j = 0; j < t[i].row_num; j++){
            if(strcmp(t[i].c[j].name, name) == 0){
                not_find = 1;
                if(ty == 0){
                    return t[i].c[j].addr;
                }else if(ty == 1){
                    return t[i].c[j].lineno;
                }
            }
        }
    }
    if(not_find == 0){
        return -1;
    }
}
    
static int lookup_table(char *name){
    int not_find = 0;
    int i = scope_num - 1;
    for(int j = 0; j < t[i].row_num; j++){
        if(strcmp(t[i].c[j].name, name) == 0){
            not_find = 1;
            return t[i].c[j].addr;
        }
    }
    if(not_find == 0){
        return -1;
    }
}

static char* lookup_type(char *name){
    int not_find = 0;
    char *str_int = "int";
    char *str_float = "float";
    char *str_string = "string";
    char *str_bool = "bool";
    if(strcmp(name, str_int) == 0 || strcmp(name, str_float) == 0 || strcmp(name, str_string) == 0 || strcmp(name, str_bool) == 0){
        not_find = 1;
        return name;
    }
    for(int i = scope_num - 1; i >= 0; i--){
        for(int j = 0; j < t[i].row_num; j++){
            if(strcmp(t[i].c[j].name, name) == 0){
                not_find = 1;
                char *tmp = "array";
                if(strcmp(t[i].c[j].type_name, tmp) == 0){
                    return t[i].c[j].element_type;
                }else{
                    return t[i].c[j].type_name;
                }
                    
            }
        }
    }
    if(not_find == 0){
        return "-";
    }
}

static void dump_symbol(){
    printf("> Dump symbol table (scope level: %d)\n", t[scope_num-1].scope_level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n", "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int i = 0; i < t[scope_num-1].row_num; ++i){
        printf("%-10d%-10s%-10s%-10d%-10d%s\n", 
            t[scope_num-1].c[i].index,
            t[scope_num-1].c[i].name,
            t[scope_num-1].c[i].type_name,
            t[scope_num-1].c[i].addr,
            t[scope_num-1].c[i].lineno,
            t[scope_num-1].c[i].element_type);
    }
    scope_num--;

}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    codegen(".source hw3.j\n");
    codegen(".class public Main\n");
    codegen(".super java/lang/Object\n");
    codegen(".method public static main([Ljava/lang/String;)V\n");
    codegen(".limit stack 100\n");
    codegen(".limit locals 100\n");
    INDENT++;

    yyparse();

	printf("Total lines: %d\n", yylineno);

    /* Codegen end */
    codegen("return\n");
    INDENT--;
    codegen(".end method\n");
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    }
    return 0;
}
