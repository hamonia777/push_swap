NAME		= push_swap
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a
LIBFT	=$(LIBFTDIR)/$(LIBFTFILE)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS	= push_swap.c \
			linked_list.c \
			push_swap_util.c \
			move.c \
			sort.c \
			mapping.c \
			hard_coding.c \
			hard_coding_util.c \

OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

all : $(NAME)

clean :
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re