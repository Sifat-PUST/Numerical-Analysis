//data for n=6
/*
    1931 12
    1941 15
    1951 20
    1961 27
    1971 39
    1981 52
*/
#include<bits/stdc++.h>
using namespace std;
int fact(int x)
{
    if(x==0)
        return 1;
    else
        return x*fact(x-1);
}
int main()
{
    int n;
    cout<<"Number Of Elements :";
    cin>>n;
    float x[n],y[n],fb[2][n],in_da,u;
    cout<<"Input All Data :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
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
    cout<<"Interpolation Data :";
    cin>>in_da;
    if(in_da<x[n/2])
    {
        u=(in_da-x[0])/(x[1]-x[0]);
        float p,q=1;
        for(int i=0;i<n-1;i++)
        {
            q*=(u-i);
            p+=q/fact(i+1)*fb[0][i+1];
        }
        float in_value=fb[0][0]+p;
        cout<<"Interpolation value is :"<<in_value<<endl;
    }
    else
    {
        u=(in_da-x[n-1])/(x[1]-x[0]);
        float p,q=1;
        for(int i=0;i<n-1;i++)
        {
            q*=(u+i);
            p+=q/fact(i+1)*fb[1][i+1];
        }
        float in_value=fb[1][0]+p;
        cout<<"Interpolation value is :"<<in_value<<endl;
    }
}
