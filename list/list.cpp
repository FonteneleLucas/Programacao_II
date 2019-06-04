
#include <iostream>
#include <stdlib.h>
#include "list.h"

using namespace std;

List::List() 
{
  init();
}

List::List(const char *lname) 
{
  init();
  name  = lname;
}

List::List(const List &list) 
{
  init();
  assign(list);
}

void List::init()
{
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

void List::assign(const List &list)
{
  Elem *elem;
  
  clear();
  
  elem = list.first;
  while(elem != NULL) {
    append(elem->data);
    elem = elem->next;
  }
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

string List::toString()
{
  string  s;
  Elem   *elem;
  
  if(!name.empty())
    s = name + " = ";
  s += "[ ";

  elem = first;
  while(elem != NULL) {
    s += to_string(elem->data);
    if(elem->next != NULL)
      s+= ',';
    elem = elem->next;
  }
  s += " ]";
  
  return s;
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

Data *List::toArray()
{
  Data  *v;
  
  if(count == 0)
    return NULL;
  
  v = new Data[count];
  
  toArray(v);
    
  return v;
}

int List::toArray(Data *v)
{
  Elem *elem;
  int   i;
  
  i = 0;
  elem = first;
  while(elem != NULL) {
    v[i++] = elem->data;
    elem = elem->next;
  }
  
  return count;  
}

int List::fromArray(Data *v, int n)
{
  Elem *elem;
  int   i;
  
  elem = first;
  for(i=0;i < n;i++) {
    if(elem != NULL) {
      elem->data = v[i];
      elem = elem->next;
    }
    else
      append(v[i]);
  }
  return n;
}

int fcomp(const void *e1, const void *e2, void *arg)
{
  Data   d1 = *((Data *) e1),
         d2 = *((Data *) e2);
  int    m  = *((int *) arg);
         
  /*
  if(d1 < d2)
    return -1;
  else if(d1 > d2)
    return 1;
  else
    return 0;
  */
        
  return (d1 < d2) ? -1 * m :
         (d1 > d2) ?  1 * m : 0;
}

void List::sort(bool asc)
{
  Data  *v;
  int    m;
  
  m = asc ? +1 : -1;
  
  v = toArray();
  qsort_r(v,count,sizeof(*v),fcomp,&m);
  fromArray(v,count);

  delete[] v;
}

List List::operator<<(int n)
{
  List  r;
  Elem *elem;
   
  elem = getElem(n % count);

  n = count;
  while(n > 0) {
    r.append(elem->data);
    
    if(elem->next != NULL)
      elem = elem->next;
    else
      elem = first;

    n--;
  }
  
  return r;
}

