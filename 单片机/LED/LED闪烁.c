#include <REGX52.H>

void Delay(unsigned int t)
{
    unsigned int i,j;
    for(i=t;i>0;i--)
        for(j=110;j>0;j--);
}

void main()
{
    while(1)
    {
        P2 = 0x00;   
        Delay(500);

        P2 = 0xFF;   
        Delay(500);
    }
}
