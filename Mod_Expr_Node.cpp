#include "Mod_Expr_Node.h"

Mod_Expr_Node::Mod_Expr_Node()
    :
    prec(1)
{
    //ctor
}

Mod_Expr_Node::~Mod_Expr_Node()
{
    //dtor
}

int Mod_Expr_Node::eval(int n1, int n2)
{
    return n1 % n2;
}

void Mod_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Mod_Expr_Node(*this);
}

int Mod_Expr_Node::getPrec()
{
    return prec;
}

