#include <bits/stdc++.h> 
class NStack
{
public:
    // Initialize your data structure.
        int free;
        int *arr;
        int *top;
        int *next;
        int s;
        int n;
             
    NStack(int N, int S)
    {
        // Write your code here.
        free=0;
        s=S;
        n=N;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        // int next[S];
        for(int i=0;i<n;i++)
        top[i]=-1;

        for(int j=0;j<s;j++)
        {
            next[j]=j+1;
            // arr[i]=-1;
        }
         next[s-1]=-1;
    }

    // 3
    // 0 -1 -1
    // -1  2 3 4 5 -1

    // free=1;
    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(free==-1)return false;

        int i=free;
        free=next[i];
        next[i]=top[m-1];
        top[m-1]=i;
        arr[i]=x;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1]==-1)return -1;
        else 
        {
            int popEleIndex = top[m-1];
            top[m-1]=next[popEleIndex];
            next[popEleIndex]=free;
            free = popEleIndex;
            // top[m-1] = i;
            return arr[popEleIndex];
        }

    }
};