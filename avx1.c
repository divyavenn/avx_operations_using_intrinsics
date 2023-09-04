
#include <stdio.h>

// intriniscs header file.
#include <immintrin.h>



int main(){

	float evens[8] = {2,4,6,8,10,12,14,16};
	
	
	// create AVX2 vector.
	// __m is the naming convention for our vector types. The 256 that follows
	// represents how many 'bits' can be stored in that vector.
	//
	// __m256 stores 256 bits of floating point data
	// __m256d stores 256 bits of double data
	// __m256i storse 256 bits of integer data
	__m256 evensAVX = _mm256_set_ps(2.0,4.0,6.0,8.0,10.0,12.0,14.0,16.0);

	// print out the vector
	float*f = (float*)&evensAVX;
	printf("%f %f %f %f %f %f %f %f\n", f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7]);
	

	

		 
	__m256i asciiMessage  = _mm256_set_epi8('a','b','c','d','e','f','g','h',
						'i','j','k','l','m','n','o','p',
						'q','r','s','t','u','v','w','x',
						'y','z','0','1','2','3','4','5');

	// print vector
	char* c = (char*)&asciiMessage;

	printf(	"asciimessage: %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",
		c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],
		c[8],c[9],c[10],c[11],c[12],c[13],c[14],c[15],
		c[16],c[17],c[18],c[19],c[20],c[21],c[22],c[23],
		c[24],c[25],c[26],c[27],c[28],c[29],c[30],c[31]
		);

	return 0;

}
