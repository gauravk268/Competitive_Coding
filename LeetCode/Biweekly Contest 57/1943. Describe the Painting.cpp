class tNode{
    public:
        long long data, startData;
        bool start, end;

        tNode(){
            data=0;
            startData=0;
            start=false;
            end=false;
        }
};

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        tNode arr[100005];

        for(auto &x:segments){
           arr[x[0]].start=true;
           arr[x[0]].startData+=x[2];
           arr[x[0]].data+=x[2];

            arr[x[1]].data-=x[2];
            arr[x[1]].end=true;
        }

        vector<vector<long long>> result;

        int lastIndex=1, sum=0;
        for(int i=1; i<100005; i++){
            arr[i].data += arr[i-1].data;

            if((arr[i].end || (lastIndex!=i && arr[i].start)) && (arr[i-1].data != 0)){
                result.push_back({lastIndex, i, arr[i-1].data});
                lastIndex=i;
            }
            
            if(arr[i].start){
                lastIndex=i;
            }
        }

        return result;
    }
};