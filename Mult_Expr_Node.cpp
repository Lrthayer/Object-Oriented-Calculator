#include "Mult_Expr_Node.h"

Mult_Expr_Node::Mult_Expr_Node()
    :
    prec(1)
{
    //ctor
}

Mult_Expr_Node::~Mult_Expr_Node()
{
    //dtor
}

int Mult_Expr_Node::eval(int num1, int num2)
{
	return num1 * num2;
}

void Mult_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Mult_Expr_Node(*this);
}

int Mult_Expr_Node::getPrec()
{
    return prec;
}
