// compile:
// 
// clang -std=c11 -mavx2 avx4.c -o avx4prog
//
// Run as normal with: 
// 
// ./avx4prog
//
#include <stdio.h>
#include <immintrin.h>

// mask is a way to hide bits of information that are not needed

// print
void print__m256(__m256 data){
	float*f = (float*)&data;
	printf("%f %f %f %f %f %f %f %f \n", f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7]);
}

void print__m256i(__m256i data){
	int*f = (int*)&data;
	printf("%i %i %i %i %i %i %i %i \n", f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7]);
}

int main(){

	__m256i mask = _mm256_setr_epi32(-1,-1,-1,-1,-1,0,2,3);
	

	int integers[8] = {1,2,3,4,5,6,7,8};


	__m256i result = _mm256_maskload_epi32(integers,mask);	

	//will not work
	print__m256(result);

	// print command specific to integer data
	print__m256i(result);

	return 0;
}
