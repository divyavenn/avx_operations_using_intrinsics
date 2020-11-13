// You will compile this source using the following:
// 
// clang -std=c11 -mavx2 avx2.c -o avx2prog
//
// Run as normal with: 
// 
// ./avx2prog
//
#include <stdio.h>
#include <immintrin.h>

// Now I want to talk about a few handy functions in the AVX library that
// are things we frequently do as programmers. 
// The first is initializing our data to a starting value.
//
// Additionally, here are two requirements in this sample.
// (1) 	We are going to work with floats
// (2) 	It would be nice to be able to have a function to print out
// 	floats given an __m256 data type.


// TODO: Implement this function
void print__m256(__m256 data){
	float* f = (float*)&data;
	printf("%f %f %f %f %f %f %f %f \n",
		f[7], f[6], f[5], f[4], f[3], f[2], f[1], f[0]);
	// Your implementation can be done in 2 lines
	//
}


int main(){

	__m256 evensAVX = _mm256_set_ps(2.0,4.0,6.0,8.0,10.0,12.0,14.0,16.0);

	// Implement your print function above.
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
	float* aligned_32 = (float*)aligned_alloc(32, 8 * sizeof(float));

	// Let's break that function down.
	// First, we cast to a float*, just as we would have done with a regular malloc.
	// The first parameter describes our alignment, in this case 4 bytes(32 bits).
	// Remember, our 256-bit vector is divided into nice 32 bit chunks.
	//
	// |32|32|32|32|32|32|32|32| = 256 bits (or 32 bytes)
	//  7  6  5  4  3  2  1  0
	//
	//
	// And why do we multiply 8 * sizeof(float)?	
	// Well, let's verify on our architecture the data size of a float in bytes.

	printf("=========Loading aligned data=========\n");
	printf("sizeof(float)=%lu\n",sizeof(float));
	
	// And hopefully whatever our result is for sizeof(float) in bytes times 8 bytes is equal to 256 bits!
	// You can read more here: 
	// https://www.gnu.org/software/libc/manual/html_node/Aligned-Memory-Blocks.html
	//
	// Okay, now let us populate our data data in a normal C array.
	
	aligned_32[0] = 0.0f;
	aligned_32[1] = 1.0f;
	aligned_32[2] = 2.0f;
	aligned_32[3] = 3.0f;
	aligned_32[4] = 4.0f;
	aligned_32[5] = 5.0f;
	aligned_32[6] = 6.0f;
	aligned_32[7] = 7.0f;

	// Now we finally load our array of floats into an AVX2 register.
	// '_mm256_load_ps' is the command to do so.
	__m256 aligned_avx = _mm256_load_ps(aligned_32);
	// And of course, we can always debug this working by printing out the individual
	// values stored in our register.
	print__m256(aligned_avx);

	// What happens if you need to load data that is unaligned?
	// Investigate _mm256_loadu_ps(...) in the intrinsics guide.
	// The short answer is this command can help us load code aligned on any boundary.


	return 0;
}

