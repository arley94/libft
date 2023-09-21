CC = cc
CFLAGS = -I. -Wextra -Werror -Wall
DEPS = libft.h
FILES = ft_isalpha \
						ft_isdigit \
						ft_isalnum \
						ft_isascii \
						ft_isprint \
						ft_strlen \
						ft_memset \
						ft_bzero \
						ft_memcpy \
						ft_memmove \
						ft_strlcpy \
						ft_strlcat \
						ft_toupper \
						ft_tolower \
						ft_strchr \
						ft_strrchr \
						ft_strncmp \
						ft_memchr \
						ft_memcmp \
						ft_strnstr \
						ft_atoi \
						ft_calloc \
						ft_strdup \
						ft_substr \
						ft_strjoin \
						ft_strtrim \
						ft_split \
						ft_itoa \
						ft_strmapi \
						ft_striteri \
						ft_putchar_fd \
						ft_putstr_fd \
						ft_putendl_fd \
						ft_putnbr_fd \

OBJ = $(FILES:%=%.o)

NAME = libft.a

$(NAME): $(OBJ)
	ar -rc $@ $^

all: $(NAME)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
