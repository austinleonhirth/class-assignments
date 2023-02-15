// Include Files
#include <stdio.h>
// Project Includes
#include "lab2header.h"
// Function Implementations

int reverse_number(int num)
{
	int reversed = 0;
 	 while(num > 0)
  	{
	  reversed = reversed * 10 + num % 10;
	  num = num / 10;
  	}
  	return reversed; 
}

int even_odd(int num)
{
	return num%2;
}


int is_prime(int num)
{
	int flag = 0;
	
	if(num==0||num==1){
		flag = 1;
	}

	int x;
	for(x = 2; x <= num/2; x++){
		if(num%x==0){
			flag = 1;
		}
	}
	return flag;
}

