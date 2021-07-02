/*
Lab #6
Justin Varga
CSE 130-01
3/3/2021
Description: Simulation of a phone book which allows for adding, removing, and displaying entries using structures and arrays with dynamic data allocation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

/* Declare and Define Structures */
typedef struct 
{
	char firstName[LEN];
	char lastName[LEN];
	char number[LEN];
} entry;

/* Function Protoypes */
int findEntry(const char*, const char*);

void addEntry(const char*, const char*, const char*);
void rmvEntry(const char*, const char*);

void switchEntries(int, int);
void sortEntries();

void displayNumber(const char*, const char*);
void displayRandom();
void displayRange(int, int);

void rmvRange(int, int);

/* Declare Global Variables */
const int START = 5;

entry *EntryList;
int iTotalEntries;
int iOpenEntries;

/* Define Main Function */
int main()
{
	// Initialize global variables
	EntryList = (entry*)calloc(START, sizeof(entry));
	iOpenEntries = START;
	iTotalEntries = 1;
	
	// Declare local variables
	char cOption;
	char cFirstName[LEN];
	char cLastName[LEN];
	char cNumber[LEN];
	
	int i = 0;
	int iRand = 0;
		
	// Begin Program
	printf("Welcome to Justin Varga's Phonebook Program!");
	
	// Loop until user enters "X"
	do
	{	
		// Prompt and take input
		printf("\n\n~~~~~Phonebook Menu~~~~~\n[0]: Add Entry\n[1]: Remove Entry\n[2]: Show Entries\n[X]: EXIT\n\nPlease enter an option listed above: ");
		scanf(" %c", &cOption);
		cOption = toupper(cOption);
		
		switch (cOption)
		{
			// Add Entry
			case '0': 
				printf("\n~~~~~Add Entry~~~~~\n");
				
				// Get first name
				printf("\nFirst Name: ");
				scanf(" %[^\n]s", &cFirstName);
				
				// Get last name
				printf("Last Name: ");
				scanf(" %[^\n]s", &cLastName);
				
				// Get number
				printf("Number: ");
				scanf(" %[^\n]s", &cNumber);
				
				// Add entry
				addEntry(cFirstName, cLastName, cNumber);
				printf("\nRecord added successfully.");
				
				// Exit switch
				break;
				
			// Remove Entry
			case '1':
				// Ensure there are entries that can be removed
				if (iTotalEntries == 0)
				{
					printf("\nThere are no entries to remove. Please select a different option.");
					break;
				}
				
				printf("\n~~~~~Remove Entry~~~~~\n");
				
				// Get name to remove
				printf("\nFirst Name: ");
				scanf(" %[^\n]s", &cFirstName);
				
				printf("Last Name: ");
				scanf(" %[^\n]s", &cLastName);
				
				// Attempt to remove entry
				rmvEntry(cFirstName, cLastName);
				printf("\nRecord removed successfully.");
				
				// Exit switch
				break;

			// Display Entries
			case '2':
				printf("\n~~~~~Phone Book~~~~~\n");
				
				displayRange(0, iTotalEntries - 1);
							
				// Exit switch
				break;	
			
			// Alphabetical Sort
			case '3':
				printf("\n~~~~~Phone Book~~~~~\n");
				
				// Exit Switch
				break;
				
			// Find Number for Name
			case '4':
				printf("\n~~~~~Phone Book~~~~~\n");
				
				// Get name to remove
				printf("\nFirst Name: ");
				scanf(" %[^\n]s", &cFirstName);
				
				printf("Last Name: ");
				scanf(" %[^\n]s", &cLastName);
				
				// Attempt to display entry
				displayNumber(cFirstName, cLastName);
				
				// Exit Switch
				break;
				
			// Random Selection
			case '5':
				printf("\n~~~~~Phone Book~~~~~\n");
				
				// Get random number
				iRand = rand() % iTotalEntries;
				
				// Display contact
				displayRange(iRand, iRand);
				
				// Exit Switch
				break;
				
			// Remove All
			case '6':
				printf("\n~~~~~Phone Book~~~~~\n");
				
				// Remove all entries
				rmvRange(0, iTotalEntries - 1);
				
				// Exit Switch
				break;
			
			// EXIT
			case 'X': 
				// Exit switch
				break;
				
			/* Any input that isn't on the menu */
			default: 
				printf("\nPlease enter an integer value corresponding to an option in the menu.");
				break;
		}
	} while (cOption != 'X');
	
	// End Program 
	printf("\n\nThank you! Have a nice day!");
	//free(EntryList);
	return 0;
}

/* Other Functions */
int findEntry(const char* fn, const char* ln) // Returns the first index of an entry with given first name fn and last name ln, -1 if not found
{
	// Delcare local variables
	entry e;
	int i;
	
	// Attempt to find it
	for (i = 0; i < iTotalEntries; i++)
	{
		e = *(EntryList + i);
		
		if (strcmp(e.lastName, ln) == 0 && strcmp(e.firstName, fn) == 0)
		{
			// A matching entry has been found!
			return i;
		}
	}
	
	// If not found, return -1
	return -1;
}

