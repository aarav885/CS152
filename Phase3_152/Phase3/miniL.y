%{
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
%}

%union{
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
}

%error-verbose 
%start prog_start

%token <num_val> NUMBER
%token <id_val> IDENT

%type <expression> function declarations declaration identifiers ident expressions expression vars var func_ident
%type <expression> bool_exp relation_and_expr relation_expr_inv relation_expr comp multiplicative_expr term 
%type <statement> statements statement 



%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE TRUE FALSE SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN RETURN FOR ENUM
%right ASSIGN
%left OR
%left AND
%right NOT
%left LT LTE GT GTE EQ NEQ
%left ADD SUB 
%left MULT DIV MOD

%%

prog_start:  
            %empty 
        {
                if (!mainFunc) {
                    printf("Error: No main function declared!\n");
                }

        }
        | function prog_start {

        }
        ;

function:   FUNCTION func_ident SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY 

    {
        std::string temp = "func ";
        temp.append($2.place);
        temp.append("\n");
        std::string s = $2.place;
        if (s == "main") {
            mainFunc = true;
        }
        temp.append($5.code);
        std::string decs = $5.code;
        int decNum = 0;
        while (decs.find(".") != std::string::npos) {
            int pos = decs.find(".");
            decs.replace(pos, 1, "=");
            std::string part = ", $" + std::to_string(decNum) + "\n";
            decNum++;
            decs.replace(decs.find("\n", pos), 1, part);
        }
        temp.append(decs);
        temp.append($8.code);
        std::string statements = $11.code;
        if (statements.find("continue") != std::string::npos) {
            printf("Error: continue outside loop in function %s\n", $2.place);
        }
        temp.append(statements);
        temp.append("endfunc\n\n");
        printf(temp.c_str());
    }
        ;

func_ident:  IDENT

{
            if (funcs.find($1) != funcs.end()) {
                printf("Error: Function %s already declared!\n", $1);
            } else {
                funcs.insert($1);
            }

            $$.place = strdup($1);
            $$.code = strdup("");
}

    ;
declarations:   %empty {
                $$.place = strdup("");
                $$.code = strdup("");
            }
            | declaration SEMICOLON declarations {
                std::string temp;
                temp.append($1.code);
                temp.append($3.code);
                $$.code = strdup(temp.c_str());
                $$.place = strdup("");
            }
            ;

declaration:    identifiers COLON INTEGER {
        size_t left = 0;
        size_t right = 0;
        std::string parse($1.place);
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
        $$.code = strdup(temp.c_str());
        $$.place = strdup("");
    }
                
        | identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER  {
        
        size_t left = 0;
        size_t right = 0;
        std::string parse($1.place);
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
                        if ($5 < 1){
                             printf("Error: Declaring array %s size is < 1.\n", ident.c_str());
                    }

                    varTemp[ident] = ident;
                    arrSize[ident] = $5;
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
                        if ($5 < 1){
                             printf("Error: Declaring array %s size is < 1.\n", ident.c_str());
                    }
                    varTemp[ident] = ident;
                    arrSize[ident] = $5;
                }
                temp.append(ident);
                left = right + 1;
            }
            temp += ", " + std::to_string($5); + "\n";
        }
        $$.code = strdup(temp.c_str());
        $$.place = strdup("");
    }
            ;

identifiers:    ident {

                std::string ident = $1.place;
                // if (funcs.find(ident) == funcs.end() && varTemp.find(ident) == varTemp.end()) {
                //         printf("Error 1: Identifier %s is not declared\n", ident.c_str());
                //     } else if (arrSize[ident] > 1) {
                //         printf("Error: Did not provide index for array Identifier %s.\n", ident.c_str());
                //     }
                $$.code = strdup($1.code);
                $$.place = strdup($1.place); 
                
            }
            | ident COMMA identifiers {
                std::string temp;
                temp.append($1.code);
                temp.append("|");
                temp.append($3.code);
                $$.code = strdup(temp.c_str());
                $$.place = strdup("");
            }
            ;

ident:       IDENT {   
                    $$.place = strdup($1);
                    $$.code = strdup("");      
            }
            ;

statements:     statement SEMICOLON {
                $$.code = strdup($1.code);
            }
            | statement SEMICOLON statements {
                std::string temp;
                temp.append($1.code);
                temp.append($3.code);
                $$.code = strdup(temp.c_str());
            }
            ;

