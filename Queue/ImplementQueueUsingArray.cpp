#include <bits/stdc++.h> 
class Queue {
public:
    int *arr;
    int top;
    int fronte;

    Queue() {
        // Implement the Constructor
        arr=new int[5001];
        fronte=-1;
        top=-1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(fronte==-1)
        return true;
        
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(fronte==-1)
        fronte++;
        
        top++;
        arr[top]=data;
        return ;
        
    }

    int dequeue() {
        // Implement the dequeue() function
        if(fronte==-1)return -1;
        else 
        {
            if(fronte==top)
            {
                int i=fronte;
                fronte=-1;
                top=-1;
                return arr[i];
            }
               
            int i=fronte;
            fronte++;
            return arr[i];
        }
        
    }

    int front() {
        // Implement the front() function
        if(fronte==-1)return -1;
        else 
        {
            return arr[fronte];
        }
    }
};