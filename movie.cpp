#include "movie.h";

Movie::Movie (string title);       // constructor for a movie with the given title

Movie::Movie (const Movie & other);  // copy constructor

Movie::~Movie ();                  // destructor

string Movie::getTitle () const;   // returns the title of the movie

void Movie::addKeyword (string keyword); 
   /* Adds the (free-form) keyword to this movie.
     If the exact same keyword (up to capitalization) was already
     associated with the movie, then the keyword is not added again. */

Set<string> Movie::getAllKeywords () const;
  /* Returns a set of all keywords associated with the movie. */