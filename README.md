# Simple Shell

Simple Shell is a basic shell program that provides functionalities similar to traditional Unix shells.

## Features

- **Hash Table**: Efficient retrieval, insertion, and deletion of key-value pairs.
- **Built-in Commands**: Includes several built-in commands like `cd`, `alias`, `unalias`, `exit`, and `help`.
- **Aliases**: Allows users to set aliases for commands.
- **Tokenization**: Parses user input into tokens, allowing for efficient command and argument processing.
- **Extensible**: Easily add new built-in commands by updating the `builtins` array.

## File Descriptions

- `main.c`: Contains the main shell loop and definitions of primary data structures.
- `hash_table.c`: Provides functions for creating, resizing, and freeing hash tables.
- `ht_operations.c`: Contains functions to insert, retrieve, and delete entries from hash tables.
- `parse_input.c`: Functions for tokenising input strings and converting token lists into arrays.
- `builtin_general.c`: Implements the built-in shell commands and an initialisation function for aliases.
- `builtin_alias.c`: Functions related to the `alias` built-in command.

## Basic Usage

1. Compile the shell program:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh