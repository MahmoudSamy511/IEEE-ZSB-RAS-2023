#include <stdio.h>
#include <stdbool.h>
int lengthOfLongestSubstring(char * s){
    int maxLen = 0;  
    int start = 0;                          //marks the starting position of the current substring being examined.
    int lastIndex[128] = {0};               //stores the last index at which a character appeared
    for (int i = 0; s[i] != '\0'; i++) {
        if (lastIndex[s[i]] >= start) {
            start = lastIndex[s[i]] + 1;
        }
        lastIndex[s[i]] = i;
        int len = i - start + 1;
        if (len > maxLen) {
            maxLen = len;
        }
    }
    
    return maxLen;
}

