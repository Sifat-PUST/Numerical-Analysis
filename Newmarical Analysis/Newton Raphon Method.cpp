#include<bits/stdc++.h>
using namespace std;
float func(float x)
{
    //return pow(x,3)-2*x-5;
    //return x-exp(-x);
    return x*exp(-x)-1;
}
float func2(float x)
{
    /*return 3*pow(x,2)-2;
    return 1+exp(-x);*/
    return -x*exp(-x)+exp(-x);
}
int main()
{
    float a,b,x,x1;
    cin>>a;
    int i=50;
    while(i--){
        x=a-func(a)/func2(a);
        a=x;
        x1=a-func(a)/func2(a);
        //i++;
        if(func(x)==func(x1))
            break;
    }
    cout<<"Root :"<<x1<<"   Iteration:"<<i<<endl;
}
$
