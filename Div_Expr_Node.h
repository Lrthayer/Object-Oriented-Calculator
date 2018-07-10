#ifndef DIV_EXPR_NODE_H
#define DIV_EXPR_NODE_H

#include "Binary_Expr_Node.h"

//division node for composite design
class Div_Expr_Node : public Binary_Expr_Node
{
    public:
        Div_Expr_Node();
        virtual ~Div_Expr_Node();

        virtual void accept (Expr_Node_Visitor &v);
        virtual int getPrec();

    private:
        int prec;
};

#endif // DIV_EXPR_NODE_H
