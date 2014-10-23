#ifndef __USER_H__
#define __USER_H__

#include "movie.h"

class User {
  public:
    User (string ID, string name);  
    /* constructor that generates a user with the given name and ID.
       While multiple users may have the same name, the ID should be unique
       (e.g., an e-mail address), so that users can log in with it. */

    User (const User & other); // copy constructor

    ~User ();            // destructor

    string getID () const;    // returns the ID associated with this user

    string getName () const;  // returns the name associated with this user

  private:
    // you get to decide what goes here.
};
