#include "Exponent_Expr_Node.h"

Exponent_Expr_Node::Exponent_Expr_Node()
{
	//set protected int from Expr_Node prec
	this->prec = 2;
}


Exponent_Expr_Node::~Exponent_Expr_Node()
{
}

void Exponent_Expr_Node::accept(Expr_Node_Visitor& v)
{
	v.Visit_Exponent_Expr_Node(*this);
}
