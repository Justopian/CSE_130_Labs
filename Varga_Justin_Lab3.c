/*
Lab #3
Justin Varga
CSE 130-01
1/26/2021
Description: Simulate a calculator with five basic operations and prime number testing.
*/

#include <stdio.h>

int main()
{
	/* Declare Variables */
	int iOption; // Stores user input 
	float fA, fB; // Addition, Subtraction, and Multiplication Variables
	float fDividend, fDivisor, fQuotient; // Division Variables
	int iDividend, iDivisor, iRemainder; // Modulo Variables
	int iPotentialPrime, iFactor1, iFactor2, iNumFactors; // Prime Number Check Variables

	/* Begin Program */
	printf("Welcome to Justin Varga's Calculator Program!");
	
	// Loop until user enters "6"
	do
	{
		// Prompt and take input
		printf("\n\nCalculator Menu:\n[0]: Addition\n[1]: Subtraction\n[2]: Multiplication\n[3]: Division\n[4]: Modulo\n[5]: Prime Number Check\n[6]: EXIT\n\nPlease enter an option listed above: ");
		scanf("%d", &iOption);
		
		switch (iOption)
		{
			/* Addition */
			case 0: 
				printf("\nAddition:\n");
				
				//Ask for two floats A and B (A + B)
				printf("\n\tPlease enter the first number: ");
				scanf("%f", &fA);
				
				printf("\tPlease enter the second number: ");
				scanf("%f", &fB);
				
				// Display addition equation
				printf("\n\t%.6f + %.6f = %.6f\n", fA, fB, fA + fB);
				
				// Exit switch
				break;
				
			/* Subtraction */
			case 1:
				printf("\nSubtraction:\n");
				
				// Ask for two floats A and B (A - B)
				printf("\n\tPlease enter the number to be subtracted from: ");
				scanf("%f", &fA);
				
				printf("\tPlease enter the value %f shall be subtracted by: ", fA);
				scanf("%f", &fB);
				
				// Display the subtraction equation
				printf("\n\t%.6f - %.6f = %.6f", fA, fB, fA - fB);
				
				// Exit switch
				break;
				
			/* Multiplication */
			case 2:
				printf("\nMultiplication:\n");
				
				// Ask for two floats A and B (A x B)
				printf("\n\tPlease enter the first number: ");
				scanf("%f", &fA);
				
				printf("\tPlease enter the second number: ");
				scanf("%f", &fB);
				
				// Display addition equation
				printf("\n\t%.6f x %.6f = %.6f", fA, fB, fA * fB);
							
				// Exit switch
				break;
				
			/* Division */
			case 3:	
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
				
			/* Modulo */
			case 4:
				printf("\nModulo:\n");
				
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
			case 5:
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
			
			/* EXIT */
			case 6: 
				// Exit switch
				break;
				
			/* Any input that isn't on the menu */
			default: 
				printf("\nPlease enter an integer value corresponding to an option in the menu.");
				break;
		}
	} while (iOption != 6);
	
	// End Program 
	printf("\n\nThank you! Have a nice day!");
	
	return 0;
}
