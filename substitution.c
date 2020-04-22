#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// I used characters arrays instead of strings
// because I couldn't add characters into the string.

// useful to get the argv[1][x] position
string alphabet = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, string argv[])
{
    // error 0
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }

    // save time and memory if argc != 2
    else
    {
        int lenght_argv = strlen(argv[1]);

        // error 1
        if (lenght_argv != 26)
        {
            printf("Key must contain 26 characters.\n");

            return 1;
        }

        else
        {

            // error 2
            for (int i = 0; i < lenght_argv; i++)
            {
                if (! isalpha(argv[1][i]))
                {
                    printf("Key must contain alphabetic characters.\n");

                    i = lenght_argv;

                    return 1;
                }
            }

            char key_lower[lenght_argv];

            for (int i = 0; i < lenght_argv; i++)
            {
                key_lower[i] = tolower(argv[1][i]);
            }

            // error 3
            for (int i = 0; i < lenght_argv; i++)
            {
                for (int j = i + 1; j < lenght_argv; j++)
                {
                    if (key_lower[i] == key_lower[j])
                    {
                        printf("Key must not contain repeated characters.\n");

                        i = lenght_argv;
                        j = lenght_argv;

                        return 1;
                    }
                }
            }

            // user input
            string plaintext = get_string("plaintext:  ");

            int lenght_plaintext = strlen(plaintext);
            char plaintext_lower[lenght_plaintext];

            for (int i = 0; i < lenght_plaintext; i++)
            {
                plaintext_lower[i] = tolower(plaintext[i]);
            }

            char ciphertext[lenght_plaintext];

            for (int i = 0; i < lenght_plaintext; i++)
            {
                if (! isalpha(plaintext[i]))
                {
                    ciphertext[i] = plaintext[i];
                }

                for (int j = 0; j < strlen(alphabet); j++)
                {
                    if (plaintext_lower[i] == alphabet[j])
                    {
                        if (isupper(plaintext[i]))
                        {
                            ciphertext[i] = toupper(key_lower[j]);
                        }

                        else
                        {
                            ciphertext[i] = key_lower[j];
                        }
                    }
                }
            }
            
            // output
            printf("ciphertext: ");

            for (int i = 0; i < lenght_plaintext; i++)
            {
                printf("%c", ciphertext[i]);
            }

            printf("\n");
        }
    }
}