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
	core/ft_memset.c \
	core/ft_bzero.c \
	core/ft_memcpy.c \
	core/ft_memmove.c \
	core/ft_memchr.c \
	core/ft_memcmp.c \
	core/ft_calloc.c \
	core/ft_strlen.c \
	core/ft_strdup.c \
	core/ft_strlcpy.c \
	core/ft_strlcat.c \
	core/ft_strchr.c \
	core/ft_strrchr.c \
	core/ft_strnstr.c \
	core/ft_strncmp.c \
	core/ft_strcmp.c \
	core/ft_atoi.c \
	core/ft_isalpha.c \
	core/ft_isdigit.c \
	core/ft_isalnum.c \
	core/ft_isascii.c \
	core/ft_isprint.c \
	core/ft_toupper.c \
	core/ft_tolower.c \
	core/ft_substr.c \
	core/ft_strjoin.c \
	core/ft_strtrim.c \
	core/ft_split.c \
	core/ft_itoa.c \
	core/ft_strmapi.c \
	core/ft_striteri.c \
	core/ft_putchar_fd.c \
	core/ft_putstr_fd.c \
	core/ft_putendl_fd.c \
	core/ft_putnbr_fd.c
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
VECTOR_SRC:= \
	vector/vector.c \
	vector/buffer.c \
	vector/setters.c \
	vector/iterator.c \
	vector/action.c
HASHTABLE_SRC:= \
	hashtable/hashtable.c \
	hashtable/mutation.c \
	hashtable/printer.c \
	hashtable/getters.c \
	hashtable/entry.c \
	hashtable/hash/hash.c \
	hashtable/hash/rehash.c
STRINGBUILDER_SRC:= \
	stringbuilder/stringbuilder.c \
	stringbuilder/iterator/iterator.c \
	stringbuilder/iterator/manipulation.c \
	stringbuilder/clipper/clipper.c \
	stringbuilder/clipper/area.c \
	stringbuilder/action/action.c \
	stringbuilder/action/delete.c \
	stringbuilder/action/insert.c \
	stringbuilder/action/field_validator.c

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