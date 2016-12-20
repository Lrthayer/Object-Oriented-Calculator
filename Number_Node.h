#ifndef NUMBER_NODE_H
#define NUMBER_NODE_H

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

//number node for composite pattern
class Number_Node : public Expr_Node
{
    public:
        Number_Node(int n);
        virtual ~Number_Node();
        virtual void accept (Expr_Node_Visitor &v);
        int getVal();
    protected:
    private:
        int val;
};

#endif // NUMBER_NODE_H
