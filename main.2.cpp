#include <iostream>
#include "Map.h"


using namespace std;

void mainmenu();
void login();
void newuser();
void check();


int main(int argc, char* argv[]){

  Map<string, string> newMap;

  string userline; //stores the lines in the user file
  int numusers; // counts the number of users in the file
  int usercount; //count the lines in the user file
  string name;
  string username; 
  string movieline; //stores the lines in the movie file
  int nummovies;// counts the number of movie in the file
  int moviecount; //count the lines in the movie file
  string movie; 
  string keyword;

  //checks if the user inputs 2 files
  if (argc != 3){
    cout << "You did not enter the correct number of arguments. (User information and movie information)" << endl;
      return 0;
  }

  //opens and reads file
  ifstream userfile;
  file.open(argv[1]);

  //checks if the file can open
  if (file.fail()){
      cout << "Error! Could not read file!" << endl;
      file.close();
      return 0;
  }

  //counts the number of lines and users in the file
  while (getline(userfile,userline)){
    usercount++;
    if (userline.size==0){
      break;
    }
    if(userline.find("BEGIN")){
      numusers++;
    }
  }

    int *users = new int[numusers];
   
    getline(userfile, userline);
    
    //stores information into an array
    string temp;
    stringstream ss;
    ss.clear();

    ss << line;
    
    for(int i=0; i<numusers; i++){
      if(userline.find("BEGIN")){
	ss >> begin >> username;
      }
      if(userline.find(""))
    }






  file.close();

  cout << "Please enter a number for your selection: " << endl;
  
  mainmenu();

  return 0;
}

void mainmenu(]){
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
    cout << "You have entered an incorrect key." << endl;
    mainmenu;
}

//login verification
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

//create new user
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

//check if username exists
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

void moviemenu(){
  int option;
  string moviechoice;
  int title;
  int key;

  cout << "1. Search movie by title" << endl;
  cout << "2. Search movie by key" << endl;
  cout << "3. Log out" << endl;

  cin >> moviechoice;

  if (option == 1){
    cout << "Enter movie title" << endl;
    seach (moviechoice, title);
}
  else if (option == 2){
    cout << "Enter movie key" << endl;
    search (moviechoice, key)
}
  else if (option == 3){
    cout << "You have successfully logged out" << endl;
    mainmenu();
}
  else{
    cout << "You have entered an incorrect key." << endl;
}
}

void check (){

}

