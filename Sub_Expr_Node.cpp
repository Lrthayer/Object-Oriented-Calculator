#include "Sub_Expr_Node.h"
#include <iostream>

Sub_Expr_Node::Sub_Expr_Node()
    :
    prec(0)
{

}

Sub_Expr_Node::~Sub_Expr_Node()
{

}

int Sub_Expr_Node::eval(int n1, int n2)
{
    return n1-n2;
}

void Sub_Expr_Node::accept(Expr_Node_Visitor& v)
{
    std::cout << "TEST!";
    v.Visit_Sub_Expr_Node(*this);
}

int Sub_Expr_Node::getPrec()
{
    return prec;
}



