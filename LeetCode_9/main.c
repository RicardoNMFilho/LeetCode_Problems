// Given an integer x, return true if x is a , and false otherwise.

#define TAM (int) 11

bool isPalindrome(int x) {
    
    int num_reverso = 0;
    int vetor[TAM];
    int i = 0;

    if (x < 0) {
        return false;
    }

    while (x / 10 != 0) {
        vetor[i] = x % 10;
        x = x / 10;
        i++;
    }

    vetor[i] = x % 10;

    int right = i;

    for (int j = 0; j < (i / 2) + 1; j++){
        if (vetor[j] != vetor[right]){
            return false;
        }

        right--;
    }

    return true;
}