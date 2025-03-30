#ifndef UTIL_ALLOCATOR_H_
#define UTIL_ALLOCATOR_H_

#include <stdlib.h>

#include "logger.h"

static inline void* allocate(size_t size) {
	void* ptr = malloc(size);
	if (ptr == NULL) {
		fatal("Failed to allocate a pointer sized %zu bytes", size);
	}
	return ptr;
}

static inline void* callocate(size_t size, size_t t_size) {
	void* ptr = calloc(size, t_size);
	if (ptr == NULL) {
		fatal("Failed to allocate a pointer sized %zu bytes", size);
	}
	return ptr;
}

static inline void* reallocate(void* ptr, size_t size) {
	if (ptr == NULL) {
		fatal("Provided pointer is NULL");
	}
	void* ptr_new = reallocate(ptr, size);
	if (ptr_new == NULL) {
		fatal("Failed to reallocate a pointer sized %zu bytes", size);
	}
	return ptr_new;
}

static inline void deallocate(void* ptr) {
	if (ptr != NULL) {
		free(ptr);
	}
}

#endif
