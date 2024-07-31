
void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\b':
            s[j++] = '\\';
            s[j++] = 'b';
            break;
        case '\f':
            s[j++] = '\\';
            s[j++] = 'f';
            break;
        case '\r':
            s[j++] = '\\';
            s[j++] = 'r';
            break;
        case '\v':
            s[j++] = '\\';
            s[j++] = 'v';
            break;
        case '\\':
            s[j++] = '\\';
            s[j++] = '\\';
            break;
        default:
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[])
{

    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
    {

        if (t[i] == '\\' && t[i + 1] != '\0')
        {
            switch (t[i + 1])
            {
            case 'n':
                s[j++] = '\n';
                ++i;
                break;
            case 't':
                s[j++] = '\t';
                ++i;
                break;
            case 'b':
                s[j++] = '\b';
                ++i;
                break;
            case 'f':
                s[j++] = '\f';
                ++i;
                break;
            case 'r':
                s[j++] = '\r';
                ++i;
                break;
            case 'v':
                s[j++] = '\v';
                ++i;
                break;
            case '\\':
                s[j++] = '\\';
                ++i;
                break;
            default:
                s[j++] = t[i];
            }
        }
        else
        {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}