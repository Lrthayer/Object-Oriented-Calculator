#ifndef MULT_EXPR_NODE_H
#define MULT_EXPR_NODE_H

#include "Binary_Expr_Node.h"

//mult node for composite design
class Mult_Expr_Node : public Binary_Expr_Node
{
    public:
        Mult_Expr_Node();
        virtual ~Mult_Expr_Node();
        virtual int eval(int num1, int num2);
        virtual void accept (Expr_Node_Visitor &v);
        virtual int getPrec();

    private:
        int prec;
};

#endif // MULT_EXPR_NODE_H
