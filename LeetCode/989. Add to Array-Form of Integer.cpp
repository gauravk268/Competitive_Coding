class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        
        int carry=0;
        for(int i=0; i<num.size(); i++){
            carry = num[i] + carry + (k%10);
            num[i] = carry%10;
            
            carry/=10;
            k/=10;
        }
        
        while(k){
            carry = carry + (k%10);
            num.push_back(carry%10);
            
            carry/=10;
            k/=10;
        }
        
        while(carry){
            num.push_back(carry%10);
            carry/=10;
        }
        
        reverse(num.begin(), num.end());
        return num;
    }
};
