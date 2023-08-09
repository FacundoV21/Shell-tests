int _setenv(const char *name, const char *value, int overwrite)
{
    char *new_env;
    int name_len = strlen(name);
    int value_len = strlen(value);

    if (!overwrite && _getenv(name))
        return 0;

    new_env = malloc(name_len + value_len + 2);
    if (!new_env)
        return -1;

    sprintf(new_env, "%s=%s", name, value);
    if (putenv(new_env) != 0)
        return -1;

    return 0;
}