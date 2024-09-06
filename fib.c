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
 Function fibRecursively takes in 3 
 integers, and calculates the Nth fibonacci
 number recursively.
*/

unsigned long long int fibRecursively(int number, int inPrevious, int inCurrent){
   unsigned long long int counter = number;
   unsigned long long int b = inPrevious;
   unsigned long long int c = inCurrent;
   unsigned long long int a = c;
   c = c + b;
   b = a;
   // Base Case
   if(counter == 0){
      return c;
   }
   // Recursive case
   c = fibRecursively(counter - 1, b, c);

   return c;
}

/*
 Function fibIteratively takes in 1
 integer, and calculates the Nth fibonacci
 number iteratively.
*/

unsigned long long int fibIteratively(int number){
   // Calculate the actual Fibonacci number,
   // final answer will be stored in "c" when the loop finishes.
   unsigned long long int a = 0;
   unsigned long long int b = 1; 
   unsigned long long int c;
    for (int i = 0; i < number ; i++) {
        c = a + b; 
        a = b;
        b = c;
    }
   return c;
}


int main(int argc, char *argv[]) {
   int inputNumber = atoi(argv[1]);
   char *rORi = argv[2];
   char *inputFileName = argv[3];

   // Read the number in the file, calculate
   // what fib number we will be going to...
   int N = readFileInteger(inputFileName) + inputNumber;
   int computedFibNumber;
   if(strcmp(rORi,"i") == 0){
      computedFibNumber = fibIteratively(N-2);
      printf("%i\n", computedFibNumber);
   }
   if(strcmp(rORi,"r") == 0){
      computedFibNumber = fibRecursively(N-3, 0, 1);
      printf("%i\n", computedFibNumber);
   }
   return computedFibNumber;
}
