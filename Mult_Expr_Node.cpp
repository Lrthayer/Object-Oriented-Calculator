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

void Mult_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Mult_Expr_Node(*this);
}

int Mult_Expr_Node::getPrec()
{
    return prec;
}
