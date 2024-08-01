#include <stdio.h>

void expand(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == '-')
        {
            if (i == 0 || s1[i + 1] == '\0')
            {
                s2[j++] = '-';
                continue;
            }
            int s = s1[i - 1];
            int e = s1[i + 1];
            for (int t = 0; t < e - s + 1; t++)
            {
                s2[j++] = (s + t);
            }
        }
    }
    s2[j++] = '\0';
}

void expand_gpt(char s1[], char s2[])
{
    int i = 0; // index for s1
    int j = 0; // index for s2

    // Skip leading '-' characters
    while (s1[i] == '-')
    {
        s2[j++] = '-';
        i++;
    }

    // Process characters in s1
    while (s1[i] != '\0')
    {
        // Check for range notation like a-z or 0-9
        if (s1[i] == '-' && s1[i - 1] != '\0' && s1[i + 1] != '\0')
        {
            char start = s1[i - 1];
            char end = s1[i + 1];

            // Check if valid range
            if ((start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z') ||
                (start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z') ||
                (start >= '0' && start <= '9' && end >= '0' && end <= '9'))
            {
                // Expand the range
                for (char c = start + 1; c < end; c++)
                {
                    s2[j++] = c;
                }
            }
            else
            {
                // Invalid range, just copy the '-'
                s2[j++] = '-';
            }

            // Move past the range in s1
            i += 2;
        }
        else
        {
            // Copy normal character
            s2[j++] = s1[i++];
        }
    }

    // Null-terminate s2
    s2[j] = '\0';
}

int main()
{
    char s[100];
    char t1[] = "a-z";
    expand(t1, s);
    printf("%s:%s\n", t1, s);
    char t2[] = "-a-z0-9A-Z-";
    expand(t2, s);
    printf("%s:%s\n", t2, s);

    char s1[] = "-a-zA-Z0-9";
    char s2[100]; // Make sure s2 is large enough to hold the expanded string

    expand_gpt(s1, s2);

    printf("Expanded string: %s\n", s2);
}