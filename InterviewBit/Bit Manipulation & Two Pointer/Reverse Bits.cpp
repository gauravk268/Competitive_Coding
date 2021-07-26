unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    uint32_t result=0;

    for(int i=0; i<32; i++){
        result <<= 1;

        if(A&1)     result |= 1;

        A >>= 1;
    }

    return result;
}