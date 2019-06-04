
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
  void  init();
  Elem *getElem(int index);
  
public:
  List();
  List(const char *lname);
  List(const List &list);
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
 
  void        random(int n, int a);
  void        show();
  void        clear();
  std::string toString();
  
  void assign(const List &list);
  int  insert(int index, Data data);
  int  append(Data data);
  int  remove(int index);
  void concat(const List &list);
  
  int   fromArray(Data *v, int n);
  Data *toArray();
  int   toArray(Data *v);
  void  sort(bool asc = true);

  List operator<<(int n);
  
  inline
  bool  empty() {
    return count == 0;
  }
  inline
  Data index(int idx) {
    return getElem(idx)->data;
  }
  inline
  Data operator[](int idx) {
    return index(idx);
  }
  inline
  const List &operator=(const List &list) {
    assign(list);
    return list;
  }
  inline
  const List &operator+=(const Data &x) {
    append(x);
    return *this;
  }
  inline
  const List operator+(const List &list) {
    List r(*this);
    r.concat(list);
    return r;
  }
};

#endif

