/*
Name: Harrison Thayer
Email: harrisonthayer@csu.fullerton.edu
Class: CPSC 351 Section 13
Date Last Modified: 9/5/2024 

Program description:
   Calculates fibonacci numbers. User has the option to calculate 
   iteratively or recursively.

*/

#include <stdio.h> // fopen()
#include <stdlib.h> // atoi()
#include <string.h>  // strcmp()

/*
 Function readFileInteger takes one input,
 a string, and returns an integer. The function
 opens the file specified by the input string,
 and pulls an integer from the file to return.

*/

int readFileInteger(char *fileName){
   FILE *myFile;                           // Create the file stream
   myFile = fopen(fileName, "r");          // Open the file for reading only

   int fileReadNumber;              
   fscanf(myFile, "%d", &fileReadNumber);  // Read the integer from the file
   fclose(myFile);                         // Close the file

   return fileReadNumber;
}

/*
 Function fibRecursively takes in 1
 integer, and calculates the Nth fibonacci
 number recursively.
*/

unsigned long long int fibRecursively(unsigned long long int number){
   if(number < 1){
      return 0;
   }
   if(number == 1){
      return 1;
   }
   return fibRecursively(number-1) + fibRecursively(number-2);
}

/*
 Function fibIteratively takes in 1
 integer, and calculates the Nth fibonacci
 number iteratively.
*/

unsigned long long int fibIteratively(int number){
   // Calculate the actual Fibonacci number,
   // final answer will be stored in "c" when the loop finishes.
   unsigned long long int nMinusTwo = 0;
   unsigned long long int nMinusOne = 1; 
   unsigned long long int fibonacci;
    for (int i = 0; i < number ; i++) {
        fibonacci = nMinusTwo + nMinusOne; 
        nMinusTwo = nMinusOne;
        nMinusOne = fibonacci;
    }
   return fibonacci;
}


int main(int argc, char *argv[]) {
   int inputNumber = atoi(argv[1]);
   char *rORi = argv[2];
   char *inputFileName = argv[3];

   // Read the number in the file, calculate
   // what fib number we will be going to...
   int N = readFileInteger(inputFileName) + inputNumber;
   unsigned long long int computedFibNumber;
   if(strcmp(rORi,"i") == 0){
      computedFibNumber = fibIteratively(N-2);
      printf("%llu\n", computedFibNumber);
   }
   if(strcmp(rORi,"r") == 0){
      computedFibNumber = fibRecursively(N);
      printf("%llu\n", computedFibNumber);
   }
   return computedFibNumber;
}
