#ifndef EXPR_TREE_H
#define EXPR_TREE_H

#include "Binary_Expr_Node.h"

//product of the build pattern, stores root for eval.
class Expr_Tree
{
    public:
        Expr_Tree();
        ~Expr_Tree();
        Expr_Node* getTree();
        void setTree(Expr_Node*);
		void deleteTree(Binary_Expr_Node*);
		void deleteTree(Number_Node*);

    private:
        Expr_Node *root_;
};

#endif // EXPR_TREE_H