statement:      vars ASSIGN expression {

                std::string temp;
                temp.append($1.code);
                temp.append($3.code);
                if($1.arr || $3.arr){
                    temp += "[]= ";
                }
                else{
                    temp += "= ";
                }
                temp.append($1.place);
                temp.append(", ");
                temp.append($3.place);
                temp += "\n";
                $$.code = strdup(temp.c_str());
    
            }
            | IF bool_exp THEN statements ENDIF {
                std::string temp;
                std::string dst1 = new_label();
                std::string dst2 = new_label();
                temp.append($2.code);
                temp = temp + "?:= " + dst1 + ", " + $2.place + "\n";
                temp = temp + ":= " + dst2 + "\n";
                temp = temp + ": " + dst1 + "\n";
                temp.append($4.code);
                temp = temp + ": " + dst2 + "\n";
                $$.code = strdup(temp.c_str());
            }
            | IF bool_exp THEN statements ELSE statements ENDIF {
                std::string temp;
                std::string dst1 = new_label();
                std::string dst2 = new_label();
                temp.append($2.code);
                temp = temp + "?:= " + dst1 + ", " + $2.place + "\n";
                temp.append($6.code);
                temp = temp + ":= " + dst2 + "\n";
                temp = temp + ": " + dst1 + "\n";
                temp.append($4.code);
                temp = temp + ": " + dst2 + "\n";
                $$.code = strdup(temp.c_str());
            }
            | WHILE bool_exp BEGINLOOP statements ENDLOOP {

                std::string dst1 = new_label();
                std::string dst2 = new_label();
                std::string dst3 = new_label();
                std::string temp1;
                std::string temp2;

                temp1.append($4.code);
                size_t pos;
                while ((temp1.find("continue")) != std::string::npos) {
                    pos = temp1.find("continue");
                    temp1.replace(pos, 8, ":= " + dst1);
                }

                
                temp2 += ": " + dst1 + "\n";
                temp2.append($2.code);
                temp2 += "?: " + dst2 + ", ";
                temp2.append($2.place);
                temp2.append("\n");
                temp2 += ":= " + dst3 + "\n";
                temp2 += ": " + dst2 + "\n";
                temp2.append(temp1);
                temp2 += ":= " + dst1 + "\n";
                temp2 += ": " + dst2 + "\n";
                $$.code = strdup(temp2.c_str());
                
                
            }
            | DO BEGINLOOP statements ENDLOOP WHILE bool_exp {
                std::string temp1;
                std::string temp2;
                std::string dst1 = new_label();
                std::string dst2 = new_label();
                temp1.append($3.code);
                size_t pos;
                while ((temp1.find("continue")) != std::string::npos) {
                    pos = temp1.find("continue");
                    temp1.replace(pos, 8 , ":= " + dst2);
                }

                temp2.append(": ");
                temp2.append("\n");
                temp2.append(temp1);
                temp2 += ": " + dst2 + "\n";
                temp2.append($6.code);
                temp2 += "?:= " + dst1 + ", ";
                temp2.append($6.place);
                temp2.append("\n");
                $$.code = strdup(temp1.c_str());
            }
            | READ vars {

                std::string temp;
                temp.append($2.code);
                size_t pos = temp.find("|", 0);
                while (pos != std::string::npos) {
                    temp.replace(pos, 1, "<");
                    pos = temp.find("|", pos);
                }

                $$.code = strdup(temp.c_str());
            }
            | WRITE vars {
                std::string temp;
                temp.append($2.code);
                size_t pos = temp.find("|", 0);
                while (pos != std::string::npos) {
                    temp.replace(pos, 1, ">");
                    pos = temp.find("|", pos);
                }

                $$.code = strdup(temp.c_str());
            }
            | CONTINUE {
                $$.code = strdup("continue\n");
            }
            | RETURN expression {
                std::string temp; 
                temp.append($2.code);
                temp.append("ret ");
                temp.append($2.place);
                temp.append("\n");
                $$.code = strdup(temp.c_str());
            }
            ;

bool_exp:       relation_and_expr {

                $$.code = strdup($1.code);
                $$.place = strdup($1.place);
                }
            |   relation_and_expr OR bool_exp {
                std::string temp; 
                std::string dst = new_temp();
                temp.append($1.code);
                temp.append($3.code);
                temp += ". " + dst + "\n";
                temp += "|| " + dst + ", ";
                temp.append($1.place);
                temp.append(", ");
                temp.append($3.place);
                temp.append("\n");
                $$.code = strdup(temp.c_str());
                $$.place = strdup(dst.c_str());    
            } 
            ;

relation_and_expr:  relation_expr_inv {

                $$.code = strdup($1.code);
                $$.place = strdup($1.place);
            }
            | relation_expr_inv AND relation_and_expr {
                std::string temp; 
                std::string dst = new_temp();
                temp.append($1.code);
                temp.append($3.code);
                temp += ". " + dst + "\n";
                temp += "&& " + dst + ", ";
                temp.append($1.place);
                temp.append(", ");
                temp.append($3.place);
                temp.append("\n");
                $$.code = strdup(temp.c_str());
                $$.place = strdup(dst.c_str());
            }
            ;


