/*
Lab #8
Justin Varga
CSE 130-01
3/19/2021
Description: Simulation of a phone book which allows for adding, removing, and displaying entries, sorting entries alphabetically, selecting a random entry, finding a number by name, and removing all entries
	     and saving to/opening from a file using structures and arrays with dynamic data allocation.
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

void sortEntries();

void displayNumber(const char*, const char*);
void displayRandom();
int displayRange(int, int);

void rmvAll();

void saveEntriesTo(const char*);
void openEntriesFrom(const char*);
void addEntriesFrom(const char*);

/* Declare Global Variables */
const char* NEM = "\nThere is not enough memory to process this task."; 

const char* OPTIONS[9] = {"Add Contact", "Remove Contact", "Show Contacts", "Sort Contacts", "Find Number by Name", "Show Random Contact", "Remove All Contacts", "Save to File", "Open from File"};
const int START = 5;

const char* DEFAULT_PATH = "phonebook.txt";

entry *EntryList;
int iTotalEntries;
int iOpenEntries;

/* Define Main Function */
int main()
{
	// Initialize global variables
	srand(time(NULL));
	EntryList = (entry*)calloc(START, sizeof(entry));
	iOpenEntries = START;
	iTotalEntries = 1;
	
	// Declare local variables
	char cOption;
	char cFirstName[LEN];
	char cLastName[LEN];
	char cNumber[LEN];
	char cFilePath[LEN];
	
	int i = 0;
	int o = 0;
	int iRand = 0;
		
	// Begin Program
	printf("Welcome to Justin Varga's Phonebook Program!\n");
	
	// Loop until user enters "X"
	do
	{	
		// Show Menu
		printf("\n\n--------- Phonebook  Menu ---------\n");
		
		for (o = 0; o < 9; o++)
		{
			printf("\n [%d]: %s", o, OPTIONS[o]);
			if (o == 2 || o == 6) printf("\n");
		}
		printf("\n\n [X]: %s\n", "EXIT");
		
		// Prompt and take input
		printf("\nPlease enter an option listed above: ");
		scanf(" %c", &cOption);
		cOption = toupper(cOption);
		
		switch (cOption)
		{
			// Add Entry
			case '0': 
				printf("\n-v-v-v-v-v- Add Contact -v-v-v-v-v-\n");
				
				// Get first name
				printf("\nFirst Name: ");
				scanf(" %[^\n]s", cFirstName);
				
				// Get last name
				printf("Last Name: ");
				scanf(" %[^\n]s", cLastName);
				
				// Get number
				printf("Number: ");
				scanf(" %[^\n]s", cNumber);
				
				// Add entry
				addEntry(cFirstName, cLastName, cNumber);
				printf("\nRecord added successfully.");
				
				// Exit switch
				break;
				
			// Remove Entry
			case '1':
				printf("\n-v-v-v-v- Remove  Contact -v-v-v-v-\n");
				
				// Ensure there are entries that can be removed
				if (iTotalEntries <= 1)
				{
					printf("\nThere are no entries to remove.");
					break;
				}
				
				// Get name to remove
				printf("\nFirst Name: ");
				scanf(" %[^\n]s", cFirstName);
				
				printf("Last Name: ");
				scanf(" %[^\n]s", cLastName);
				
				// Attempt to remove entry
				rmvEntry(cFirstName, cLastName);
				
				// Exit switch
				break;

			// Display Entries
			case '2':
				printf("\n-v-v-v-v-  Contact  List  -v-v-v-v-\n");
				
				if (displayRange(0, iTotalEntries - 1) == 0)
				{
					printf("\nThere are no entries to display.");
				}
							
				// Exit switch
				break;	
			
			// Alphabetical Sort
			case '3':
				printf("\n-v-v-v-v-  Contact  List  -v-v-v-v-\n");
				
				if (iTotalEntries <= 2)
				{
					printf("\nThere are not enough entries to sort.");
					break;
				}
				
				sortEntries();
				
				displayRange(0, iTotalEntries - 1);
				
				// Exit Switch
				break;
				
			// Find Number for Name
			case '4':
				printf("\n-v-v-v-v-v- Find Number -v-v-v-v-v-\n");
				
				// Ensure there are even contacts to be searched
				if (iTotalEntries <= 1)
				{
					printf("\nThere are no entries to be searched.");
					break;
				}
				
				// Get name to remove
				printf("\nFirst Name: ");
				scanf(" %[^\n]s", cFirstName);
				
				printf("Last Name: ");
				scanf(" %[^\n]s", cLastName);
				
				// Attempt to display entry
				displayNumber(cFirstName, cLastName);
				
				// Exit Switch
				break;
				
			// Random Selection
			case '5':
				printf("\n-v-v-v-v- Random  Contact -v-v-v-v-\n");
				
				// Ensure there is a contact to display
				if (iTotalEntries <= 1)
				{
					printf("\nThere is not an entry to be selected.");
					break;
				}
				
				// Display contact
				displayRandom();
				
				// Exit Switch
				break;
				
			// Remove All
			case '6':
				printf("\n-v-v-v- Remove All Contacts -v-v-v-\n");
				
				// Ensure there are entries to remove
				if (iTotalEntries <= 1)
				{
					printf("\nThere are no entries to remove.");
					break;
				}
				
				// Remove all entries
				rmvAll();
				
				// Signal the user
				printf("\nAll records have been removed.");
				
				// Exit Switch
				break;
			
			// Save to file
			case '7':
				printf("\n-v-v- Save Entry List To File -v-v-\n");
				
				// Get file name from the user
				printf("\nText File Path: ");
				scanf(" %[^\n]s", cFilePath);
				
				if (strstr(cFilePath, ".txt") == NULL)
				{
					strcat(cFilePath, ".txt");
				}
				
				// Save to the file
				saveEntriesTo(cFilePath);
				
				// Exit Switch
				break;
			
			// Open from file
			case '8':
				printf("\n-v-v-v-  Open File Entries  -v-v-v-\n");
				
				// Get file name from the user
				printf("\nText File Path: ");
				scanf(" %[^\n]s", cFilePath);
				
				if (strstr(cFilePath, ".txt") == NULL)
				{
					strcat(cFilePath, ".txt");
				}
				
				// Attempt to open file
				openEntriesFrom(cFilePath);
				
				// Exit Switch
				break;
			
			// EXIT
			case 'X': 
				printf("\n\nThank you! Have a nice day!");
				exit(EXIT_SUCCESS);
				break;
				
			/* Any input that isn't on the menu */
			default: 
				printf("\nPlease enter an integer value corresponding to an option in the menu.");
				break;
		}
		
		printf("\n\n-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-");
		
	} while (cOption != 'X');
	
	// End Program 
	//free(EntryList);
	
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
		perror(NEM);
		exit(EXIT_FAILURE);
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
	//free(list2);	
	
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
			perror(NEM);
			exit(EXIT_FAILURE);
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
		//free(list2);
		
		printf("\nRecord removed successfully.");
	}
}

