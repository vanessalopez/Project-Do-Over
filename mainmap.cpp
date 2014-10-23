#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include "map.h"

using namespace std;

void mainmenu();
void moviemenu();

Map<string, string> usernames;
Map<string, string> movies;
Map<string, string> moviekeys;

int main(int argc, char* argv[]){

	cout << "Welcome!" << endl;
	mainmenu();

return 0;
}

void mainmenu(){

  int choice;
  string username;
  string name;
  string lastname;

  cout << "1. Log in" << endl;
  cout << "2. Create a new user" << endl;
  cout << "3. Quit" << endl;

  cin >> choice;


	if (choice == 1){
	  	string username;
	  	cout << "Enter your username: " << endl;
	  	cin >> username;
	  	try{
	  		usernames.get(username);
	  		moviemenu();
	  	}
	    catch(const exception &e){
	  		cout << "ERROR! You have entered the incorrect username!";
	  		mainmenu();
	  	}
  	} 
  	else if (choice == 2){
	  	cout <<  "Enter username: " << endl;
	    cin >> username;

	    cout << "Enter your name: (First and last name)" << endl;
	    cin >> name >> lastname;

	    try{
	    	usernames.add(username, name);	
	    	cout << "Welcome: " << usernames.get(username) << "!" <<endl;
	    	moviemenu();
	    }
	    catch(const exception &e){
	    	cout << "ERROR! That username is already taken!";
	    	mainmenu();
	    }
	 }
	else if (choice == 3){
		return;
	}
	else{
	  	cout << "You have entered an incorrect key." << endl;
	  	mainmenu();
	}
}


void moviemenu(){
  int option;
  string moviechoice;

  cout << "1. Search movie by title" << endl;
  cout << "2. Search movie by key" << endl;
  cout << "3. Log out" << endl;

  cin >> option;

  if (option == 1){
    cout << "Enter movie title" << endl;
   	cin >> moviechoice;
   	try{
    	movies.get(moviechoice);		
   	}
   	catch(const exception &e){
   		cout << "Error movie not in list!" << endl;
   		moviemenu();
   	}
    //seach (moviechoice, title);
}
  else if (option == 2){
  	try{
  		cout << "Enter movie key" << endl;
  	}
    catch(const exception &e){
    	cout << "Key not found!" << endl;
    	moviemenu();
    }
    // search (moviechoice, key);
}
  else if (option == 3){
    cout << "You have successfully logged out" << endl;
    mainmenu();
}
  else{
    cout << "You have entered an incorrect key." << endl;
    moviemenu();
}
}