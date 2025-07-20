class Solution {
    public int romanToInt(String s) {
        int n=s.length();
        int resp = 0;
        
        for(int i=0; i<n; i++){
            if(i<=n-2 && val(s.charAt(i)) < val(s.charAt(i+1))){
                resp += val(s.charAt(i+1)) - val(s.charAt(i));
                i++;
            }
            else{
                resp += val(s.charAt(i));
            }
        }

        return resp;
    }

    private int val(char c){
        switch(c){
            case 'I':  return 1;
            case 'V':  return 5;
            case 'X':  return 10;
            case 'L':  return 50;
            case 'C':  return 100;
            case 'D':  return 500;
            case 'M':  return 1000;
        }

        return 0;
    }
}