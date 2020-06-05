/*
Hash Table By Andrew Thomas 6/4/2020  Mr.Galbriath's C++ class. This code has a hash list of students that spreads the students throughout the table and when the table is half full or there is too many collisions then the table exands and spreads the students to the new table. You can random add students. Just choose how many students you want to add. You can manually add students. you can remove students from the list and you can also type quit to exit the program.  
*/
// source: https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/
#include <iostream> // initializes libraries
#include <cstring>
//#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std; // uses namespace std
struct Student{ // creates the structure student
  char firstName[20]; // initializes variables of students
  char lastName[20];
  int id;
  float gpa;
  Student* connection = NULL; // linked list connections to rehash the list

}; // functions
//void Add(Student** hashTable, char** firstName, char** lastName); // initializes the function
Student** Add(Student** hashTable, char** firstNameCollection, char** lastNameCollection, int numberofnames, int& ID, int& size);
//void Subtract(vector<Student*>* v);
void Subtract(Student** hashTable, int deleteID, int size);
//void Print(vector<Student*>* v);
//int hash(int ID, int size);
int initialhash(int ID, int size);
void Print(Student** hashTable, int size);
Student** ReHash(Student** hashTable, int& size);
Student** ManualAdd(Student** hashTable, char* firstName, char* lastName, int& MID, int& size, float GPA); // creates the student pointer to add to vector

int main() { // main function
  bool stop = false; // initializes the variables
  char stopChar;
  //vector<Student*>* v = new vector<Student*>;
  cout << "Welcome to Hash Table" << endl;
  char input[20];
  char quit[5];
  bool invalid = false;
  int ID = 0;
  int size = 100;
  char* MFirst = new char[20];
  char* MLast = new char[20];
  int MID;
  float MGPA;
  //int GPA;
  Student** hashTable = new Student*[100];
    do{ // Continues running the programm until the QUIT funciton
	    cout << "Enter a function: Random Add, Manual Add, Print, Delete, Quit" << endl;
    // cout << "are you sure you want to quit y/n" << endl;
	    cin.get(input, 20); // asks and gets input
	    cin.clear();
	    cin.ignore();
	    if(strcmp(input, "Random Add") == 0){ // ADD functi2on
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
		hashTable = Add(hashTable, FirstCollection, LastCollection,  numberofnames, ID, size);
		cout << "added" << endl;
		}
	      invalid = false;
		}
	    else if(strcmp(input, "Manual Add") == 0){

	      cout << "What is the first name of the student" << endl;
	      cin.get(MFirst, 20);
	      cin.clear();
	      cin.ignore();
	      cout << "What is the last name of the student" << endl;
	      cin.get(MLast, 20);
	      cin.clear();
	      cin.ignore();
	      //  cout << "What is the ID of the student" << endl;
	      //cin >> MID;
	      //cin.clear();
	      //cin.ignore();
	      cout << "What is the GPA of the student" << endl;
	      cin >> MGPA;
	      cin.clear();
	      cin.ignore();
	    
	      hashTable = ManualAdd(hashTable, MFirst, MLast, ID, size, MGPA);
	      cout << "added" << endl;
	    }
	    else if(strcmp(input, "Delete") == 0){ // DELETE function
	      cout << "please enter the ID of the student you want to delete" << endl;
	      int deleteID = 0;
	      cin >> deleteID;
	      cin.clear();
	      cin.ignore();
	      Subtract(hashTable, deleteID, size);
	    }
	    else if(strcmp(input, "Quit") == 0){ // QUIT function
	      stop = true; // sets the stop boolean to true
	    }
	    else if(strcmp(input, "Print") == 0){ // PRINT function
      //cout << "Print" << endl;
	      Print(hashTable, size);
	     
	    }
	    else{
	      cout << "Command not recognized. Please check your spelling and make sure it is all capital letters." << endl; // input is not any of the commands
	    }
	    
	  }
    while(stop == false); // keeps going while stop is false
	  return 0;
}
Student** Add(Student** hashTable, char** firstNameCollection, char** lastNameCollection, int numberofnames, int& ID, int& size){ // creates the student pointer to add to vector
  bool collision = false;
  for(int i = 0; i < numberofnames; i++) {
     // bool collision = false;
     Student* newStudent = new Student();
     int firstRandom = rand() % 19;
     strcpy((*newStudent).firstName, firstNameCollection[firstRandom]); 
      int lastRandom = rand() % 21;
      strcpy((*newStudent).lastName, lastNameCollection[lastRandom]);
      ID++;
      (*newStudent).id = ID;
     float ingpa = (float)rand()/(RAND_MAX)*5; 
     (*newStudent).gpa = ingpa;
     int space;
     space = initialhash(ID, size); 
    if (hashTable[space] == NULL) {
      hashTable[space] = newStudent; 
    }
    else {
      int counter = 0;
      Student* chain = hashTable[space]; 
      while((*chain).connection != NULL) { 
	counter++;
	chain = (*chain).connection;
      }
      counter++;  
      (*chain).connection = newStudent; 
      if(counter > 2) { 
		collision = true;
      }
    }
    
   }
    if(collision == true) { 
    hashTable = ReHash(hashTable, size); 
  }
  int fillingSize = 0;
  for(int j = 0; j < size; j++) {
    if(hashTable[j] != NULL) {
      fillingSize++; 
    }
  }
  
  if (fillingSize > size/2) { //if more than halfway full
    hashTable = ReHash(hashTable, size);//rehash
  }
  return hashTable;
}
void Subtract(Student** hashTable, int deleteID, int size){ // deletes the student from the vector
  int location = initialhash(deleteID, size);
  if(hashTable[location] != NULL){
    Student* chaining = hashTable[location];
  
  if((*chaining).connection == NULL){
    if((*chaining).id == deleteID){
      hashTable[location] = NULL;
		delete chaining;
		cout << "deleted" << endl;
    }
      else{
	cout << "invalid ID input" << endl;
      }
  }
  else{
    if((*chaining).id == deleteID){
      hashTable[location] = (*chaining).connection;
      delete chaining;
      cout << "deleted" << endl;;
    }
    else{
      bool invalid = true;
      while(chaining != NULL && (*chaining).connection != NULL){
	if((*(*chaining).connection).id == deleteID){
	Student* deleteThis = (*chaining).connection;
	(*chaining).connection = (*deleteThis).connection;
	delete deleteThis;
	invalid = false;
	cout << "deleted" << endl;
      }
      chaining = (*chaining).connection;
    }
    if(invalid){
      cout << "invalid ID input" << endl;
	    }
  }
  }
}
 else{
   cout << "invalid ID input" << endl;
   
 }
}

