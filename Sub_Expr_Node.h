#ifndef SUB_EXPR_NODE_H
#define SUB_EXPR_NODE_H

#include "Binary_Expr_Node.h"

//subtraction node for composite design
class Sub_Expr_Node : public Binary_Expr_Node
{
    public:
        Sub_Expr_Node();
        virtual ~Sub_Expr_Node();
        virtual void accept (Expr_Node_Visitor &v);

};

#endif // SUB_EXPR_NODE_H
