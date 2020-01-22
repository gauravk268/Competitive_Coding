#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct value{
    int x;
    int y;
};

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 


void bubbleSort(struct value arr[], int n) 
{ 
   int i, j; 
   bool swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j].x > arr[j+1].x) 
        { 
           swap(&arr[j].x, &arr[j+1].x); 
           swapped = true; 
        }
     } 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
} 


int main() {
    int T, i;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        
        struct value arr[n];
        int dist[n];
        
        for(int i=0; i<n; i++){
            cin>>arr[i].x>>arr[i].y;
            //dist[i] = pow((pow(arr[i].x, 2) + pow(arr[i].y, 2), 0.5))
        }
        
        bubbleSort(arr, n);
        
        for(int i=0; i<n; i++){
            if(arr[i].x<arr[i+1].x)
                
        }
        
    }
    return 0;
}

