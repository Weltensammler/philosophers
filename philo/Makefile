SOURCE = philosophers.c philosophers_utils.c eating.c cycle.c printing.c\
checking.c philo_help.c

OBJECTS = $(SOURCE:.c=.o)

FLAGS = -Werror -Wall -Wextra -pthread -fsanitize=thread

NAME = philo

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all