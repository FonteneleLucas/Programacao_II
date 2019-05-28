
#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;

List::List() 
{
  count = 0;
  first = NULL;
}

List::List(const char *lname) 
{
  name  = lname;
  count = 0;
  first = NULL;
}

List::~List() 
{
  clear();
}

Elem *List::getElem(int index)
{
  Elem *elem;   // Current element
  int   pos;    // Current index
  
  if((index < 0) || (index >= count))
    return NULL;
  
  pos  = 0;
  elem = first;
  while(elem != NULL) {
    if(pos == index)
      return elem;
    
    pos++;
    elem = elem->next;
  }
  
  return NULL;
}

int List::insert(int index, Data data) 
{
  Elem  *prev,  // Previous element
        *elem;  // New element
        
  if((index < 0) || (index > count))
    return -1;
        
  elem = new Elem;
  if(elem == NULL)
    return -1;

  elem->data = data;
    
  if(index > 0) {
    prev = getElem(index - 1);
    
    elem->next = prev->next;
    prev->next = elem;
  }
  else {
    elem->next = first;
    first = elem;
  }
  count++;
  
  return index;
}

int List::append(Data data) 
{
  return insert(count,data);
}

int List::remove(int index)
{
  Elem *elem,
       *prev;
  
  if((index < 0) || (index >= count))
    return -1;
    
  if(index > 0) {
    prev = getElem(index - 1);
    elem = prev->next;
    prev->next = elem->next;
  }
  else {
    elem = first;
    first = elem->next;
  }
  
  count--;
  delete elem;
  
  return index;
}

void List::show() 
{
  Elem  *elem;
  
  if(!name.empty())
    cout << name << " = ";
  
  cout << "[ ";
  
  elem = first;
  while(elem != NULL) {
    cout << elem->data << ',';
    elem = elem->next;
  }
  cout << "\b ]" << endl;
}

void List::random(int n, int a)
{
  for(int i=0;i < n;i++)
    append(rand() % a);
}

void List::clear()
{
  Elem  *elem,
        *next;
        
  elem = first;
  while(elem != NULL) {
    next = elem->next;
    delete elem;
    elem = next;
  }
  count = 0;
  first = NULL;
}

void List::concat(const List &list)
{
  Elem  *elem;
  
  elem = list.first;
  while(elem != NULL) {
    append(elem->data);
    elem = elem->next;
  }
}


