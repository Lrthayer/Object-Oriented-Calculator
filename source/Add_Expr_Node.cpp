#include "Add_Expr_Node.h"

Add_Expr_Node::Add_Expr_Node()
{
	//set protected int from Expr_Node prec
	this->prec = 0;
}

Add_Expr_Node::~Add_Expr_Node()
{
}

void Add_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Add_Expr_Node(*this);
}

