// compile:
// 
// clang -std=c11 -mavx2 avx3.c -o avx3prog
//
// run: 
// 
// ./avx3prog
//
#include <stdio.h>
#include <immintrin.h>

// print
void print__m256(__m256 data){
	float*f = (float*)&data;
	printf("%f %f %f %f %f %f %f %f\n", f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7]);
}


int main(){

	
	__m256 a = _mm256_set_ps(0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0);
	__m256 b = _mm256_set_ps(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
	__m256 dst = _mm256_add_ps(a, b);

	print__m256(dst);
	
	__m256 float_a = _mm256_set_ps(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0);
	__m256 float_b = _mm256_set_ps(10.0,10.0,10.0,10.0,10.0,10.0,10.0,10.0);
	__m256 float_dst = _mm256_mul_ps(a,b);

	print__m256(float_dst);	
	

	return 0;
}
