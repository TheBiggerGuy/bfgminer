#ifndef BFG_MINING_ALGORITHM_H
#define BFG_MINING_ALGORITHM_H

#include <stdint.h>

#include "work.h"

enum pow_algorithm {
#ifdef USE_KECCAK
	POW_KECCAK,
#endif
#ifdef USE_SHA256D
	POW_SHA256D,
#endif
#ifdef USE_SCRYPT
	POW_SCRYPT,
#endif
	POW_ALGORITHM_COUNT,
};

struct mining_algorithm;

struct mining_algorithm {
	const char *name;
	const char *aliases;
	
	enum pow_algorithm algo;
	uint8_t ui_skip_hash_bytes;
	uint8_t worktime_skip_prevblk_u32;
	float reasonable_low_nonce_diff;
	
	void (*hash_data_f)(void *digest, const void *data);
	
	int goal_refs;
	int staged;
	int base_queue;
	
	struct mining_algorithm *next;
	
#ifdef USE_OPENCL
	bool opencl_nodefault;
	float (*opencl_oclthreads_to_intensity)(unsigned long oclthreads);
	unsigned long (*opencl_intensity_to_oclthreads)(float intensity);
	unsigned long opencl_min_oclthreads;
	unsigned long opencl_max_oclthreads;
	float opencl_min_nonce_diff;
	char *(*opencl_get_default_kernel_file)(const struct mining_algorithm *, struct cgpu_info *, struct _clState *);
#endif
};

#endif /* BFG_MINING_ALGORITHM_H */