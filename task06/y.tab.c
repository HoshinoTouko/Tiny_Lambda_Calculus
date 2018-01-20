/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "grammar.y"

/* the grammar of lambda expression */
#include "tree.h"
#include "closure.h"
#include "type.h"
/*#include "code.h"
void yyerror (char const *);
/************************************/

char *name_env[MAX_ENV] = {"+", "-", "*", "/", "=", "<"};

AST *ast_env[MAX_ENV];
int current = INIT_POS;
#define YYSTYPE AST *
FILE *texfile;
FILE *eval_tree;
int is_decl = 0;
CLOSURE_LIST *init_clos;
CBN_ENV *init_env_cbn; 
extern FILE * yyin;
extern int step;

static void (* set_method)(char *, AST *);
static void (* call_method)(AST *);
#line 46 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define THEN 257
#define ELSE 258
#define INT 259
#define LET 260
#define ID 261
#define IF 262
#define FI 263
#define CONCAT 264
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    1,    1,    3,    3,    3,    3,    4,
    3,    3,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    6,    2,    1,    1,    7,    3,    0,
    5,    2,
};
static const YYINT yydefred[] = {                         0,
    6,    3,    7,    0,    0,    0,    0,    1,    0,    0,
    0,    0,   10,    2,    5,   12,    0,    0,    9,    0,
    0,    0,    0,    0,    0,    0,    4,    0,    8,
};
static const YYINT yydgoto[] = {                          7,
    8,   10,   16,   20,
};
static const YYINT yysindex[] = {                       -35,
    0,    0,    0,   -5,   -5, -260,  -35,    0,  -31, -259,
  -25,  -21,    0,    0,    0,    0,  -58,   -5,    0,  -42,
   -5,  -15,   -5,   -9,   -5,   -5,    0,  -40,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -1,    0,   40,    0,
};
#define YYTABLESIZE 264
static const YYINT yytable[] = {                          5,
   13,   17,   21,   23,    5,   14,    0,    0,    5,    0,
    0,    0,    0,    0,    5,    0,    0,    0,    5,   19,
    0,    0,    0,    6,    5,    0,    0,   15,    6,    0,
    5,    0,    6,    0,    5,    0,    0,    0,    6,    9,
    0,   11,    6,   11,   12,    0,    9,    0,    6,   27,
    0,    0,    0,    0,    6,    0,    0,   22,    6,   11,
   24,    0,   26,    0,   28,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,
    3,    4,   29,    1,    2,    3,    4,    1,    0,    3,
    4,   18,    0,    1,    0,    3,    4,    1,    0,    3,
    4,    0,   25,    1,    0,    3,    4,    0,    0,    1,
    0,    3,    4,    1,    0,    3,    4,   11,   11,    0,
    0,    0,    0,   11,
};
static const YYINT yycheck[] = {                         40,
  261,  261,   61,   46,   40,    7,   -1,   -1,   40,   -1,
   -1,   -1,   -1,   -1,   40,   -1,   -1,   -1,   40,   41,
   -1,   -1,   -1,   64,   40,   -1,   -1,   59,   64,   -1,
   40,   -1,   64,   -1,   40,   -1,   -1,   -1,   64,    0,
   -1,   41,   64,    4,    5,   -1,    7,   -1,   64,   59,
   -1,   -1,   -1,   -1,   64,   -1,   -1,   18,   64,   59,
   21,   -1,   23,   -1,   25,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,   -1,
  261,  262,  263,  259,  260,  261,  262,  259,   -1,  261,
  262,  257,   -1,  259,   -1,  261,  262,  259,   -1,  261,
  262,   -1,  258,  259,   -1,  261,  262,   -1,   -1,  259,
   -1,  261,  262,  259,   -1,  261,  262,  257,  258,   -1,
   -1,   -1,   -1,  263,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 264
#define YYUNDFTOKEN 271
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,0,0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,"'='",0,0,
"'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"THEN",
"ELSE","INT","LET","ID","IF","FI","CONCAT",0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : lines",
"lines : decl",
"lines : lines decl",
"$$1 :",
"decl : LET $$1 ID '=' expr ';'",
"decl : expr ';'",
"expr : INT",
"expr : ID",
"expr : IF expr THEN expr ELSE expr FI",
"expr : '(' expr ')'",
"$$2 :",
"expr : '@' ID $$2 '.' expr",
"expr : expr expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 60 "grammar.y"


void yyerror ( char const *s)
{
  printf ("%s!\n", s);
}

void set_call_by_name(char *name, AST *ast)
{
  CLOSURE *clos = NULL;
  Type_ptr type = typing(NULL, ast, current);

  name_env[current] = (char *) name;
  global_type_env [current] = storetype(type);
  ast_env[current] = ast;

  init_clos = make_list(clos, init_clos);
  printf("%s is defined: \n", name);
  printtype(type);
  new_env();
  clos = (eval_cbn(make_cbn_env(make_clos(ast, NULL,  current),NULL))) -> cbn_env;
  printf("\n");
  if( yyin == stdin) {
    print_closure(clos);
    printf("\n");
    printf("please input a lambda term with \";\":\n");
  }
  global_eval_env[current] = clos;
  current++;
  if (current == MAX_ENV) {
    printf("%d, buffer exceeds!", current);
    exit(1);
  }
}

void set_call_by_value(char *name, AST *ast)
{
  Type_ptr type = typing(NULL, ast, current);
  ast_env[current] = ast;
  global_type_env [current] = storetype(type);
  name_env[current] = name;

  CLOSURE *clos = make_clos(clone_tree(ast), NULL, current);

  printf("%s is defined: \n", name);
  printtype(type);
  printf("\n");
  if( yyin == stdin) {
    print_closure(clos);
    printf("\nplease input a lambda term with \";\":\n");
  } 
 
  /*
  OBJECT *exe_result;
  exe_result = execution(compile(ast));
  if (exe_result -> kind == CLOS)
    exe_result -> env -> value = current;
  global_exec_env[current] = exe_result;
  */

  new_env();
  /* if (strcmp(name, "fact") == 0) { */
  /*   printf("looop\n"); */
  /*   CLOSURE_LIST *loop =  make_list(eval_cbv(clos), NULL); */
  /*   loop -> next = loop; */
  /*   init_eval_env[current] = loop;  */
  /* } */
  /* else */
  global_eval_env[current] = eval_cbv(clos);
  current++; 
  if (current == MAX_ENV) {
    printf("%d, buffer exceeds!", current);
    exit(1);
  }
}

void call_by_name(AST *ast)
{
  CLOSURE *clos = make_clos(ast, NULL, current);
  Type_ptr type = typing(NULL, ast, current);
  CBN_ENV *cbn_clos;
  print_expression(ast, stdout);
  printf(" |== ");
  printtype (type);
  printf("\n"); 
  new_env();
  printtree(ast);
  print_closure(clos);
  printf("\n");
  cbn_clos = (eval_cbn(make_cbn_env(clos, NULL)));
  print_closure(cbn_clos -> cbn_env);
  free_cbn_env(cbn_clos);
  printf("\nstep = %d\nplease input a lambda term with \";\":\n", step);
  step = 0;
}

void call_by_value(AST * ast)
{
  printf("evaluating!!\n");
  CLOSURE *clos = make_clos(ast, NULL, current);
  Type_ptr type = typing(NULL, ast, current);
  print_expression(ast, stdout);
  printf(" |== ");
  printtype (type);
  printf("\n"); 
  new_env();
  printtree(ast);
  print_closure(clos);
  clos = eval_cbv(clos);
  printf(" => ");
  print_closure(clos);
  free_clos(clos);
  printf("\nstep = %d\nplease input a lambda term with \";\":\n",step);
  step = 0;
}

int main(int argc, char ** argv)
{
  // select call_by_name or call_by_value by the argument
  set_method = set_call_by_name;
  call_method = call_by_name;
  while (argc > 1) {
    argc --; ++argv;
    if (strcmp(argv[0], "-v") == 0) { 
      set_method = set_call_by_value;
      call_method = call_by_value;
      break;
    }  
  }

  eval_tree = fopen("evaltree.tex", "w");
  fprintf(eval_tree, "\\begin{prooftree}\n");

  // test the prededined library text
  yyin = fopen("library.txt", "r");
  if (yyin == NULL) {
    printf("predefined library file can not be opened!\n");
  }
  //printf("please input a lambda term with \";\":\n");
  init_eval();
  init_type_env();
  // init_exec_env();
  texfile = fopen("expr.tex", "w");
  fprintf(texfile, "\\exptree{\\Tree\n");
  yyparse ();
  fprintf(texfile, "}\n");
  fprintf(eval_tree, "\\end{prooftree}\n");
  fclose(eval_tree);
  fclose(texfile);
  return 0;
}
#line 405 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 3:
#line 36 "grammar.y"
	{is_decl = 1;}
break;
case 4:
#line 36 "grammar.y"
	{
  set_method((char *) yystack.l_mark[-3] -> lchild, yystack.l_mark[-1]);
  }
break;
case 5:
#line 39 "grammar.y"
	{
  /*printf("\nevaluating!\n");
  call_method(yystack.l_mark[-1]);
  }
break;
case 7:
#line 46 "grammar.y"
	{
   int deepth = find_deepth((char *) yystack.l_mark[0] -> lchild);
   yyval = yystack.l_mark[0], yyval -> value = deepth;
 }
break;
case 8:
#line 50 "grammar.y"
	{yyval = make_cond(yystack.l_mark[-5], yystack.l_mark[-3], yystack.l_mark[-1]);}
break;
case 9:
#line 51 "grammar.y"
	{ yyval = yystack.l_mark[-1];}
break;
case 10:
#line 52 "grammar.y"
	{ name_env[current] = (char *) yystack.l_mark[0] ->lchild ;
   current++; }
break;
case 11:
#line 53 "grammar.y"
	{ 
  yyval = make_abs( (char *) yystack.l_mark[-3] -> lchild, yystack.l_mark[0]);
  sfree (yystack.l_mark[-3]);
  current--; }
break;
case 12:
#line 57 "grammar.y"
	{yyval = make_app(yystack.l_mark[-1], yystack.l_mark[0]); }
break;
#line 652 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}