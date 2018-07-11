#include "Sub_Expr_Node.h"

Sub_Expr_Node::Sub_Expr_Node()
{
	//set protected int from Expr_Node prec
	this->prec = 0;
}

Sub_Expr_Node::~Sub_Expr_Node()
{

}

void Sub_Expr_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Sub_Expr_Node(*this);
}