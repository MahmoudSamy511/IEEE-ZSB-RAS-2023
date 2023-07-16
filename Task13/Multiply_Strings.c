#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * multiply(char * num1, char * num2){
    if(num1[0]=='0' || num2[0]=='0') return "0";
    int n,m;
    n = strlen(num1);
    m = strlen(num2);
    char* ans = (char*)calloc(n+m+1,sizeof(char));       //maximum possible length of the result.
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            int k = i+j+1;
            int mul = (num1[i]-'0') * (num2[j]-'0');
            while(mul){
                mul += ans[k];
                ans[k] = (mul)%10;
                mul = mul/10;
                k--;                        //move to the next index to store the digit before the current one .
            }
        }
    }
    for(int i=0 ; i<m+n ; i++){
        ans[i] += '0';
    }
    if(ans[0]=='0') return ans+1;
    return ans;
}
