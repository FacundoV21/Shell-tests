#include <stdio.h>
#include <stdlib.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    const size_t alloc_size = 128;  // Arbitrary size for reallocation
    size_t index = 0;
    int ch;

    // Allocate buffer if not allocated
    if (*lineptr == NULL)
    {
        *lineptr = malloc(alloc_size);
        if (!*lineptr) return -1;
        *n = alloc_size;
    }
    while ((ch = fgetc(stream)) != EOF && ch != '\n')
    {
        (*lineptr)[index++] = ch;
        
        // Reallocate memory if buffer is full
        if (index >= *n)
        {
            *n += alloc_size;
            *lineptr = realloc(*lineptr, *n);
            if (!*lineptr) return -1;
        }
    }
    if (index == 0 && ch == EOF)
        return -1;  // EOF with no input 

    (*lineptr)[index] = '\0';
    return (index);
}
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("$ ");
    while ((read = my_getline(&line, &len, stdin)) != -1)
    {
        printf("%s\n", line);
        printf("$ ");
    }
    free(line);
    return (0);
}