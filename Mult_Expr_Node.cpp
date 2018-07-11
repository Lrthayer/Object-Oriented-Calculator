#include "Mult_Expr_Node.h"

Mult_Expr_Node::Mult_Expr_Node()
{
	//set protected int from Expr_Node prec
	this->prec = 1;
}

Mult_Expr_Node::~Mult_Expr_Node()
{
    //dtor
}

void Mult_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Mult_Expr_Node(*this);
}
