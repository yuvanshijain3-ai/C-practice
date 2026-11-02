#include <stdio.h>
int main()
{
    int a,b,temp;
    printf("enter first number: ");
    scanf("%d",&a);

    printf("enter second number: ");
    scanf("%d",&b);

    temp=a;
    a=b;
    b=temp;
    
    printf("After swapping: first number = %d, second number = %d",a,b);
    return 0;
}