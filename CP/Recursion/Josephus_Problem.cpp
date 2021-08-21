#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &people, int k, int place)
{
    if(people.size()==1)
        return people[0];
    
    place = (place+k)%people.size();
    people.erase( people.begin()+place );
    
    return solve(people, k, place);
}

int main()
{
    int t=1;
    // cin>>t;
    
   while(t--)
   {
        int n=5, k=3;
        // cin>>n>>k;
        vector<int> people(n);
        for(int i=0; i<n; i++)
        {
            people[i]=i+1;
        }
        
        cout<<solve(people, --k, 0)<<endl;
   }
    return 0;
}