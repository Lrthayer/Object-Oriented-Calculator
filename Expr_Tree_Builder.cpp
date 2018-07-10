#include "Expr_Tree_Builder.h"
#include <iostream>
#include <vector>

Expr_Tree_Builder::Expr_Tree_Builder()
    :
    root(0)
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

void Expr_Tree_Builder::build_expression(Expr_Node *lastNode)
{

	while (n_.size() != 0)
	{
		if (n_.size() < 2)
			break;
		Binary_Expr_Node * expression = nullptr;
		if (o_.empty())
			expression = (Binary_Expr_Node*)lastNode;
		else
		{
			expression = (Binary_Expr_Node*)o_.top();
			o_.pop();
		}

		/*if (o_.size() > 0)
		{
			expression->right_ = this->o_.top();
			this->o_.pop();
		}
		else
		{*/
			expression->right_ = (this->n_.front());
			this->n_.pop_front();
		//}

		if (n_.size() == o_.size())
		{
			//n_.push_front(tree_->getTree());
		}

		expression->left_ = (this->n_.front());
		this->n_.pop_front();

		// Comment: The accept method should be called from the visitor and not the builder.
		/*
		* I removed the statement "expression->accept(evaluate_tree);" as it did not belong in the builder.
		*/


		//we need to make sure the current tree doesn't have a case where a higher prec ended up being the root of a node
		//make sure left isn't a number
		if (!static_cast<Number_Node*>(expression->left_))
		{
			std::cout << "!";

			if (static_cast<Binary_Expr_Node*>(expression->left_) && expression->getPrec() > expression->left_->getPrec())
			{
				//temp store current expression
				Expr_Node *t = expression;

				//remove old root's left side, essentially deparenting it
				t->left_ = nullptr;

				//grap old leaf's right leaf
				Expr_Node *t2 = expression->left_->right_;

				//set that the old root's left side
				t->left_ = t2;

				//push the bottom node up
				expression = (Binary_Expr_Node*)expression->left_;

				expression->left_ = t;
			}
		}
		
		this->n_.push_front(expression);
		tree_->setTree(expression);
	}
}

//take all the operators and numbers that have been set according to precedence and build the tree
Expr_Node* Expr_Tree_Builder::get_expression(void)
{
	return this->tree_->getTree();
	/*
	while (!n_.empty() && !o_.empty())
	{
		temp = o_.top();
		o_.pop();
		temp->right_ = n_.back();
		n_.pop_back();
		temp->left_ = n_.back();
		n_.pop_back();
		n_.push_front(temp);
	}
	Expr_Node *t = n_.back();
	n_.pop_back();
	tree_->setTree(t);
	return tree_->getTree();
	*/
/*
    bool buildingTree = true;
    while(buildingTree)
    {
        if (o_.is_empty())
        {
			if (n_.is_empty())
				tree_->setTree(root);
			else
				tree_->setTree(n_.pop());
            buildingTree = false;
            return tree_->getTree();
        }
        else
        {

            temp = o_.pop();
			if (!n_.is_empty())
				temp->left_ = n_.pop();
			if (!n_.is_empty())
				temp->right_ = n_.pop();

			if (root == nullptr)
				root = temp;
			else
			{
				Expr_Node *t;
				t = root->right_;
				while (t->right_ != nullptr)
				{
					t = t->right_;
				}
				t->right_ = temp;
				std::cout << "just used for breakpoint";
			}
        }
    }*/
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
    bool checking = true;
    while (checking)
    {
        if(o_.empty())
        {
            o_.push(node);
            checking = false;
        }
		else if (node->getPrec() > o_.top()->getPrec())
		{
			o_.push(node);
			checking = false;
		}
        else
        {
			checking = false;
			build_expression(node);
			o_.push(node);
			/*
			std::vector<Expr_Node*> moving;
            while ( !o_.empty() && node->getPrec() > o_.top()->getPrec())
            {
				moving.push_back(o_.top());
				o_.pop();

				//if this makes the stack empty, swap two entries
				//if (o_.empty())
				//{
				//	o_.push(node);
				//	o_.push(moving.at(0));
				//	moving.pop_back();
				//}

    //            temp = o_.top();
				//o_.pop();
    //            temp->left_ = n_.back();
				//n_.pop_back();
    //            temp->right_ = n_.back();
				//n_.pop_back();
    //            n_.push_back(temp);
				//o_.push(node);
            }
			o_.push(node);
			for (int i = 0; i < moving.size(); i++)
			{
				o_.push(moving.at(i));
			}
			checking = false;
			*/
        }
    }
}
