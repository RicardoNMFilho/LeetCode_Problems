// Given a string s consisting of lowercase English letters, 
// return the first letter to appear twice.

char repeatedCharacter(char* s) {
   int ascii_table[256] = {0};
   char *ptr = s;

   while (*ptr) {
    ascii_table[*ptr] = ascii_table[*ptr] + 1;
    if (ascii_table[*ptr] == 2){
        return *ptr;
    }
    ptr = ptr + 1;
   }

   return *ptr;

}