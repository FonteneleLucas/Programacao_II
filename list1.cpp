
#include <iostream>

using namespace std;

// List base type
typedef int DATA;

// List element
struct ELEM { 
  DATA  data;
  ELEM *next;
};

// List head
struct LIST {
  int   count;    // Number of elements
  ELEM *first;    // Reference to first element
};

// List initialization
void ListInit(LIST &list)
{
  list.count = 0;
  list.first = NULL;
}

// Returns the element in 'index' posistion
ELEM *ListElem(const LIST &list, int index) 
{
  ELEM *elem;   // Current element
  int   pos;    // Current index
  
  if((index < 0) || (index >= list.count))
    return NULL;
  
  pos  = 0;
  elem = list.first;
  while(elem != NULL) {
    if(pos == index)
      return elem;
    
    pos++;
    elem = elem->next;
  }
  
  return NULL;
}

// Insert a data in list
int ListInsert(LIST &list, int index, DATA data)
{
  ELEM  *prev,  // Previous element
        *elem;  // New element
        
  if((index < 0) || (index > list.count))
    return -1;
        
  elem = new ELEM;
  if(elem == NULL)
    return -1;

  elem->data = data;
    
  if(index > 0) {
    prev = ListElem(list,index - 1);
    
    elem->next = prev->next;
    prev->next = elem;
  }
  else {
    elem->next = list.first;
    list.first = elem;
  }
  list.count++;
  
  return index;
}

int ListAppend(LIST &list, DATA data)
{
  return ListInsert(list,list.count,data);
}

int ListRemove(LIST &list, int index) 
{
  ELEM *elem,
       *prev;
  
  if((index < 0) || (index >= list.count))
    return -1;
    
  if(index > 0) {
    prev = ListElem(list,index - 1);
    elem = prev->next;
    prev->next = elem->next;
  }
  else {
    elem = list.first;
    list.first = elem->next;
  }
  
  list.count--;
  delete elem;
  
  return index;
}

void ListShow(const LIST &list, const char *prompt = NULL)
{
  ELEM  *elem;
  
  if(prompt != NULL)
    cout << prompt;
  
  cout << "[ ";
  
  elem = list.first;
  while(elem != NULL) {
    cout << elem->data << ',';
    elem = elem->next;
  }
  cout << "\b ]" << endl;
}

int main()
{
  LIST   a;
 
  ListInit(a);

  ListShow(a,"A = ");
  ListAppend(a,10);  
  ListAppend(a,30);  
  ListAppend(a,15);  
  ListAppend(a,50);  
  ListAppend(a,40);  
  ListAppend(a,20);  
  ListAppend(a,35);  
  ListShow(a,"A = ");
 
  ListRemove(a,3);
  ListShow(a,"A = ");

  ListRemove(a,0);
  ListShow(a,"A = ");

  return 0;
}

