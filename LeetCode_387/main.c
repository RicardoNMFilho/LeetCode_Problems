// Given a string s, find the first non-repeating character in it 
// and return its index. If it does not exist, return -1

int firstUniqChar(char* s) {
    int ascii_table[256] = {0};
    char *ptr = s;
    int idx = 0;

    while (*ptr) {
        ascii_table[*ptr] = ascii_table[*ptr] + 1;
        ptr = ptr + 1;
    }

    while (*s) {
        if (ascii_table[*s] == 1){
            return idx;
        }

        idx = idx + 1;
        s = s + 1;
    }

    return -1;
}