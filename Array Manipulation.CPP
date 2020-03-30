#Array Manipulation using Prefix Sum method
#Time Complexity - O(n)
#Auxiliary Space - O(1)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n,m,max=INT_MIN;
    cin>>n>>m;
    long int *ar = new long int[n+1] ();
    while(m--)
    {
        long int a,b,k;
        cin>>a>>b>>k;
        ar[a]+=k;
        if((b+1)!=n+1)
           ar[b+1]-=k;
    }
    for(long int i = 0 ; i < n ; i++)
    {
        ar[i+1]+=ar[i];
        if(max<ar[i+1])
           max=ar[i+1];
    }
    cout<<max;
}
