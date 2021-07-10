vector<string> Solution::fizzBuzz(int a) {
    vector<string> result;
    for(int i=1; i<=a; i++){
        if(!(i%3) && !(i%5))    result.push_back("FizzBuzz");
        else if(!(i%3))   result.push_back("Fizz");
        else if(!(i%5))   result.push_back("Buzz");
        else  result.push_back(to_string(i));
    }
    
    return result;
}
