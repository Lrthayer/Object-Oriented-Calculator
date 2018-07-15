#include "Expr_Tree_Builder.h"
#include <iostream>
#include <vector>

Expr_Tree_Builder::Expr_Tree_Builder()
    :
	inParentheses(0)
{
    //ctor
}

Expr_Tree_Builder::~Expr_Tree_Builder()
{
    //dtor
}

//start the expression by creating the tree to start building
void Expr_Tree_Builder::start_expression(void)
{
    this->tree_ = new Expr_Tree();
}

void Expr_Tree_Builder::build_expression()
{
	Binary_Expr_Node *lastOperator = nullptr;
	while (n_.size() != 0)
	{
		//if there are less than 2 items left in the operands stack, we know there isn't enough to build a binary expression
		if (n_.size() < 2)
			break;

		Binary_Expr_Node * expression = (Binary_Expr_Node*)o_.top();
		if (lastOperator && expression->getPrec() > lastOperator->getPrec())
			break;
		lastOperator = expression;

		o_.pop();

		expression->setRightLeaf(this->n_.front());
		this->n_.pop_front();

		expression->setLeftLeaf(this->n_.front());
		this->n_.pop_front();

		this->n_.push_front(expression);
		tree_->setTree(expression);
	}
}

void Expr_Tree_Builder::finish_expression()
{
	while (n_.size() != 0)
	{
		//if there are less than 2 items left in the operands stack, we know there isn't enough to build a binary expression
		if (n_.size() < 2)
			break;

		Binary_Expr_Node * expression = (Binary_Expr_Node*)o_.top();
		o_.pop();

		expression->setRightLeaf(this->n_.front());
		this->n_.pop_front();

		expression->setLeftLeaf(this->n_.front());
		this->n_.pop_front();

		this->n_.push_front(expression);
		tree_->setTree(expression);
	}
}

//take all the operators and numbers that have been set according to precedence and build the tree
Expr_Node* Expr_Tree_Builder::get_expression(void)
{
	return this->tree_->getTree();
}

//create the nodes to be used to create the tree
void Expr_Tree_Builder::build_division_operand(void)
{
    Div_Expr_Node *node = new Div_Expr_Node();
    checkPrec(node);
}

void Expr_Tree_Builder::build_multiplication_operand(void)
{
    Mult_Expr_Node *node = new Mult_Expr_Node();
    checkPrec(node);
}

void Expr_Tree_Builder::build_modular_operand(void)
{
    Mod_Expr_Node *node = new Mod_Expr_Node();
    checkPrec(node);
}

void Expr_Tree_Builder::build_subtract_operand(void)
{
    Sub_Expr_Node *node = new Sub_Expr_Node();
    checkPrec(node);
}

void Expr_Tree_Builder::build_open_parentheses(void)
{
	this->inParentheses += 3;
}

void Expr_Tree_Builder::build_close_parenteses(void)
{
	this->inParentheses -= 3;
}

void Expr_Tree_Builder::build_add_operand(void)
{
    Add_Expr_Node *node = new Add_Expr_Node();
    checkPrec(node);
}

void Expr_Tree_Builder::build_number(double n)
{
    Number_Node *nNode = new Number_Node(n);
    n_.push_front(nNode);

}

//sort operators in stack according to precedence, if operator empty just pass node, if prec occures set current stack top to previous numbers, else nothing
void Expr_Tree_Builder::checkPrec(Expr_Node *node)
{
	//if in () increase operator precedence by number of times it is encapsulated by parentheses
	if (inParentheses > 0)
	{
		node->setPrec(node->getPrec() + inParentheses);
	}

    if(o_.empty())
    {
        o_.push(node);
    }

	else
	{
		bool checkingPrec = true;
		while (checkingPrec)
		{
			if (node->getPrec() > o_.top()->getPrec())
			{
				checkingPrec = false;
				o_.push(node);
			}
			else
			{
				build_expression();
				if (o_.empty())
					checkingPrec = false;
				o_.push(node);
			}
		}
	}
}

