#include "shell.h"
/**
 * build_path - Builds a linked list of directories from PATH
 * Return: Pointer to the head of the linked list
 */
path_t *parse_path(void)
{
    char *path = getenv("PATH");
    char *token;
    path_t *head = NULL, *new_node, *temp;

    token = strtok(path, ":");
    while (token)
    {
        new_node = malloc(sizeof(path_t));
        if (!new_node)
            exit(EXIT_FAILURE);

        new_node->dir = strdup(token);
        new_node->next = NULL;
        if (!head)
            head = new_node;
        else
        {
            temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = new_node;
        }
        token = strtok(NULL, ":");
    }
    return (head);
}
/**
 * search_path - Searches for an executable in PATH directories
 * @cmd: The command to find
 * @path_list: The linked list of PATH directories
 * Return: Full path to executable or NULL if not found
 */
char *search_path(char *cmd, path_t *path_list)
{
    char *full_path;
    struct stat st;

    while (path_list)
    {
        full_path = malloc(strlen(path_list->dir) + strlen(cmd) + 2);
        if (!full_path)
            exit(EXIT_FAILURE);

        strcpy(full_path, path_list->dir);
        strcat(full_path, "/");
        strcat(full_path, cmd);

        if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
            return (full_path);

        free(full_path);
        path_list = path_list->next;
    }
    return (NULL);
}
/**
 * free_path_list - Frees a linked list of PATH directories
 * @head: The head of the linked list
 */
void free_path_list(path_t *head)
{
    path_t *temp;

    while (head)
    {
        temp = head->next;
        free(head->dir);
        free(head);
        head = temp;
    }
}