/*	Definition section */
%{
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
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    char *ident_val;
    char *type_val;
    /* ... */
}
/* Token without return */
%token INT FLOAT BOOL STRING ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token SEMICOLON LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE
%token OR AND EQL NEQ LEQ GEQ LSS GTR NOT
%token IF ELSE FOR WHILE TRUE FALSE RETURN

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT BOOL_LIT
%token <ident_val> IDENT
%token <type_val> INC DEC ADD SUB MUL QUO REM PRINT

/* Nonterminal with return, which need to sepcify type */
%type <type_val> binary_op add_op cmp_op assign_op mul_op or_op and_op unary_op
%type <type_val> Operand TypeName Type PrimaryExpr IndexExpr UnaryExpr Literal ConversionExpr
%type <type_val> Expression Expression1 Expression2 Expression3 Expression4 Expression5

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList {dump_symbol();}
;

StatementList
    : StatementList Statement 
    | 
;

Type
    : TypeName {$$=$1;}
;

TypeName
    : INT 
    | FLOAT 
    | STRING
    | BOOL
;

Literal
    : INT_LIT {
        $$="int";
        fprintf(fout, "ldc %d\n", $1);
        printf("INT_LIT %d\n", $1);
    }
    | FLOAT_LIT {
        $$="float";
        printf("FLOAT_LIT %f\n", $1);
    }
    | STRING_LIT {
        $$="string";
        printf("STRING_LIT %s\n", $1);
    }
    | BOOL_LIT {
        $$="bool";
        printf("%s\n", $1);
    }
;

Statement
    : DeclarationStmt 
    | AssignmentStmt
    | IncDecStmt
    | Block
    | IfStmt
    | WhileStmt
    | ForStmt
    | PrintStmt
    | Expression SEMICOLON
;

PrintStmt
    : PRINT LPAREN Expression RPAREN SEMICOLON {
        printf("%s %s\n", $1, lookup_type($3));
        fprintf(fout, "%s %s\n", $1, lookup_type($3));
    }
;

Expression
    : Expression or_op Expression1 {
        char *first = lookup_type($1);
        char *third = lookup_type($3);
        char *rem = "REM", *f = "float", *a = "AND", *o = "OR", *b = "bool";
        if(strcmp($2, rem) == 0 && (strcmp(first, f) == 0 || strcmp(third, f) == 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on float)\n", yylineno, $2);
        }else if((strcmp($2, a) == 0 || strcmp($2, o) == 0) && (strcmp(first, b) != 0 || strcmp(third, b) != 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on int)\n", yylineno, $2);
        }else if(strcmp(first, third) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, $2, first, third);
        }else if(strcmp(first, third) == 0){
            $$=first;
        }
        printf("%s\n", $2);
    }
    | Expression1{$$=$1;}
;


Expression1
    : Expression1 and_op Expression2 {
        char *first = lookup_type($1);
        char *third = lookup_type($3);
        char *rem = "REM", *f = "float", *a = "AND", *o = "OR", *b = "bool";
        if(strcmp($2, rem) == 0 && (strcmp(first, f) == 0 || strcmp(third, f) == 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on float)\n", yylineno, $2);
        }else if((strcmp($2, a) == 0 || strcmp($2, o) == 0) && (strcmp(first, b) != 0 || strcmp(third, b) != 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on int)\n", yylineno, $2);
        }else if(strcmp(first, third) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, $2, first, third);
        }else if(strcmp(first, third) == 0){
            $$=first;
        }
        printf("%s\n", $2);
    }
    | Expression2{$$=$1;}
;


