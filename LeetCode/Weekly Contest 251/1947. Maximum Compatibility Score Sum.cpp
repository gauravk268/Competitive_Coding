class Solution {
public:
    int xnor(bitset<8> &a, bitset<8> &b, int n){
        int count=0;
        for(int i=n-1; i>=0; i--){
            if(a[i]==b[i])  count++;
        }

        return count;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size(), m=students[0].size();
        bitset<8> stu[n], men[n];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(students[i][j])  stu[i].set(j);
                if(mentors[i][j])  men[i].set(j);
            }
        }

        string a="";
        int iTmp=0;
        while(iTmp<n){
            a+='0'+iTmp;
            iTmp++;
        }

        bool nextPer=true;
        int result=0;
        while(nextPer){
            int tmpRes=0;
            for(int i=0; i<n; i++){
                tmpRes += xnor(stu[i], men[a[i]-'0'], m);
            }
            
            result = max(result, tmpRes);
            nextPer=next_permutation(a.begin(), a.end());
        }

        return result;
    }
};