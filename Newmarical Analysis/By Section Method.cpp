#include<bits/stdc++.h>
using namespace std;
float func(float x)
{
    return pow(x,3)-4*x-9;
}
int main()
{
    float a,b,x,x1,i=0;
    cin>>a>>b;
    while(1){
        x=(a+b)/2;
        if(func(x)<0){
            a=x;
        }
        else if(func(x)>0){
            b=x;
        }
        x1=(a+b)/2;
        i++;
        if(func(x)==func(x1))
            break;
    }
    cout<<x1<<"   "<<i<<endl;
}