Expression2
    : Expression2 cmp_op Expression3 {
        char *first = lookup_type($1);
        char *third = lookup_type($3);
        char *rem = "REM", *f = "float", *a = "AND", *o = "OR", *b = "bool";
        if(strcmp($2, rem) == 0 && (strcmp(first, f) == 0 || strcmp(third, f) == 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on float)\n", yylineno, $2);
        }else if((strcmp($2, a) == 0 || strcmp($2, o) == 0) && (strcmp(first, b) != 0 || strcmp(third, b) != 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on int)\n", yylineno, $2);
        }else if(strcmp(first, third) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, $2, first, third);
        }else if(strcmp(first, third) == 0){
            $$="bool";
        }
        printf("%s\n", $2);
    }
    | Expression3{$$=$1;}
;


Expression3
    : Expression3 add_op Expression4 {
        char *first = lookup_type($1);
        char *third = lookup_type($3);
        char *rem = "REM", *f = "float", *a = "AND", *o = "OR", *b = "bool";
        if(strcmp($2, rem) == 0 && (strcmp(first, f) == 0 || strcmp(third, f) == 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on float)\n", yylineno, $2);
        }else if((strcmp($2, a) == 0 || strcmp($2, o) == 0) && (strcmp(first, b) != 0 || strcmp(third, b) != 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on int)\n", yylineno, $2);
        }else if(strcmp(first, third) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, $2, first, third);
        }else if(strcmp(first, third) == 0){
            $$=first;
        }
        printf("%s\n", $2);
    }
    | Expression4{$$=$1;}
;

Expression4
    : Expression4 mul_op Expression5 {
        char *first = lookup_type($1);
        char *third = lookup_type($3);
        char *rem = "REM", *f = "float", *a = "AND", *o = "OR", *b = "bool";
        if(strcmp($2, rem) == 0 && (strcmp(first, f) == 0 || strcmp(third, f) == 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on float)\n", yylineno, $2);
        }else if((strcmp($2, a) == 0 || strcmp($2, o) == 0) && (strcmp(first, b) != 0 || strcmp(third, b) != 0)){
            printf("error\:%d\: invalid operation\: (operator %s not defined on int)\n", yylineno, $2);
        }else if(strcmp(first, third) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, $2, first, third);
        }else if(strcmp(first, third) == 0){
            $$=first;
        }
        printf("%s\n", $2);
    }
    | Expression5{$$=$1;}
;

Expression5
    : UnaryExpr {
        $$=$1;
    }
;

UnaryExpr
    : PrimaryExpr {$$=$1;}
    | unary_op UnaryExpr {
        $$=$2;
        printf("%s\n", $1);
    }
;

binary_op
    : or_op  {$$=$1;}
    | and_op  {$$=$1;}
    | cmp_op {$$=$1;}
    | add_op {$$=$1;}
    | mul_op {$$=$1;}
;

or_op
    : OR
;

and_op
    : AND
;

cmp_op
    : EQL 
    | NEQ 
    | LEQ
    | GEQ 
    | LSS 
    | GTR 
;

add_op
    : ADD 
    | SUB 
;

mul_op
    : MUL 
    | QUO 
    | REM
;

unary_op
    : ADD {$$="POS";}
    | SUB {$$="NEG";}
    | NOT 
;

PrimaryExpr
    : Operand {$$=$1;}
    | IndexExpr {$$=$1;}
    | ConversionExpr {$$=$1;}
;

Operand
    : '"' Literal '"'{$$=$2;}
    | Literal{$$=$1;}
    | IDENT { 
        $$ = $1;
        int addr = lookup_symbol($1, 0);
        if(addr == -1){
            printf("error\:%d\: undefined\: %s\n",yylineno,$1);
            $$="er";
        }else{
            printf("IDENT (name=%s, address=%d)\n", $1, addr); 
        }
        
    }
    | LPAREN Expression RPAREN{
        $$=$2;

    }
;

IndexExpr
    : PrimaryExpr LBRACK Expression RBRACK{
        $$=$1;
    }
;

ConversionExpr
    : LPAREN Type RPAREN Expression {
        char *type1 = $2;
        char *type2 = lookup_type($4);
        $$=$2;
        printf("%c to %c\n", toupper(type2[0]), toupper(type1[0]));
    }
