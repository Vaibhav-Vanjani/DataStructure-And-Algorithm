//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
};

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }

// } Driver Code Ends




/* 

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
        // Your Code
        arr[rear]=x;
        rear++;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        // Your Code
        if(!front && !rear)
        return -1;
        
         int ele = front;
        if((front+1)==rear)
        {
           
            front=0;
            rear=0;
            return arr[ele];
        }
        
        // int ele=front;
        front++;
        return arr[ele];
}

-----------------------
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