#include "set.h"

template <class T> Set<T>::Set()
{

}

//copy constructor
//template <class T> Set<T>::Set (const Set<T> & other){

//}

template <class T> Set<T>::~Set()
{

}

template <class T> 
int Set<T>::size() const
{
	return this->internalStorage.size();
}

template <class T> 
void Set<T>::add (const T& item)
{
	this->internalStorage.add(item, 0);
}
      
template <class T> 
void Set<T>::remove (const T item)
{
	this->internalStorage.remove(item);
}

template <class T> 
bool Set<T>::contains (T item) const
{
	bool check;
	try {
		this->internalStorage.get(item);
		check=true
	}
	catch(const NoSuchElementException& e){
		check=false;
	}
	return check;
}

template <class T> 
void Set<T>::merge (const Set<T> & other)
{
	this->internalStorage.merge(other.internalStorage);
}

template <class T> 
void Set<T>::printAll () const
{
	this->internalStorage.printAll();
}


/*template <class T> 
Set<T> setUnion (const Set<T> & other) const;
  // Returns the union of this and other. Does not alter this.

template <class T> 
Set<T> setIntersection (const Set<T> & other) const;
  // Returns the intersection of this and other. Does not alter this.*/