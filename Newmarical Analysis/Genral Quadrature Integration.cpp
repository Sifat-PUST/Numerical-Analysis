#include<bits/stdc++.h>
using namespace std;
float func(float x)
{
    return 1/(1+x);
}
int main()
{
    float ll,hl,h;
    cout<<"Lower Limit :";
    cin>>ll;
    cout<<"Higer Limit :";
    cin>>hl;
    int n;
    cout<<"Number Of divition :";
    cin>>n;
    h=(hl-ll)/n;

    float y[n],fb[2][n],in_da,u;
    float hi=0;
    for(int i=0;i<n;i++)
    {
        hi+=h;
        y[i]=func(hi);
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
    int m;
    cin>>m;
    float p;
    p=h*(m*fb[0][0]+pow(m,2)*fb[0][1]/2+(pow(m,3)/3-pow(m,2)/2)*fb[0][2]/2+(pow(m,4)/4-pow(m,3)+pow(m,2))*fb[0][3]/6);
    cout<<"Quadrature value is :"<<p<<endl;
}
