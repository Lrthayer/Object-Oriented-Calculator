#ifndef EXPONENT_NODE_H
#define EXPONENT_NODE_H

#include "Binary_Expr_Node.h"

class Exponent_Expr_Node : public Binary_Expr_Node
{
public:
	Exponent_Expr_Node();
	~Exponent_Expr_Node();
	virtual void accept(Expr_Node_Visitor &v);
};

#endif
