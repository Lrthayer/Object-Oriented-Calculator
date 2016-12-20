#include "Add_Expr_Node.h"

Add_Expr_Node::Add_Expr_Node()
    :
    prec(0)
{
}

Add_Expr_Node::~Add_Expr_Node()
{
}

int Add_Expr_Node::eval(int n1, int n2)
{
    return n1 + n2;
}

void Add_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Add_Expr_Node(*this);
}

int Add_Expr_Node::getPrec()
{
    return prec;
}

