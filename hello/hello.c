#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Asks for name and prints hello name
    string name = get_string("What is your name?: ");
    printf("hello, %s\n", name);
}