CC=g++ # define the compiler to use
TARGET=calc # define the name of the executable
SOURCES=main.cpp Add_Expr_Node.cpp Binary_Expr_Node.cpp Div_Expr_Node.cpp Eval_Expr_Tree.cpp Expr_Builder.cpp Expr_Node.cpp Expr_Node_Visitor.cpp Expr_Tree.cpp Expr_Tree_Builder.cpp Mod_Expr_Node.cpp Mult_Expr_Node.cpp Number_Node.cpp Sub_Expr_Node.cpp
CFLAGS=
LFLAGS=-fprofile-arcs -ftest-coverage

################################################################################
### DO NOT EDIT THE FOLLOWING LINES ############################################

# define list of objects
OBJSC=$(SOURCES:.c=.o)
OBJS=$(OBJSC:.cpp=.o)

# the target is obtained linking all .o files
all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

purge: clean
	rm -f $(TARGET)

clean:
	rm -f *.o

################################################################################
################################################################################
