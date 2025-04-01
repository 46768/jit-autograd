#ifndef MATH_IR_OPERATOR_H_
#define MATH_IR_OPERATOR_H_

#include <stdlib.h>

typedef enum {
	// Values
	Constant,
	Variable,

	// Arithmetic operators
	Add,
	Sub,
	Mul,
	Div,
} MathIROPEnum;

typedef enum {
	Int,
	Float,
	Node,
} MathIRTypeEnum;

typedef struct {
	size_t argc;
	void** argv; // Can be int, float, or another node
	MathIRTypeEnum* argt;
} MathIROPArgs;

typedef struct {
	MathIROPEnum type;
	MathIROPArgs* args;
} MathIROPNode;

// Node Deconstructor

void irop_free_node(MathIROPNode*);

// Node constructors

MathIROPNode* irop_constant_long(int);
MathIROPNode* irop_constant_float(float);

MathIROPNode* irop_add(void*, void*);
MathIROPNode* irop_sub(void*, void*);
MathIROPNode* irop_mul(void*, void*);
MathIROPNode* irop_div(void*, void*);

#endif
