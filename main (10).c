#include <stdio.h>
#include <string.h>

unsigned long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
int main() {
    char word[15];
    printf("Введіть слово: ");
    scanf("%14s", word);
    int len = strlen(word);
    int freq[256] = {0};
    for (int i = 0; i < len; i++) {
        freq[(int)word[i]]++;
    }
    unsigned long total_anagrams = factorial(len);
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 1) {
            total_anagrams /= factorial(freq[i]);
        }
    }
    printf("Кількість анаграм: %lu\n", total_anagrams);
    return 0;
}
