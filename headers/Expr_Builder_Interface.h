#ifndef EXPR_BUILDER_INTERFACE_H
#define EXPR_BUILDER_INTERFACE_H

#include "Expr_Node.h"

//Interface for Expr_Tree_Builder
class Expr_Builder_Interface
{
    public:
		Expr_Builder_Interface();
        virtual ~Expr_Builder_Interface();
        virtual void start_expression (void);
        virtual void build_number (double n) = 0;
        virtual void build_add_operand (void) = 0;
        virtual void build_subtract_operand (void) = 0;
        virtual void build_modular_operand (void) = 0;
        virtual void build_multiplication_operand (void) = 0;
        virtual void build_division_operand (void) = 0;

        // get the current expression
        virtual Expr_Node *get_expression (void) = 0;
    protected:
    private:
};

#endif // EXPR_BUILDER_H
