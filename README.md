# Libft

An all-in-one library for data structures and utility functions needed for the 42 curriculum.

The core library features:

- LIBFT/string.h: Functions to compare, copy and iterate on C strings (NULL-terminated or not)
- LIBFT/ctype.h: Functions to get the type of integer
- LIBFT/general.h: Convertion between different data and allocation functions
- LIBFT/io.h: Simple IO functions to write to given file descriptors
- LIBFT/vector.h: dynamic array
- LIBFT/vector/stringvector.h: A dynamic array of string. Easy manipulation of char **
- LIBFT/slice.h: A slice of an iterable. String slice is current defined.

Additional data structure includes:

- LIBFT/stringbuilder.h: Easy string manipulation that minimize use of malloc
- LIBFT/stringbuilder/clipper.h: A clipper to turn a stringbuilder to a NULL-terminated string
- LIBFT/stringbuilder/sb_iterator.h: A stringbuilder iterator, with interface to mutate the underlying string during iteration
- LIBFT/hashtable.h: hashtable
- LIBFT/list.h: linked list
- LIBFT/smartpointer.h: Rust-like pointers implemented in C (for educational purposes)

Additional utility functions:

- LIBFT/iostream.h: A more flexible way to receive input from a file descriptor
- LIBFT/gnl.h: features the get_next_line function which extract one line as NULL-terminated string from a file descriptor
- LIBFT/printf.h: features the ft_printf function which does the same thing as the normal "printf" but without buffering 

## Compilation

The core library is compiled in any case. In case user intends to include additional modules, one have to specify which additional modules you need through the make command option.

For example, this will compile the core, vector and get_next_line:

```sh
make USE="vector gnl"
```

Avaliable options:

- stringbuilder
- hashtable
- list
- smartpointer
- iostream
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
