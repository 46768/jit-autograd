#include "irop.h"

#include "allocator.h"

// Node allocations

MathIROPArgs* irop_allocate_args(size_t argc) {
	MathIROPArgs* args = allocate(sizeof(MathIROPArgs));
	args->argc = argc;
	args->argv = allocate(sizeof(void*)*argc);
	args->argt = allocate(sizeof(MathIRTypeEnum)*argc);

	return args;
}

MathIROPNode* irop_allocate_node(size_t argc) {
	MathIROPNode* node = allocate(sizeof(MathIROPNode));
	node->args = irop_allocate_args(argc);

	return node;
}

// Node deallocations

void irop_free_args(MathIROPArgs* args) {
	deallocate(args->argv);
	deallocate(args->argt);
	deallocate(args);
}

void irop_free_node(MathIROPNode* node) {
	irop_free_args(node->args);
	deallocate(node);
}

// Node generics

MathIROPNode* irop_generic_2args(void* a, void* b) {
	MathIROPNode* node = irop_allocate_node(2);
	node->args->argv[0] = a;
	node->args->argt[0] = Node;

	node->args->argv[1] = b;
	node->args->argt[1] = Node;

	return node;
}

MathIROPNode* irop_constant_int(long num) {
	MathIROPNode* node = irop_allocate_node(1);
	node->type = Constant;
	node->args->argv[0] = (void*)num;
	node->args->argt[0] = Int;

	return node;
}

MathIROPNode* irop_constant_float(float num) {
	MathIROPNode* node = irop_allocate_node(1);
	node->type = Constant;
	node->args->argv[0] = (void*)(long)num;
	node->args->argt[0] = Float;

	return node;
}

// Arithmetic nodes

MathIROPNode* irop_add(void* a, void* b) {
	reallocate(NULL, 0);
	MathIROPNode* node = irop_generic_2args(a, b);
	node->type = Add;

	return node;
}

MathIROPNode* irop_sub(void* a, void* b) {
	MathIROPNode* node = irop_generic_2args(a, b);
	node->type = Sub;

	return node;
}

MathIROPNode* irop_mul(void* a, void* b) {
	MathIROPNode* node = irop_generic_2args(a, b);
	node->type = Mul;

	return node;
}

MathIROPNode* irop_div(void* a, void* b) {
	MathIROPNode* node = irop_generic_2args(a, b);
	node->type = Div;

	return node;
}
