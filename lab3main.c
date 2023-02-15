#include <stdio.h>
#include "lab3header.h"

int main(void) 
{ 
	int a[] = {0,1,2,3,4,5};
	char ch = 'N'; /* variable to accept the user's choice, 
										N represents the condition not to exit from the program */ 
	int num; /* variable to accept a number */ 
	int base, exp;
	while( (ch != 'Y') && (ch != 'y') ) 
	{ 

		printf("Enter S to Sum all \n"); 
		printf("Enter B for Power fucntion \n"); 
		printf("Enter Y or y to exit the program\n"); 
		printf("Enter your choice: "); 

		scanf("%c", &ch); 
		while(getchar() != '\n'); /*clears the input buffer, alternatively 
																you can use fflush*(stdin)*/

		switch(ch) 
		{ 
			case 'Y': case 'y': 
				printf("Exiting the program.\n\n"); 
				break;

			case 'S': case 's': 
				printf("sumall: %d",sumall(a,3)); 
				printf("\n");
				break;

			case 'B': case 'b': 
				printf("Enter your base: ");
				scanf("%d",&base); 
				printf("Enter your exponent: ");
				scanf("%d",&exp);
				printf("Power function: %d", power(base,exp));
				printf("\n");
				break;

			default: 
				printf("You have entered a wrong choice. Try again\n"); 
				break; 
		} /* switch */
	} /* while */ 
	return 0; 
} /* main */ 
