#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(vector<int>& a,vector<int>& b)
{
   double a1 = (1.0 * a[0])/a[1];
   double b1 = (1.0 * b[0])/b[1];
   return a1>b1;
}


double fractionalKnapsack(vector<int>& val,vector<int>& wt,int capacity)
{
    int n = val.size();

    vector<vector<int>>item;
    for(int i=0;i<n;i++)
    {
        item.push_back({val[i],wt[i]});
    }
    sort(item.begin(),item.end(),compare);

    double res=0.0;
    int currentCapacity=capacity;


    for(int i=0;i<n;i++)
    {
        if(item[i][1]<=currentCapacity)
        {
            res+=item[i][0];
            currentCapacity-=item[i][1];
        }
        else
        {
            res+=(1.0*item[i][0]/item[i][1])*currentCapacity;
            break;
        }
    }

    return res;
}

int main()
{
    vector<int> val={60,100,120};
    vector<int> wt={10, 20, 30};
    int capacity = 50;
    cout<<fractionalKnapsack(val,wt,capacity)<<endl;
    return 0;
}

