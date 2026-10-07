#include<bits/stdc++.h>
using namespace std;


int lis(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lis(n,1);
    for(int i=1;i<n;i++)
    {
        for(int prev=1;prev<i;prev++)
        {
            if(arr[i]>arr[prev])
            {
                lis[i]=max(lis[i],lis[prev]+1);
            }
        }
    }
    return * max_element(lis.begin(),lis.end());
}


int main()
{
    vector<int> arr = {3, 10, 2, 1, 20};
    cout<<lis(arr)<<endl;
    return 0;
}
