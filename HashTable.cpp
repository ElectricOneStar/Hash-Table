#include <iostream> // initializes libraries
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std; // uses namespace std
struct Student{ // creates the structure student
  char firstName[20]; // initializes variables
  char lastName[20];
  int id;
  float gpa;
};
void Add(Student** hashTable, char** firstName, char** lastName); // initializes the function
void Subtract(vector<Student*>* v);
void Print(vector<Student*>* v);
int main() { // main function
  bool stop = false; // initializes the variables
  char stopChar;
  //vector<Student*>* v = new vector<Student*>;
  cout << "Welcome to Hash Table" << endl;
  char input[20];
  char quit[5];
  bool invalid = false;
  //int ID;
  //int GPA;
  Student** hashTable = new Student*[100];
    do{ // Continues running the programm until the QUIT funciton
	    cout << "Enter a function: Add, Print Delete, Quit" << endl;
    // cout << "are you sure you want to quit y/n" << endl;
	    cin.get(input, 20); // asks and gets input
	    cin.clear();
	    cin.ignore();
	    if(strcmp(input, "Add") == 0){ // ADD function
	      int numberofnames;
	      cout << "how many students would you like to add?" << endl;
	      cin >> numberofnames;
	      cin.clear();
	      cin.ignore();
	      char* firstNameFileName = new char[20];
	      char* lastNameFileName = new char[20];
	      cout << "Please enter the Firstname File" << endl;
	      cin.get(firstNameFileName, 20);
	      cin.ignore();
	      cin.clear();
	        char** FirstCollection = new char*[40];
      for (int j = 0; j < 40; j ++) {
        FirstCollection[j] = new char[20];
      }
      char First[20];
 	      ifstream FirstNameFile;
	      FirstNameFile.open(firstNameFileName);
	      if(!FirstNameFile){
		cout << "invalid input" << endl;
		invalid = true;
		//return;
	      }
	      else{
		int wordCounter = 0;
	     while (wordCounter < 19) {
          FirstNameFile.getline(First, 80, ',');
	    strcpy(FirstCollection[wordCounter], First);
          wordCounter++;
        }
		  
		//cout << "in" << endl;
		
		
	      }
	      FirstNameFile.close();
	      FirstNameFile.clear();
      char** LastCollection = new char*[40];
      for (int j = 0; j < 40; j ++) {
        LastCollection[j] = new char[20];
      }
      char Last[20];

	      cout << "Please eneter the Lastname File" << endl;
	        cin.get(lastNameFileName, 20);
	      cin.ignore();
	      cin.clear();
	    ifstream LastNameFile;
	     LastNameFile.open(lastNameFileName);
	      if(!LastNameFile){
		cout << "invalid input" << endl;
		invalid = true;
	      }
	      else{
		//	cout << "in" << endl;
			int wordCounter2 = 0;
	     while (wordCounter2 < 21) {
          LastNameFile.getline(Last, 80, ',');
	    strcpy(LastCollection[wordCounter2], Last);
          wordCounter2++;
        }
	      }
	       LastNameFile.close();
	      LastNameFile.clear();
	      if(invalid){
		cout << "could not add" << endl;
	      }
	      else{
		cout << "added" << endl;
		}
	      invalid = false;
		} 
	    else if(strcmp(input, "Delete") == 0){ // DELETE function

	    }
	    else if(strcmp(input, "Quit") == 0){ // QUIT function
	      stop = true; // sets the stop boolean to true
	    }
	    else if(strcmp(input, "Print") == 0){ // PRINT function
      //cout << "Print" << endl;

	     
	    }
	    else{
	      cout << "Command not recognized. Please check your spelling and make sure it is all capital letters." << endl; // input is not any of the commands
	    }
	    
	  }
    while(stop == false); // keeps going while stop is false
	  return 0;
}
void Add(Student** hashTable, char** firstName, char** lastName){ // creates the student pointer to add to vector
  
 }
void Subtract(vector<Student*>* v){ // deletes the student from the vector

}
void Print(vector<Student*>* v){ // prints all the students in the vector
}
