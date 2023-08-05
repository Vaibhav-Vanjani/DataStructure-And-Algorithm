// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Stack{

public:
int *arr;
int top;
int size;

  Stack(int size)
  {
      this->size = size;
      top=-1;
      arr = new int[size];
  }
  
  void push(int d)
  {
     if((size - top) == 1)
     {
         cout<<"stack is full"<<endl;
         return ;
     }
      top++;
      arr[top]=d;
  }
  
  void pop()
  {
      if(top == -1)
      {
      cout<<"stack underFlow";
      return;
      }
      
      top--;
      return ;
  }
  
  void peek()
  {
      if(top == -1)
      {
          cout<<"no element";
          return ;
      }
      cout<<"top element :";
      cout<<arr[top]<<endl;
  }
  
  bool isEmpty()
  {
      if(top == -1)
          return true;
          
      return false;
  }
};

int main() {
    // Write C++ code he
    // Stack* s = new Stack();
    // s->push(3);
    // s->push(5);
    // s->push(2);
    // s->push(1);
    // s->peek();
    // s->pop();
    // s->peek();
    
    Stack s(5);
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(1);
    s.peek();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.peek();
    
    return 0;
}