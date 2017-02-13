#include "stdio.h"
int main(int argc, char const *argv[])
{
	int score;
	while (~scanf("%d", &score)) 
		if (score >= 0 && score <= 100) {
			if (score < 60)
				printf("E\n");
			else 
				if (score < 70)
					printf("D\n");
				else 
				 	if (score < 80)
				 		printf("C\n");
				 	else
				 		if (score < 90)
				 			printf("B\n");
				 		else printf("A\n");
		}
		else printf("Score is error!\n");
	return 0;
}