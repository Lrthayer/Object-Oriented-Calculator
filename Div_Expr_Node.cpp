#include <iostream>
#include "Div_Expr_Node.h"

Div_Expr_Node::Div_Expr_Node()
    :
    prec(1)
{

}

Div_Expr_Node::~Div_Expr_Node()
{

}

//if this accepts call eval on eval tree
void Div_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Div_Expr_Node(*this);
}

int Div_Expr_Node::getPrec()
{
    return prec;
}

