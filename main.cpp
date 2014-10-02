#include <iostream>

using namespace std;

void mainmenu();
void login();
void newuser();

int main (){

  cout << "Please enter a number for your selection: " << endl;
  
  mainmenu();

  return 0;
}

void mainmenu(){
  int choice;

  cout << "1. Log in" << endl;
  cout << "2. Create a new user" << endl;
  cout << "3. Quit" << endl;

  cin >> choice;
  
  if (choice == 1)
    login();
  else if (choice == 2)
    newuser();
  else if (choice == 3)
    return 0;
  else 
    mainmenu;
}

void login(){
  string username;
  int check;

  cout << "Enter your username: " << endl;
  cin >> username;
  // going to have to pass in this username to check if it exits on the list or not.
  check = users(username);

  if (check == 1){
    cout << "You have entered the wrong username!" << endl;
    login();
  }
  else
    (username);
    
}

void newuser(){
  string username;
  string name;
  int check;
  cout <<  "Enter username: " << endl;
    cin >> username;
  
  check = users(username);
  
  if (check = 1){
    cout <<  "Sorry that username has already been taken." << endl;
      newuser();
  }
  else
    cout << "Enter your name: " << endl;
      cin >> name;
      moviemenu(username, name);
      
}

int users(username){
  string *ids = {vanessll, ttrojan, aaroncot, dkempe}
  int check;
  
  if (int i=0; i<=4; i++){
    if(ids[i] == username)
      check = 2;
  }
  else 
    check = 1;
  
  return check;
}
