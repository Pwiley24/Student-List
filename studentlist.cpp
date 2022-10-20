//This program stores the IDs, GPA, and name of students and lists them.
//Author: Paige Wiley
//Date: 10-20-2022

#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
#include <iomanip>

using namespace std;

/*
 * Struct for any student
 * Assigns a first and last name, their student ID, and GPA.
 */
struct Student{
  char firstN[10];
  char lastN[10];
  int id;
  float gpa;
};

void deleteItem(vector<Student*> &list);
void add(vector<Student*> &list);
void print(vector<Student*> &list);

int main(){
  bool running = true;
  vector<Student*> list;
  
  while(running){
    char input[10];
    cout << "Enter a command (ADD, DELETE, PRINT, QUIT):" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');

    if(strcmp(input, "ADD") == 0){ //add student command
      cout << "Adding" << endl;
      add(list);
    }else if(strcmp(input, "PRINT") == 0){ //print command
      cout << "printing" << endl;
      print(list);
    }else if(strcmp(input, "DELETE") == 0){ //delete command
      deleteItem(list);
    }else if(strcmp(input, "QUIT") == 0){ //quit command
      running = false;
    }
    
  }
    
  return 0;
}


/*
 * Function deletes a student from the list.
 */
void deleteItem(vector<Student*> &list){
  int input;
  vector<Student*>::iterator ptr; //declare the iterator
  
  cout << "ID of the student you wish to remove:" << endl;
  cin >> input;
  cin.ignore(10, '\n');
  
  for(ptr = list.begin(); ptr < list.end(); ptr++){
    if((*ptr)->id == input){ //ID is in the vector
      list.erase(ptr);
      break;
    }
  }
}

/*
 * Function adds a new student and their information
 */
void add(vector<Student*> &list){
  Student* newStudent = new Student();
  
  //first name:
  cout << "What is the student's first name?" << endl;
  cin >> newStudent->firstN;
  cin.ignore(10, '\n');

  //Last name:
  cout << "What is the student's last name?" << endl;
  cin >> newStudent->lastN;
  cin.ignore(10, '\n');

  //Id number:
  cout << "What is the student's ID number?" << endl;
  cin >> newStudent->id;
  cin.ignore(10, '\n');

  //GPA:
  cout << "What is the student's GPA?" << endl;
  cin >> newStudent->gpa;
  cin.ignore(10, '\n');
      
  //Add to vector list
  list.push_back(newStudent);
}

/*
 * Function prints information of all students
 * Format of each student: First Last, ID, GPA
 */
void print(vector <Student*> &list){

  vector<Student*>::iterator ptr; //declare iterator to a vector
    
  for(ptr = list.begin(); ptr < list.end(); ptr++){
    cout << (*ptr)->firstN << " " << (*ptr)->lastN << ". ID: " << (*ptr)->id << ". GPA: " << fixed << setprecision(3) << (*ptr)->gpa << endl;
  }
}
