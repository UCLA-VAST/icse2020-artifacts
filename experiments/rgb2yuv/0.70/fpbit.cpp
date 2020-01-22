#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int flag = 1;
	int size = 1206;
	float ar[size];
	float apr[size];
	float m;	

	printf("Reading the accurate results\n");
	FILE* f1 = fopen("result", "r");	
	for (int h = 0; h < size; h++)
	{

		fscanf(f1, "%f ", &m);
		ar[h] = m;

	}
	fclose(f1);

	printf("Reading the approximate results\n");
	FILE* f2 = fopen("19", "r");
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
        	
	if(pass < size*0.70)
	{
		printf("Verification failed. Verifid bitwidth is: bit\n");
		return 0;
	}
	printf("Verification succeed.\n");
	return 1;
}

