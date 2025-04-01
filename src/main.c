#include <stdio.h>

#include "irop.h"

int main() {
	MathIROPNode* node = irop_constant_long(5);
	MathIROPNode* node2 = irop_constant_float(5.1);

	printf("Hello World!\n");
	printf("%ld\n", (long)(node->args->argv[0]));

	irop_free_node(node);

	return 0;
}
