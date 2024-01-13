#include<iostream>
using namespace std;
double x[10];
void greedyknapsack(double m,int n,double p[],double w[])
{

    for(int i=0;i<n;i++)
    {
        x[i]=0.0;
    }
    double u=m;
    int j;
    for(int i=0;i<n;i++)
    {
        j=i;
        if(w[i]>u)
        {
            break;
        }
        x[i]=1.0;
        u=u-w[i];

    }
    if(j<n)
    {
        x[j]=u/w[j];
    }
    for(int i=0;i<n;i++){
        cout<<x[i]<<"  ";
    }
    double profit=0.0;
    for(int i=0;i<n;i++)
    {
        profit= profit + (x[i]*p[i]);
    }
    cout<<endl<<"The total profit : "<<profit;
}

int main()
{
    int n;
    double m,p[n],w[n];
    cout<<"Enter the value of number of products and max weight:"<<endl;
    cin>>n>>m;
    cout<<"Enter the value of products individual profit :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<"Enter the value of products individual weight :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    greedyknapsack(m,n,p,w);
    return 0;
}
