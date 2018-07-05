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
void Eval_Expr_Tree::Visit_Div_Expr_Node(const Div_Expr_Node& node)
{
    double numL, numR;
	right_ = node.right_;
    right_->accept(*this);
    numR = this->result();

	left_ = node.left_;
    left_->accept(*this);
    numL = this->result();

    result_ = numR / numL;
}

void Eval_Expr_Tree::Visit_Mult_Expr_Node(const Mult_Expr_Node& node)
{
    double numL, numR;
	right_ = node.right_;

    right_->accept(*this);
    numR = this->result();

	left_ = node.left_;
    left_->accept(*this);
    numL = this->result();

    result_ = numL * numR;
}

void Eval_Expr_Tree::Visit_Mod_Expr_Node(const Mod_Expr_Node& node)
{
    int numL, numR;
	right_ = node.right_;
    right_->accept(*this);
    numR = this->result();

	left_ = node.left_;
    left_->accept(*this);
    numL = this->result();

    result_ = numR % numL;
}

void Eval_Expr_Tree::Visit_Sub_Expr_Node(const Sub_Expr_Node& node)
{
    double numL, numR;
	right_ = node.right_;
    right_->accept(*this);
    numR = this->result();

	left_ = node.left_;
    left_->accept(*this);
    numL = this->result();

    result_ = numL - numR;
}

void Eval_Expr_Tree::Visit_Add_Expr_Node(const Add_Expr_Node& node)
{
    double numL, numR;
	right_ = node.right_;
    right_->accept(*this);
    numR = this->result();

	left_ = node.left_;
	if (left_ != nullptr)
		left_->accept(*this);
    numL = this->result();

    result_ = numL + numR;
}

void Eval_Expr_Tree::Visit_Number_Node( Number_Node& node)
{
    result_ = node.getVal();
	if (node.right_ != nullptr)
	{
		node.right_->left_ = new Number_Node(node.getVal());
		node.right_->accept(*this);
	}
}