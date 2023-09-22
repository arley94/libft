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

BONUS = ft_lstnew_bonus \
							ft_lstadd_front_bonus \
							ft_lstsize_bonus \
							ft_lstlast_bonus \
							ft_lstadd_back_bonus \
							ft_lstdelone_bonus \
							ft_lstclear_bonus \
							ft_lstiter_bonus \
							ft_lstmap_bonus \

OBJ = $(FILES:%=%.o)

BOBJ = $(BONUS:%=%.o)

NAME = libft.a

$(NAME): $(OBJ)
	ar -rc $@ $^

all: $(NAME)

bonus: $(BOBJ)
	ar -rc $(NAME) $^

test: $(OBJ) $(BOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean: 
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: 

.PHONY: all, clean, fclean, re
