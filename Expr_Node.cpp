#include "Expr_Node.h"

Expr_Node::Expr_Node()
{
    //ctor
}

Expr_Node::~Expr_Node()
{
    //dtor
}

int Expr_Node::getPrec()
{
	return this->prec;
}

void Expr_Node::setPrec(int newPrec)
{
	this->prec = newPrec;
}
