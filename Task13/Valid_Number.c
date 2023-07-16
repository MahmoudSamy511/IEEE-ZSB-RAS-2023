#include <stdbool.h>
bool isNumber(char * s){
    bool hasSign = false, hasExponential = false, hasDot = false, hasNumber = false; 
    while (*s != '\0'){
        if (*s == '+' || *s == '-'){
            if (hasSign || hasNumber || *(s+1) == '\0' || hasDot) return false;
            hasSign = true;
        }
        else if (*s == 'e' || *s == 'E'){
            if (hasExponential || *(s+1) == '\0' || !hasNumber) return false;
            hasExponential = true;
            hasSign = false;
            hasNumber = false;
            hasDot = false;
        }
        else if (*s == '.'){
            if (hasDot || hasExponential || (!hasNumber && *(s+1) == '\0')) return false;
            hasDot = true;
        }
        else if ('A' <= *s && *s <= 'Z' || 'a' <= *s && *s <= 'z'){
            return false;
        } 
        else{
            hasNumber = true;
        }
        s++; 
    }
    return true;
 }