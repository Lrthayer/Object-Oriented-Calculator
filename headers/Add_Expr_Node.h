#ifndef ADD_EXPR_NODE_H
#define ADD_EXPR_NODE_H

#include "Binary_Expr_Node.h"

//add node for composite design.
class Add_Expr_Node : public Binary_Expr_Node
{
    public:
        Add_Expr_Node();
        virtual ~Add_Expr_Node();
        virtual void accept (Expr_Node_Visitor &v);
};

#endif // ADD_EXPR_NODE_H
