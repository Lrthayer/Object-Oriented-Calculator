#include "Binary_Expr_Node.h"

Binary_Expr_Node::Binary_Expr_Node()
{

}

Binary_Expr_Node::~Binary_Expr_Node()
{
}

Expr_Node * Binary_Expr_Node::getRightLeaf()
{
	return this->rightLeaf;
}

void Binary_Expr_Node::setRightLeaf(Expr_Node * newLeaf)
{
	this->rightLeaf = newLeaf;
}

Expr_Node * Binary_Expr_Node::getLeftLeaf()
{
	return this->leftLeaf;
}

void Binary_Expr_Node::setLeftLeaf(Expr_Node * newLeaf)
{
	this->leftLeaf = newLeaf;
}
