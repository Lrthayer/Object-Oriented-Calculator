#ifndef EXPR_NODE_H
#define EXPR_NODE_H

class Expr_Node_Visitor;
//base class, used for interface and for base class storing
class Expr_Node
{
    public:
        Expr_Node();
        virtual ~Expr_Node();
        virtual void accept(Expr_Node_Visitor &v) = 0;
        Expr_Node * right_;
        Expr_Node * left_;
        virtual int getPrec();

    private:
};

#endif // EXPR_NODE_H
