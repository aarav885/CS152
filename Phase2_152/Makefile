# parse: miniL.lex miniL.y
# 	bison -v -d --file-prefix=y miniL.y
# 	flex miniL.lex
# 	gcc -o parser y.tab.c lex.yy.c -lfl

# test:
# 	cat mytest.min | parser

# clean:
# 	rm -f lex.yy.c y.tab.* y.output *.o parser 
CFLAGS = -g -Wall -ansi -pedantic

Phase3: miniL.lex miniL.y
	bison -d -v miniL.y
	flex miniL.lex
	g++ $(CFLAGS) -std=c++11 lex.yy.c miniL.tab.c -lfl -o Phase3
	rm -f lex.yy.c *.output *.tab.c *.tab.h

test: Phase3
	cat ./primes.min | ./Phase3 > ./primes.mil 
	cat ./mytest.min | ./Phase3 > ./mytest.mil
	cat ./fibonacci.min | ./Phase3 > ./fibonacci.mil
	cat ./errors.min | ./Phase3 > ./errors.mil