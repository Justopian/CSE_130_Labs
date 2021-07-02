/*
Lab #5
Justin Varga
CSE 130-01
2/15/2021
Description: A program which uses pointers and arrays to formulate an ad lib story.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function Prototype
int iRandom(int);

void toLower(char *);
void toUpper(char *);

void capitalizeFirst(char *);

void changeUp(char [], char []);

// Begin Program
int main()
{
	// Initialize Variables
	const char *cDESSERTS[10] = {"pudding cup", "cake", "fruit", "donut", "brownie", "milkshake", "smoothie", "cheesecake", "pie", "cookie"};
	const char *cCARTYPES[10] = {"Ford F-150", "Toyota Corolla", "BMW i8", "Ford Mustang", "1961 VW Microbus", "Tesla Model S", "Jeep", "Yugo", "VW Beetle", "Prius"};
	char *cUSCITIES[10] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix", "Milwaukee", "Boston", "Orlando", "Seattle", "Atlanta"};
	char *cKYCITIES[10] = {"Louisville", "Lexington", "Covington", "Bowling Green", "Paducah", "Pikeville", "Frankfort", "Owensboro", "Danville", "Ashland"};
	
	char cYou[50];
	char cColor[50];
	char cHome[50];
	
	char cWizard[50];
	char cNeverland[50];
	
	int iRandoms[4];
	int iSquadSize;
	int iAge;
	int iLuck;
	int i;
	
	char cDessert[11];
	char cCar[20];
	char cGroup[10];
	char *cCities[4];
	
	// Generate random numbers for the story
	srand(time(NULL));
	
	// Get rid of duplicates so that the cities are not the same
	for(i = 0; i < 4; i += 2)
	{
		iRandoms[i] = iRandom(10);
		iRandoms[i+1] = iRandom(10);
		
		while(iRandoms[i] == iRandoms[i+1])
		{
			iRandoms[i] = iRandom(10);
			iRandoms[i+1] = iRandom(10);
		}
	}
	
	// Apply the random numbers
	strcpy(cCar, cCARTYPES[iRandom(10)]);
	strcpy(cDessert, cDESSERTS[iRandom(10)]);
	toLower(cDessert);
	
	for(i = 0; i < 4; i++)
	{
		if(i < 2)
		{
			cCities[i] = cKYCITIES[iRandoms[i]];	
		}
		else
		{
			cCities[i] = cUSCITIES[iRandoms[i]];	
		}
	}
	
	iAge = iRandom(20) + 15;
	
	// Take input
	printf("What is your name?\n");
	scanf(" %[^\n]s", &cYou); // Debugging these required something that wasn't in the book
	
	printf("\nAbout how many close friends do you have?\n");
	scanf("%d", &iSquadSize);
	
	printf("\nWhat is your favorite color?\n");
	scanf(" %[^\n]s", &cColor);
	
	printf("\nWhat is your hometown?\n");
	scanf(" %[^\n]s", &cHome);
	
	// Tell the Story
	changeUp(cYou, cWizard);
	changeUp(cHome, cNeverland);
	strcat(cNeverland, " City");
	
	if(iSquadSize < 0) iSquadSize *= -1;
	iLuck = iRandom(2 * iSquadSize + 3) % 5;
	
	capitalizeFirst(cHome);
	
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	
	printf("\tWhen %s was at the age of %d, they looked out their window at their humble home of %s.", cYou, iAge, cHome);
	printf("\nOn this fateful day, %s saw quite a spectacle coming down the road!", cYou);
	printf("\nIt was an old man driving a %s %s. Nobody in %d miles of %s owns such a vehicle!", cColor, cCar, iRandom(50) + 25, cHome);
	
	printf("\n\n\t%s called out, \"Hey, old man! What are you doing around these parts?\"", cYou);
	printf("\n\tThe old man stopped his vehicle, stepped out, and replied to the heckler, \"%s, I've been looking for you!", cYou);
	printf("\nMy name is %s, and I come from the distant land of %s! It's a few miles outside of %s. I come bearing gifts!\"", cWizard, cNeverland, cCities[2]);
	
	printf("\n\n\tIntrigued, %s asked the man, \"%s, how did you know my name, and what gifts did you bring?\"", cYou, cWizard);
	printf("\n\t%s responded, \"You see, I am magic! I know just what you crave: assorted %ss!\"", cWizard, cDessert);
	printf("\n\t%s waved his hand, and, poof! he produced a shimmering %s %s out of thin air! %s was amazed. \"Wow! May I have it?\"", cWizard, cColor, cDessert, cYou);
	printf("\n\t%s handed the %s to %s gingerly. \"Well of course! I mean, I brought it all the way from %s for you.", cWizard, cDessert, cYou, cCities[2]);
	printf("\n\"But don't be deceived by the copies found in %s or %s. Those ones may be... dangerous...\"", cCities[3], cCities[1]);
	
	printf("\n\n\tOnce they received the %s, %s took a suspicious taste. Noticing nothing extraordinary at first, they took another. Soon, only crumbs remained!", cDessert, cYou);
	printf("\n\tThe old wizard of %s grinned a toothy grin, then whispered, \"", cNeverland);
	
	switch(iLuck)
	{
		case 0: // Very bad
			printf("I brought that one from %s.", cCities[3]);
			printf("\n\"You see, I am not just a wizard. I am a MALEFICENT wizard! You should never take sweets from a stranger! Especially an old man like me!\"");
			printf("\n\t%s then snapped his fingers. Before %s could blink, the old man and his %s %s were gone!", cWizard, cYou, cColor, cCar);
			printf("\n\tWithin minutes, %s's stomach started the gurgle. Then, they collapsed! Poison...", cYou);
			break;
			
		case 1: // Bad
			printf("I brought that one from %s.", cCities[1]);
			printf("\n\"You see, I am not just a wizard. I am an EVIL wizard! You should never take sweets from a stranger! Especially an old man like me!\"");
			printf("\n\t%s then snapped his fingers. Before %s could blink, the old man and his %s %s were gone!", cWizard, cYou, cColor, cCar);
			printf("\n\tWithin minutes, %s noticed a nasty aftertaste. However, they realized it could have been worse...", cYou);
			break;
				
			
		case 3: // Good
			printf("I brought you %s's finest.", cCities[2]);
			printf("\n\"You see, I am not just a wizard. I am a GOOD wizard! However, you should probably not take sweets from a stranger! Especially an old man like me!\"");
			printf("\n\t%s then snapped his fingers. Before %s could blink, the old man and his %s %s were gone!", cWizard, cYou, cColor, cCar);
			printf("\n\tWithin minutes, %s felt elated. It was truly the best dessert they had ever consumed.", cYou);
			break;
			
			
		case 4: // Very good
			printf("I brought you %s's finest.", cCities[2]);
			printf("\n\"You see, I am not just a wizard. I am a MAGNANIMOUS wizard! However, you should probably not take sweets from a stranger! Especially an old man like me!\"");
			printf("\n\t%s then snapped his fingers. Before %s could blink, the old man was gone. However, he left his %s %s, and the keys were still in the ignition!", cWizard, cYou, cColor, cCar);
			printf("\n\tIn the coming months, %s used their new ride to become the coolest kid from %s to %s.", cYou, cHome, cCities[0]);
			break;
			
		default: // Neutral
			printf("I brought that one from %s.", cCities[2]);
			printf("\n\"You see, I am but a novice wizard. You should probably not take sweets from a stranger, though. Especially an old man like me!\"");
			printf("\n\t%s then snapped his fingers. Before %s could blink, the old man and his %s %s were gone!", cWizard, cYou, cColor, cCar);
			printf("\n\tWithin minutes, %s started to lose the memories of what had just taken place, but they remembered the lesson...", cYou);
			break;
	}
	
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~The End~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	return 0;
}

// Define helper functions
int iRandom(int max)
{
	return rand() % max;
}

void toLower(char *str) // Makes all characters in string str lowercase
{
	int i;
	for(i = 0; i < strlen(str); i++)
	{
		char c = tolower(str[i]);
		str[i] = c;
	}
}

void toUpper(char *str) // Capitalizes the entire string str
{
	int i;
	for(i = 0; i < strlen(str); i++)
	{
		char c = toupper(str[i]);
		str[i] = c;
	}
}

void capitalizeFirst(char *str)
{
	int i;
	for(i = 0; i < strlen(str); i++)
	{
		if(i == 0 || str[i-1] == ' ')
		{
			str[i] = toupper(str[i]);
		}
	}
}

int firstIndexOf(char c, char *str)
{
	int i;
	for(i = 0; str[i]; i++)
	{
		if(str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

void changeUp(char name[], char newName[])
{
	char *cLetters = "aeiouybcdfghjklmnpqrstvwxz";
	char cRandomLs[26];
	
	// Randomize the characters
	int r = iRandom(20);
	
	int i;
	for(i = 0; i < 6; i++)
	{
		cRandomLs[i] = cLetters[(i + r) % 6];
	}
	for(i = 6; i < 26; i++)
	{
		cRandomLs[i] = cLetters[(i + r) % 20 + 6];
	}
	
	// Switch the characters
	for(i = 0; name[i]; i++)
	{
		char c = tolower(name[i]);
		int n = firstIndexOf(c, cLetters);
		
		if(n == -1) // Not a letter
		{
			newName[i] = c;	
		}
		else
		{
			newName[i] = cRandomLs[n];
		}
	}
	
	toLower(newName);
	capitalizeFirst(newName);
}
