# Basic-Calculator
Simple Calculator

This recursive descent parser follows the BNF grammar:  


	<expr> ::= <term> | <term> "+" <expr> | <variable> "=" <expr>
	<term> ::= <factor> | <term> "*" <factor>
	<factor> ::= <constant> | <variable> | "(" <expr> ")"
	<variable> ::= "x" | "y" | "z"
	<constant> ::= <digit> | <digit> <constant>
	<digit> ::= "0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"
 


to return mathematic expressions input through the terminal. It currently supports addition and multiplication as well as variable assignment to 'x', 'y', or 'z' for further use in the session.

example input could be:     1 + 1  
                            2 * 5  
                            z = 5  
then in a subsequent line   z + 4 would yield 9
