#Dynamic Array Using Vector

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q,lastAnswer=0;
    cin>>n>>q;
    vector<int> seqList[n];
    while(q--)
    {
        
        int t;
        long int x,y;
        cin>>t>>x>>y;
        if (t==1) 
            seqList[(x^lastAnswer)%n].push_back(y);
        else 
        {
            lastAnswer=seqList[(x^lastAnswer)%n][y%seqList[(x^lastAnswer)%n].size()];
            cout << lastAnswer << endl;
        }
    }
    return 0;
}
