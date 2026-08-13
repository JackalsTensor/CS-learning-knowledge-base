#include <iostream>
#include<cstring>
using namespace std;

int main()
{
  int arr[5]={1,2,3,4,5};
  memset(arr,0,20);
  
  for(int e:arr)
  {
    cout<<e<<" ";    
  }
  cout<<endl;
  return 0;
}

/"
0 0 0 0 0                                                                                                               
                   
"/
