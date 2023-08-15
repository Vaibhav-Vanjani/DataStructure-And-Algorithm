#include <bits/stdc++.h> 
class CircularQueue{
    public:

    int *arr;
    int top;
    int N;
    int front;
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.

        arr=new int[n];
        top=-1;
        front=-1;
        N=n;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((top==N-1 && front==0) or ((front+N-1)%N) == top)
        return false;
        else if(front==-1)
        {
            front++;
            top++;
            arr[top]=value;
        }
        else if(top==N-1 && front!=0)
        {
            top=0;
            arr[top]=value;
        }
        else{
            top++;
            arr[top]=value;
        }
        
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if((front==-1))
        return -1;
        else if(front==top)
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

            if(front==N)
            front=0;
            
            return arr[i];
        }
    }
};