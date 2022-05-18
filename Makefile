NAME=push_swap
CHECKER=checker
CC=cc
CFLAGS=-Wall -Wextra -Werror -g

PUSH_SWAP_SOURCES_FILES=push_swap.c \
		parse.c \
		shrink.c \
		list_utils.c \
		operations.c \
		sort.c \
		sort_big.c \
		sort_small.c
PUSH_SWAP_SOURCES_DIR=src/push_swap
PUSH_SWAP_SOURCES=$(addprefix $(PUSH_SWAP_SOURCES_DIR)/,$(PUSH_SWAP_SOURCES_FILES))

PUSH_SWAP_OBJECTS_DIR=obj/push_swap
PUSH_SWAP_OBJECTS=$(addprefix $(PUSH_SWAP_OBJECTS_DIR)/,$(PUSH_SWAP_SOURCES_FILES:.c=.o))

CHECKER_SOURCES_FILES=checker.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			parse.c \
			check_dublicates.c \
			list_utils.c \
			operations.c \
			sort.c \
			sort_utils.c
CHECKER_SOURCES_DIR=src/checker
CHECKER_SOURCES=$(addprefix $(CHECKER_SOURCES_DIR)/,$(CHECKER_SOURCES_FILES))

CHECKER_OBJECTS_DIR=obj/checker
CHECKER_OBJECTS=$(addprefix $(CHECKER_OBJECTS_DIR)/,$(CHECKER_SOURCES_FILES:.c=.o))

PUSH_SWAP_HEADER=push_swap.h
HEADERS_DIR=include
PUSH_SWAP_HEADERS=$(addprefix $(HEADERS_DIR)/,$(PUSH_SWAP_HEADER))
PUSH_SWAP_HEADERS+=libft/libft.h

CHECKER_HEADER=checker.h
CHECKER_HEADERS=$(addprefix $(HEADERS_DIR)/,$(CHECKER_HEADER))

LIBFT_DIR=libft/
LIBFT_NAME=ft
LIBFT=libft/libft.a

MAKEFILE=Makefile

all: libft $(NAME)

$(NAME): $(PUSH_SWAP_OBJECTS) $(MAKEFILE)
	$(CC) $(PUSH_SWAP_OBJECTS) -L $(LIBFT_DIR) -l $(LIBFT_NAME) -o $(NAME)

bonus: libft $(CHECKER)

$(CHECKER): $(CHECKER_OBJECTS) $(MAKEFILE)
	$(CC) $(CHECKER_OBJECTS) -L $(LIBFT_DIR) -l $(LIBFT_NAME) -o $(CHECKER)

$(PUSH_SWAP_OBJECTS_DIR)/%.o: $(PUSH_SWAP_SOURCES_DIR)/%.c $(PUSH_SWAP_HEADERS) $(LIBFT) | $(PUSH_SWAP_OBJECTS_DIR)
	$(CC) $(CFLAGS) -I ./include -I $(LIBFT_DIR) -c $< -o $@

$(CHECKER_OBJECTS_DIR)/%.o: $(CHECKER_SOURCES_DIR)/%.c $(CHECKER_HEADERS) $(LIBFT) | $(CHECKER_OBJECTS_DIR)
	$(CC) $(CFLAGS) -I ./include -I $(LIBFT_DIR) -c $< -o $@

$(CHECKER_OBJECTS_DIR):
	mkdir -p $(CHECKER_OBJECTS_DIR)

$(PUSH_SWAP_OBJECTS_DIR):
	mkdir -p $(PUSH_SWAP_OBJECTS_DIR)

libft:
	make -C libft bonus

clean:
	make -C libft clean
	rm -rf $(PUSH_SWAP_OBJECTS_DIR)
	rm -rf $(CHECKER_OBJECTS_DIR)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)
	rm -rf $(CHECKER)

re: fclean all

.PHONY : all clean fclean re bonus libft
