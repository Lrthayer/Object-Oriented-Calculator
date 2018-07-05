#include "Expr_Tree_Builder.h"

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

//take all the operators and numbers that have been set according to precedence and build the tree
Expr_Node* Expr_Tree_Builder::get_expression(void)
{
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
			}
        }
    }
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

void Expr_Tree_Builder::build_number(int n)
{
    Number_Node *nNode = new Number_Node(n);
    n_.push(nNode);

}

//sort operators in stack according to precedence, if operator empty just pass node, if prec occures set current stack top to previous numbers, else nothing
void Expr_Tree_Builder::checkPrec(Expr_Node *node)
{
    bool checking = true;
    while (checking)
    {
        if(o_.is_empty())
        {
            o_.push(node);
            checking = false;
        }
        else
        {
            if(node->getPrec() > o_.top()->getPrec())
            {
                temp = o_.pop();
                temp->left_ = n_.pop();
                temp->right_ = n_.pop();
                n_.push(temp);
				o_.push(node);
            }
            else if (node->getPrec() == o_.top()->getPrec())
            {
				o_.push(node);
                checking = false;
            }
			else
			{
				checking = false;
			}
        }
    }
}
