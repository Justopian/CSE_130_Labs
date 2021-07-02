/*
Name: Justin Varga
Class: CSE 130-01
Lab #2
Date: 1/27/2021
Description: An ACII table displaying conversions for six (6) different currencies given any input value.
Note: All exchange rates are sourced from the US Federal Reserve, updated 1/19/2021. (https://www.federalreserve.gov/Releases/H10/current/)
*/

#include <stdio.h>

int main()
{
	// Initialize constants
	const float fUSD2USD = 1.0f; // US Dollar to US Dollar (it's obviously 1)
	const float fUSD2BPD = 1.0f / 1.3599f; // US Dollar (USD) to British Pound
	const float fUSD2EUR = 1.2099f; // USD to Euro
	const float fUSD2INR = 73.08f; // USD to Indian Rupee
	const float fUSD2JPY = 103.8f; // USD to Japanese Yen
	const float fUSD2CNY = 6.48f; // USD to Chinese Yuan
	
	const float fFACTORS[] = {fUSD2USD, fUSD2BPD, fUSD2EUR, fUSD2INR, fUSD2JPY, fUSD2CNY};
	const char *cISOCODES[] = {"USD", "BPD", "EUR", "INR", "JPY", "CNY"};
	const char *cHDIVIDER = "\n+-----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n";
	
	// Initialize variables	
	float fInputAmount;
	
	// Begin Program
	printf("Welcome to Justin Varga's Currency Table and Calculator!\n\n");
	
	// Take input
	printf("Please input the monetary amount to be converted: ");
	scanf("%f", &fInputAmount);
	
	// Display table
	printf(cHDIVIDER); // Top Border
	
	/* Headers */
	printf("|     |");
	int i;
	for (i = 0; i < 6; i++)
	{
		printf("       %3s       |", cISOCODES[i]);
	}
	
	printf(cHDIVIDER);
	
	/* Rest of the table */
	int j; // iterator for Converted From Currency
	for (j = 0; j < 6; j++)
	{	
		/* Left Column: Converting From Currency is determined by j*/
		printf("| %3s |", cISOCODES[j]);
		
		/* The rest of the table: k determines the Converted To Currency */
		int k; // iterator for Converted To Currency
		for (k = 0; k < 6; k++)
		{
			/* Conversion = input / USDtoFROM * USDtoTO */
			float fConvertedAmount = fInputAmount / fFACTORS[j] * fFACTORS[k];
			
			/* Display the number and add vertical separator */
			if (fConvertedAmount >= 1e8) // Ensures the value with fit within the cell size
			{
				// If the value is more than 8 digits left of the decimal, it will be displayed in scientific notation...
				printf(" %15.8e |", fConvertedAmount);
			}
			else
			{
				// ...otherwise, it will fit when rounded four places to the right of the decimal.
				printf(" %15.4f |", fConvertedAmount);
			}
		}
		
		/* Bottom Border / Row Divider */
		printf(cHDIVIDER);
	}
	
	// Print Source Information
	printf("\n\nConversion factors are derived from the Federal Reserve's USD conversion factors.\nUpdated 1/19/2021: https://www.federalreserve.gov/Releases/H10/current/\n");
	
	// End program
	return 0;
}
