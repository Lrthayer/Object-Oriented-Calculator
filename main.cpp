#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "Expr_Node.h"
#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"


//parse, call builder
bool parse_expr(const std::string &infix, Expr_Builder &b)
{
    std::istringstream input(infix);
    std::string token;
    b.start_expression();

    while(!input.eof())
    {
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
        else if(token == "")
        {
            std::cout << "space";
        }
        else
        {
            b.build_number(std::stoi(token));
        }
    }
    Eval_Expr_Tree eval;
    Expr_Node *evalTree = b.get_expression();
    evalTree->accept(eval);
    std::cout << "d\n" << eval.result() << "\n";

    return true;
}

int main()
{
	// get input from STDIN concrete factory
	bool running = true;
	char userInput[1000];
	while(running)
    {
        std::cout << "Please give an expression (form of 1 / 2 + 4)\n";
        std::fgets(userInput, 1000, stdin);
        std::string infix = userInput;
        if(infix == "Quit\n")
        {
            running = false;
        }
        else
        {
            Expr_Tree_Builder b;
            parse_expr(infix, b);
        }
    }
    return 0;
}
