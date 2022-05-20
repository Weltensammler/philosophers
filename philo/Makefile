SOURCE = philosophers.c philosophers_utils.c eating.c cycle.c printing.c\
checking.c philo_help.c

OBJECTS = $(SOURCE:.c=.o)

FLAGS = -Werror -Wall -Wextra -pthread

NAME = philo

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all