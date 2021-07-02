/*
Lab #4
Justin Varga
CSE 130-01
2/8/2021
Description: Simulate a calculator using functions.
*/

#include <stdio.h>

// Function Prototypes
float fInput(char prompt[]);
int iInput(char prompt[]);

float add(float fA, float fB);
float subtract(float fA, float fB);
float multiply(float fA, float fB);
float divide(float fDividend, float fDivisor);

int mod(int iDividend, int iDivisor);
int primeTest(int iNum);
int factorial(int iNum);
int power(int iBase, int iExponent);

int padovanSequence(int iN);

// Define Variables
int iOption; // The user's option
int iA, iB, iN, iResult; // Variables used in integer only equations
float fA, fB, fResult; // Variables used in all other equations

// Function Definitions
int main()
{
	printf("Welcome to Justin Varga's Advanced Calculator Program\n");
	
	do
	{
		printf("\nCalculator Menu:\n[1]: Addition\n[2]: Subtraction\n[3]: Multiplication\n[4]: Division\n[5]: Modulus*\n[6]: Test if Prime*\n[7]: Factorial*\n[8]: Power*\n[9]: Padovan Sequence*\n[0]: EXIT\n\n* = integers only\n");
		
		iOption = iInput("\nPlease choose an option listed above: ");
		
		switch(iOption)
		{
			// Addition
			case 1:
				printf("\nAddition:\n");
				
				// Take Input
				fA = fInput("\n\tPlease input a number to add: ");
				fB = fInput("\n\tPlease input another number to add: ");
				
				// Find Result
				fResult = add(fA, fB);
				
				// Display Result
				printf("\n\t%.6f + %.6f = %.6f\n", fA, fB, fResult);
				
				// Exit Switch
				break;
			
			// Subtraction
			case 2:
				printf("\nSubtraction:\n");
				
				// Take Input
				fA = fInput("\n\tPlease input a number to subtract from: ");
				fB = fInput("\n\tPlease input a number to subtract by: ");
				
				// Find Result
				fResult = subtract(fA, fB);
				
				// Display Result
				printf("\n\t%.6f - %.6f = %.6f\n", fA, fB, fResult);
				
				// Exit Switch
				break;
			
			// Multiplication
			case 3:
				printf("\nMultiplication:\n");
				
				// Take Input
				fA = fInput("\n\tPlease input a number to multiply: ");
				fB = fInput("\n\tPlease input another number to multiply: ");
				
				// Find Result
				fResult = multiply(fA, fB);
				
				// Display Result
				printf("\n\t%.6f x %.6f = %.6f\n", fA, fB, fResult);
				
				// Exit Switch
				break;
			
			// Division
			case 4:
				printf("\nDivision:\n");
				
				// Take Input
				fA = fInput("\n\tPlease input an integer divisor: ");
				fB = fInput("\n\tPlease input an integer dividend: ");
				
				while(fB == 0.0)
				{
					fB = fInput("\n\tYou can not divide by 0!\rPlease enter a non-zero number: ");
				}
				
				// Find Result
				fResult = divide(fA, fB);
				
				// Display Result
				printf("\n\t%.6f / %.6f = %.6f\n", fA, fB, fResult);
				
				// Exit Switch
				break;
			
			// Modulus
			case 5:
				printf("\nModulus:\n");
				
				// Take Input
				iA = iInput("\n\tPlease input an integer for the divisor: ");
				iB = iInput("\n\tPlease input an integer for the dividend: ");
				
				// Find Result
				iResult = mod(iA, iB);
				
				// Display Result
				printf("\n\t%d %% %d = %d\n", iA, iB, iResult);
				
				// Exit Switch
				break;
			
			// Test if Prime
			case 6:
				printf("\nPrime Test:\n");
				
				// Take Input
				iN = iInput("\n\tPlease input an integer to check: ");
				
				// Find and Display Result
				iResult = primeTest(iN); // The return is thrown away here but may be used in extensions.
				
				// Exit Switch
				break;
			
			// Factorial
			case 7:
				printf("\nFactorial:\n");
				
				// Take Input
				iN = iInput("\n\tPlease input an integer to find the factorial: ");
				
				// Make sure input is positive
				while(iN < 0)
				{
					iN = iInput("\n\tPlease input a positive number: ");
				}
	
				// Find and Display Result
				iResult = factorial(iN);
				
				// Exit Switch
				break;
			
			// Power
			case 8:
				printf("\nPower:\n");
				
				// Take Input
				iA = iInput("\n\tPlease input an integer base number: ");
				iB = iInput("\n\tPlease input an integer exponent: ");
				
				// Find Result
				iResult = power(iA, iB);
				
				// Display Result
				if(iB >= 0)
				{
					printf("\n\t(%d)^(%d) = %d\n", iA, iB, iResult);
				}
				else
				{
					if(iResult > 0)
					{
						printf("\n\t(%d)^(%d) = 1/%d\n", iA, iB, iResult);
					}
					else
					{
						printf("\n\t(%d)^(%d) = -1/%d\n", iA, iB, -1*iResult);
					}
				}
				
				// Exit Switch
				break;
			
			// Sequence
			case 9:
				printf("\nPadovan Sequence:\n");
				
				// Take Input
				iN = iInput("\n\tPlease input the number of entries in the Padovan sequence to be shown: ");
				
				// Make sure input is positive
				while(iN < 0)
				{
					iN = iInput("\n\tPlease input a positive number: ");
				}
				
				// Find and display the Result
				iResult = padovanSequence(iN);
				
				printf("\n\tP(%d) = %d\n", iN, iResult);
				
				// Exit Switch
				break;
			
			// Exit
			case 0:
				printf("\nExiting...\n\nThank you! Have a nice day!");
				break;
				
			// Unlisted options
			default:
				printf("\nPlease enter an option that is listed!");
				break;
		}
	}
	while (iOption != 0);
}

