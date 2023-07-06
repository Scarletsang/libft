################################
######     Variables     #######
################################

NAME:=libft.a

CC:=cc
CFLAGS:= -Wall -Wextra -Werror
ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
	LDFLAGS+= -g3 -fsanitize=address
endif
INCLUDE_DIR= \
	include

###################################
######     Source files     #######
###################################

# To add souce files, create a varaible for each folder, and then
# contatenate them in the SRC variable like this:
CORE_SRC:= \
	core/general/ft_calloc.c \
	core/general/ft_atoi.c \
	core/general/ft_itoa.c \
	core/ctype/ft_isalpha.c \
	core/ctype/ft_isdigit.c \
	core/ctype/ft_isalnum.c \
	core/ctype/ft_isascii.c \
	core/ctype/ft_isspace.c \
	core/ctype/ft_isprint.c \
	core/ctype/ft_toupper.c \
	core/ctype/ft_tolower.c \
	core/string/ft_bzero.c \
	core/string/ft_memchr.c \
	core/string/ft_memcmp.c \
	core/string/ft_memcpy.c \
	core/string/ft_memmove.c \
	core/string/ft_memset.c \
	core/string/ft_split.c \
	core/string/ft_strchr.c \
	core/string/ft_strcmp.c \
	core/string/ft_strdup.c \
	core/string/ft_striteri.c \
	core/string/ft_strjoin.c \
	core/string/ft_strlcat.c \
	core/string/ft_strlcpy.c \
	core/string/ft_strlen.c \
	core/string/ft_strljoin.c \
	core/string/ft_strmapi.c \
	core/string/ft_strncmp.c \
	core/string/ft_strncpy.c \
	core/string/ft_strnstr.c \
	core/string/ft_strrchr.c \
	core/string/ft_strtrim.c \
	core/string/ft_substr.c \
	core/io/ft_putchar_fd.c \
	core/io/ft_putstr_fd.c \
	core/io/ft_putendl_fd.c \
	core/io/ft_putnbr_fd.c \
	core/vector/vector.c \
	core/vector/buffer.c \
	core/vector/setters.c \
	core/vector/action.c \
	core/vector/iterator/iterator.c \
	core/vector/iterator/action.c \
	core/vector/stringvector/stringvector.c \
	core/vector/stringvector/action.c \
	core/slice/str.c \
	core/slice/str_nt.c
LIST_SRC:= \
	list/ft_lstnew.c \
	list/ft_lstadd_front.c \
	list/ft_lstsize.c \
	list/ft_lstlast.c \
	list/ft_lstadd_back.c \
	list/ft_lstdelone.c \
	list/ft_lstclear.c \
	list/ft_lstiter.c \
	list/ft_lstmap.c
HASHTABLE_SRC:= \
	hashtable/hashtable.c \
	hashtable/hashtable_entry.c \
	hashtable/rehash.c \
	hashtable/action.c \
	hashtable/printer.c \
	hashtable/internal/hash.c \
	hashtable/internal/query.c
STRINGBUILDER_SRC:= \
	stringbuilder/stringbuilder.c \
	stringbuilder/iterator/iterator.c \
	stringbuilder/iterator/action.c \
	stringbuilder/iterator/manipulation.c \
	stringbuilder/clipper/clipper.c \
	stringbuilder/clipper/action.c \
	stringbuilder/clipper/area.c \
	stringbuilder/action/action.c \
	stringbuilder/action/perform.c \
	stringbuilder/action/field_validator.c
SMARTPOINTER_SRC:= \
	smartpointer/smartpointer.c \
	smartpointer/borrow.c
IOSTREAM_SRC:=\
	$(STRINGBUILDER_SRC) \
	iostream/iostream.c \
	iostream/action.c
GNL_SRC:= \
	gnl/get_next_line.c
GNL_BONUS_SRC:= \
	gnl/get_next_line_bonus.c
FT_PRINTF_SRC:= \
	ft_printf/printers/cs.c \
	ft_printf/printers/diu.c \
	ft_printf/printers/xXp.c \
	ft_printf/printers/prefix.c \
	ft_printf/printers/hex_printer.c \
	ft_printf/printers/sequencer.c \
	ft_printf/parsers/parsers.c \
	ft_printf/parsers/calc_numlen.c \
	ft_printf/parsers/calc_strlen.c \
	ft_printf/parsers/calc_states.c \
	ft_printf/parsers/peek.c \
	ft_printf/parsers/utils.c \
	ft_printf/sequence/substitution_printer.c \
	ft_printf/sequence/str_sequence.c \
	ft_printf/sequence/num_sequence.c \
	ft_printf/sequence/num_precision_sequence.c \
	ft_printf/logic.c \
	ft_printf/ft_printf.c

SRC:= $(CORE_SRC)
ifdef USE
    SRC += $(foreach dep,$(USE),\
		$($(shell echo $(dep) | tr '[:lower:]' '[:upper:]')_SRC))
endif

####################################
######     Library files     #######
####################################

# To compile a library, store a variable for their library file like this
# and add a rule for it after the main rules:

# To add a library, add the library header file like this:

# Then add the library to the linking process in one of the following ways:
# LDFLAGS+= -Llib/LIBRARY_NAME -lLIBRARY_NAME
# LDFLAGS+= lib/LIBRARY_NAME/libLIBRARY_NAME.a

###########################################
######     Object name reformat     #######
###########################################

# This in effect makes all the object files to be compiled in the OBJ_DIR directory

SRC_DIR:=src
OBJ_DIR:=obj
OBJ:= $(addprefix $(OBJ_DIR)/,$(subst /,@,$(SRC:.c=.o)))

#################################
######     Main rules     #######
#################################

all:
	@$(MAKE) $(NAME) -j

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ) && echo "Compilation of $(NAME) successful"

##########################################
######     Library compilation     #######
##########################################

# To compile a library, add a rule like this:

# $(LIBRARY_NAME):
# 	@${MAKE} $(if $(FSANITIZE),FSANITIZE=yes,) -C lib/LIBRARY_NAME

#########################################
######     Object compilation     #######
#########################################

.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/$$(subst @,/,$$*).c
	@$(CC) $(CFLAGS) $(addprefix -iquote ,$(INCLUDE_DIR)) $(addprefix -I ,$(LIB_INCLUDE_DIR)) -c $< -o $@

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

###############################
######     Cleaning     #######
###############################

clean: 
	@rm -f $(OBJ_DIR)/*.o

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re