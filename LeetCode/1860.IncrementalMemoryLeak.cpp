class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int flag1=0,flag2=0,flag3=0;
        for(int i=1;;i++){
            if(memory1>=memory2){if(i<=memory1)memory1-=i;else flag1=1,flag2=1;}else{
                if(i<=memory2)memory2-=i;else flag1=1,flag2=1;
            }
            
            if(flag1==1&&flag2==1){flag3=i;break;}
           
        }
        return {flag3,memory1,memory2};
    }
};