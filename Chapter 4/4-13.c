#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void reverse_helper(char s[], int left, int right);
void swap(char v[], int i, int j);

int main(void){
    char s[100] = "Hello world";
    printf("\nOriginal string: %s", s);
    reverse(s);
    printf("\nReversed string: %s", s);
    return 0;
}

void reverse(char s[]){
    reverse_helper(s, 0, strlen(s) - 1);
}

void reverse_helper(char s[], int left, int right){
    if(right <= left)
        return;
    swap(s, left, right);
    reverse_helper(s, left+1, right-1);
}

void swap(char v[], int i, int j){
    char temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}