relation_expr_inv:  NOT relation_expr_inv {
                    std::string temp;
                    std::string dst = new_temp();
                    temp.append($2.code);
                    temp += ". " + dst + "\n";
                    temp += "! " + dst + ", ";
                    temp.append($2.place);
                    temp.append("\n");
                    $$.code = strdup(temp.c_str());
                    $$.place = strdup(dst.c_str());
                }
                | relation_expr {
                    $$.code = strdup($1.code);
                    $$.place = strdup($1.place);
                }
                ;

relation_expr:   
             expression comp expression {
                std::string dst = new_temp();
                std::string temp;
                temp.append($1.code);
                temp.append($3.code);
                temp = temp + ". " + dst + "\n" + $2.place + dst + ", " + $1.place + ", " + $3.place + "\n";
                $$.code = strdup(temp.c_str());
                $$.place = strdup(dst.c_str());
                
            }
            | TRUE {
   
                std::string temp;
                temp.append("1");
                $$.code = strdup("");
                $$.place = strdup(temp.c_str());
            }
            | FALSE {

                std::string temp;
                temp.append("0");
                $$.code = strdup("");
                $$.place = strdup(temp.c_str());
            }
            | L_PAREN bool_exp R_PAREN {
                $$.code = strdup($2.code);
                $$.place = strdup($2.place);
            }
            ;

comp:           EQ {

            $$.code = strdup("");
            $$.place = strdup("== ");
            }
            | NEQ {
            
            $$.code = strdup("");
            $$.place = strdup("!= ");
            }
            | LT {            
            $$.code = strdup("");
            $$.place = strdup("< ");
            }
            | GT {           
            $$.code = strdup("");
            $$.place = strdup("> ");
            }
            | LTE {

            $$.code = strdup("");
            $$.place = strdup("<= ");
            }
            | GTE {
            $$.code = strdup("");
            $$.place = strdup(">= ");
            }
            ;

expressions:	  expression {

        std::string temp;
        temp.append($1.code);
        temp.append("param ");
        temp.append($1.place);
        temp.append("\n");
        $$.code = strdup(temp.c_str());
        $$.place = strdup("");
        }	
		| expression COMMA expressions {

        std::string temp;
        temp.append($1.code);
        temp.append("param ");
        temp.append($1.place);
        temp.append("\n");
        temp.append($3.code);
        $$.code = strdup(temp.c_str());
        $$.place = strdup("");
        }
		;

expression: multiplicative_expr { 
                $$.code = strdup($1.code);
                $$.place = strdup($1.place);
            }

        	| multiplicative_expr ADD expression { 

                std::string temp;
                std::string dst = new_temp();
                temp.append($1.code);
                temp.append($3.code);
                temp += ". " + dst + "\n";
                temp += "+ " + dst + ", ";
                temp.append($1.place);
                temp += ", ";
                temp.append($3.place);
                temp += "\n";
                $$.code = strdup(temp.c_str());
                $$.place = strdup(dst.c_str());
            }
        	| multiplicative_expr SUB expression { 
                std::string temp;
                std::string dst = new_temp();
                temp.append($1.code);
                temp.append($3.code);
                temp += ". " + dst + "\n";
                temp += "- " + dst + ", ";
                temp.append($1.place);
                temp += ", ";
                temp.append($3.place);
                temp += "\n";
                $$.code = strdup(temp.c_str());
                $$.place = strdup(dst.c_str());
            }
		    ;

multiplicative_expr:
            term {
                    $$.code = strdup($1.code);
                    $$.place = strdup($1.place);        
            }
            | term MULT multiplicative_expr 
            {
                std::string temp;
                std::string dst = new_temp();
                temp.append($1.code);
                temp.append($3.code);
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "* " + dst + ", ";
                temp.append($1.place);
                temp += ", ";
                temp.append($3.place);
                temp += "\n";
                $$.code = strdup(temp.c_str());
                $$.place = strdup(dst.c_str());    
            }
            | term DIV multiplicative_expr {
                std::string temp;
                std::string dst = new_temp();
                temp.append($1.code);
                temp.append($3.code);
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "/ " + dst + ", ";
                temp.append($1.place);
                temp += ", ";
                temp.append($3.place);
                temp += "\n";
                $$.code = strdup(temp.c_str());
                $$.place = strdup(dst.c_str());
            }
            | term MOD multiplicative_expr {
                std::string temp;
                std::string dst = new_temp();
                temp.append($1.code);
                temp.append($3.code);
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "% " + dst + ", ";
                temp.append($1.place);
                temp += ", ";
                temp.append($3.place);
                temp += "\n";
                $$.code = strdup(temp.c_str());
                $$.place = strdup(dst.c_str());
            }
            ;

