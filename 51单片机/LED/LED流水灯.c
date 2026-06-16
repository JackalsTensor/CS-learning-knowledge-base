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
        P2=0xFE;
        Delay(500);

        P2=0xFD;
        Delay(500);

        P2=0xFB;
        Delay(500);

        P2=0xF7;
        Delay(500);

        P2=0xEF;
        Delay(500);

        P2=0xDF;
        Delay(500);

        P2=0xBF;
        Delay(500);

        P2=0x7F;
        Delay(500);
    }
}
