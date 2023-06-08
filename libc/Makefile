##
## EPITECH PROJECT, 2023
## make for lib
## File description:
## make
##

NAME = libmy.a

SRC = my_getnbr.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strdup.c \
	my_str_to_word_array.c \
	my_strlen.c \
	my_put_nbr.c \
	my_putstr.c \
	my_putchar.c \
	my_frees.c \
	my_strcat.c \
	my_strstr.c \
	creatpath.c \
	my_append_array.c \
	my_strchr.c \
	my_calloc.c \
	my_is_digit.c \
	list.c \
	linked_list.c \
	list_nothing.c \
	my_itoa.c \
	str_nrm.c \
	get_av.c \
	swap_endian.c \
	multi_av.c \

SRC_PRINTF = 	printf/flags_extra.c \
				printf/my_flags.c \
				printf/my_length_modifier.c \
				printf/my_printf.c \
				printf/my_printmodulo.c \
				printf/my_put_nbr.c \
				printf/my_putchar.c \
				printf/my_putnbr_base.c \
				printf/my_putnbr_wtn.c \
				printf/my_putfloat.c \
				printf/my_putstr.c \
				printf/my_showstr.c \
				printf/my_strlen.c \
				printf/parser.c \
				printf/my_getnbr.c \
				printf/all_printf.c \

SRC_PARSING_JSON = 		parsing_json/get_json.c \
						parsing_json/json_array.c \
						parsing_json/json_obj.c \
						parsing_json/json_value.c \
						parsing_json/json_pair.c \
						parsing_json/json_bool_string_float.c \
						parsing_json/parser_json.c \

OBJ = $(SRC:.c=.o)

OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

OBJ_PARSING_JSON = $(SRC_PARSING_JSON:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -W  -I./parsing_json/ -I./printf/ -I./

LDFLAGS = -I./parsing_json/

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_PRINTF) $(OBJ_PARSING_JSON)
	ar rc $(NAME) $(OBJ) $(OBJ_PRINTF) $(OBJ_PARSING_JSON)
	cp $(NAME) ../

clean:
	find -type f -name "#*#" -delete -o \
	-type f -name "*~" -delete -o -type f -name "*.o" -delete -o \
	-type f -name "*.gc*" -delete

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