// Define functions used in main()

float fInput(char prompt[]) // Takes and returns a float input given a prompt string.
{
	float fIn;
	
	printf(prompt);
	scanf("%f", &fIn);
	
	return fIn;
}

int iInput(char prompt[]) // Takes and returns an integer input given a prompt string.
{
	int iIn;
	
	printf(prompt);
	scanf("%d", &iIn);
	
	return iIn;
}

float add(float fA, float fB)
{
	return fA + fB;
}

float subtract(float fA, float fB)
{
	return fA - fB;
}

float multiply(float fA, float fB)
{
	return fA * fB;
}

float divide(float fDividend, float fDivisor)
{
	return fDividend / fDivisor;
}

int mod(int iDividend, int iDivisor)
{
	return iDividend % iDivisor;
}

int primeTest(int iNum) // Returns 0 when iNum is not prime and 1 when iNum is prime. Displays whether iNum is prime with special case management.
{
	// Declare variables
	int iNumFactors, iFactor1, iFactor2;
	
	// Test using branched conditions
	iNumFactors = 0;
	
	if (iNum == 0)
	{
		// Zero (0) is technically neither, but it is generally regarded as a non-prime number.
	}
	else if (iNum < 0)
	{
		// All negative numbers are multiplicable by an infinite number of -1 and/or other negative numbers.
		iNumFactors = -1;
	}
	else if (iNum == 1)
	{
		// One is the only factor of itself. Therefore, it only has 1 unique divisor.
		iNumFactors = 1;
	}
	else
	{
		// Find all factors of the potential prime number
		int i = 0;
		for (iFactor1 = 1; iFactor1 < iNum; iFactor1++)
		{						
			if (iNum % iFactor1 == 0) // Branch when the potential prime is divisible by the factor
			{
				// Add the number of unique factors
				iFactor2 = iNum / iFactor1;
				
				if (iFactor1 == iFactor2)
				{
					iNumFactors += 1;
				}
				else
				{
					iNumFactors += 2;
				}
				
				// Add the factors to the list unless already there
				if (iFactor1 <= iFactor2)
				{
					// Add the factors to the list
					i++;
					printf("\n\t%d:\t%d = %d x %d", i, iNum, iFactor1, iFactor2);
				}
				else
				{
					// All unique factors are already present in the list
					break;
				}
			}
		}
	}
	
	switch (iNumFactors)
	{
		// Only true for 0
		case 0:
			printf("\n\t0 is an ambiguous case. It is neither prime nor composite.\n");
			return 0;
			break;
			
		// Only true for 1
		case 1:
			printf("\n\t1 is NOT a prime number by definition.\n");
			return 0;
			break;
		
		// Only true for prime numbers	
		case 2:
			printf("\n\n\t%d is a prime number.\n", iNum);
			return 1;
			break;
		
		// Only true for negative numbers
		case -1:
			printf("\n\tNegative numbers are NOT prime. Therefore, %d is NOT a prime number.\n", iNum);
			return 0;
			break;
		
		// True for all other numbers
		default:
			printf("\n\n\t%d is NOT a prime number.\n", iNum);
			return 0;
			break;
	}
}

int factorial(int iNum) // Returns the factorial iNum
{
	/* Special Case for 0
	if(iNum == 0)
	{
		return 1;
	}*/
	
	// Declare Variables
	int iFactorial = 1;
	int i;
	
	// Display and Find Factorial
	printf("\n\t%d! = ", iNum);
	
	for(i = iNum; i > 0; i--)
	{
		iFactorial *= i;
		
		printf("%d", i);
		
		if(i > 1)
		{
			printf(" x ");
		}
		else
		{
			printf(" = ");	
		}
	}
	
	printf("%d\n", iFactorial);
	
	return iFactorial;
}

int power(int iBase, int iExponent) // Returns iBase raised to the iExponent power (so long as both are integers)
{
	// Declare Variables
	int iResult = 1;
	int i;
	
	// Find Power
	for(i = 0; i < iExponent; i++)
	{
		iResult *= iBase;
	}
	
	// Return Value
	return iResult;
}

int padovanSequence(int iN) // Returns the iN-th value of the Padovan Sequence after displaying all terms up to it.
{	
	// Declare Variables
	int iSequence[iN];
	int n;
	
	// Generate Sequence and Display it
	printf("\n\tP(n) for 0 <= n <= %d: {", iN);
	
	for(n = 0; n <= iN; n++)
	{
		// Generate P(n)
		if (n <= 2)
		{
			iSequence[n] = 1;
		}
		else
		{
			iSequence[n] = iSequence[n - 2] + iSequence[n - 3];
		}
		
		// Display P(n) with padding
		printf("%d", iSequence[n]);
		
		if (n != iN)
		{
			printf(", ");
		}
		else
		{
			printf("}\n");	
		}
	}
	
	// Return P(iN)
	return iSequence[iN];
}
