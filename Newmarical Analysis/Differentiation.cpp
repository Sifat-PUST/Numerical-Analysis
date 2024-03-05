#include<bits/stdc++.h>
using namespace std;
float func(float x)
{
    return pow(x,3);
}
int main()
{
    int n=5;
    float p,h;
    cout<<"At point :";
    cin>>p;
    h=0.01;
    /*
        if h increase then top->down derivation  accuracy increase
        if h decrease then bottom->up derivation accuracy increase
        so,when you find 1st derivation let h=low.And when you find
        3rd,4th etc. then let h=high.
    */
    float y[n],fb[2][n]={0},u;
    for(int i=0;i<n;i++)
    {
        y[i]=func(p+(i*h));
    }
    //u=0 because we differentiate tabulated value.Otherwise u=(p-a)/h
    for(int k=0;k<n;k++)
    {
        fb[0][k]=y[0];
        fb[1][k]=y[n-k-1];
        for(int i=0;i<n-1;i++)
        {
            y[i]=y[i+1]-y[i];
        }
    }
    for(int k=0;k<2;k++)
    {
        for(int i=0;i<n;i++)
        {
            cout<<fb[k][i]<<" ";
        }
        cout<<endl;
    }
    float r1=(1/h)*(fb[0][1]-(1/2)*fb[0][2]+(1/3)*fb[0][3]-(1/4)*fb[0][4]);
    float r2=(1/pow(h,2))*(fb[0][2]-fb[0][3]-(11/12)*fb[0][4]);
    float r3=(1/pow(h,3))*(fb[0][3]-(3/2)*fb[0][4]);
    cout<<"1st Differential Value is :"<<r1<<endl;
    cout<<"2nd Differential Value is :"<<r2<<endl;
    cout<<"3nd Differential Value is :"<<r3<<endl;
}
