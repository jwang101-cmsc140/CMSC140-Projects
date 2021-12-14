/*
 * Class: CMSC140 22867
 * Instructor: Greg Grinberg
 * Project 4
 * Description: Record and calculate employee absences and output to a text report file.
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Joseph Wang
*/

#include <string> //needed for manipulating string variables
#include <iostream> //needed for displaying output and getting input (cout/cin/getline)
#include <iomanip> //needed for output manipulation (setprecision/fixed)
#include <fstream> //needed for input/output file operations

using namespace std;

int main()
{
	const string DUE_DATE = "11/15/2021", PROGRAMMER_NAME = "Joseph Wang";
	const int ASSIGNMENT_NUMBER = 4;
	double averageAbsentDaysValue;
	int numEmployees, totalDaysMissedValue;
	ofstream outFile("employeeAbsences.txt"); //output filestream object declaration
	int NumOfEmployees(); //function prototype, no parameters
	int totalDaysMissed(int, ofstream&); //function prototype, code in this function writes to 
	//ofstream object declared in main function, we need to pass ofstream argument as a reference 
	//variable so this code has access to the actual file, not a copy
	double averageAbsentDays(int, int); //function prototype, takes

	numEmployees = NumOfEmployees();
	outFile << "EMPLOYEE ABSENCE REPORT\n"; //outfile sections here write to the file
	outFile << "employee id" << setw(15) << "days absent\n";
	totalDaysMissedValue = totalDaysMissed(numEmployees, outFile);
	averageAbsentDaysValue = averageAbsentDays(numEmployees, totalDaysMissedValue);
	outFile << "\nThe " << numEmployees << " employees were absent a total of " << totalDaysMissedValue << " days.\n"
		<< "The average number of days absent is " << fixed << setprecision(1) << averageAbsentDaysValue << " days.\n" //set precision to 1 decimal place
		<< "\nProgrammer: " << PROGRAMMER_NAME;
	outFile.close(); //close the file after all output operations are done.
	cout << "\n\nThank you for testing my program!!\nPROGRAMMER: " << PROGRAMMER_NAME << "\nCMSC140 Common Project " << ASSIGNMENT_NUMBER << "\nDue Date: "
		<< DUE_DATE << endl;

	return 0;
}

int NumOfEmployees() {
	int numEmployeesInput;
	cout << "Please enter number of employees in the company: ";
	cin >> numEmployeesInput;
	while (numEmployeesInput < 1) { //validate num employees must be at least 1
		cout << "Number of employees cannot be less than 1, please reenter: ";
		cin >> numEmployeesInput;
	}
	return numEmployeesInput; //return number of employees as an integer
}

int totalDaysMissed(int numEmployees, ofstream &outFile){
	int totalDaysMissed = 0, employeeID, missedDays, counter = 0; //local variables are not initialized to 0, only globals are
	do {
		cout << "Please enter an employee ID: ";
		cin >> employeeID;
		cout << "Please enter number of days this employee was absent: ";
		cin >> missedDays;
		while (missedDays < 0) { //validate missed days cannot be negative
			cout << "Missed days cannot be negative, reenter: ";
			cin >> missedDays;
		}
		outFile << setw(8) << employeeID << setw(10) << missedDays << endl; //cannot write to outfile here unless we have passed it as a ref argument
		totalDaysMissed += missedDays; //accumulator
		counter += 1; //counter increment
	} while (counter < numEmployees); //loop until we have recorded enough employees as input by the user
	return totalDaysMissed; //return the total number of days missed by all employees equal to value of the accumulator
}

double averageAbsentDays(int totalNumEmployees, int totalMissedDays) {
	double avgMissedDays;
	avgMissedDays = static_cast<double>(totalMissedDays) / static_cast<double>(totalNumEmployees);
	return avgMissedDays; //return the average of missed days as a raw float. We will deal with decimal places later
}
