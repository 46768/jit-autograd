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

static inline void* callocate(size_t size, size_t t_size) {
	void* ptr = calloc(size, t_size);
	if (ptr == NULL) {
		abort();
	}
	return ptr;
}

static inline void* reallocate(void* ptr, size_t size) {
	if (ptr == NULL) {
		abort();
	}
	void* ptr_new = reallocate(ptr, size);
	if (ptr_new == NULL) {
		abort();
	}
	return ptr_new;
}

static inline void deallocate(void* ptr) {
	if (ptr != NULL) {
		free(ptr);
	}
}

#endif
