/*
Hash Table By Andrew Thomas 6/4/2020  Mr.Galbriath's C++ class. This code has a hash list of students that spreads the students throughout the table and when the table is half full or there is too many collisions then the table exands and spreads the students to the new table. You can random add students. Just choose how many students you want to add. You can manually add students. you can remove students from the list and you can also type quit to exit the program.  
*/
// source: https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/
#include <iostream> // initializes libraries
#include <cstring>
#include <cstdlib>
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
	    if(strcmp(input, "Random Add") == 0){ // Random ADD functi2on
	      int numberofnames;
	      cout << "how many students would you like to add?" << endl;
	      cin >> numberofnames; //gets the number of students the user wants to add
	      cin.clear();
	      cin.ignore();
	      char* firstNameFileName = new char[20]; // first name file name
	      char* lastNameFileName = new char[20]; //  last name file name
	      cout << "Please enter the Firstname File" << endl;
	      cin.get(firstNameFileName, 20); 
	      cin.ignore();
	      cin.clear();
	        char** FirstCollection = new char*[40];
      for (int j = 0; j < 40; j ++) {
        FirstCollection[j] = new char[20];
      }
      char First[20];
      ifstream FirstNameFile; // gets first name file
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
	  strcpy(FirstCollection[wordCounter], First); // puts all of the first names into a list
          wordCounter++;
        }
		  
		//cout << "in" << endl;
		
		
	      }
	      FirstNameFile.close();
	      FirstNameFile.clear();
      char** LastCollection = new char*[40];
      for (int j = 0; j < 40; j ++) { // 
        LastCollection[j] = new char[20];
      }
      char Last[20];

	      cout << "Please eneter the Lastname File" << endl;
	        cin.get(lastNameFileName, 20);
	      cin.ignore();
	      cin.clear();
	      ifstream LastNameFile; // gets last name file
	     LastNameFile.open(lastNameFileName);
	      if(!LastNameFile){
		cout << "invalid input" << endl;
		invalid = true;
	      }
	      else{
		//	cout << "in" << endl;
			int wordCounter2 = 0;
			while (wordCounter2 < 21) { // puts all of the last names into a list
          LastNameFile.getline(Last, 80, ',');
	    strcpy(LastCollection[wordCounter2], Last);
          wordCounter2++;
        }
	      }
	       LastNameFile.close();
	      LastNameFile.clear();
	      if(invalid){ // one of the files could not open
		cout << "could not add" << endl;
	      }
	      else{ // time to add
		hashTable = Add(hashTable, FirstCollection, LastCollection,  numberofnames, ID, size);
		cout << "added" << endl;
		}
	      invalid = false;
		}
	    else if(strcmp(input, "Manual Add") == 0){ // manual add function

	      cout << "What is the first name of the student" << endl; // gets the first name of the student
	      cin.get(MFirst, 20);
	      cin.clear();
	      cin.ignore();
	      cout << "What is the last name of the student" << endl; // gets the last name of the student
	      cin.get(MLast, 20);
	      cin.clear();
	      cin.ignore();
	      //  cout << "What is the ID of the student" << endl;
	      //cin >> MID;
	      //cin.clear();
	      //cin.ignore();
	      cout << "What is the GPA of the student" << endl; // gets the gpa of the student
	      cin >> MGPA;
	      cin.clear();
	      cin.ignore();
	    
	      hashTable = ManualAdd(hashTable, MFirst, MLast, ID, size, MGPA); // manually added
	      cout << "added" << endl;
	    }
	    else if(strcmp(input, "Delete") == 0){ // DELETE function
	      cout << "please enter the ID of the student you want to delete" << endl;
	      int deleteID = 0;
	      cin >> deleteID; // getst the ID the person wants to delete
	      cin.clear();
	      cin.ignore();
	      Subtract(hashTable, deleteID, size); // deletes it
	    }
	    else if(strcmp(input, "Quit") == 0){ // QUIT function
	      stop = true; // sets the stop boolean to true
	    }
	    else if(strcmp(input, "Print") == 0){ // PRINT function
      //cout << "Print" << endl;
	      Print(hashTable, size); // prints
	     
	    }
	    else{
	      cout << "Command not recognized. Please check your spelling and make sure it is all capital letters." << endl; // input is not any of the commands
	    }
	    
	  }
    while(stop == false); // keeps going while stop is false
	  return 0;
}
Student** Add(Student** hashTable, char** firstNameCollection, char** lastNameCollection, int numberofnames, int& ID, int& size){ // creates the student pointer to add to the HashTable
  bool collision = false;
  for(int i = 0; i < numberofnames; i++) {
     // bool collision = false;
    Student* newStudent = new Student(); // creates a new student
     int firstRandom = rand() % 19; // gets a random first name
     strcpy((*newStudent).firstName, firstNameCollection[firstRandom]); 
     int lastRandom = rand() % 21; // gets a random last name
      strcpy((*newStudent).lastName, lastNameCollection[lastRandom]);
      ID++;
      (*newStudent).id = ID; // sets the id
     float ingpa = (float)rand()/(RAND_MAX)*5; 
     (*newStudent).gpa = ingpa; // gets a random id
     int space;
     space = initialhash(ID, size);  // gets the space from the hash function
     if (hashTable[space] == NULL) { //empty space
      hashTable[space] = newStudent; 
    }
     else { // collision
      int counter = 0;
      Student* chain = hashTable[space]; //creates a chain from the occupided space stduent 
      while((*chain).connection != NULL) { 
	counter++;
	chain = (*chain).connection; // keep building on the chain
      }
      counter++;  
      (*chain).connection = newStudent; // chain the student  
      if(counter > 2) {  //chain is too long and there was 3 collisions
	collision = true;
      }
    }
    
   }
    if(collision == true) { 
      hashTable = ReHash(hashTable, size);  // too many collisions means rehashing the table
  }
  int fillingSize = 0;
  for(int j = 0; j < size; j++) { // figures out how many students rae in the table
    if(hashTable[j] != NULL) {
      fillingSize++; 
    }
  }
  
  if (fillingSize > size/2) { //if more than halfway full
    hashTable = ReHash(hashTable, size);//rehash
  }
  return hashTable; // there are two rehash conditions to make the new hashtable as spread out as possible.
}
void Subtract(Student** hashTable, int deleteID, int size){ // deletes the student from the hash Table
  int location = initialhash(deleteID, size); // gets the locaiton of the student to delete
  if(hashTable[location] != NULL){ // spot is open
    Student* chaining = hashTable[location]; // begin the clain
  
    if((*chaining).connection == NULL){ // no connection
    if((*chaining).id == deleteID){ // the chain is the delete id
      hashTable[location] = NULL;
      delete chaining; //delete it
		cout << "deleted" << endl;
    }
    else{ //the ID does nto exist
	cout << "invalid ID input" << endl;
      }
  }
  else{ // there is a connection from the chain
    if((*chaining).id == deleteID){ // the chain is the delete ID
      hashTable[location] = (*chaining).connection;
      delete chaining; // delete the chain
      cout << "deleted" << endl;;
    }
    else{ // continue the chain
      bool invalid = true;
      while(chaining != NULL && (*chaining).connection != NULL){
	if((*(*chaining).connection).id == deleteID){ // this is the student
	Student* deleteThis = (*chaining).connection;
	(*chaining).connection = (*deleteThis).connection;
	delete deleteThis;// keep going through the chain till it find the student and deletes it
	invalid = false;
	cout << "deleted" << endl;
      }
      chaining = (*chaining).connection;
    }
      if(invalid){ // the student does not exist wrong ID
      cout << "invalid ID input" << endl;
	    }
  }
  }
}
  else{ // student DNE wrong ID
   cout << "invalid ID input" << endl;
   
 }
}

