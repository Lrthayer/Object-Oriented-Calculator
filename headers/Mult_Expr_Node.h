#ifndef MULT_EXPR_NODE_H
#define MULT_EXPR_NODE_H

#include "Binary_Expr_Node.h"

//mult node for composite design
class Mult_Expr_Node : public Binary_Expr_Node
{
    public:
        Mult_Expr_Node();
        virtual ~Mult_Expr_Node();
		virtual void accept (Expr_Node_Visitor &v);
};

#endif // MULT_EXPR_NODE_H
