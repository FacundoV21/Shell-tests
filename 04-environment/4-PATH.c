typedef struct path_s
{
    char *str;
    struct path_s *next;
} path_t;

path_t *build_path_list(void)
{
    char *path = _getenv("PATH");
    char *token, *token_copy;
    path_t *head = NULL, *new, *temp;

    token = strtok(path, ":");
    while (token)
    {
        new = malloc(sizeof(path_t));
        if (!new)
            return NULL;
        token_copy = strdup(token);
        new->str = token_copy;
        new->next = NULL;

        if (!head)
            head = new;
        else
        {
            temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = new;
        }
        token = strtok(NULL, ":");
    }
    return head;
}