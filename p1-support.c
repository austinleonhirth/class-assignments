#include "p1-support.h"
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////
//
// File           : p1support.c
// Description    : This is a set of general-purpose utility functions 
//                  we use for the 257 project #1. Fall 2022
// Author         : ***Type Author Name ***
// Date           : ***Type the date Date you completed***
// Notes          : ***Type bug fixes/other with dates for your records 


////////////////////////////////////////////////////////////////////////
// Function Definitions
////////////////////////////////////////////////////////////////////////

//Function definitions as decribed in the project manual 

//This function prints out the array of integer values
void display_array(unsigned int* arr, int size){
  int i;
  printf("{");
  for(i = 0;i<size;i++){
    printf("%4d%s",arr[i],(i==9)?"":",");
  }
  printf("}\n");
  
}

//Additional function definitions for helper functions
//Shortly describe each function above the function definition.

//Adds two integers using only bitwise operations
//Algorithm works with negative or positive ints
int bitwise_add(int num1, int num2)
{
  while(num2 != 0)
  {
    unsigned int carry = num1 & num2;
    num1 = num1 ^ num2;
    num2 = carry << 1;
  }
  return num1;
}

//Shifts num1 to the left num2 places
int bitwise_shift_left(int num1, int num2)
{ 
  return num1 << num2;
}

//returns the number of 1's in the binary representation of an int
int count_set_bits(int num){

  int last_bit;
  int counter = 0;

  while(num != 0) //loop until end of number
  {
    /*
    Using & 1 gets the last bit
    Example:

    011001          011000
  & 000001        & 000001
  --------   OR   --------
  = 000001        = 000000
    */
    last_bit = num & 1;

    if(last_bit != 0 ) //increment if found a 1 at the end
    {
      counter++;
    }
  
    num = num >> 1; //shift everything to the right to move on to next bit
  }

  return counter;
}

//populates a string with the binary representation of an int
void binary_string(unsigned int num, char str[BUFSZ]){

  int last_bit;
  char c;
  int counter = 31;

  while(counter>=0){
    last_bit = num & 1;
    c = last_bit+'0';
    num = num >> 1;
    str[counter]=c;
    counter--;
  }
  str[BUFSZ-1]='\0';
} 

//returns the result of num % 32 only using bitwise operations
int bitwise_mod32(int num){
  return num & ((1U << 5)-1);
}

//returns absolute value of an int using twos compliment
int bitwise_abs(int num){
  if(num>0)
    return num; 
 return bitwise_add(~num,1);

}

//returns the "offset" bit in num
int bit_get(int num,int offset){   
  return (num >> offset) & 1;
}

//Returns one if odd, zero if even
int odd_or_even(unsigned int num){
  if(num&1)
    return 1;
  return 0;
}

//Swaps the values of two integers using bitwise XOR trick :)
void swap_ints(int *a,int *b){

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;

}


