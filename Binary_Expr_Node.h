#ifndef BINARY_EXPR_NODE_H
#define BINARY_EXPR_NODE_H

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"


//used for binary nodes derives from expr_node for base class storing.
class Binary_Expr_Node : public Expr_Node
{
    public:
        Binary_Expr_Node();
        virtual ~Binary_Expr_Node();
        virtual void accept(Expr_Node_Visitor &v)= 0;
        virtual int eval();
    protected:

    private:
};

#endif // BINARY_EXPR_NODE_H
