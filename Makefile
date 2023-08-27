NAME		= libsihlee.a

CC			= cc
CFLAG		= -Wall -Wextra -Werror

RM			= rm -f

AR			= ar
ARFLAGS		= rs

INCLUDES	= ./libsihlee.h

SRC			= ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\

SRCS        = $(SRC)
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) make_bonus

re: fclean all