// Given two strings needle and haystack, return the index of the 
// first occurrence of needle in haystack, or -1 if needle is not 
// part of haystack.

int strStr(char* haystack, char* needle) {
    
    int len_needle = strlen(needle);
    int len_haystack = strlen(haystack);
    int control;
    int index;

    if (len_needle == len_haystack) {
        if (strcmp(haystack, needle) == 0) {
            return 0;
        }

        else {
            return -1;
        }
    }

    for (int i = 0; i <= len_haystack - len_needle; i++) {
        control = 0;
        index = i;

        for (int j = 0; j < len_needle; j++) {
            if (needle[j] != haystack[i + j]){
                control = 1;
                break;
            }
        }

        if (control == 0){
            return index;
        }
    }

    return -1;

}