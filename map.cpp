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
    //this is a pointer to address an &other gets the memory address of the value which are being compared
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
  // check if key is in map (think about functions youve already implemented)
  // if key is not in map
  //    create new map item
  //    set map items key and value to key and value
  //    add new item to either head or tail (remember to change next/prev pointers)
  // end
template <class keyType, class valueType>
void Map<keyType, valueType>::add (const keyType& key, valueType& value)
{
    MapItem<keyType, valueType> *newitem = new MapItem<keyType, valueType>();
    //check if the list is not empty, and if it is just add the values into the list
    /*if (head==NULL){
      newitem->key=key;
      newitem->value=value;
      newitem=tail->next;
      tail=newitem;
      tail->next=NULL;
      this->count++;
    }
    else{
      newitem->key=key;
      newitem->value=value;
      tail->next=newitem;
      newitem->prev=tail;
      tail=newitem;
      tail->next=NULL;
      this->count++;*/
    newitem->key=key;
    try{
      newitem->value=get(newitem->key);
    }
    catch(const NoSuchElementException& e){
      newitem->key=key;
      newitem->value=value;
      if(head==NULL){
        newitem=head;
        this->count++;
      }
      else{
      newitem = tail->next;
      tail = newitem;
      tail->next=NULL;
      this->count++;
      }
    }
}


    //check if the list is empty
    //if it is then just add the key and value



    /*
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
}
*/


/* Removes the association for the given key.
If the key has no association, it should do nothing. */
//checks for key
//erases the value
template <class keyType, class valueType>
void Map<keyType, valueType>::remove (const keyType& key)
{
  MapItem<keyType, valueType> *iter, *temp;

  iter=head;
  //go throught the list check
    while (iter!=NULL){
      //check if the key is in the list
      if (iter->key==key){
      //this is only going to run if iter->key==key!
      //means that we found the place where the key matches
      //then remove the value in that location
          //connects iter->prev to iter->next
          if(iter==head){
            head=iter->next;
          }
          else if(iter==tail){
            tail=iter->prev;
          }
          else{
          (iter->prev)->next=iter->next;
          (iter->next)->prev=iter->prev;
          //delete what is in iter
          }
          temp=iter->next;
          delete iter;
          iter=temp;
          this->count--;
      }
      else{
        iter=iter->next; 
      } 
    }
}





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

  while (iter!=NULL && iter->key!=key){
    iter=iter->next;
  }
  if (iter==NULL){
    throw NoSuchElementException();
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
  iter=this->head;
      while (iter->next!=NULL){
        if (otherIter->key==iter->key){
          if(otherIter->value!=iter->value){
            std::cout << "There is already an assoication with the key: " << iter->key << std::endl;
          }
        }
        else{
        add(otherIter->key, otherIter->value);
        }
      iter=iter->next;
      }
}