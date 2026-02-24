#include <stdio.h>
 
int main() {
 
    int t;
    scanf("%d", &t);
 
    while(t--) {
 
        int n;
        scanf("%d", &n);
 
        long long arr[n];
 
        for(int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
        }
 
        int index1 = -1;
        int index2 = -1;
 
        
        long long max = arr[n-1];
        int maxpos = n-1;
 
        
        for(int i = n-2; i >= 0; i--) {
 
            if(max > arr[i]) {
                index1 = i;
                index2 = maxpos;
            }
 
            if(arr[i] > max) {
                max = arr[i];
                maxpos = i;
            }
        }
 
        if(index1 != -1) {
 
            int l = index1;
            int r = index2;
 
            while(l < r) {
                long long temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                l++;
                r--;
            }
        }
 
        for(int i = 0; i < n; i++) {
            printf("%lld ", arr[i]);
        }
 
        printf("\n");
    }
 
    return 0;
}
