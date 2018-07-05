#include <iostream>
#include "Number_Node.h"

Number_Node::Number_Node(double n)
:
val(n)
{

}

Number_Node::~Number_Node()
{
}

void Number_Node::accept(Expr_Node_Visitor& v)
{
    v.Visit_Number_Node(*this);
}

double Number_Node::getVal()
{
    return val;
}
