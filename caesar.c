#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //make sure we only get one command line argument:

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    // Make sure every character in argv[1] is a digit
    string key = argv[1];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Prompt user for plaintext
    string plaintext = get_string("Plaintext: ");

    // Convert key to integer
    int k = atoi(key);
    printf("ciphertext: ");

    //obtain cipher text
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {

            printf("%c", (((plaintext[i] - 65) + k) % 26) + 65);
        }

        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97) + k) % 26) + 97);
        }

        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

}