;

DeclarationStmt
    : Type IDENT SEMICOLON {
        if(insert_symbol($2, $1, 0) == -1){
            printf("error\:%d\: %s redeclared in this block. previous declaration at line %d\n", yylineno, $2, lookup_symbol($2, 1));
        }else{
            int row_num = t[scope_num-1].row_num-1;
            printf("> Insert {%s} into symbol table (scope level\: %d)\n", t[scope_num-1].c[row_num].name, t[scope_num-1].scope_level);
        }
    }
    | Type IDENT ASSIGN Expression SEMICOLON {
        insert_symbol($2, $1, 0);
        int row_num = t[scope_num-1].row_num-1;
        printf("> Insert {%s} into symbol table (scope level\: %d)\n", t[scope_num-1].c[row_num].name, t[scope_num-1].scope_level);
    }
    | Type IDENT LBRACK Expression RBRACK SEMICOLON {
        insert_symbol($2, $1, 1);
        int row_num = t[scope_num-1].row_num-1;
        printf("> Insert {%s} into symbol table (scope level\: %d)\n", t[scope_num-1].c[row_num].name, t[scope_num-1].scope_level);
    }
;

AssignmentExpr
    : Expression assign_op Expression {
        char *first = lookup_type($1);
        char *third = lookup_type($3);
        char *er = "er";
        char *i = "int";
        if(strcmp(first, third) != 0 && strcmp(er, $1) != 0 && strcmp($3, er) != 0){
            printf("error\:%d\: invalid operation\: %s (mismatched types %s and %s)\n", yylineno, $2, first, third);
        }else if(strcmp(i, $1) == 0){
            printf("error\:%d\: cannot assign to int\n", yylineno);
        }
        printf("%s\n", $2);
    }
;

AssignmentStmt
    : AssignmentExpr SEMICOLON
;

assign_op
    : ASSIGN
    | ADD_ASSIGN
    | SUB_ASSIGN
    | MUL_ASSIGN
    | QUO_ASSIGN
    | REM_ASSIGN
;

IncDecExpr
    : Expression INC {printf("INC\n");}
    | Expression DEC {printf("DEC\n");}
;

IncDecStmt
    : IncDecExpr SEMICOLON 
;

Block
    : LBRACE {
        create_symbol();
    }StatementList RBRACE {
        dump_symbol();
    }
;

IfStmt
    : IF LPAREN Condition RPAREN Block
    | IF LPAREN Condition RPAREN Block ELSE IfStmt
    | IF LPAREN Condition RPAREN Block ELSE Block
;

Condition
    : Operand binary_op Operand{
        printf("%s\n", $2);
        char *a = "ADD", *s = "SUB", *m = "MUL", *q = "QUO", *r = "REM";
        char *first = lookup_type($1);
        char *third = lookup_type($3);
        if((strcmp($2, a)==0 || strcmp($2, s)==0 || strcmp($2, m)==0 || strcmp($2, q)==0 || strcmp($2, r)==0) && strcmp(first, third) == 0){
            printf("error\:%d\: non-bool (type %s) used as for condition\n", yylineno+1,first);
        }
    }
    | UnaryExpr{
        char *b = "bool";
        char *t = lookup_type($1);
        if(strcmp(b, t) != 0){
            printf("error\:%d\: non-bool (type %s) used as for condition\n", yylineno+1,t);
        }
    }
;

WhileStmt
    : WHILE LPAREN Condition RPAREN Block
;

ForStmt
    : FOR LPAREN ForClause RPAREN Block
;

ForClause
    : InitStmt SEMICOLON Condition SEMICOLON PostStmt
;

InitStmt
    : SimpleExpr
;

PostStmt
    : SimpleExpr
;

SimpleExpr
    : AssignmentExpr
    | Expression
    | IncDecExpr
;


%%

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