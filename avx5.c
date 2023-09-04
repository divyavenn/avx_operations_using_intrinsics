// compile:
// 
// clang -std=c11 -mavx2 avx5.c -o avx5prog
//
// run:
// 
// ./avx5prog
//
#include <stdio.h>
#include <immintrin.h>


// print
void print__m256(__m256 data){
	float*f = (float*)&data;
	printf("%f %f %f %f %f %f %f %f\n", f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7]);
}

int main(){


	__m256 a = _mm256_setr_ps(1.0,2.0,3.0,4.0,1.0,2.0,3.0,4.0);	
	print__m256(a);

	__m256 result = _mm256_permute_ps(a,0b10110100); 

	print__m256(result);


	return 0;
}
