#ifndef MOD_EXPR_NODE_H
#define MOD_EXPR_NODE_H

#include "Binary_Expr_Node.h"

//mod node for composite design
class Mod_Expr_Node : public Binary_Expr_Node
{
    public:
        Mod_Expr_Node();
        virtual ~Mod_Expr_Node();
        virtual void accept (Expr_Node_Visitor &v);
};

#endif // MOD_EXPR_NODE_H
