#include <iostream> // initializes libraries
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std; // uses namespace std
struct Student{ // creates the structure student
  char firstName[20]; // initializes variables
  char lastName[20];
  int id;
  float gpa;
};
void Add(); // initializes the function
void Subtract(vector<Student*>* v);
void Print(vector<Student*>* v);
int main() { // main function
  bool stop = false; // initializes the variables
  char stopChar;
  //vector<Student*>* v = new vector<Student*>;
  cout << "Welcome to Hash Table" << endl;
  char input[20];
  char quit[5];
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
void Add(){ // creates the student pointer to add to vector
 }
void Subtract(vector<Student*>* v){ // deletes the student from the vector

}
void Print(vector<Student*>* v){ // prints all the students in the vector
}
