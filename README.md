# Libft

An all-in-one library for data structures and utility functions needed for the 42 curriculum.

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

The core library is compiled in any case. In case user intends to include additional modules, one have to specify which additional modules you need through the make command option.

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

## Linking

All the public headers can be found inside the include folder directory.

For example, you install libft inside your lib directory directory or via git submodule, you should have a rule that include the header files of the library during object compilation, as well as a rule to compile the library before linking:

```Makefile

LIBFT:=lib/libft/libft.a

all: $(LIBFT)
# Linking happens here

%.o: %.c
	@$(CC) $(CFLAGS) -iquote lib/libft/include -c $< -o $@

$(LIBFT):
	@$(MAKE) USE="vector hashtable ft_printf gnl_bonus" -C lib/libft

```

In your source code, include the library like this:

```c
#include "LIBFT/list.h"
#include "LIBFT/gnl.h"
```
