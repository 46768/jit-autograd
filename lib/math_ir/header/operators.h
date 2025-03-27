#ifndef MATH_IR_OPERATOR_H_
#define MATH_IR_OPERATOR_H_

// Going something similar to lambda calculus but way higher level
// So every operator returns a "function" that resolves with or
// without arguments, and a "function" can only have 1 input
// argument like lambda calculus
typedef enum {
	// Values
	Constant,
	Variable,

	// Arithmetic operators
	// Each operator takes "2" argument by using a LHS function that
	// generate a RHS function binded to the LHS value
	Add, AddGRHS,
	Sub, SubGRHS,
	Mul, MulGRHS,
	Div, DivGRHS,
} MathIROPEnum;

#endif
