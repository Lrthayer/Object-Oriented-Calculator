#ifndef EVAL_EXPR_TREE_H
#define EVAL_EXPR_TREE_H

#include "Stack.h"
#include "Expr_Node_Visitor.h"
#include "Add_Expr_Node.h"
#include "Sub_Expr_Node.h"
#include "Mult_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Div_Expr_Node.h"
#include "Number_Node.h"

//used for eval, after tree is built
class Eval_Expr_Tree : public Expr_Node_Visitor
{
    public:
        Eval_Expr_Tree();
        virtual ~Eval_Expr_Tree();

        //Methods for visiting concrete nodes, visit left node, visit right node, then perform eval
        virtual void Visit_Add_Expr_Node(const Add_Expr_Node &node);
        virtual void Visit_Sub_Expr_Node(const Sub_Expr_Node &node);
        virtual void Visit_Mod_Expr_Node(const Mod_Expr_Node &node);
        virtual void Visit_Mult_Expr_Node(const Mult_Expr_Node &node);
        virtual void Visit_Div_Expr_Node(const Div_Expr_Node &node);
        virtual void Visit_Number_Node( Number_Node &node);
        double result();

    protected:
    private:
        double result_;
        Expr_Node *left_;
        Expr_Node *right_;

};

#endif // EVAL_EXPR_TREE_H
