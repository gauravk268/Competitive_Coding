#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, i, zeroes=0, twos=0, temp, sum=0;
        scanf("%d", &N);
        
        for(i=0; i<N; i++){
            scanf("%d", &temp);
            
            if(temp == 2)
                twos++;
            if(temp == 0)
                zeroes++;
        }
        
        if(twos<1)
            twos=0;
        if(zeroes<1)
            zeroes=0;
            
        sum = ((twos*(twos-1)/2) + (zeroes*(zeroes-1)/2));
        
            
        printf("%d\n", sum);
    }
	return 0;
}
