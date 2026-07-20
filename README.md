*This project has been created as part of the 42 curriculum by vrouxel.*

# Libft

## Description
Libft is a custom static C library, `libft.a`, implemented as the first foundational project in the 42 curriculum. It re-creates a subset of the standard C library and adds extra utilities for memory handling, strings, character classification, output helpers, and singly linked list management. The goal is to provide a reusable base of well-tested functions for later 42 projects while reinforcing low-level programming, manual memory management, and API design.

This implementation follows the subject requirements: all files are located at the repository root, compiled with `-Wall -Wextra -Werror`, archived using `ar`, and written according to the 42 Norm. Global variables are not used, helper functions are declared `static` where appropriate, and heap allocations are freed properly.

### Features

### Libc reimplementations (Part 1)
Reimplemented core C library functions with `ft_` prefix:

- Character classification: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- Case conversion: `ft_toupper`, `ft_tolower`
- String handling: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- Memory handling: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- Conversion: `ft_atoi`

The implementations are written to match the behavior described in the manual pages, including edge cases such as overlapping memory regions in `ft_memmove`, zero-length operations, etc...

### Additional utilities (Part 2)
Higher-level helper functions built on top of the basic primitives:

- Substring and concatenation: `ft_substr`, `ft_strjoin`
- Trimming: `ft_strtrim` (trim characters in a given set from both ends)
- Splitting: `ft_split` (split a string on a delimiter into a NULL-terminated array)
- Integer to string: `ft_itoa`
- String mapping and iteration: `ft_strmapi`, `ft_striteri`
- File descriptor output: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

These functions are designed to be safe with respect to allocation failures and to avoid leaks even in error paths.

### Linked list (Part 3)
A minimal singly linked list abstraction based on the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;
```

Implemented linked list helpers:

- `ft_lstnew`      – allocate a new node
- `ft_lstadd_front` – insert at the beginning of the list
- `ft_lstsize`     – count nodes
- `ft_lstlast`     – get last node
- `ft_lstadd_back` – append at the end of the list
- `ft_lstdelone`   – delete a single node using a user-provided `del` function
- `ft_lstclear`    – delete an entire list and set the pointer to `NULL`
- `ft_lstiter`     – apply a function to each node’s content
- `ft_lstmap`      – create a new list by mapping a function over another list’s content, handling allocation failures via `del`

This set is used to practice generic data structures with `void *content` and robust cleanup logic.

## Repository structure

```text
.
└──ft_atoi.c
└──ft_bzero.c
└──ft_calloc.c
└──ft_isalnum.c
└──ft_isalpha.c
└──ft_isascii.c
└──ft_isdigit.c
└──ft_isprint.c
└──ft_itoa.c
└──ft_lstadd_back.c
└──ft_lstadd_front.c
└──ft_lstclear.c
└──ft_lstdelone.c
└──ft_lstiter.c
└──ft_lstlast.c
└──ft_lstmap.c
└──ft_lstnew.c
└──ft_lstsize.c
└──ft_memchr.c
└──ft_memcmp.c
└──ft_memcpy.c
└──ft_memmove.c
└──ft_memset.c
└──ft_putchar_fd.c
└──ft_putendl_fd.c
└──ft_putnbr_fd.c
└──ft_putstr_fd.c
└──ft_split.c
└──ft_strchr.c
└──ft_strdup.c
└──ft_striteri.c
└──ft_strjoin.c
└──ft_strlcat.c
└──ft_strlcpy.c
└──ft_strlen.c
└──ft_strmapi.c
└──ft_strncmp.c
└──ft_strnstr.c
└──ft_strrchr.c
└──ft_strtrim.c
└──ft_substr.c
└──ft_tolower.c
└──ft_toupper.c
└──libft.h
└──Makefile
└──README.md
```

## Instructions

### Build the library
Use the Makefile at the repository root:

```bash
make
```

This command should compile all `.c` files and produce `libft.a` without unnecessary relinking. `.o` files remain in the `build` directory to keep things tidy(nobody likes never ending file list)

### Clean and rebuild

```bash
make clean   # remove object files
make fclean  # remove objects and libft.a
make re      # full rebuild
```

### Use libft in other projects
To use libft in another project:

1. Copy `libft.a` and `libft.h` or add this repository as a submodule.
2. Include the header in your source files:

   ```c
   #include "libft.h"
   ```

3. Link the library when compiling:

   ```bash
   cc -Wall -Wextra -Werror main.c libft.a -o main
   ```

Example:

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
	char const *s = "libft";
	printf("len = %d\n", ft_strlen(s));
	return (0);
}
```

On some glibc-based systems, functions like `strlcpy`, `strlcat`, and `bzero` are not part of the default C library, so system-level comparison may require including `bsd/string.h` and linking with `-lbsd`.

## Testing
A set of small test programs and custom cases were used to validate the library:

- Comparison of `ft_*` functions with system functions for valid inputs.
- Edge-case tests (empty strings, large sizes, overlapping memory, integer limits, `NULL` pointers where allowed).
- Valgrind runs to verify absence of memory leaks and invalid reads/writes.
- Specific tests for linked list functions to ensure correct insertion, deletion, and cleanup behavior.
- Open source available testers ( kudos to: Kjur0, tripouille, WarMachine, Sfabi28).

## Resources and AI usage

### AI usage
Any AI used during the project was double checked by human.
No core logic was written with AI, only human.
The libft.h file was autocompleted using AI.
This README file was generated using Perplexity LLM then adjusted manually.

### References
- man
- man
- C language references such as the C99 standard documentation and online C library references.
- and man again
- 42 intra documentation for project rules, the Norm, and AI guidelines.
- Lot of man google
- Lot of rubber duck talking
- Lot of fellow students <3
- Lot of coffee

*La route est longue, mais la voie est libre*