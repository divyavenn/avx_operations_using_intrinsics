// For this exercise, you are going to read in data from a file called 'data.txt'
// Increment all of the values by 1 and print them to the stdout on the terminal.
// 
// You will compile this source using the following:
// clang -std=c11 -mavx2 ex1.c -o ex1prog
//
// Run as normal with: 
// ./ex1prog
//
#include <stdio.h>
#include <immintrin.h>



// print (Note, you may need to change this function or write another for your data)
void print__m256(__m256 data){
	float*f = (float*)&data;
	printf("%f %f %f %f %f %f %f %f\n", f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7]);
}
void doTheThing(float i){
	__m256 data = _mm256_set1_ps(i);
	__m256 x = _mm256_set1_ps (1);
	data =  _mm256_add_ps (x, data);
	float* toPrint = (float*)&data;
	printf("%i ", (int)(toPrint[0]));	
}
int main(){
	FILE *fp;
	fp = fopen("data.txt", "r");
	if (fp == NULL){
		printf("Can't find file!");
		exit(1);
	}
	int value;
	float num;
	while (fscanf(fp, "%f", &num) != EOF){
		//Zhu L
		doTheThing(num);
	}	
	printf("\n");
	return 0;
}
