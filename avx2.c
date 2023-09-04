
// clang -std=c11 -mavx2 avx2.c -o avx2prog
//
// Run with:
// 
// ./avx2prog
//
#include <stdio.h>
#include <immintrin.h>

void print__m256(__m256 data){
	float* f = (float*)&data;
	printf("%f %f %f %f %f %f %f %f \n",
		f[7], f[6], f[5], f[4], f[3], f[2], f[1], f[0]);
	// Your implementation can be done in 2 lines
	//
}


int main(){

	__m256 evensAVX = _mm256_set_ps(2.0,4.0,6.0,8.0,10.0,12.0,14.0,16.0);

	printf("=========Printing evens=========\n\n");
	print__m256(evensAVX);

	__m256 test1 = _mm256_setzero_ps();
	__m256 test2 = _mm256_set1_ps(42.0);

	printf("=========Printing 0's and 42's=========\n\n");
	print__m256(test1);
	print__m256(test2);
	__m256 test3 = _mm256_setr_ps(7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0, 0.0);
	
	printf("=========Printing _mm256_set_ps=========\n\n");
	print__m256(test3);
	//size of float is 32, total for 256
	float* aligned_32 = (float*)aligned_alloc(32, 8 * sizeof(float));

	printf("=========Loading aligned data=========\n");
	printf("sizeof(float)=%lu\n",sizeof(float));

	
	aligned_32[0] = 0.0f;
	aligned_32[1] = 1.0f;
	aligned_32[2] = 2.0f;
	aligned_32[3] = 3.0f;
	aligned_32[4] = 4.0f;
	aligned_32[5] = 5.0f;
	aligned_32[6] = 6.0f;
	aligned_32[7] = 7.0f;

	// load our array of floats into an AVX2 register.
	__m256 aligned_avx = _mm256_load_ps(aligned_32);
	// printing out the individual values stored in register to debug
	print__m256(aligned_avx);

	return 0;
}

