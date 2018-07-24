#include "Expr_Tree.h"

Expr_Tree::Expr_Tree()
{
    //ctor
}

Expr_Tree::~Expr_Tree()
{		
	deleteTree(static_cast<Binary_Expr_Node*>(root_));
}

Expr_Node* Expr_Tree::getTree()
{
    return root_;
}

void Expr_Tree::setTree(Expr_Node *r)
{
    root_ = r;
}

void Expr_Tree::deleteTree(Binary_Expr_Node *node)
{
	if (node == nullptr) return;

	/* first delete both subtrees */
	if (node->getRightLeaf() != nullptr)
	{
		node->getRightLeaf()->deleteThis();
	}

	if (node->getLeftLeaf() != nullptr)
	{
		node->getLeftLeaf()->deleteThis();
	}

	delete node;
}

void Expr_Tree::deleteTree(Number_Node *)
{
}
