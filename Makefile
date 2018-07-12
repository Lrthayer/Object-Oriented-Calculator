GCC=gcc
CXXFLAGS=-o -std=c++0x

hellomake:
	$(GCC) $(CXXFLAGS) main.cpp Expr_Node.cpp Add_Expr_Node.cpp Binary_Expr_Node.cpp Div_Expr_Node.cpp Eval_Expr_Tree.cpp Expr_Builder.cpp Expr_Node_Visitor.cpp Expr_Tree.cpp Expr_Tree_Builder.cpp Mod_Expr_Node.cpp Mult_Expr_Node.cpp Number_Node.cpp Sub_Expr_Node.cpp -I.
