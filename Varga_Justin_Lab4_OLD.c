/*
Lab #4
Justin Varga
CSE 130-01
2/8/2021
Description: Simulate a calculator with five basic operations and prime number testing.
*/

#include <stdio.h>

int main()
{
	/* Declare Variables */
	int iOption; // Stores user input 
	float fA, fB, fResult; // Addition, Subtraction, and Multiplication Variables
	float fDividend, fDivisor, fQuotient; // Division Variables
	int iDividend, iDivisor, iRemainder; // Modulo Variables
	int iPotentialPrime, iFactor1, iFactor2, iNumFactors; // Prime Number Check Variables
	int iBase, iExponent; // Power Variables
	int iN, iResult; // Power, Factorial and Pell Number Variable
	long int lBigResult; // Pell Number Variable (numbers can get very large very quickly)
	int iP[1000]; // Pell Number Variable
	
	/* Begin Program */
	printf("Welcome to Justin Varga's Advanced Calculator Program!");
	
	// Loop until user enters "0"
	do
	{
		// Prompt and take input
		printf("\n\nCalculator Menu:\n[1]: Addition\n[2]: Subtraction\n[3]: Multiplication\n[4]: Division\n[5]: Modulus*\n[6]: Prime Number Check*\n[7]: Factorial*\n[8]: Power*\n[9]: Pell Numbers*\n[0]: EXIT\n\n* = integers only\n\nPlease enter an option listed above: ");
		scanf("%d", &iOption);
		
		switch (iOption)
		{
			/* EXIT */
			case 0: 
				// Exit switch
				break;
				
			/* Addition */
			case 1: 
				printf("\nAddition:\n");
				
				//Ask for two floats A and B (A + B)
				printf("\n\tPlease enter the first number: ");
				scanf("%f", &fA);
				
				printf("\tPlease enter the second number: ");
				scanf("%f", &fB);
				
				// Display addition equation
				fResult = fA + fB;
				printf("\n\t%.6f + %.6f = %.6f\n", fA, fB, fResult);
				
				// Exit switch
				break;
				
			/* Subtraction */
			case 2:
				printf("\nSubtraction:\n");
				
				// Ask for two floats A and B (A - B)
				printf("\n\tPlease enter the number to be subtracted from: ");
				scanf("%f", &fA);
				
				printf("\tPlease enter the value %f shall be subtracted by: ", fA);
				scanf("%f", &fB);
				
				// Display the subtraction equation
				fResult = fA - fB;
				printf("\n\t%.6f - %.6f = %.6f", fA, fB, fResult);
				
				// Exit switch
				break;
				
			/* Multiplication */
			case 3:
				printf("\nMultiplication:\n");
				
				// Ask for two floats A and B (A x B)
				printf("\n\tPlease enter the first number: ");
				scanf("%f", &fA);
				
				printf("\tPlease enter the second number: ");
				scanf("%f", &fB);
				
				// Display addition equation
				fResult = fA * fB;
				printf("\n\t%.6f x %.6f = %.6f", fA, fB, fResult);
							
				// Exit switch
				break;
				
			/* Division */
			case 4:	
				printf("\nDivision:\n");
				
				// Ask for dividend and divisor (A / B)
				printf("\n\tPlease enter the dividend: ");
				scanf("%f", &fDividend);
				
				printf("\tPlease enter the divisor: ");
				scanf("%f", &fDivisor);
				
				// Make sure to not divide by 0
				while (fDivisor == 0.0)
				{
					printf("\n\tYou can not divide by zero!\rPlease enter a non-zero number for the divisor: ");
					scanf("%f", &fDivisor);	
				}
				
				// Calculate the quotient and display the equation
				fQuotient = fDividend / fDivisor;
				printf("\n\t%.6f / %.6f = %.6f", fDividend, fDivisor, fQuotient);
				
				// Exit switch
				break;
				
			/* Modulus */
			case 5:
				printf("\nModulus:\n");
				
				// Prompt and take input for the dividend and divisor (dividend % divisor = remainder)
				printf("\n\tPlease enter the dividend: ");
				scanf("%d", &iDividend);
				
				printf("\tPlease enter the divisor: ");
				scanf("%d", &iDivisor);
				
				// Calculate remainder and display the equation
				iRemainder = iDividend % iDivisor;
				printf("\n\t%d %% %d = %d", iDividend, iDivisor, iRemainder);
				
				// Exit switch
				break;
				
			/* Prime Number Check */
			case 6:
				printf("\nPrime Number Check:\n");
				
				// Prompt and take input for the number to be checked.
				printf("\n\tPlease enter the number to be checked: ");
				scanf("%d", &iPotentialPrime);
				
				// Test using branched conditions
				iNumFactors = 0;
				
				if (iPotentialPrime == 0)
				{
					// Zero (0) is technically neither, but it is generally regarded as a non-prime number.
				}
				else if (iPotentialPrime < 0)
				{
					// All negative numbers are multiplicable by an infinite number of -1 and/or other negative numbers.
					iNumFactors = -1;
				}
				else if (iPotentialPrime == 1)
				{
					// One is the only factor of itself. Therefore, it only has 1 unique divisor.
					iNumFactors = 1;
				}
				else
				{
					// Find all factors of the potential prime number
					int i = 0;
					for (iFactor1 = 1; iFactor1 < iPotentialPrime; iFactor1++)
					{						
						if (iPotentialPrime % iFactor1 == 0) // Branch when the potential prime is divisible by the factor
						{
							// Add the number of unique factors
							iFactor2 = iPotentialPrime / iFactor1;
							
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
								printf("\n\t%d:\t%d = %d x %d", i, iPotentialPrime, iFactor1, iFactor2);
							}
							else
							{
								// All unique factors are already present in the list
								break;
							}
						}
					}
				}
				
				// Display the results of the test
				switch (iNumFactors)
				{
					// Only true for 0
					case 0:
						printf("\n\t0 is an ambiguous case. It is neither prime nor composite.");
						break;
						
					// Only true for 1
					case 1:
						printf("\n\t%d is NOT a prime number by definition.", iPotentialPrime);
						break;
					
					// Only true for prime numbers	
					case 2:
						printf("\n\n\tThere are only 2 unique factors of %d.\n\tTherefore, %d is a prime number.", iPotentialPrime, iPotentialPrime);
						break;
					
					// Only true for negative numbers
					case -1:
						printf("\n\tNegative numbers have an infinite number of factors when including -1.\n\tTherefore, %d is NOT a prime number.", iPotentialPrime);
						break;
					
					// True for all other numbers
					default:
						printf("\n\n\tThere are %d unique factors of %d, including 1 and itself.\n\tTherefore, %d is NOT a prime number.", iNumFactors, iPotentialPrime, iPotentialPrime);
						break;
				}
				
				// Exit switch
				break;
			
			/* Factorial */
			case 7:
				printf("\nFactorial:\n");
				
				// Take input for the number
				
				// Calculate the factorial
				
				// Display the result
				
				// Exit Switch
				break;
			
			/* Power */
			case 8:
				printf("\nPower:\n");
				
				// Take input
				printf("\n\tPlease enter the base number: ");
				scanf("%d", &iBase);
				
				printf("\tPlease enter the exponent: ");
				scanf("%d", &iExponent);
				
				// Find the result
				int iNegativePower = 0;
				if(iExponent < 0)
				{
					iNegativePower = 1;
					iExponent *= -1;
				}
				
				lBigResult = 1;
				
				int i;
				for (i = 0; i < iExponent; i++)
				{
					lBigResult *= iBase;
				}
				
				// Display the result
				if (iNegativePower == 1 && iBase != 0)
				{
					if (lBigResult < 0)
					{
						printf("\n\t(%d)^%d = -1/%d", iBase, iExponent, -1*lBigResult);
					}
					else
					{
						printf("\n\t(%d)^%d = 1/%d", iBase, iExponent, lBigResult);
					}
				}
				else
				{
					printf("\n\t(%d)^%d = %d", iBase, iExponent, lBigResult);
				}
				
				// Exit switch 
				break;
			
			/* Pell Numbers */
			case 9:
				printf("\nPell Number:\n\tPell Numbers follow the sequence P[n] = {0, 1, 2P[n-1] + P[n-2]}\n");
				
				// Take input for the nth term
				printf("\n\tPlease input the n which you want the sequence to display to: ");
				scanf("%d", &iN);
				
				while (iN < 0)
				{
					printf("\n\tPlease input a positive number for n: ");
					scanf("%d", &iN);
				}
				
				// Initialize and calculate the array for the sequence
				iP[0] = 0;
				iP[1] = 1;
				
				int n;
				for (n = 2; n <= iN; n++)
				{
					int iPn1 = iP[n-1];
					int iPn2 = iP[n-2];
					
					iP[n] = 2*iPn1 + iPn2;
				}
				
				// Display the sequence
				printf("\n\tThe sequence is ");
				
				int j;
				for (j = 0; j < iN; j++)
				{
					printf("%d, ", iP[j]);
				}
				
				printf("%d, ...\n\tThe %d-th term is %d.", iP[iN], iN, iP[iN]);
				
				// Exit switch
				break;
				
			/* Any input that isn't on the menu */
			default: 
				printf("\nPlease enter an integer value corresponding to an option in the menu.");
				break;
		}
	} while (iOption != 0);
	
	// End Program 
	printf("\n\nThank you! Have a nice day!");
	
	return 0;
}
