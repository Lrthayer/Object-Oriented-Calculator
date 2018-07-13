#include <iostream>
#include "Eval_Expr_Tree.h"

Eval_Expr_Tree::Eval_Expr_Tree()
    :
    result_(0)
{
    //ctor
}

Eval_Expr_Tree::~Eval_Expr_Tree()
{
    //dtor
}
double Eval_Expr_Tree::result()
{
    return result_;
}
//eval the left and right then return result.
void Eval_Expr_Tree::Visit_Div_Expr_Node(Div_Expr_Node& node)
{
    double numL, numR;
	node.getRightLeaf()->accept(*this);
    numR = this->result();

	node.getLeftLeaf()->accept(*this);
    numL = this->result();

    result_ = numL / numR;
}

void Eval_Expr_Tree::Visit_Mult_Expr_Node(Mult_Expr_Node& node)
{
    double numL, numR;
	node.getRightLeaf()->accept(*this);

    numR = this->result();

	node.getLeftLeaf()->accept(*this);
    numL = this->result();

    result_ = numL * numR;
}

void Eval_Expr_Tree::Visit_Mod_Expr_Node(Mod_Expr_Node& node)
{
    int numL, numR;
	node.getRightLeaf()->accept(*this);
    numR = this->result();

	node.getLeftLeaf()->accept(*this);
    numL = this->result();

    result_ = numR % numL;
}

void Eval_Expr_Tree::Visit_Sub_Expr_Node(Sub_Expr_Node& node)
{
    double numL, numR;
	node.getRightLeaf()->accept(*this);
    numR = this->result();

	node.getLeftLeaf()->accept(*this);
    numL = this->result();

    result_ = numL - numR;
}

void Eval_Expr_Tree::Visit_Add_Expr_Node(Add_Expr_Node& node)
{
    double numL, numR;
	node.getRightLeaf()->accept(*this);
    numR = this->result();

	node.getLeftLeaf()->accept(*this);
    numL = this->result();

    result_ = numL + numR;
}

void Eval_Expr_Tree::Visit_Number_Node(Number_Node& node)
{
    result_ = node.getVal();
}
