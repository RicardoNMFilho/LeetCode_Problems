// Given a string s, find the length of the longest 
// without duplicate characters.

int lengthOfLongestSubstring(char* s) {
    int table_ascii[256];
    int longest_substring = 0;
    int longest_actual = 0;
    int start = 0;

    memset(table_ascii, -1, sizeof(table_ascii));

    for (int end = 0; s[end] != '\0'; end++) {
        if (table_ascii[s[end]] >= start) {
            start = table_ascii[s[end]] + 1;
        }

        table_ascii[s[end]] = end;

        longest_actual = end - start + 1;
        if (longest_actual > longest_substring) {
            longest_substring = longest_actual;
        }
    }

    return longest_substring;
}