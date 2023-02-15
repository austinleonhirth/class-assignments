////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s22-p1.c
//  Description    : This is the main source code for for the first 
//                   project of CMSC257.  
//                   See the related assignment page for details.
//
//  Author         : Austin Leonhirth
//  Last Modified  : 9/28/2022
//

// System Includes
#include <stdio.h>
#include <stdlib.h>

// Project Includes
#include "p1-support.h"


// Functions
///////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMSC257 project #1
// 
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Output       : 0 if successful test, -1 if failure

int main(int argc, char *argv[]) {

  // Local variables
  int int_array1[10];
  unsigned int uint_array1[10], uint_array2[10];
  int i;
  int option = 0;
  int offset = -2;
  //Add more local variables here as needed
    
  if (argc < 11)
  {   
  //Exit if there are less than 10 inputs
    printf("Exiting the program, missing input");
    return 0;	
  }

  // Step a - Read in the integer numbers input at 
  // the time of execution and save them into int_array1
  for (i=1; i<11; i++) {
    int_array1[i-1] = atoi(argv[i]);//converting input to integer
  }
  //You don't need to modify the code above for testing
  //Modify/uncomment the code below for testing as needed

  //INITAL INPUT PRINTING
  printf("--------------------------------------------------------\nInital Input: \n");
  display_array(int_array1, 10);//display the input array
  printf("\n");

  //BITWISE ADDING TESTING
  //Add index values of each array element on the array elements
  //test entering different offsets, maybe get input using scanf
  for (i=0; i<10; i++){
    int_array1[i] = bitwise_add(int_array1[i], offset);
  }
  
  printf("Bitwise addition : adding %d\n", offset);
	display_array(int_array1, 10);



  //BITWISE COUNTING ONE'S
  printf("\nNumber of 1's in 9(1001) = %d\n", count_set_bits(9));
  printf("Number of 1's in 22(10110) = %d\n", count_set_bits(22));



  //BINARY TO STRING TESTING
  char test_string[32];
  binary_string(977,test_string);
  printf("\n977 in Binary: 0b%s\n",test_string);
  

  //BITWISE MOD TESTING
  printf("\nMOD TESTING \n");
  printf("31 mod 32 = %d\n",bitwise_mod32(31));


  //BITWISE ABSOLUTE VALUE TESTING
  printf("\nABS TESTING\n");
  printf("ABS of 20 = %d\n",bitwise_abs(20));
  printf("ABS of -40 = %d\n",bitwise_abs(-40));

  //BIT GET TESTING
  printf("\nBIT GET\n");
  printf("3rd bit from right of 77(1001101) = %d\n",bit_get(77,2));
  printf("5th bit from right of 222(11011110) = %d\n",bit_get(222,4));
	
  //ODD EVEN TESTING
  printf("\nODD/EVEN TESTING (0=EVEN, 1=ODD)\n");
  printf("22 is = %d\n",odd_or_even(22));
  printf("19 is = %d\n",odd_or_even(19));

  //SWAP INT TESTING
  printf("\nINT SWAPPING\n");

  int a = 3;
  int b = 8;

  int c = 10;
  int d = 22;

  printf("(%d,%d)",a,b);
  swap_ints(&a,&b);
  printf(" -> (%d,%d)\n",a,b);

  printf("(%d,%d)",c,d);
  swap_ints(&c,&d);
  printf(" -> (%d,%d)\n",c,d);
  
	
  // Return successfully
  return(0);
}
