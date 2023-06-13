# Libft

An all-in-one library for data struture and utility functions needed for the 42 curriculum.

The core library features:

- Functions to compare, copy and iterate on C NULL-terminated strings
- Functions to create new strings by allocating on heap on every call
- Functions to compare and copy on arbitary memory location
- Simple IO functions to write to given file descriptors

Additional data structure includes:

- vector (dynamic array)
- stringbuilder
- hashtable
- list (linked list)

Additional utility functions:

- get_next_line
- ft_printf

## Compilation

The core library is compiled in any case. Users have to specify which additional modules you need to include them in the compilation.

For example, this will compile the core, vector and get_next_line:

```sh
make USE="vector gnl"
```

Avaliable options:

- vector
- stringbuilder
- hashtable
- list
- gnl
- gnl_bonus
- ft_printf

gnl_bonus is the version of the get_next_line function that allows it to get input from multiple file descriptors at the same time. It is also not recommended to use gnl and gnl_bonus at the same time because it will cause function name clashes.