#include <stdio.h>

int binsearch(int target, int arr[], int len){
    int low, mid, high;
    low = 0;
    high = len-1;
    while(low < high-1){
        mid = (low + high) / 2;
        if (target < arr[mid]){
            high = mid;
        }else{
            low = mid; 
        }
    }
    if(arr[low] == target){
        return low;
    }else if(arr[high] == target){
        return high;
    }else{
        return -1;
    }
}

main(){
    printf("%d\n", binsearch(1, (int[]){1, 2, 3, 4, 5, 6, 7, 10, 12, 16}, 10));
}