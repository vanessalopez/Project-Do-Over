#include "map.h"
#include <iostream>


MapItem <keyType, valueType> *head=NULL;
MapItem <keyType, valueType> *tail=NULL;

int Map::size () const{ // returns the number of key-value pairs
  int count=0;
  
  while(head!=NULL){
    int count++;
    head=head->next
  }

  return count;
}

void add (keyType key, valueType value){
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should do nothing.
      */
  
  //search for key 
  //if key exists and doesnt have a value then add value
  //if key exists and already has a value then do nothing
  //if key doesnt exist add it and assign the value to key

  MapItem* newMap = new MapItem;

  if(head == NULL){
    //if the list is empty just need to put 
    head = newMap;
    tail = newMap;
    newMap->next=NULL;
    newMap->prev=NULL;

    newMap->key=key;
    newMap->value=value;
  }

  else if{
    //the key does exits and already has a value
  }

  else{
    //if the key does not exit add key to the end
  newMap->key = key;
  newMap->value = value;

  newMap->prev = head;
  head->next=newMAp;
  newMap->next = tail;
  tail->next=NULL;
  }


}

void remove (keyType key){
     /* Removes the association for the given key.
        If the key has no association, it should do nothing. */
  //checks for key
  //erases the value
  MapItem* newMap = new MapItem;

  while(newMap=head && newMap!= NULL && newMap->next!=NULL){
    newMap = newMap->next;
  }

  if(newMap->key==key){
    
      head=newMap->next
  }
  
}

valueType get (keyType key, bool & success) const{
     /* Returns the value associated with the given key.
        If the key existed in the map, success should be set to true.
        If the key has no association, it should set success to false. */
  //looks for key
  //if key exists: 
    //success = true
  //return value
  //else:
    //success=false
  //cout could not get value of << key << because its empty
}

void merge (const Map<keyType, valueType> & other){
     /* Adds all the key-value associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */
}
