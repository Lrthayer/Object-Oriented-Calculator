#ifndef ADD_EXPR_NODE_H
#define ADD_EXPR_NODE_H

#include "Binary_Expr_Node.h"

//add node for composite design.
class Add_Expr_Node : public Binary_Expr_Node
{
    public:
        Add_Expr_Node();
        virtual ~Add_Expr_Node();
        virtual int eval(int num1, int num2);
        virtual void accept (Expr_Node_Visitor &v);
        virtual int getPrec();

    private:
        int prec;
};

#endif // ADD_EXPR_NODE_H
