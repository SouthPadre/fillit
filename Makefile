NAME		= fillit
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= create_field.c \
				create_flist.c \
				free_lst.c \
				free_twin.c \
				list_size.c \
				main.c \
				print_puzzle.c \
				print_twin.c \
				solution.c \
				tetr.c \
				valid.c \
				valid_tetrimo.c 
OBJS 		= $(SRCS:%.c=%.o)
SRCDIR		= ./srcs
IFLAGS		= -I./includes -I./libft
LFLAGS 		= -L./libft/ -lft

all: $(NAME) 

$(NAME): make_lib $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME)

$(OBJS): 
	$(CC) $(CFLAGS) -c $(addprefix $(SRCDIR)/, $(SRCS)) $(IFLAGS)
make_lib:
	cd ./libft && make 
clean_lib:
	cd ./libft && make fclean
clean_lib_o:
	cd ./libft && make clean

clean: clean_lib_o
	rm -f *.o *.gch 
fclean: clean_lib clean 
	rm -f $(NAME)
re:	fclean all 
