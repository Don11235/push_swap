CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = src/operations/push_operations.c src/operations/rev_rotate_operations.c \
      src/operations/rotate_operations.c src/operations/swap_operations.c \
	  src/create_stack.c src/initialize_stack.c src/parse_input_values.c \
	  src/push_swap.c src/sort_stack.c src/small_sort.c utils/ft_atol.c \
	  utils/count_numbers.c utils/find_index.c utils/free_split.c utils/free_stack.c \
	  utils/ft_split.c utils/is_valid_number.c utils/max_bits.c utils/quick_sort.c \
	  utils/free_allocated_memory.c utils/is_valid_int.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re