CC = gcc
NAME = malloc
SRC = $(shell find ./ -name "*.c")
OBJ = $(SRC:.c=.o)
ECHO = /bin/echo -e

INCLUDE = 	-I./include/					\
			-I./include/malloc_function/	\
			-I./include/lib/ 
LFLAGS = -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -ldl -lpthread -lopencv_imgproc -lopencv_objdetect -lopencv_video -lopencv_core -lavcall -lusb -std=c11
DEBUG = -g -g3
CFLAGS = -W -Wall -Werror

DEFLT	=	"\033[00m"
PINK	=	"\033[0;36m"
GREEN	=	"\033[1;32m"
TEAL	=	"\033[1;36m"
RED		=	"\033[0;31m"
BLINK 	= 	"\033[1;92m"
SBLINK	= 	"\033[0m"

all:	full libmalloc.so

full:	$(NAME) 
		@ $(ECHO) $(GREEN) "[BUILD]" $(DEFLT) $(PINK) $(NAME) $(DEFLT)

%.o : %.c
		@ $(CC) -o $@ -c $< $(INCLUDE) $(DEBUG) $(CFLAGS) && \
		$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $< $(DEFLT) || \
		$(ECHO) $(RED) "[KO]" $(PINK) $< $(DEFLT)

libmalloc.so: $(SRC)
		@ $(CC) $(INCLUDE) $(SRC) -o libmalloc.so -fPIC -shared 

$(NAME):$(OBJ)
		@ $(CC) -o $@ $^ && \
		$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $< $(DEFLT) || \
		$(ECHO) $(RED) "[KO - OBJECT]" $(TEAL) $< $(DEFLT)

clean:
		@ find -name "*.o" -delete && find -name "*~" -delete && \
		$(ECHO) $(BLINK) "[CLEAN SUCCESS]" $(DEFLT) || \
		$(ECHO) $(RED) "[CLEAN ERROR]" $(DEFLT)

fclean:
		@ find -name "*.o" -delete 
		@ find -name "*~" -delete 
		@ rm $(NAME)
		@ rm libmalloc.so && \
		$(ECHO) $(BLINK) "[FCLEAN SUCCESS]" $(DEFLT) || \
		$(ECHO) $(RED) "[FCLEAN ERROR]" $(DEFLT)


re: 	fclean all

run: 	$(NAME)
		@ $(ECHO) $(GREEN) "[RUNNING]" $(DEFLT) $(PINK) $(NAME) $(DEFLT)
		@ ./$(NAME)

.PHONY: $(CUSTLIBS)
