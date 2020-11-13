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



//adds 1 to data and prints
void do_the_thing(float i){
	//Populate __m256 vector with array
	__m256 data = _mm256_set1_ps(i);
	//Populate __m256 vector with float 1
	__m256 x = _mm256_set1_ps (1);
	//Add both vectors to create one vector filled with target value
	data =  _mm256_add_ps (x, data);
	//Convert vector to array of floats
	float* toPrint = (float*)&data;
	//To access target value, extract any of the indexes in array
	//print
	printf("%i ", (int)(toPrint[0]));	
}
int main(){
	FILE *fp;
	fp = fopen("data.txt", "r");
	if (fp == NULL){
		printf("Can't find file!");
		exit(1);
	}
	float num;
	while (fscanf(fp, "%f", &num) != EOF){
		//ZHU LI!
		do_the_thing(num);
	}	
	printf("\n");
	return 0;
}
