/*
Final Project
Justin Varga
CSE 130-01
4/24/2021
Description: Create an illness symptoms checker that displays a symptom table. Additionally, randomly generate a user-input number of patient symptoms and tabulate the results.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <iterator>
#include <sstream>
#include <cstring>
#include <map>

using namespace std;

const string SYMPTOM_LIST[] = {"Fever", "Cough", "Shortness of Breath", "Runny Nose", "Headache", "Sneezing", "Fatigue"};

typedef pair<const string, int> symptom;

class Disease // Abstract class for a disease
{
	protected:
		map<string,int> ss; // Map of symptoms <Symptom Name, Severity>
		string name; // Disease name
		
		void setName(string n) // Sets disease name
		{
			name = n;
		}
		
		void setBaseSymptoms() // Sets all symptom values to 0
		{
			for(int i = 0; i < 7; i++)
			{
				ss.insert(symptom(SYMPTOM_LIST[i], 0));
			}
		}
		
		virtual void setSymptoms() = 0; // Sets the symptoms in derived classes.
		
	public:	
		map<string,int> getSymptoms() // Returns the symptom map
		{
			return ss;
		}
		
		string getName() // Returns the disease's name
		{
			return name;
		}
		
		char getSeverity(string symptomName) // Returns severity of symptom (-,+,*) or ! if symptom is not present
		{
			switch(ss[symptomName])
			{
				case 0:	return '-';
					
				case 1:	return '+';
				
				case 2: return '*';
				
				default: return '!';
			}
		}
};

class Covid : public Disease
{
	protected:
		void setSymptoms()
		{
			setBaseSymptoms();
			
			ss["Fever"] = 2;
			ss["Cough"] = 2;
			ss["Shortness of Breath"] = 2;
			ss["Runny Nose"] = 1;
			ss["Headache"] = 1;
			ss["Fatigue"] = 1;
		}
		
	public:
		Covid()
		{
			setName("COVID-19");
			setSymptoms();
		}
};

class Cold : public Disease
{
	protected:
		void setSymptoms()
		{
			setBaseSymptoms();
			
			ss["Fever"] = 1;
			ss["Cough"] = 1;
			ss["Runny Nose"] = 2;
			ss["Headache"] = 1;
			ss["Sneezing"] = 2;
			ss["Fatigue"] = 1;
		}
		
	public:
		Cold()
		{
			setName("Cold");
			setSymptoms();
		}
};

class Flu : public Disease
{
	protected:
		void setSymptoms()
		{
			setBaseSymptoms();
			
			ss["Fever"] = 2;
			ss["Cough"] = 2;
			ss["Runny Nose"] = 1;
			ss["Headache"] = 2;
			ss["Fatigue"] = 2;
		}
		
	public:
		Flu()
		{
			setName("Flu");
			setSymptoms();
		}
};

class Patient
{
	private:
		map<string,int> symptoms; // <Symptom Name, Absent/Present>
	
	public:
		Patient()
		{
			for(int i = 0; i < 7; i++)
			{
				symptoms.insert(symptom(SYMPTOM_LIST[i], rand() % 2));
			}
		}
		
		Patient(int arr[]) // Constructor used for testing
		{
			for (int i = 0; i < 7; i++)
			{
				symptoms.insert(symptom(SYMPTOM_LIST[i], arr[i]));
			}
		}
		
		bool diagnose(Disease* d) // Patient has a disease if and only if it perfectly matches the chart (has all common symptoms and none of the "no" symptoms)
		{	
			for(int i = 0; i < 7; i++) // For each symptom
			{
				string sN = SYMPTOM_LIST[i]; // Symptom's Name
				
				char disSev = d->getSeverity(sN); // Disease's Severity of Symptom
				bool patHas = (symptoms[sN] == 1); // Patient Has (1)/Doesn't Have (0) Symptom
				
				// Check if patient has a common symptom / doesn't have a "no" symptom / has or doesn't have an uncommon symptom
				if ((patHas && disSev == '*') || (!patHas && disSev == '-') || disSev == '+')
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			
			return true;
		}
		
		void printSymptomChart() // Print used for testing
		{
			map<string, int>::iterator itr;
			
			for (itr = symptoms.begin(); itr != symptoms.end(); ++itr)
			{
				cout << itr->first << ":\t" << itr->second << '\n';
			}
			
			cout << endl;
		}
};

int main()
{
	// Initialize Variables
	Covid covid = Covid();
	Cold cold = Cold();
	Flu flu = Flu();
	
	int numPatients = 0;
	
	int results[] = {0,0,0,0};
	
	const string ROW = "\n+---------------------+----------+------+-----+\n";
	
	// Display Symptom Table
	cout << "Welcome to the Symptom Checker Program!\nby: Justin Varga" << endl;
	
	cout << ROW << "|       SYMPTOM       | COVID-19 | Cold | Flu |" << ROW;
	
	for (int i = 0; i < 7; i++)
	{
		string symName = SYMPTOM_LIST[i];
		
		cout << left << "| " << setw(19) << symName << " | " << setw(8) << covid.getSeverity(symName) << " | " << setw(4) << cold.getSeverity(symName) << " | " << setw(3) << flu.getSeverity(symName) << " |" << ROW;
	}
	
	cout << "Key: - = Not Present  + = Uncommon  * = Common\n" << endl;
	
	// Ask for input
	while (numPatients <= 0)
	{
		cout << "Please enter the number of patients to test : " << endl;
	
		string nPatients;
		
		try
		{
			cin >> nPatients;
			while ((getchar()) != '\n'); // Clear stream
			
			numPatients = atoi(nPatients.c_str());
		}
		catch(exception err)
		{
			nPatients = "";
			numPatients = 0;
		}
	}
	
	if (numPatients > 150)
	{
		cout << "\nNote: Patient lists exceeding 150 may experience display issues." << endl;
	}
	
	// Diagnose patients
	for (int i = 0; i < numPatients; i++)
	{
		Patient p = Patient();
		
		if (p.diagnose(&covid))
		{
			results[0] += 1;
		}	
		else if (p.diagnose(&cold))
		{
			results[1] += 1;
		}	
		else if (p.diagnose(&flu))
		{
			results[2] += 1;
		}
		else
		{
			results[3] += 1;
		}
	}
	
	// Format result row
	string resultRow = "+----------+";
	
	int max = results[0];
	for(int i = 1; i < 4; i++) // Find greatest result #
	{
		if (results[i] > max)
		{
			max = results[i];
		}
	}
	
	stringstream maxStr;
	maxStr << max;
	int midColW = strlen(maxStr.str().c_str());
	
	// Add length of middle column
	for(int i = 0; i < 2 + midColW; i++) 
	{
		resultRow += '-';
	}
	
	// Add length of percentage column
	resultRow += "+--------+";
	
	// Add length of final column
	for (int i = 0; i < 2 + max; i++) 
	{
		resultRow += '-';
	}
	
	resultRow += '+';
	
	// Display Results
	cout << left << "\n" << resultRow << "\n| " << setw(8) << "DISEASES" << " | " << setw(midColW) << setprecision(0) << "#" << " | " << setw(6) << "%" << " | " << left;
	
	for (int j = 0; j < max; j++) cout << ' ';
	cout << " |";
	
	for (int i = 0; i < 4; i++)
	{
		// Set disease name
		string name;
		
		switch(i)
		{
			case 0:
				name = "COVID-19";
				break;
			
			case 1: 
				name = "Cold";
				break;
				
			case 2:
				name = "Flu";
				break;
			
			default:
				name = "Other";
				break;
		}
		
		// Print table
		cout << left << "\n" << resultRow << "\n| " << setw(8) << name << " | " << setw(midColW) << setprecision(0) << results[i] << " | " << right << setw(5) << setprecision(4) << (double)(results[i]*100)/(numPatients) << "% | " << left;
		
		for (int j = 0; j < max; j++)
		{
			char c = ' ';
			
			if (j < results[i])
			{
				c = '+';
			}
			
			cout << c;
		}
		
		cout << " |";
		
	}
	
	cout << "\n" << resultRow << endl;
	
	system("pause");
}