int displayRange(int a, int b)
{
	int iEntries = 0;
	int i;
	
	// Test if range is valid
	if (a > b || b >= iTotalEntries || a < 0 || b < 0)
	{
		//printf("\nCan not display entries [%d, %d]\nRange is invalid.", a, b);
		return -1;
	}
	
	// Display all entries in range
	for (i = a; i <= b; i++)
	{
		entry e = EntryList[i];
		if (strcmp(e.firstName, "") != 0 && strcmp(e.lastName, "") != 0 && strcmp(e.number, "") != 0)
		{
			iEntries += 1;
			printf("\n%s, %s : %s", &e.lastName, &e.firstName, &e.number);
		}
	}
	
	return iEntries;
}

void displayRandom()
{
	int iRand;
	
	do
	{
		iRand = rand() % iTotalEntries;
	}
	while(displayRange(iRand, iRand) <= 0);
}

void sortEntries() // Sorts entries in EntryList alphabetically by last name then first name
{
	// Declare local variables
	int i, j, k;
	
	// Go through all entries
	for (i = 1; i < iTotalEntries; i++)
	{
		for (j = i + 1; j < iTotalEntries; j++)
		{
			// Declare variables
			entry *e1, *e2;
			char *ln1, *fn1, *nm1;
			char *ln2, *fn2, *nm2;
			char *ln3, *fn3, *nm3;
			
			// Initialize variables
			e1 = &EntryList[i];
			e2 = &EntryList[j];
			
			fn1 = (char*)calloc(strlen(ln1), sizeof(char));
			ln1 = (char*)calloc(strlen(ln1), sizeof(char));
			nm1 = (char*)calloc(strlen(nm1), sizeof(char));
			
			fn2 = (char*)calloc(strlen(ln1), sizeof(char));
			ln2 = (char*)calloc(strlen(ln1), sizeof(char));
			nm2 = (char*)calloc(strlen(nm2), sizeof(char));
			
			if (fn1 == NULL || fn2 == NULL || ln1 == NULL || ln2 == NULL || nm1 == NULL || nm2 == NULL)
			{
				perror(NEM);
				exit(EXIT_FAILURE);
			}
			
			strcpy(fn1, (*e1).firstName);
			strcpy(ln1, (*e1).lastName);
			strcpy(nm1, (*e1).number);
			
			strcpy(fn2, (*e2).firstName);
			strcpy(ln2, (*e2).lastName);
			strcpy(nm2, (*e2).number);
		
			// Test for alphabetical order
			if (strcmp(fn1, "") != 0 && strcmp(fn2, "") != 0 && strcmp(ln1, "") != 0 && strcmp(ln2, "") != 0) // Valid entry
			{
				// Get valid names for comparison
				char* n1 = (char*)calloc(strlen(ln1), sizeof(char));
				char* n2 = (char*)calloc(strlen(ln2), sizeof(char));
				
				if (n1 == NULL || n2 == NULL) 
				{
					perror(NEM);
					exit(EXIT_FAILURE);
				}
				
				// Copy last names into n1 and n2
				strcpy(n1, ln1);
				strcpy(n2, ln2);
				
				// Capitalize all letters in the strings
				for (k = 0; k < strlen(n1); k++) n1[k] = toupper(ln1[k]);
				for (k = 0; k < strlen(n2); k++) n2[k] = toupper(ln2[k]);
				
				// Compare last names
				if (strcmp(n1, n2) > 0) // Swap entries
				{	
					// Switch Entries
					strncpy((*e1).firstName,	fn2,		LEN);
					strncpy((*e1).lastName,		ln2,		LEN);
					strncpy((*e1).number,		nm2,		LEN);
					
					strncpy((*e2).firstName,	fn1,		LEN);
					strncpy((*e2).lastName,		ln1,		LEN);
					strncpy((*e2).number,		nm1,		LEN);
					/*
					strncpy((e2).firstName,		(temp).firstName,	LEN);	printf("\n100");
					strncpy((e2).lastName,		(temp).lastName,	LEN);	printf("\n200");
					strncpy((e2).number,		(temp).number,		LEN);	printf("\n300");
					*/
				}
			}
		}
	}
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

void rmvAll() // Removes all entries
{
	entry *temp;
	int i;
	
	temp = (entry*)calloc(START, sizeof(entry));
	
	if (temp == NULL)
	{
		perror(NEM);
		exit(EXIT_FAILURE);
	}
	else
	{
		//free(EntryList);
		EntryList = temp;
		iTotalEntries = 1;
		//free(temp);
		return;
	}
}

void saveEntriesTo(const char* fileName)
{
	// Declare local variables
	FILE *pFile;
	int i;
	
	// Get file
	pFile = fopen(fileName, "w");
	
	if (pFile == NULL)
	{
		pFile = fopen(DEFAULT_PATH, "w");
		
		if (pFile == NULL)
		{
			perror("\nFile could not be opened.");
			exit(EXIT_FAILURE);
		}
	}
	
	// fprintf every entry into the file
	for (i = 0; i < iTotalEntries; i++)
	{
		entry e = EntryList[i];
		if (strcmp(e.firstName, "") != 0 && strcmp(e.lastName, "") != 0 && strcmp(e.number, "") != 0) // Make sure the entry is valid
		{
			fprintf(pFile, "%s\t\t%s\t\t%s\n", &e.firstName, &e.lastName, &e.number);
		}
	}
	
	// Exit file
	fclose(pFile);
	
	// Prompt user
	printf("\nSaved file \"%s\" successfully.", fileName);
}

void openEntriesFrom(const char* fileName) // Make EntryList the same as file
{
	// Declare local variables
	FILE *pSource;
	int iEntries = 0;
	
	// Get file
	pSource = fopen(fileName, "r");
	
	if (pSource == NULL)
	{
		pSource = fopen(DEFAULT_PATH, "r");
		
		if (pSource == NULL)
		{
			perror("\nFile could not be opened.");
			exit(EXIT_FAILURE);
		}
	}
	
	// Remove all existing entries
	rmvAll();
	
	// Parse every entry from the file
	while (!feof(pSource))
	{
		// Prepare catcher variables
		char fn[LEN];
		char ln[LEN];
		char nm[LEN];
		
		// Scan file
		fscanf(pSource, "%s\t\t%s\t\t%s", fn, ln, nm);
		
		// Add entry if unique and valid
		if (strcmp(fn, "") != 0 && strcmp(ln, "") != 0 && strcmp(nm, "") != 0 && findEntry(fn, ln) < 0)
		{
			addEntry(fn, ln, nm);	
			iEntries++;
		}
	}
	
	// Close file
	fclose(pSource);
	
	// Prompt user
	if (iEntries <= 0)
	{
		printf("\nNo entries were found in that file.");
	}
	else
	{
		printf("\n%d entries from \"%s\" successfully added.", iEntries, fileName);
	}
}
