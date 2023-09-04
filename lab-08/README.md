# Implementing AVX Basic Operations Using Intrinsics

<img align="right" src="./Media/ymm.png" width="300px" alt="ymm avx2 registers">

The [advanced vector extensions](https://en.wikipedia.org/wiki/Advanced_Vector_Extensions) (AVX) are an instruction set for Intel (and AMD) machines that help utilize the parallel processing(at the instruction level) capabilities of our modern [superscalar processor](https://en.wikipedia.org/wiki/Superscalar_processor).

Put simply, a superscalar processor allows fetching, decoding, and executing more than 1 instruction at a time. The image below shows an example. 

<img align="center" src="./Media/Superscalarpipeline.PNG" width="500px" alt="ymm avx2 registers">

> Simple superscalar pipeline. By fetching and dispatching two instructions at a time, a maximum of two instructions per cycle can be completed. (IF = Instruction Fetch, ID = Instruction Decode, EX = Execute, MEM = Memory access, WB = Register write back, i = Instruction number, t = Clock cycle [i.e., time]) [[source](https://en.wikipedia.org/wiki/Superscalar_processor)]

## Intrinsics

[Intrinsic functions](https://en.wikipedia.org/wiki/Intrinsic_function) are built-in functions within a compiler. They appear as functions, and when used within a programming language, generate the appropriate assembly automatically for us. Typically instrinics, or intrinsic functions, are provided to give some sort of specific optimization within a language.

The instrinsic functions for our compiler (either gcc or clang) are located in a header file named [immintrin.h](https://github.com/gcc-mirror/gcc/blob/master/gcc/config/i386/immintrin.h):

 ```c
 #include <immintrin.h> // Brings in the AVX Intrinsics
 ```

Navigating to `/lib/gcc/x86_64-redhat-linux/4.8.5/include/immintrin.h` you can actually see the contents of this file and where various intrinsic functions are implemented.

The below code includes AVX specifically:
```c
#ifdef __AVX2__
#include <avx2intrin.h>
#endif
```

* [avx1.c](./avx1.c) - packs bytes into a basic instruction
* [avx2.c](./avx2.c) - a print debugging function 
* [avx3.c](./avx3.c) - implements arithmetic operations
* [avx4.c](./avx4.c) - masking
* [avx5.c](./avx5.c) - permutes and rearranges data with masks
* [ex1.c](./ex1.c)   - reads in data from [data.txt](./data.txt) increments all of the values by 1 and prints them to the stdout on the terminal.
* [ex2.c](./ex2.c)   - loads the data from [data2.txt](./data2.txt) implements a simple caeser shift decrypt then output the results as a char to stdout on the terminal.

Compile each source using the following:
```c
clang -std=c11 -mavx2 <src.c> -o <executable>
```

**Note** the `-mavx2` includes the avx2 functionality.

Run with:
```c
./<executable>
```


## Resources I used: 

* Practical SIMD Programming: http://www.cs.uu.nl/docs/vakken/magr/2017-2018/files/SIMD%20Tutorial.pdf
* Intel Intrinsics guide: https://software.intel.com/sites/landingpage/IntrinsicsGuide/
* intrinsic functions: https://en.wikipedia.org/wiki/Intrinsic_function

