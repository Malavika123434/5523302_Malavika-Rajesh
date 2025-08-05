Flipping Bits:

Code:


#include stdio.h
#include stdint.h

int main()
{
    uint32_t mask = 0xFFFFFFFF;
    int n,i;
    uint32_t x;
    
    scanf(%d,&n);

    for(i = 0;in;i++)
    {
        scanf(%u,&x);
        printf(%un,x ^ mask);
    }
    return 0;
}