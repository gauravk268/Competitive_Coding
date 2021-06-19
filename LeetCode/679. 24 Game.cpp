class Solution {
public:
    double op(double &a, double &b, int i){
        switch(i){
            case 0:     return a+b;
            case 1:     return a-b;
            case 2:     return a*b;
            case 3:     return a/b;
        }
        return 0;
    }
    
    bool judgePoint24(vector<int>& cards) {
        double nums[4];
        sort(cards.begin(), cards.end());
        
        for(int i=0; i<4; i++)  nums[i]=cards[i];
        if(valid4(nums[0], nums[1], nums[2], nums[3]))  return true;
        
        while(next_permutation(cards.begin(), cards.end())){
            for(int i=0; i<4; i++)  nums[i]=cards[i];
            if(valid4(nums[0], nums[1], nums[2], nums[3]))  return true;
        }
        
        return false;
    }
    
    bool valid4(double a, double b, double c, double d){
        for(int i=0; i<4; i++)  if(valid3(op(a, b, i), c, d))     return true;
        for(int i=0; i<4; i++)  if(valid3(a, op(b, c, i), d))     return true;
        for(int i=0; i<4; i++)  if(valid3(a, b, op(c, d, i)))     return true;
        return false;
    }
    
    bool valid3(double a, double b, double c){
        for(int i=0; i<4; i++)  if(b && valid2(op(a, b, i), c))     return true;
        for(int i=0; i<4; i++)  if(c && valid2(a, op(b, c, i)))     return true;
        return false;
    }
    
    bool valid2(double a, double b){
        for(int i=0; i<4; i++)  if(b && abs(op(a, b, i)-24.0)<0.0001)     return true;
        return false;
    }
};