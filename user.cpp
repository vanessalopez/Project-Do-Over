#include "user.h";

User::User (string ID, string name);  
    /* constructor that generates a user with the given name and ID.
       While multiple users may have the same name, the ID should be unique
       (e.g., an e-mail address), so that users can log in with it. */

User::User (const User & other); // copy constructor

User::~User ();            // destructor

string User::getID () const;    // returns the ID associated with this user

string User::getName () const;  // returns the name associated with this user
