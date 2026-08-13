#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {0};
    memcpy(b, a, 10 * sizeof(int));
    for(int e: b)
    {
        cout << e << " ";
    }
    return 0;
}

/"
1 2 3 4 5 6 7 8 9 10 
"/
