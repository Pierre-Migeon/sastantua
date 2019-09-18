COMPILER = gcc
FLAGS = -Wall -Werror -Wextra
SOURCES = *.c
NAME = sastantua

all: $(NAME)

$(NAME): 
	$(COMPILER) $(FLAGS) $(SOURCES) -o $(NAME)

clean:
	/bin/rm $(NAME)

re: clean all
