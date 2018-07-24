#ifndef EXPR_NODE_VISITOR_H
#define EXPR_NODE_VISITOR_H

class Add_Expr_Node;
class Sub_Expr_Node;
class Mod_Expr_Node;
class Mult_Expr_Node;
class Div_Expr_Node;
class Number_Node;
class Exponent_Expr_Node;

//Visitor for Expr_Eval_Tree, stores all methods.
class Expr_Node_Visitor
{
    public:
        Expr_Node_Visitor();
        virtual ~Expr_Node_Visitor();

        //Methods for visiting concrete nodes
        virtual void Visit_Add_Expr_Node(Add_Expr_Node &node) = 0;
        virtual void Visit_Sub_Expr_Node(Sub_Expr_Node &node) = 0;
        virtual void Visit_Div_Expr_Node(Div_Expr_Node &node) = 0;
        virtual void Visit_Mult_Expr_Node(Mult_Expr_Node &node) = 0;
        virtual void Visit_Mod_Expr_Node(Mod_Expr_Node &node) = 0;
		virtual void Visit_Exponent_Expr_Node(Exponent_Expr_Node &node) = 0;
        virtual void Visit_Number_Node( Number_Node &node) = 0;

    private:
};

#endif // EXPR_NODE_VISITOR_H
