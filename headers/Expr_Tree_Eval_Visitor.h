#ifndef EVAL_EXPR_TREE_H
#define EVAL_EXPR_TREE_H

#include "Expr_Node_Visitor.h"
#include "Add_Expr_Node.h"
#include "Sub_Expr_Node.h"
#include "Mult_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Div_Expr_Node.h"
#include "Number_Node.h"

//used for eval, after tree is built
class Expr_Tree_Eval_Visitor : public Expr_Node_Visitor
{
    public:
		Expr_Tree_Eval_Visitor();
        virtual ~Expr_Tree_Eval_Visitor();

        //Methods for visiting concrete nodes, visit left node, visit right node, then perform eval
        virtual void Visit_Add_Expr_Node(Add_Expr_Node &node);
        virtual void Visit_Sub_Expr_Node(Sub_Expr_Node &node);
        virtual void Visit_Mod_Expr_Node(Mod_Expr_Node &node);
        virtual void Visit_Mult_Expr_Node(Mult_Expr_Node &node);
        virtual void Visit_Div_Expr_Node(Div_Expr_Node &node);
        virtual void Visit_Number_Node( Number_Node &node);
        double result();

    private:
        double result_;

};

#endif // EVAL_EXPR_TREE_H
