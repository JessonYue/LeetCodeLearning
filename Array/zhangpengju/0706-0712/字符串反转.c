

void string_reverse(char *s)
{
    char *t;
    int c;

    for (t = s + (strlen(s) - 1); s < t; s++, t--)
    {
        c = *s;
        *s = *t;
        *t = c;
    }
}