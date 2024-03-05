
#include<bits/stdc++.h>
using namespace std;
float result,h;
float func(float x)
{
    return 1/(1+x);
}
void Trapezoidal(float y[],int n)
{
    float s=0;
    for(int i=1;i<n;i++)
    {
        s+=y[i];
    }
    result=(h/2)*(y[0]+y[n]+2*s);
    cout<<"Result Trapezoidal Rule :"<<result<<endl;
}
void Simpson_1_3(float y[],int n)
{
    float s1=0,s2=0;
        for(int i=1;i<n;i++)
        {
            if(i%2!=0)
               s1+=y[i];
            else
                s2+=y[i];
        }
        result=(h/3)*(y[0]+y[n]+4*s1+2*s2);
        cout<<"Result Simpson's 1/3 Rule :"<<result<<endl;
}
void Simpson_3_8(float y[],int n)
{
    float s1=0,s2=0;
        for(int i=1;i<n;i++)
        {
            if(i%3!=0)
               s1+=y[i];
            else
                s2+=y[i];
        }
        result=(3*h/8)*(y[0]+y[n]+3*s1+2*s2);
        cout<<"Result Simpson's 3/8 Rule :"<<result<<endl;
}
void Weddle(float y[],int n)
{
    float s1=0,s2=0,s3=0,s4;
    cout<<"------------"<<endl;
        for(int i=0;i<=n;i++)
        {
            if( (i%2==0&&(i%6!=0 || i==0) )|| i==n)
               s1+=y[i];
            else if(i%6==0 && i!=0 && i!=n)
                s2+=y[i];
            else if(i%3==0 && i%6!=0)
                s3+=y[i];
            else if(i%2!=0 && i%3!=0)
                s4+=y[i];
            cout<<y[i]<<" ";
        }
        //s1=s1+y[0]; //y[0] not add for because of condition.
        cout<<endl;
        cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
        cout<<"----------------"<<endl;
        result=(3*h/10)*(s1+2*s2+6*s3+5*s4);
        cout<<"Result Weddle's Rule :"<<result<<endl;
}
int main()
{
    float ll,hl;
    cout<<"Lower Limit :";
    cin>>ll;
    cout<<"Higher Limit :";
    cin>>hl;
    int n;
    cout<<"Number Of divisor :";
    cin>>n;
    h=(hl-ll)/n;
    float y[n];
    for(int i=0;i<=n;i++)
    {
        y[i]=func(ll+h*i);
    }
    cout<<"Click 1 : For Trapezoidal Rule."<<endl;
    cout<<"Click 2 : For Simpson 1/3 Rule."<<endl;
    cout<<"Click 3 : For Simpson 3/8 Rule."<<endl;
    cout<<"Click 4 : For Weddle's Rule."<<endl;
    cout<<"Click 5 : For All Integration Rules."<<endl;
    int choice;
    cin>>choice;
    system("cls");
    if(choice==1)
    {
        Trapezoidal(y,n);
    }
    else if(choice==2)
    {
        Simpson_1_3(y,n);
    }
    else if(choice==3)
    {
        Simpson_3_8(y,n);
    }
    else if(choice==4)
    {
        Weddle(y,n);
    }
    else
    {
        Trapezoidal(y,n);
        Simpson_1_3(y,n);
        Simpson_3_8(y,n);
        Weddle(y,n);
    }
}
