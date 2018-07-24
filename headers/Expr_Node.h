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
        virtual int getPrec();
		virtual void setPrec(int);
		virtual void deleteThis() = 0;

	protected:
		int prec;
};

#endif // EXPR_NODE_H