void Print(Student** hashTable, int size){ // prints all the students in the hash Table
  int* numberOfStudents = new int; 
  (*numberOfStudents) = 0;
  Student* print = NULL;
  for(int i = 0; i < size; i++) { // loops through the hash Table
       print = hashTable[i];
       while(print != NULL) { // the location is not null so print
      (*numberOfStudents)++;
      cout << "Space: " << i << ", "; // print the location
      cout << "Name: " << (*print).firstName << " " << (*print).lastName << ", "; // print full name
      cout << "ID: " << (*print).id << ", "; // print ID
      //   cout << "gpa: " << (*print).gpa << endl;
      cout << "GPA: " << fixed << setprecision(2) << (*print).gpa << endl; // print GPA rounded to hundreaths
      print = (*print).connection; // goes to the conenction
    } 
				 
   }
  cout << "The Hash Table is " << size << " Spaces long" << endl; // prints size and # of students
  cout << "The Hash Table has " << (*numberOfStudents) << " students" << endl;
}
int initialhash(int ID, int size){ // gets a position from the hashtable
  int sum; 
  sum = 0;
  int starting = ID; // gets the starting ID
  for (int i = 0; i < 6; i++) {
    sum += sum + starting % 10; // sum from the starting ID 6 times 
    starting = starting/10;  // divide the ID by ten each time
  }
  int save = ID * sum; // multipty the ID by the sum
  int position = save % size; // and modulous this from the size to the get the position to ensure taht the location is within the size
  return position; 

  
}
Student** ReHash(Student** hashTable, int& size){ // resizes the table and puts all of the students back into the table
  int loop = size; // gets the origional size
  bool collision = false;
  size = size + 100; // expands the size
   //    size = size * 2;
  Student** newHashTable = new Student*[size]; // creates the new table with the expanded size
    for(int i = 0; i < size; i++) {
    newHashTable[i] = NULL; 
  }
    for(int i = 0; i < loop; i++){ // loops through the origional table
      if(hashTable[i] != NULL){
	Student* studentHolder = hashTable[i]; // gets the student from teh position
	do{
	  Student* connectionHolder = (*studentHolder).connection; // gets teh connection from the student
	  (*studentHolder).connection = NULL;
	  int place = initialhash((*studentHolder).id, size);
	  if(newHashTable[place] == NULL){ // there is an open space
	    newHashTable[place] = studentHolder; // put the student in there
	  }
	  else{ // space occupied
	    int counter = 0;
	    Student* chaining = newHashTable[place]; // begin a chain
	    while((*chaining).connection != NULL){
	      counter++;
	      chaining = (*chaining).connection; // continue chaining until end of chain
	    }
	    (*chaining).connection = studentHolder; // put the student there
	    counter++; 
	    if(counter > 2){ // there is 3 collisions
	        collision = true;
	    }
	  }
	  studentHolder = connectionHolder; // puts all of the students in the new list 
	}
	while(studentHolder != NULL);  // loops until all students are transfered
      }
    }
    if(collision){
      newHashTable = ReHash(newHashTable, size); // rehash
    }
    int fillingSize;
    for(int i = 0; i < size; i++){
      if(newHashTable[i] != NULL){ // checks # of students
	fillingSize++;
      }
    }
    if(fillingSize > size/2){
      newHashTable = ReHash(newHashTable, size); // more than half so rehash
    }
    return newHashTable;
}
Student** ManualAdd(Student** hashTable, char* firstName, char* lastName, int& ID, int& size, float GPA){ // creates the student pointer to add to hash table manually
  bool collision = false;
  // for(int i = 0; i < numberofnames; i++) {
     // bool collision = false;
     Student* newStudent = new Student();
     //    int firstRandom = rand() % 19;
     strcpy((*newStudent).firstName, firstName); // sets the first name 
     //  int lastRandom = rand() % 21;
     strcpy((*newStudent).lastName, lastName); // sets the last name
      ID++;
      (*newStudent).id = ID; // set the id
      //  float ingpa = (float)rand()/(RAND_MAX)*5; 
      (*newStudent).gpa = GPA; // sets the gpa
     int space;
     space = initialhash(ID, size);  // gets the space from the intial hash function
     if (hashTable[space] == NULL) { // there is an open space
       hashTable[space] = newStudent;  // put a student in the open space
    }
     else { // collision
      int counter = 0;
      Student* chain = hashTable[space]; 
      while((*chain).connection != NULL) { // keept the chain going 
	counter++;
	chain = (*chain).connection;
      }
      counter++;  
      (*chain).connection = newStudent; 
      if(counter > 2) {  //there were 3 collisions
	collision = true;
      }
    }
    
    //}
    if(collision == true) { 
      hashTable = ReHash(hashTable, size);  // reshash because of 3 collisions
  }
  int fillingSize = 0;
  for(int j = 0; j < size; j++) { // checks how many students are in the hash table
    if(hashTable[j] != NULL) {
      fillingSize++; 
    }
  }
  
  if (fillingSize > size/2) { //if more than halfway full
    hashTable = ReHash(hashTable, size);//rehash
  }
  return hashTable;
}
