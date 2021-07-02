/*
Name: Justin Varga
Class: CSE 130-01
Lab #2
Date: 1/27/2021
Description: An ACII table displaying conversions for six (6) different currencies given any input value.
Note: All exchange rates are sourced from the US Federal Reserve, updated 1/25/2021. (https://www.federalreserve.gov/Releases/H10/current/)
*/

#include <stdio.h>

int main()
{
	// Initialize constants (USD -> X Currency)
	const float fToUSD = 1.0f; // US Dollar to US Dollar (it's obviously 1)
	const float fToBPD = 1.0f / 1.3685f; // British Pound Sterling
	const float fToEUR = 1.0f / 1.2179f; // Euro
	const float fToMXN = 19.9250f; // Indian Rupee
	const float fToJPY = 103.8f; // Japanese Yen
	const float fToCNY = 6.481f; // Chinese Yuan
	
	// Initialize variables	
	float fInput;
	float fUSDtoUSD, fUSDtoBPD, fUSDtoEUR, fUSDtoMXN, fUSDtoJPY, fUSDtoCNY;
	float fBPDtoUSD, fBPDtoBPD, fBPDtoEUR, fBPDtoMXN, fBPDtoJPY, fBPDtoCNY;
	float fEURtoUSD, fEURtoBPD, fEURtoEUR, fEURtoMXN, fEURtoJPY, fEURtoCNY;
	float fMXNtoUSD, fMXNtoBPD, fMXNtoEUR, fMXNtoMXN, fMXNtoJPY, fMXNtoCNY;
	float fJPYtoUSD, fJPYtoBPD, fJPYtoEUR, fJPYtoMXN, fJPYtoJPY, fJPYtoCNY;
	float fCNYtoUSD, fCNYtoBPD, fCNYtoEUR, fCNYtoMXN, fCNYtoJPY, fCNYtoCNY;
	
	
	// Begin Program
	printf("Welcome to Justin Varga's Currency Table and Calculator!\n\n");
	
	// Take input
	printf("Please input the monetary amount to be converted: ");
	scanf("%f", &fInput);
	
	/* Display Table */
	// Table Headers
	printf("\n+-----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	printf("|     |   US  Dollars   | Pounds Sterling |      Euros      |  Mexican Pesos  |  Japanese  Yen  |  Chinese  Yuan  |");
	printf("\n+-----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	
	// US Dollars (USD)
	fUSDtoUSD = fInput;
	fUSDtoBPD = fUSDtoUSD * fToBPD;
	fUSDtoEUR = fUSDtoUSD * fToEUR;
	fUSDtoMXN = fUSDtoUSD * fToMXN;
	fUSDtoJPY = fUSDtoUSD * fToJPY;
	fUSDtoCNY = fUSDtoUSD * fToCNY;
	
	printf("| USD | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f |", fUSDtoUSD, fUSDtoBPD, fUSDtoEUR, fUSDtoMXN, fUSDtoJPY, fUSDtoCNY);
	printf("\n+-----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	
	// Pounds Sterling (BPD)
	fBPDtoUSD = fUSDtoUSD / fToBPD;
	fBPDtoBPD = fInput;
	fBPDtoEUR = fUSDtoEUR / fToBPD;
	fBPDtoMXN = fUSDtoMXN / fToBPD;
	fBPDtoJPY = fUSDtoJPY / fToBPD;
	fBPDtoCNY = fUSDtoCNY / fToBPD;
	
	printf("| BPD | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f |", fBPDtoUSD, fBPDtoBPD, fBPDtoEUR, fBPDtoMXN, fBPDtoJPY, fBPDtoCNY);
	printf("\n+-----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	
	// Euro (EUR)
	fEURtoUSD = fUSDtoUSD / fToEUR;
	fEURtoBPD = fUSDtoBPD / fToEUR;
	fEURtoEUR = fInput;
	fEURtoMXN = fUSDtoMXN / fToEUR;
	fEURtoJPY = fUSDtoJPY / fToEUR;
	fEURtoCNY = fUSDtoCNY / fToEUR;
	
	printf("| EUR | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f |", fEURtoUSD, fEURtoBPD, fEURtoEUR, fEURtoMXN, fEURtoJPY, fEURtoCNY);
	printf("\n+-----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	
	// Indian Rupee (MXN)
	fMXNtoUSD = fUSDtoUSD / fToMXN;
	fMXNtoBPD = fUSDtoBPD / fToMXN;
	fMXNtoEUR = fUSDtoEUR / fToMXN;
	fMXNtoMXN = fInput;
	fMXNtoJPY = fUSDtoJPY / fToMXN;
	fMXNtoCNY = fUSDtoCNY / fToMXN;
	
	printf("| MXN | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f |", fMXNtoUSD, fMXNtoBPD, fMXNtoEUR, fMXNtoMXN, fMXNtoJPY, fMXNtoCNY);
	printf("\n+-----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	
	// Japanese Yen (JPY)
	fJPYtoUSD = fUSDtoUSD / fToJPY;
	fJPYtoBPD = fUSDtoBPD / fToJPY;
	fJPYtoEUR = fUSDtoEUR / fToJPY;
	fJPYtoMXN = fUSDtoMXN / fToJPY;
	fJPYtoJPY = fInput;
	fJPYtoCNY = fUSDtoCNY / fToMXN;
	
	printf("| JPY | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f |", fJPYtoUSD, fJPYtoBPD, fJPYtoEUR, fJPYtoMXN, fJPYtoJPY, fJPYtoCNY);
	printf("\n+-----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	
	// Chinese Yuan (CNY)
	fCNYtoUSD = fUSDtoUSD / fToCNY;
	fCNYtoBPD = fUSDtoBPD / fToCNY;
	fCNYtoEUR = fUSDtoEUR / fToCNY;
	fCNYtoMXN = fUSDtoMXN / fToCNY;
	fCNYtoJPY = fUSDtoJPY / fToCNY;
	fCNYtoCNY = fInput;
	
	printf("| CNY | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f | %15.4f |", fCNYtoUSD, fCNYtoBPD, fCNYtoEUR, fCNYtoMXN, fCNYtoJPY, fCNYtoCNY);
	printf("\n+-----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	
	// Print Source Information
	printf("\n\nConversion factors are derived from the Federal Reserve's USD conversion factors.\nUpdated 1/25/2021: https://www.federalreserve.gov/Releases/H10/current/\n");
	
	// End program
	return 0;
}
