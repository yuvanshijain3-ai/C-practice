#include<stdio.h>
int main() 
{
    int x,y;
    char choice;

    printf("enter the operator (+,-,*,/) \n");
    scanf("%c",&choice);

    printf("enter the two numbers \n");
    scanf("%d %d",&x,&y);

    switch(choice)
    {
        case '+':
            printf("the sum is %d",x+y);
            break;
        
        case '-':
            printf("the difference is %d",x-y);
            break;
        
        case '*':
            printf("the product is %d",x*y);
            break;
            
        case '/':
            if(y!=0)
            {
                printf("the division is %d",x/y);
            }
            else
            {
                printf("division by zero is not allowed");
            }
            break;
            
        default:
            printf("invalid operator");
    }
}    