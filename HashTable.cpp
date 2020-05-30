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
Student* Add(); // initializes the function
void Subtract(vector<Student*>* v);
void Print(vector<Student*>* v);
int main() { // main function
  bool stop = false; // initializes the variables
  char stopChar;
  vector<Student*>* v = new vector<Student*>;
  cout << "Welcome to Hash Table" << endl;
  char input[20];
  char quit[5];
  //int ID;
  //int GPA;
    
    do{ // Continues running the programm until the QUIT funciton
	    cout << "Enter a function: Add, Print Delete, Quit" << endl;
    // cout << "are you sure you want to quit y/n" << endl;
	    cin.get(input, 20); // asks and gets input
	    cin.clear();
	    cin.ignore();
	    if(strcmp(input, "Add") == 0){ // ADD function
	      (*v).push_back(Add()); // add the student created in ADD funtion the the vector pointer of student pointers
		//	cout << (*v.front()).id << endl;
		//	cout << (*v.front()).gpa << endl;
		//for(int i=0;i<10;i++){
		  // cout << (*v.front()).firstName[i];
		 //}
		  } 
	    else if(strcmp(input, "Delete") == 0){ // DELETE function
	      //  cout << "Delete" << endl;
	      Subtract(v); // DELETES
	      }
	    else if(strcmp(input, "Quit") == 0){ // QUIT function
	      stop = true; // sets the stop boolean to true
	    }
	    else if(strcmp(input, "Print") == 0){ // PRINT function
      //cout << "Print" << endl;

	      Print(v); // prints
	    }
	    else{
	      cout << "Command not recognized. Please check your spelling and make sure it is all capital letters." << endl; // input is not any of the commands
	    }
	    
	  }
    while(stop == false); // keeps going while stop is false
	  return 0;
}
Student* Add(){ // creates the student pointer to add to vector
  Student *create = new Student(); // student created
  cout << "Please enter the student's first name." << endl;
  cin.get((*create).firstName, 20); // firstname
  //(*create).firstName.add('\0');
  cin.clear();
  cin.ignore();
  (*create).firstName[20] = '\0';
  cout << "Please enter the student's last name." << endl;
  cin.get((*create).lastName, 20); // lastname
  cin.clear();
  cin.ignore();
  (*create).lastName[20] = '\0';
  cout << "Please enter the student's ID number." << endl;
  cin >>(*create).id; //id
  cin.clear();
  cin.ignore();
    cout << "Please enter the student's GPA." << endl;
    cin >> (*create).gpa; // gpa
    cin.clear();
    cin.ignore();
    //(*create).gpa = (int)((*create).gpa * 100 + 0.5);
    //cout << (*create).gpa << endl;
    //(*create).gpa = (float)(*create).gpa / 100;
  
    //cout << (*create).gpa << endl;
   //  (*create).gpa = round((*create).gpa);

   //cin.ignore();
   return create; // return the created student will these inputed values
}
void Subtract(vector<Student*>* v){ // deletes the student from the vector
  int unwantedID;
  int loss;
  bool del = false;
  cout << "Please enter the ID of the student you want to delete." << endl;
  cin >> unwantedID; // gets the ID
  cin.clear();
  cin.ignore();
  //int i = 0;
   for(vector<Student*>::iterator it = (*v).begin(); it != (*v).end(); ++it){ // goes through vector
     for (int i =0; i < (*v).size(); i++){ // gets id of the elements that the iterator goes through
       if((*(*it)).id == unwantedID){ // if the id match
	 loss = i; // does not delete the student here but saves the information here and deletes after the iterator
       del = true;
      cout << "Deleted" << endl;
       break;
    }
    }
   }
   if(del){
 (*v).erase(loss + (*v).begin());
   }
  return;
}
void Print(vector<Student*>* v){ // prints all the students in the vector
  for(vector<Student*>::iterator it = (*v).begin(); it != (*v).end(); ++it){ // goes through the vector
    for(int j =0; j< strlen((*it)->firstName); j++){
      cout << (*(*it)).firstName[j]; //prints first name
    }
    cout << " ";
    for(int f = 0; f<strlen((*it)->firstName); f++){
      cout << (*(*it)).lastName[f]; // prints last name
    }
    cout << ", "; 
    cout << (*(*it)).id; // prints ID
  cout << ", ";
  cout << fixed << setprecision(2) << (*(*it)).gpa; // prints GPA
  
  cout  << endl;
  }
  return;
}
