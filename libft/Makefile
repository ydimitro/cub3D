# Compiling the program with flags
NAME = libft.a

.SUFFIXES: .o .c

# Macros
CC = gcc
CFLAGS = -Wall -Wextra -Werror
B_SRC = ft_ls*.c
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_power.c \
		ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		ft_split.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_nbrlen.c\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strcmp.c ft_strncmp.c ft_strncpy.c\
		ft_strndup.c ft_strstr.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_memdel.c ft_putendl.c ft_strisnum.c ft_skip_spacenl.c ft_skip_space.c \
		get_next_line.c get_next_line_helper.c
OBJ = $(SRC:.c=.o)
B_OBJ = ${B_SRC:.c=.o}
REMOVE = rm -f

# ar -rcs,  
# r Insert the files member into archive (with replacement). 
# c Write an object-file index into the archive, or update an existing one, even if no other change is made to the archive. You may use this modifier flag either with any operation, or alone. 
# Running "ar s" on an archive is equivalent to running ranlib on it.
# Rules
all:	$(NAME)

$(NAME):	$(OBJ)
	@ ar -rcs $(NAME) $(OBJ)

#ar rcs
# -C Change to directory dir before reading the makefiles or doing anything else
$(OBJ): $(SRC)
	@ $(CC) $(CFLAGS) -c $(SRC)


bonus:	${B_OBJ}
	@ ar -rcs $(NAME) $(B_OBJ)

$(B_OBJ): $(B_SRC)
	@ $(CC) $(CFLAGS) -c $(B_SRC)

clean:
	@ ${REMOVE} ${OBJ} ${B_OBJ}

fclean: clean
	@ ${REMOVE} $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re