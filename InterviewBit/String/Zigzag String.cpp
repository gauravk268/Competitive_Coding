string Solution::convert(string A, int B) 
{
    if(B==1)    return A;

    int n=A.length();
    vector<string> arr;
    for(int i=0; i<B; i++)  arr.push_back("");

    int row=0;
    bool down=true;
    string result="";

    for(int i=0; i<n; i++)
    {
        arr[row] += A[i];

        if(row==B-1)    down=false;
        if(row==0)  down=true;

        if(down)  row++;
        else      row--;
    }

    for(int i=0; i<B; i++)  result += arr[i];

    return result;
}
