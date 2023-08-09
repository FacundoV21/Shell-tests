int _unsetenv(const char *name)
{
    char **ep, **dp;
    int len = strlen(name);

    for (ep = environ; *ep; ++ep)
    {
        if (!strncmp(*ep, name, len) && (*ep)[len] == '=')
        {
            for (dp = ep; *dp; ++dp)
                dp[0] = dp[1];
            return 0;
        }
    }
    return -1;
}