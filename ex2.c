
#include <stdio.h>
#include <immintrin.h>
#include <string.h>


void do_the_thing(int asc){
	//import asci code to __m26i char format
	__m256i data = _mm256_set1_epi8(asc);
	__m256i x = _mm256_set1_epi8(1);
	//add 1 to ascii code
	data =  _mm256_add_epi8 (x, data);
	//convert to character arry and print
	char* toPrint = (char*)&data;
	printf("%c ", (toPrint[0]));	
}
int main(){
	FILE *fp;
	fp = fopen("data2.txt", "r");
	if (fp == NULL){
		printf("Can't find file!");
		exit(1);
	}
	int value;
	char ch[150];
	while (fgets(ch, 150, fp) != NULL){
		//remove blank space
		char * c = strtok(ch, "\n");
		int i;
		int j;
		//accumulator
		int asc = 0;
		int digit = 0;
		int len = strlen(c);
		//iterate through every digit
		for (int i = 0; i<len; i++){
			digit = ((int)(c[i]) - 48);
			//multiply by appropriate power of 10
			for (int j = 0; j < (len - i - 1); j++){
				digit = digit * 10;
			}
			asc += digit;
		}
		//printf("%i ", asc);
		do_the_thing(asc);
	}	
	//doTheThing(101);
	printf("\n");
	return 0;
}
