// Given two strings needle and haystack, return the index of the 
// first occurrence of needle in haystack, or -1 if needle is not 
// part of haystack.

int strStr(char* haystack, char* needle) {
    int lenHaystack = strlen(haystack);
    int lenNeedle = strlen(needle);

    int lps[lenNeedle];
    int len = 0;

    int j = 0;

    lps[0] = 0;

    for (int i = 1; i < lenNeedle; i++){
        if (needle[i] == needle[len]){
            len++;
            lps[i] = len;
        }

        else {
            if (len != 0){
                len = lps[len - 1];
                i = i - 1;
            }
            
            else {
                lps[i] = 0;
            }
        }
    }

    for (int i = 0; i < lenHaystack; i++) {
        if (needle[j] == haystack[i]){
            j++;

            if (j == lenNeedle) {
                return (i - j) + 1;
            }
        }

        else {
            if (j != 0) {
                j = lps[j - 1];
                i = i - 1;
            }
        }
    }

    return -1;
}