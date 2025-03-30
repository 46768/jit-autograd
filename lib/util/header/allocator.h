#ifndef UTIL_ALLOCATOR_H_
#define UTIL_ALLOCATOR_H_

#include <stdlib.h>

static inline void* allocate(size_t ptr_size) {
	void* ptr = malloc(ptr_size);
	if (ptr == NULL) {
		abort();
	}
	return ptr;
}

static inline void deallocate(void* ptr) {
	if (ptr != NULL) {
		free(ptr);
	}
}

#endif
