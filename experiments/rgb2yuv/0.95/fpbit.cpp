#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double rate = 0;
	int size = 2064;
	float ar[size];
	float apr[size];
	float m;	

	printf("Reading the accurate results\n");
	FILE* f1 = fopen("result.txt", "r");	
	for (int h = 0; h < size; h++)
	{

		fscanf(f1, "%f ", &m);
		ar[h] = m;

	}
	fclose(f1);

	printf("Reading the approximate results\n");
	FILE* f2 = fopen("22", "r");
	for (int h = 0; h < size; h++)
	{

		fscanf(f2, "%f ", &m);
		apr[h] = m;
	}
	fclose(f2);
	
	int pass = 0;
	double error[size];
	for (int h = 0; h < size; h++)
	{
		error[h] = fabs(ar[h]-apr[h]);
		if(error[h] < 0.0001)
		{
			pass++;
		}
//		error[h] = sqrt(tmp[0]*tmp[0] + tmp[1]*tmp[1] + tmp[2]*tmp[2]);
	}
	printf("passed: %d\n", pass);
        	
	if(pass < size*0.95)
	{
		printf("Verification failed. Verifid bitwidth is: bit\n");
		return 0;
	}
	printf("Verification succeed.\n");
	return 1;
}

