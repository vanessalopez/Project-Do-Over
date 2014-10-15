#include "map.h"
#include <iostream>


//constructor
template <class keyType, class valueType> Map<keyType, valueType>::Map()
{
  head=NULL;
  tail=NULL;

  size = 0;
}


//copy constructor
template <class keyType, class valueType> Map<keyType, valueType>::Map (const Map<keyType, valueType> & other);
{
  MapItem<keyType, valueType> *copy = new MapItem<keyType, valueType>();
  
  other->head = this->head;
  other->tail = this->tail;
  //make deep copy here

}


//deconstructor
template <class keyType, class valueType> Map<keyType, valueType>::~Map()
{
  MapItem<keyType, valueType> *iter = new MapItem<keyType, valueType>();
  iter=head->next;
  while (head!=NULL){
    delete head;
    head=iter;
    iter=head->next;
    size--;
  }
    //or
  /*
  head->prev=temp;
  temp->next=head;
    while(head!=NULL){
      delete temp;
      temp=head
      head=head->next;
    }
  */
}

template <class keyType, class valueType> 
Map<keyType, valueType>& Map<keyType, valueType>::operator= (const Map<keyType, valueType>& other){
  this->size=other->key;
  this->key=other->key
  this->value=other->value;
}

// returns the number of key-value pairs
template <class keyType, class valueType>
int Map<keyType, valueType>::size () const
{  
  return size;
}


/* Adds a new association between the given key and the given value.
If the key already has an association, it should do nothing.
*/
//search for key 
//if key exists and doesnt have a value then add value
//if key exists and already has a value then do nothing
//if key doesnt exist add it and assign the value to key
template <class keyType, class valueType>
void Map<keyType, valueType>::add (const key, &value)
{
  MapItem<keyType, valueType> *newitem = new MapItem<keyType, valueType>();

  if (head=NULL){
    head=newitem;
    tail=newitem;
    newitem->key=key;
    newitem->value=value;
    size++;
  } 
  else if (this->key == key){
    if (this->value == NULL){
      tail->next=newitem;
      newitem->prev=tail;
      tail=newitem;
      tail->next=NULL;
      newitem->value = value;
  }
    else{
      cout << "You already have a value associated to this key!";
  }
  }
  else{
      tail->next=newitem;
      newitem->prev=tail;
      tail=newitem;
      tail->next=NULL;
      newitem->key=key;
      newitem->value=value;
      size++;
  }
}


/* Removes the association for the given key.
If the key has no association, it should do nothing. */
//checks for key
//erases the value
template <class keyType, class valueType>
void Map<keyType, valueType>::remove (const key)
{
  //if the list is empty throw exeption
  if (head==NULL)
    throw NoSuchElementException();
  //if the list is not empty and has a key associated
  else if (this->key==key){
    //means that we found the place where the key matches
  MapItem<keyType, valueType> *iter = new MapItem<keyType, valueType>();
    
    iter=head;
    //iter->next=head->next;

    while (iter->key!=key){
      iter->prev=iter;
      iter=iter->next;  
    }
    //iter is now pointing to the the place to the key we want to remove
    (iter->prev)->next = iter->next;
    delete iter;

    size --;

  //means that there is no association with the key
  else{
      cout << "There is no association for that key";
    } 
  }
  
}




//chose on of the following: whether you want it with const or not

// Returns the value associated with the given key.
/*If the key is not in the Map, throws a NoSuchElementException
if you do the valueType then you have to change your add function 
if you do the const valueType then you have to modify what is in that function 
to make it to pointers to add your information because it is const*/
template <class keyType, class valueType>
const valueType Map<keyType, valueType>::& get (const keyType & key) const
{
 MapItem<keyType, valueType> *iter = new MapItem<keyType, valueType>();

 iter=head; 

  if (head=NULL){
    throw NoSuchElementException();
  }
  while (iter->key!=NULL && iter->key!=key){
    iter=iter->next;
  }
  return iter->value;
}


     /* Adds all the key-value associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */
     // get the function of other
    //check if what is in other in in map if not add that into map.
template <class keyType, class valueType>
void Map::merge (const Map<keyType, valueType> & other){
MapItem<keyType, valueType> *iter = new MapItem<keyType, valueType>();
  iter=other.head
        if (other->key==this->key){
          if(this->value==NULL){
            add(other);
          }
          else{
          cout << "Key already has a value associated to it." << endl;
          }
        }
        else{
          add(other);
        }
}