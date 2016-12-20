#ifndef EXPR_TREE_BUILDER_H
#define EXPR_TREE_BUILDER_H

#include "Expr_Builder.h"
#include "Expr_Tree.h"
#include "Stack.h"
#include "Div_Expr_Node.h"
#include "Mult_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Add_Expr_Node.h"
#include "Sub_Expr_Node.h"
#include "Number_Node.h"

//buildes Expr_Tree
class Expr_Tree_Builder : public Expr_Builder
{
    public:
        Expr_Tree_Builder();
        virtual ~Expr_Tree_Builder();
        virtual void start_expression();
        virtual void build_number(int n);
        virtual void build_add_operand();
        virtual void build_division_operand();
        virtual void build_multiplication_operand();
        virtual void build_modular_operand();
        virtual void build_subtract_operand();
        void checkPrec(Expr_Node *node);
        Expr_Node *get_expression();

    private:
        Expr_Tree *tree_;
        Expr_Node *root;
        Expr_Node *temp;
        Expr_Node *tempRoot;
        Stack<Expr_Node*> o_;
        Stack<Expr_Node*> n_;
};

#endif // EXPR_TREE_BUILDER_H
