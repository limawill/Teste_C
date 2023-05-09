#include <stdio.h>
#include <string.h>

int isPalindrome(char word[])
{
    int i, j;
    int len = strlen(word);

    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        if (word[i] != word[j])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    FILE *file = fopen("strings_01.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    char line[1000];

    while (fgets(line, sizeof(line), file))
    {
        int len = strlen(line);
        int i, j, k;
        int maxPalindrome = 0;

        for (i = 0; i < len; i++)
        {
            for (j = i; j < len; j++)
            {
                int isPal = 1;

                for (k = i; k <= (i + j) / 2; k++)
                {
                    if (line[k] != line[j - k + i])
                    {
                        isPal = 0;
                        break;
                    }
                }

                if (isPal && (j - i + 1) > maxPalindrome)
                {
                    maxPalindrome = j - i + 1;
                }
            }
        }

        printf("%d\n", maxPalindrome);
    }

    fclose(file);

    return 0;
}