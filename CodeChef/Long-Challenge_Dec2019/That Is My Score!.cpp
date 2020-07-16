#include<stdio.h>
#include<string.h>

int max(int a, int b){
	if(a>b)
		return a;
	return b;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, arr[11], i, que, marks, sum=0;
		
		scanf("%d", &n);
		memset(arr, 0, 11*sizeof(int));
		
		for(i=0; i<n; i++){
			scanf("%d %d", &que,&marks);
			arr[--que]=max(marks, arr[que]);
		}
		
		for(i=0; i<8; i++)
			sum += arr[i];
			
		printf("%d\n", sum);
	}
	return 0;
}
