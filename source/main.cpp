#include <iostream>
#include <string>
#include <sstream>
#include <string>

#include <stdio.h>
#include "Expr_Node.h"
#include "Expr_Builder_Interface.h"
#include "Expr_Tree_Builder.h"
#include "Expr_Tree_Eval_Visitor.h"

//parse, call builder
void parse_expr(const std::string &infix)
{
    std::istringstream input(infix);
    std::string token;
	Expr_Tree_Builder b;
    b.start_expression();

    while(!input.eof())
    {
		if (input.eof())
			break;
        input >> token;
        if(token == "+")
        {
            b.build_add_operand();
        }
        else if(token == "-")
        {
            b.build_subtract_operand();
        }
        else if(token == "*")
        {
            b.build_multiplication_operand();
        }
        else if(token == "/")
        {
            b.build_division_operand();
        }
        else if(token == "%")
        {
            b.build_modular_operand();
        }
		else if (token == "(")
		{
			b.build_open_parentheses();
		}
		else if (token == ")")
		{
			b.build_close_parenteses();
		}
        else if(token == "")
        {
            std::cout << "space";
        }
        else
        {
            b.build_number(std::stod(token));
        }
    }
	//finish expression
	b.build_expression();
    Expr_Tree_Eval_Visitor eval;
    Expr_Node *evalTree = b.get_expression();
    evalTree->accept(eval);
    std::cout << "\n" << eval.result() << "\n";
}

int main()
{
	// get input from STDIN concrete factory
	bool running = true;
	std::string userInput;
	parse_expr("1 + ( 3 * 3 ) * 2");
	parse_expr("( 4 * ( 2 - 2 ) ) + 10 * 2 - 25");
	parse_expr("( 2 + 2 ) / 4");
	parse_expr("3 * 8 / 6 - 4");
	while(running)
    {
		bool keepGoing = true;
		while (keepGoing)
		{
			std::cout << "Please give an expression(form of 1 / 2 + 4)\n";
			std::getline(std::cin, userInput);

			if (userInput == "QUIT" || userInput == "quit")
			{
				keepGoing = false;
				return 0;
			}

			parse_expr(userInput);
		}
    }
    return 0;
}

