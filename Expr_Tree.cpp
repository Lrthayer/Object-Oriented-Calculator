#include "Expr_Tree.h"

Expr_Tree::Expr_Tree()
{
    //ctor
}

Expr_Tree::~Expr_Tree()
{
    //dtor
}

Expr_Node* Expr_Tree::getTree()
{
    return root_;
}

void Expr_Tree::setTree(Expr_Node *r)
{
    root_ = r;
}
