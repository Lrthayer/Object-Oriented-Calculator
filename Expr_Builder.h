#ifndef EXPR_BUILDER_H
#define EXPR_BUILDER_H

#include "Expr_Node.h"

//Interface for Expr_Tree_Builder
class Expr_Builder
{
    public:
        Expr_Builder();
        virtual ~Expr_Builder();
        virtual void start_expression (void);
        virtual void build_number (int n) = 0;
        virtual void build_add_operand (void) = 0;
        virtual void build_subtract_operand (void) = 0;
        virtual void build_modular_operand (void) = 0;
        virtual void build_multiplication_operand (void) = 0;
        virtual void build_division_operand (void) = 0;
       // virtual void build_open_parenthesis (void) = 0;
       // virtual void build_close_parenthesis (void) = 0;
        // get the current expression
        virtual Expr_Node * get_expression (void) = 0;
    protected:
    private:
};

#endif // EXPR_BUILDER_H
