#include "Mod_Expr_Node.h"

Mod_Expr_Node::Mod_Expr_Node()
{
    //set protected int from Expr_Node prec
	this->prec = 1;
}

Mod_Expr_Node::~Mod_Expr_Node()
{
    //dtor
}

void Mod_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Mod_Expr_Node(*this);
}

