#include<iostream>
using namespace std;

class stack
{
    private:
    int stack[10];
    int top;

    public:
    stack()
    {
        top=-1;
    }

    void push(int value)
    {
        if(top== 10-1)
        {
         cout<<"stack overflow!"<<endl;
        }
        top++;
        stack[top]=value;
        cout<<"value<<"<<value<<"pushed successfully!"<<endl;
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"stack underflow!"<<endl;
        }
        else
        {
            cout<<"value<<"<<stack[top]<<"deleted successfully!"<<endl;
            top--;
        }
    }
    void peek()
    {
        if(top==-1)
        {
            cout<<"stack is empty!"<<endl;
        }
        else
        {
            cout<<"top value is:"<<stack[top]<<endl;
        }
    }
    void display()
    {
        if(top==-1)
        {
            cout<<"stack is empty!"<<endl;
        }
        else
        {
            cout<<"\n stack elements are:"<<endl;
            for(int i=top;i>=0;i--)
            {
                cout<<stack[i]<<endl;
            }
        }
    }    

};

int main()
{
    stack s;
    int choice,value;

    do
    {
        cout<<"1.push"<<endl;
        cout<<"2.pop"<<endl;
        cout<<"3.peek"<<endl;
        cout<<"4.display"<<endl;
        cout<<"5.exit"<<endl;
        cout<<"enter your choice:"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"enter integer:"<<endl;
                cin>>value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                exit(0);

            default:
                cout<<"invalid choice!"<<endl;
        }
    }
    while(choice!=5);
}