void Print(Student** hashTable, int size){ // prints all the students in the vector
  int* numberOfStudents = new int;
  (*numberOfStudents) = 0;
  Student* print = NULL;
  for(int i = 0; i < size; i++) {
       print = hashTable[i];
    while(print != NULL) {
      (*numberOfStudents)++;
      cout << "Space: " << i << ", ";
      cout << "Name: " << (*print).firstName << " " << (*print).lastName << ", ";
      cout << "ID: " << (*print).id << ", ";
      //   cout << "gpa: " << (*print).gpa << endl;
      cout << "GPA: " << fixed << setprecision(2) << (*print).gpa << endl;
      print = (*print).connection;
    } 
				 
   }
  cout << "The Hash Table is " << size << " Spaces long" << endl;
  cout << "The Hash Table has " << (*numberOfStudents) << " students" << endl;
}
int initialhash(int ID, int size){
  int sum;
  sum = 0;
  int starting = ID;
  for (int i = 0; i < 6; i++) {
    sum += sum + starting % 10; 
    starting = starting/10; 
  }
  int save = ID * sum; 
  int position = save % size;
  return position; 

  
}
Student** ReHash(Student** hashTable, int& size){
  int loop = size;
  bool collision = false;
   size = size + 100;
   //    size = size * 2;
  Student** newHashTable = new Student*[size];
    for(int i = 0; i < size; i++) {
    newHashTable[i] = NULL; 
  }
    for(int i = 0; i < loop; i++){
      if(hashTable[i] != NULL){
	Student* studentHolder = hashTable[i];
	do{
	  Student* connectionHolder = (*studentHolder).connection;
	  (*studentHolder).connection = NULL;
	  int place = initialhash((*studentHolder).id, size);
	  if(newHashTable[place] == NULL){
	    newHashTable[place] = studentHolder;
	  }
	  else{
	    int counter = 0;
	    Student* chaining = newHashTable[place];
	    while((*chaining).connection != NULL){
	      counter++;
	      chaining = (*chaining).connection;
	    }
	    (*chaining).connection = studentHolder;
	    counter++;
	    if(counter > 2){
	        collision = true;
	    }
	  }
	  studentHolder = connectionHolder;
	}
	while(studentHolder != NULL);
      }
    }
    if(collision){
      newHashTable = ReHash(newHashTable, size);
    }
    int fillingSize;
    for(int i = 0; i < size; i++){
      if(newHashTable[i] != NULL){
	fillingSize++;
      }
    }
    if(fillingSize > size/2){
      newHashTable = ReHash(newHashTable, size);
    }
    return newHashTable;
}
Student** ManualAdd(Student** hashTable, char* firstName, char* lastName, int& ID, int& size, float GPA){ // creates the student pointer to add to vector
  bool collision = false;
  // for(int i = 0; i < numberofnames; i++) {
     // bool collision = false;
     Student* newStudent = new Student();
     //    int firstRandom = rand() % 19;
     strcpy((*newStudent).firstName, firstName); 
     //  int lastRandom = rand() % 21;
      strcpy((*newStudent).lastName, lastName);
      ID++;
      (*newStudent).id = ID;
      //  float ingpa = (float)rand()/(RAND_MAX)*5; 
     (*newStudent).gpa = GPA;
     int space;
     space = initialhash(ID, size); 
    if (hashTable[space] == NULL) {
      hashTable[space] = newStudent; 
    }
    else {
      int counter = 0;
      Student* chain = hashTable[space]; 
      while((*chain).connection != NULL) { 
	counter++;
	chain = (*chain).connection;
      }
      counter++;  
      (*chain).connection = newStudent; 
      if(counter > 2) { 
	collision = true;
      }
    }
    
    //}
    if(collision == true) { 
    hashTable = ReHash(hashTable, size); 
  }
  int fillingSize = 0;
  for(int j = 0; j < size; j++) {
    if(hashTable[j] != NULL) {
      fillingSize++; 
    }
  }
  
  if (fillingSize > size/2) { //if more than halfway full
    hashTable = ReHash(hashTable, size);//rehash
  }
  return hashTable;
}
