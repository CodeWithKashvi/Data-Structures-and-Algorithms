//Aim: To write a C program to read an integer value (age) from the user 
//and print it using standard input and output functions

#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Your age is: %d\n", age);

    return 0;
}
