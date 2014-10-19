//#include "map.h"
#include <iostream>


//constructor
template <class keyType, class valueType> 
Map<keyType, valueType>::Map()
{
  //initiate head and tail to NULL
  head=NULL;
  tail=NULL;
  //set the count or size of the list=0
  count = 0;
}


//copy constructor
template <class keyType, class valueType> Map<keyType, valueType>::Map (const Map<keyType, valueType> & other)
{
  //ititiate head and tail to NULL
  head=NULL;
  tail=NULL;

  //create MapItem temp to go add the value of other 
  MapItem<keyType, valueType> *temp;

  //set temp to point to the head of other
  //go through the list and add the elements into this
  temp=other.head;
  while(temp!=NULL){
    add(temp->key, temp->value);
    temp=temp->next;
  } 
}


//deconstructor
template <class keyType, class valueType> Map<keyType, valueType>::~Map()
{
  //set iter to point to the head of the list
  //go through list and erase the values
  MapItem<keyType, valueType> *iter;
  iter=head;
  while (head!=NULL){
    iter=head->next;
    delete head;
    head=iter;
  }
}

template <class keyType, class valueType> 
Map<keyType, valueType>& Map<keyType, valueType>::operator= (const Map<keyType, valueType>& other){
  if (this!=&other){
    //this-pointer to address an &other gets the memory address of the value and compares
    MapItem<keyType, valueType> *iter;
    iter=this->head;
    while(iter!=NULL){
      iter=head->next;
      delete head;
      head=iter;
    }
    iter=other.head;
    count=0;
    while(iter!=NULL){
      add(iter->key, iter->value);
      iter=iter->next;    
    }
  }
    return *this;
}


// returns the number of key-value pairs
template <class keyType, class valueType>
int Map<keyType, valueType>::size () const
{  
  return this->count;
}


/* Adds a new association between the given key and the given value.
If the key already has an association, it should do nothing.
*/
//search for key 
//if key exists and doesnt have a value then add value
//if key exists and already has a value then do nothing
//if key doesnt exist add it and assign the value to key
template <class keyType, class valueType>
void Map<keyType, valueType>::add (const keyType& key, valueType& value)
{
  MapItem<keyType, valueType> *newitem = new MapItem<keyType, valueType>();
  newitem=head;
  //check if the list is empty
  //if it is then just add the key and value
  if (head==NULL){
    newitem->key=key;
    newitem->value=value;
    this->count++;
  } 
  else{
  //goes through list
    while(head!=NULL){
      //if they key is already in the list:
        while(newitem->key!=key);
        newitem=newitem->next;
        }
      //newitem is now pointing to the key, but if the key is in the list then the newitm is point to that location
      if (newitem->key == key){
        //then check if the key has a value associate to it
        if (newitem->value == NULL){
          //if it doesnt have one associated to it then add value
          newitem->value=value;
          tail->next=newitem;
          newitem->prev=tail;
          tail=newitem;
          tail->next=NULL;
          newitem->value = value;
        }
        //if it already has a value associated to it then do nothing
        else{
          std::cout << "You already have a value associated to this key!" << std::endl;
        }
      }
      else{
      newitem=tail->next;
      newitem->prev=tail;
      tail=newitem;
      tail->next=NULL;
      newitem->key=key;
      newitem->value=value;
      this->count++;
      }
  }
}


/* Removes the association for the given key.
If the key has no association, it should do nothing. */
//checks for key
//erases the value
template <class keyType, class valueType>
void Map<keyType, valueType>::remove (const keyType key)
{
  MapItem<keyType, valueType> *iter;
  iter=head;
  //if the list is empty throw exeption
  if (head==NULL){
    throw NoSuchElementException();
  }
  //go throught the list check
    while (iter!=NULL){
      //check if the key is in the list
      if (iter->key==key){
      //this is only going to run if iter->key==key!
      //means that we found the place where the key matches
      //then remove the value in that location
          //connects iter->prev to iter->next
          (iter->next)->prev=iter->prev;
          (iter->prev)->next=iter->next;
          //delete what is in iter
          delete iter;
          this->count--;
      }
      else if(iter==tail->next){
            std::cout << "There is no association for that key" << std::endl;
        }
      else{
        iter->prev=iter;
        iter=iter->next; 
      } 
    }
  //means that there is no association with the key
  else{
    cout << "The key provided is not in the list" << endl;  
  }  
}




//chose on of the following: whether you want it with const or not

// Returns the value associated with the given key.
/*If the key is not in the Map, throws a NoSuchElementException
if you do the valueType then you have to change your add function 
if you do the const valueType then you have to modify what is in that function 
to make it to pointers to add your information because it is const*/
template <class keyType, class valueType>
const valueType& Map<keyType, valueType>::get (const keyType & key) const
{
 MapItem<keyType, valueType> *iter;

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
void Map<keyType, valueType>::merge (const Map<keyType, valueType> & other){
MapItem<keyType, valueType> *otherIter;
  otherIter=other.head;
MapItem<keyType, valueType> *iter;
  iter=this.head;
      while (iter->next!=NULL){
        if (iter->key==this->key && iter->value!=this->value){
          std::cout << "There is already an assoication with the key:" << iter->key << std::endl;
          iter=iter->next;
        }
        else{
        add(iter->key, iter->value);
        iter=iter->next;
        }
      }
      add(iter->key, iter->value);
}