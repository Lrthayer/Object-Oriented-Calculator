#ifndef NUMBER_NODE_H
#define NUMBER_NODE_H

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

//number node for composite pattern
class Number_Node : public Expr_Node
{
    public:
        Number_Node(double n);
        virtual ~Number_Node();
        virtual void accept (Expr_Node_Visitor &v);
        double getVal();
    protected:
    private:
        double val;
};

#endif // NUMBER_NODE_H