void addEntry(const char* fn, const char* ln, const char* num)
{
	// Declare local variables
	entry* list2;
	int i;
	
	// Allocate memory for the addition
	if (iTotalEntries + 1 >= iOpenEntries)
	{
		iOpenEntries *= 2;
	}
	
	list2 = (entry*)malloc(iOpenEntries * sizeof(entry));
	
	if (list2 == NULL)
	{
		printf("\nNo more memory is available for allocation...");
		return;
	}
	
	// Add the items
	strncpy(list2[iTotalEntries].firstName, fn, LEN);
	strncpy(list2[iTotalEntries].lastName, ln, LEN);
	strncpy(list2[iTotalEntries].number, num, LEN);
	
	for (i = 0; i < iTotalEntries; i++)
	{
		list2[i] = EntryList[i];
	}
	
	EntryList = list2;
	
	// Initialize all elements of the array
	for (i = 0; i <= iTotalEntries; i++)
	{
		strncpy(EntryList[i].firstName, list2[i].firstName, LEN);
		strncpy(EntryList[i].lastName, list2[i].lastName, LEN);
		strncpy(EntryList[i].number, list2[i].number, LEN);
	}
	
	// Increment entries present
	iTotalEntries++;
	
	// Free memory
	free(list2);	
	
	// Exit function
	return;
}

void rmvEntry(const char* fn, const char* ln)
{
	// Declare variables
	int rmvIndex, i;
	
	// Attempt to find a matching entry
	rmvIndex = findEntry(fn, ln);
	
	if (rmvIndex < 0) // Nothing to remove
	{
		printf("\nNo record exists by that name.");
	}
	else // A matching record was found
	{
		// Change size of array if appropriate
		if (iOpenEntries / 2 > iTotalEntries && iOpenEntries / 2 >= 5)
		{
			iOpenEntries /= 2;
		}
		
		entry* list2 = (entry*)malloc(iOpenEntries * sizeof(entry));
		
		if (list2 == NULL)
		{
			printf("\nThere is not enough memory to perform this task.");
			return;
		}
		
		// Copy all elements except the one being removed
		int j = 0;
		for (i = 0; i < iTotalEntries; i++)
		{
			if (i == rmvIndex) continue;
			strncpy(list2[i].firstName, EntryList[i].firstName, LEN);
			strncpy(list2[i].lastName, EntryList[i].lastName, LEN);
			strncpy(list2[i].number, EntryList[i].number, LEN);
		}
		
		// Copy Back
		EntryList = list2;
		
		for (i = 0; i < iTotalEntries; i++)
		{
			strncpy(EntryList[i].firstName, list2[i].firstName, LEN);
			strncpy(EntryList[i].lastName, list2[i].lastName, LEN);
			strncpy(EntryList[i].number, list2[i].number, LEN);
		}
		
		// Decrement the number of entries
		iTotalEntries--;
		
		// Handle error when no entries exist
		if (iTotalEntries == 0)
		{
			strncpy(EntryList[0].firstName, "", LEN);
			strncpy(EntryList[0].lastName, "", LEN);
			strncpy(EntryList[0].number, "", LEN);
		}
		
		// Free memory
		free(list2);
	}
}

void displayRange(int a, int b)
{
	int iEntries = 0;
	int i;
	
	// Test if range is valid
	if (a > b || b >= iTotalEntries || a < 0 || b < 0)
	{
		printf("\nCan not remove entries [%d, %d]\nRange is invalid.", a, b);
		return;
	}
	
	// Display all entries in range
	for (i = a; i <= b; i++)
	{
		entry e = EntryList[i];
		if (strcmp(e.firstName, "") != 0 && strcmp(e.lastName, "") != 0 && strcmp(e.number, "") != 0)
		{
			iEntries++;
			printf("\n%s, %s : %s", &e.lastName, &e.firstName, &e.number);
		}
	}
	
	if (iEntries <= 0)
	{
		printf("\nThere are no entries to display. Please select a different option.");
	}
}

void switchEntries(int a, int b) // Switches entries a and b
{	
	// Declare local variables
	entry *tempE, *eA, *eB;
	
	// Test if the two exist and are valid
	if (a == b || a < 0 || b < 0 || a >= iTotalEntries || b >= iTotalEntries)
	{
		printf("\nCan not switch entries.");
		return;
	}
	
	// Switch Entries
	*tempE = EntryList[b];
	*eA = EntryList[a];
	*eB = EntryList[b];
	
	*eB = *eA;
	*eA = *tempE;	
}

void sortEntries()
{
	// Declare local variables
	
	
	// Go through all entries
	
	// Compare EntryList[i] and EntryList[i+1]
		// Switch if needed
}

void displayNumber(const char* fn, const char* ln)
{
	int n = findEntry(fn, ln);
	
	if (n < 0) // No such record exists
	{
		printf("\nNo record was found with that name.");
	}
	else // Entry found
	{
		entry e = *(EntryList + n);
		printf("\n%s", &e.number);
	}
}

void rmvRange(int a, int b) // Removes all entries in EntryList from EntryList[a] to EntryList[b], inclusive
{
	// Declare local variables
	entry e;
	int i;
	
	// Test if range is valid
	if (a > b || b >= iTotalEntries || a < 0 || b < 0)
	{
		printf("\nCan not remove entries [%d, %d]\nRange is invalid.", a, b);
		return;
	}
	
	// Remove entries
	for (i = a; i <= b; i++)
	{
		e = *(EntryList + i);
		rmvEntry(e.firstName, e.lastName);
	}
}
