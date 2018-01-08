BASE_DIR = .
SRC = 

CSRC = $(BASE_DIR)/main.c \

INC = -I $(BASE_DIR) 	  			\
	  -I $(BASE_DIR)/../			\
	  -I $(BASE_DIR)/../logger/inf/ \

LIB = -l:../logger/candyLogger.a

CC = gcc
AR = ar
DEBUG = -g

TAR = test.out

CSEL = 
OBJDIR = 
LSEL = -o $(TAR)

OBJ = $(SRC:%.cpp=$(OBJDIR)%.o) 
COBJ = $(CSRC:%.c=$(OBJDIR)%.co) 

all:$(OBJ) $(COBJ) ../logger/candyLogger.a
	$(CC) $(LSEL) $(COBJ) $(OBJ) $(LIB)

$(OBJ): $(OBJDIR)%.o:%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CSEL) $(INC) $(DEBUG) -c -o $@ $< 

$(COBJ): $(OBJDIR)%.co:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CSEL) $(INC) $(DEBUG) -c -o $@ $< 

../logger/candyLogger.a:
	@cd ../logger/ && make all

clean:
	rm $(OBJ) $(COBJ) $(TAR)

cleanAll:
	rm $(OBJ) $(COBJ) $(TAR)
	@cd ../logger/ && make clean
