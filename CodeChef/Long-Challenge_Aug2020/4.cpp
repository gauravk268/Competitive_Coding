#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define endl "\n"
#define MOD 1e9+7
#define deb(x) cout << #x << "=" << x << endl


#define ENABLE_DEBUG


void solve(string original, string pattern)
{
    if(original==pattern || original.length()==pattern.length())
    {
        cout<<pattern<<endl;
        return;
    }
    
    bool flag=1;
    for(int i=1; i<pattern.length(); i++)
    {
        if(pattern[i]<pattern[i-1])
        {
            flag = 0;
            break;
        }
        else if(pattern[i]>pattern[i-1])
            break;
    }
    
    string patternCopy=pattern;
    
    sort(patternCopy.begin(), patternCopy.end());
    sort(original.begin(), original.end());
    
    int index=0;
    string originalTemp;
    for(int i=0; i<original.length(); i++)
    {
        if(patternCopy[index]==original[i])
        {
            index++;
        }
        else
        {
            originalTemp += original[i];
        }
    }
    
    patternCopy.erase();
    original = originalTemp;
    originalTemp.erase();
    
    // cout<<original<<endl;
    
    string result;
    if(original[0]>pattern[0])
    {
        result = pattern+original;
    }
    else if(original[original.length()-1] < pattern[0])
    {
        result = original+pattern;
    }
    else
    {
        for(int i=0; i<original.length(); i++)
        {
            if(original[i]==pattern[0] && !flag)
            {
                if(!i)
                    result = pattern + original;
                else
                    result = original.substr(0, i) + pattern + original.substr(i, original.length()-1);
                    
                break;
            }
            
            if(original[i]>pattern[0])
            {
                result = original.substr(0, i) + pattern + original.substr(i, original.length()-1);
                break;
            }
        }
    }
    
    cout<<result<<endl;
    return;
}



void takeInput()
{
    string original, pattern;
    cin>>original>>pattern;
    
    solve(original, pattern);
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
	cin>>t;

	while(t--)
	{
	    takeInput();
	}
	
	return 0;
}