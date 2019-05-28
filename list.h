
#ifndef __list_h
#define __list_h

#include <string>

typedef int Data;

struct Elem {
  Data   data;
  Elem  *next;
};

class List
{
private:
  std::string name;
  int         count;
  Elem       *first;

private:
  Elem *getElem(int index);
  
public:
  List();
  List(const char *lname);
 ~List();
 
  inline
  int  getCount() {
    return count;
  }
  inline
  std::string getName() {
    return name;
  }
  inline
  void setName(const char *lname) {
    if(lname != NULL) name = lname;
  }
 
  void random(int n, int a);
  void show();
  void clear();
  
  int  insert(int index, Data data);
  int  append(Data data);
  int  remove(int index);
  void concat(const List &list);
  
  inline
  bool  empty() {
    return count == 0;
  }
  inline
  Data index(int idx) {
    return getElem(idx)->data;
  }
};

#endif

