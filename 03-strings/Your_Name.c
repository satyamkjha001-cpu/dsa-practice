/*
Problem: Rearrange letters to match another string
Concept: Strings, Frequency Array, Anagram Check
Time Complexity: O(n)
*/
#include <stdio.h>
#include <string.h>

int main()
{
    
        
        int n;
        scanf("%d",&n);
        
        int freqS[26]={0};
        int freqT[26]={0};
        
        char s[21];
        char q[21];
        
        scanf("%s %s", s, q);
        
        for(int i=0;i<n;i++){
            freqS[s[i]-'a']++;
            freqT[q[i]-'a']++;
        }
        
        int flag=1;
        
        for(int i=0;i<26;i++){
            if(freqS[i]!=freqT[i]){
                flag=0;
                break;
            }
        }
        
        if(flag) printf("YES\n");
        else printf("NO\n");

    return 0;
}