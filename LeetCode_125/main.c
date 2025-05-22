// A phrase is a palindrome if, after converting all uppercase 
// letters into lowercase letters and removing all non-alphanumeric 
// characters, it reads the same forward and backward. Alphanumeric 
//characters include letters and numbers.

//Given a string s, return true if it is a palindrome, or false 
// otherwise.

bool isPalindrome(char* s) {
    int lenS = strlen(s);
    int i = 0;
    int j = lenS - 1;
    int control = 0;

    while (i < j){
        if (s[i] < 48 || (s[i] > 57 && s[i] < 65) || (s[i] > 90 && s[i] < 97) || s[i] > 122){
            control = 1;
            i++;
        }

        if (s[j] < 48 || (s[j] > 57 && s[j] < 65) || (s[j] > 90 && s[j] < 97) || s[j] > 122){
            control = 1;
            j--;
        }

        if (s[i] >= 65 && s[i] <= 90) {
            s[i] = s[i] + 32;
        }

        if (s[j] >= 65 && s[j] <= 90) {
            s[j] = s[j] + 32;
        }

        if (control == 0) {
            if (s[i] != s[j]) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }

        control = 0;

    }

    return true;
}