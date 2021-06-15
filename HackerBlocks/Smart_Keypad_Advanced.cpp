#include<bits/stdc++.h>
using namespace std;

string key(int a){
	switch(a){
		case 2:	return "abc";
		case 3:	return "def";
		case 4:	return "ghi";
		case 5:	return "jkl";
		case 6:	return "mno";
		case 7:	return "pqrs";
		case 8:	return "tuv";
		case 9:	return "wxyz";
	}

	return "";
}

int main() {
	vector<string> searchIn = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak","utkarsh", "divyam", "vidhi", "sparsh", "akku"};

	string str;	cin>>str;
	vector<string> values;
	for(int i=0; i<str.length(); i++){
		values.push_back(key(str[i]-'0'));
	}

	vector<string> sub;
	for(int i=0; i<values[0].length(); i++){
		sub.push_back(values[0].substr(i, 1));
	}

	vector<string> temp;
	for(int i=1; i<values.size(); i++){
		for(auto x:sub){
			for(auto k:values[i]){
				temp.push_back(x+k);
			}
		}
		sub.clear();
		sub.assign(temp.begin(), temp.end());
		temp.clear();
	}

	int k=values.size();
	vector<string> result;
	for(auto x:searchIn){
		if(x.length()>=k){
			for(auto pat: sub){
				auto found=x.find(pat);
				if(found!=string::npos){
					result.push_back(x);
					break;
				}
			}
		}
	}

	reverse(result.begin(), result.end());
	for(auto x:result)	cout<<x<<"\n";

	return 0;
}