term:		  var { 
            std::string dst = new_temp();
            std::string temp;
            if ($1.arr) {
                temp.append($1.code);
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "=[] " + dst + ", ";
                temp.append($1.place);
                temp.append("\n");
            }
            else {
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp = temp + "= " + dst + ", ";
                temp.append($1.place);
                temp.append("\n");
                temp.append($1.code);
            }

            if (varTemp.find($1.place) != varTemp.end()) {
                varTemp[$1.place] = dst;
            }
            $$.code = strdup(temp.c_str());
            $$.place = strdup(dst.c_str());       
        }
		| SUB var { 
            std::string dst = new_temp();
            std::string temp;
            if ($2.arr) {
                temp.append($2.code);
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "=[] " + dst + ", ";
                temp.append($2.place);
                temp.append("\n");
            }
            else {
                temp.append(". ");
                temp.append(dst);
                temp.append("\n");
                temp += "= " + dst + ", ";
                temp.append($2.place);
                temp.append("\n");
                temp.append($2.code);
            }

            if (varTemp.find($2.place) != varTemp.end()) {
                varTemp[$2.place] = dst;
            }
            
            $$.code = strdup(temp.c_str());
            $$.place = strdup(dst.c_str());
        }
		| NUMBER { 
            std::string dst = new_temp();
            std::string temp;
            temp.append(". ");
            temp.append(dst);
            temp.append("\n");
            temp = temp + "= " + dst + ", " + std::to_string($1) + "\n";
            $$.code = strdup(temp.c_str());
            $$.place = strdup(dst.c_str());
        }
		| SUB NUMBER { 

            std::string dst = new_temp();
            std::string temp;
            temp.append(". ");
            temp.append(dst);
            temp.append("\n");
            temp = temp + "= " + dst + ", -" + std::to_string($2) + "\n";
            $$.code = strdup(temp.c_str());
            $$.place = strdup(dst.c_str());
         }
		| L_PAREN expression R_PAREN { 
            $$.code = strdup($2.code);
            $$.place = strdup($2.place);

        }
		| SUB L_PAREN expression R_PAREN { 
            std::string temp;
            temp.append($3.code);
            temp.append("* ");
            temp.append($3.place);
            temp.append(", ");
            temp.append($3.place);
            temp.append(", -1\n");
            $$.code = strdup(temp.c_str());
            $$.place = strdup($3.place);
         }
		| ident L_PAREN R_PAREN { 
             $$.place = strdup("");
             $$.code = strdup("");   
            }
		| ident L_PAREN expressions R_PAREN {
            std::string func = $1.place;
            std::string temp;
            if (funcs.find(func) == funcs.end()) {
                
                printf("Calling undeclared function %s.\n", func.c_str());
            }
            std::string dst = new_temp();
            temp.append($3.code);
            temp += ". " + dst + "\ncall ";
            temp.append($1.place);
            temp += ", " + dst + "\n";
            $$.code = strdup(temp.c_str());
            $$.place = strdup(dst.c_str());

         }
		;

vars:   var {
            std::string temp;
            temp.append($1.code);
            if($1.arr){
                temp.append(".[]| ");
            }
            else{
                temp.append(".| ");
            }
            temp.append($1.place);
            temp.append("\n");
            $$.code = strdup(temp.c_str());
            $$.place = strdup("");
        }
		| var COMMA vars 
        {
            std::string temp;
            temp.append($1.code);
            if($1.arr){
                temp.append(".[]| ");
            }
            else{
                temp.append(".| ");
            }
            temp.append($1.place);
            temp.append("\n");
            temp.append($3.code);
            $$.code = strdup(temp.c_str());
            $$.place = strdup("");
        }
		;
	
var:              ident {

                    std::string temp;
                    std::string ident = $1.place;

                    // builds bottom was always coming undeclared variable error
                    if (funcs.find($1.place) == funcs.end()) {
                        funcs.insert($1.place);
                    }


                    if (funcs.find(ident) == funcs.end() && varTemp.find(ident) == varTemp.end()) {
                        printf("Error: Identifier %s is not declared\n", ident.c_str());
                    } else if (arrSize[ident] > 1) {
                        printf("Error: Did not provide index for array Identifier %s.\n", ident.c_str());
                    }
                    $$.code = strdup("");
                    $$.place = strdup(ident.c_str());
                    $$.arr = false;
                }
                | ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
                    
                    std::string temp;
                    std::string ident = $1.place;
                    if (funcs.find(ident) == funcs.end() && varTemp.find(ident) == varTemp.end()) {
                        printf("Error: Identifier %s is not declared\n", ident.c_str());
                    } else if (arrSize[ident] == 1) {
                        printf("Error: Provided index for non-array Identifier %s.\n", ident.c_str());
                    }
                    temp.append($1.place);
                    temp.append(",");
                    temp.append($3.place);
                    $$.code = strdup($3.code);
                    $$.place = strdup(temp.c_str());
                    $$.arr = true;
                } 
                ;

%%

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