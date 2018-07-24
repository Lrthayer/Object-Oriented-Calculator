#include <iostream>
#include "Expr_Tree_Eval_Visitor.h"
#include <math.h>

Expr_Tree_Eval_Visitor::Expr_Tree_Eval_Visitor()
    :
    result_(0)
{
    //ctor
}

Expr_Tree_Eval_Visitor::~Expr_Tree_Eval_Visitor()
{
    //dtor
}
double Expr_Tree_Eval_Visitor::result()
{
    return result_;
}
//eval the left and right then return result.
void Expr_Tree_Eval_Visitor::Visit_Div_Expr_Node(Div_Expr_Node& node)
{
    double numL, numR;
	node.getRightLeaf()->accept(*this);
    numR = this->result();

	node.getLeftLeaf()->accept(*this);
    numL = this->result();

    result_ = numL / numR;
}

void Expr_Tree_Eval_Visitor::Visit_Exponent_Expr_Node(Exponent_Expr_Node & node)
{
	double numL, numR;
	node.getRightLeaf()->accept(*this);
	numR = this->result();

	node.getLeftLeaf()->accept(*this);
	numL = this->result();

	result_ = pow(numL,numR);

}

void Expr_Tree_Eval_Visitor::Visit_Mult_Expr_Node(Mult_Expr_Node& node)
{
    double numL, numR;
	node.getRightLeaf()->accept(*this);

    numR = this->result();

	node.getLeftLeaf()->accept(*this);
    numL = this->result();

    result_ = numL * numR;
}

void Expr_Tree_Eval_Visitor::Visit_Mod_Expr_Node(Mod_Expr_Node& node)
{
    int numL, numR;
	node.getRightLeaf()->accept(*this);
    numR = this->result();

	node.getLeftLeaf()->accept(*this);
    numL = this->result();

    result_ = numR % numL;
}

void Expr_Tree_Eval_Visitor::Visit_Sub_Expr_Node(Sub_Expr_Node& node)
{
    double numL, numR;
	node.getRightLeaf()->accept(*this);
    numR = this->result();

	node.getLeftLeaf()->accept(*this);
    numL = this->result();

    result_ = numL - numR;
}

void Expr_Tree_Eval_Visitor::Visit_Add_Expr_Node(Add_Expr_Node& node)
{
    double numL, numR;
	node.getRightLeaf()->accept(*this);
    numR = this->result();

	node.getLeftLeaf()->accept(*this);
    numL = this->result();

    result_ = numL + numR;
}

void Expr_Tree_Eval_Visitor::Visit_Number_Node(Number_Node& node)
{
    result_ = node.getVal();
}
