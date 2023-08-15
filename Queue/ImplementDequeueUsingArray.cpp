#include <bits/stdc++.h> 
class Deque
{
public:
    int *arr;
    int top;
    int front;
    int s;
    // Initialize your data structure.
    Deque(int n)
    {
        s=n;
        front=-1;
        arr=new int[n];
        top=-1;
        // Write your code here.
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
      
       if((front==0 && top==s-1) or ((front == top+1)))
        return false;
      else if(isEmpty())
      {
          front=0;
          top=0;
        arr[front]=x;     
      }
      else if(front==0 && (top!=s-1))
      {
        front=s-1;
        arr[front]=x;   
      }
      else
      {
          front--;
          arr[front]=x;
      }
    //   arr[front]=x;
      return true;
                
        // Write your code here.
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
          if((front==0 && top==s-1) or (front == top+1))
        return false;
      else if(front==-1)
      {
          front=0;
          top=0;
         arr[top]=x;
      }
      else if(front!=0 && (top==s-1))
      {
        top=0;
        arr[top]=x;   
      }
      else
      {
          top++;
          arr[top]=x;
      }
      
      return true;
                

    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.

        if(front==-1)return -1;
        
        if(front==top)
        {
            int i=front;
            front=-1;
            top=-1;
            return arr[i];
        }
        else 
        {
            int i=front;
            front++;
            return arr[i];
        }
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
         if(front==-1)return -1;
        
        if(front==top)
        {
            int i=front;
            front=-1;
            top=-1;
            return arr[i];
        }
        else 
        {
            int i=top;
            top--;
            return arr[i];
        }
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.

        if(front==-1)return -1;
        
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        
        if(front==-1)return -1;
        
        return arr[top];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.

        if(front==-1)
        return true;
        else 
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
          if((front==0 && top==s-1) or ((front == top+1)))
            return true;
          
          return false;
    }
};