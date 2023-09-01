// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class heap{
  public:
  
  int arr[100];
  int size;
  
  heap(){
      size=0;
      arr[0]=-1;
  }
  
  void insert(int d){
      size++;
      int indx = size ;
      
      arr[indx]=d;
      
      while(indx>1)
      {
          int parent = indx/2;
          
          if(arr[parent] < arr[indx])
          {
              swap(arr[parent],arr[indx]);
              indx=parent;
          }
          else
          {
              return ;
          }
      }
  }
  
  void print()
  {
      for(int i=1;i<=size;i++)
      {
          cout<<arr[i]<<" ";
      }
  }
  
  void deleteF()
  {
    //   int root = 1;
      int indx=1;
      arr[1]=arr[size];
      size--;
      
      while(indx<=size)
      {
          int leftChild = 2*indx;
          int rightChild = 2*indx + 1;
          
     
        
       
            if(rightChild<=size)
            {
             int maxi = max(arr[leftChild],arr[rightChild]);
            
            if(maxi>arr[indx])
            { 
                if(maxi == arr[rightChild])
                 {
                  swap(arr[rightChild],arr[indx]);
                  indx = rightChild;
                 }
                 else 
                 {
                  swap(arr[leftChild],arr[indx]);
                  indx = leftChild;
                 }
            }
            else return;
            }
          else if(leftChild<=size and arr[leftChild]>arr[indx])
          {
              swap(arr[leftChild],arr[indx]);
              indx = leftChild;
          }
          else return ;
      }
      
      
  }
  
  
  
  
  
};

int main() {
   
   heap h;
   h.insert(50);
   h.insert(55);
   h.insert(35);
   h.insert(80);
   h.insert(25);
   h.insert(19);
   h.print();
   cout<<endl;
   h.deleteF();
   h.print();  cout<<endl;
   h.deleteF();
   h.print();  cout<<endl;
   h.deleteF();
   h.print(); cout<<endl;
    h.deleteF();
   h.print();  cout<<endl;
   h.deleteF();
   h.print();  

    return 0;
}