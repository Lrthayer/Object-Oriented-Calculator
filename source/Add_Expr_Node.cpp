#include "Add_Expr_Node.h"
#include <iostream>

Add_Expr_Node::Add_Expr_Node()
{
	//set protected int from Expr_Node prec
	this->prec = 0;
}

Add_Expr_Node::~Add_Expr_Node()
{
	std::cout << "add deleted\n";
}

void Add_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Add_Expr_Node(*this);
}
