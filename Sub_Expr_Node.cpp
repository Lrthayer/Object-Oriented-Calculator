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

void Sub_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Sub_Expr_Node(*this);
}

int Sub_Expr_Node::getPrec()
{
    return prec;
}