BASE_DIR = .
SRC = 

CSRC = $(BASE_DIR)/main.c \

INC = -I $(BASE_DIR) 	  			\
	  -I $(BASE_DIR)/../			\
	  -I $(BASE_DIR)/../logger/inf/ \
	  -I $(BASE_DIR)/../list/ \
	  -I $(BASE_DIR)/../hashmap/ \

LIB = ../logger/candyLogger.a \
	  ../list/list.a \
	  ../hashmap/hashmap.a \


CC = gcc
AR = ar
DEBUG = -g

TAR = test.out

CSEL = 
OBJDIR = 
LSEL = -o $(TAR)

OBJ = $(SRC:%.cpp=$(OBJDIR)%.o) 
COBJ = $(CSRC:%.c=$(OBJDIR)%.co) 
ELIB = $(LIB:%=-l:%)

$(TAR):$(OBJ) $(COBJ) $(LIB)
	$(CC) $(LSEL) $(COBJ) $(OBJ) $(ELIB)

$(OBJ): $(OBJDIR)%.o:%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CSEL) $(INC) $(DEBUG) -c -o $@ $< 

$(COBJ): $(OBJDIR)%.co:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CSEL) $(INC) $(DEBUG) -c -o $@ $< 

$(LIB): %.a:
	@cd $(dir $@) && make

clean:
	rm $(OBJ) $(COBJ) $(TAR)

cleanAll: $(CLIB)
	@for lib in $(LIB);	\
		do \
		cd $$(dirname $$lib) && make clean; \
		done

	rm $(OBJ) $(COBJ) $(TAR)
