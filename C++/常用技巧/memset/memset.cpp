#include <iostream>
#include<cstring>
using namespace std;

int main()
{
  char arr[]="hello world";
  cout<<arr<<endl;
  
  memset(arr,'x',5);
  cout<<arr<<endl;
}
