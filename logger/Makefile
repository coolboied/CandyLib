BASE_DIR = .
SRC = 

CSRC = $(BASE_DIR)/loggerController.c \
	   $(BASE_DIR)/loggerHandle.c	  \
	   $(BASE_DIR)/loggerMode.c       \


INC = -I $(BASE_DIR) 	  \
	  -I $(BASE_DIR)/../		\
	  -I $(BASE_DIR)/inf/ \

CC = gcc
AR = ar
DEBUG = -g

ifdef SHAREDLIB
TAR = candyLogger.so
CSEL = -fpic -DLIB
LSEL = -shared -o $(TAR)
OBJDIR = build/sobj/
LINKER = $(CC)
else
TAR = candyLogger.a
CSEL = 
LSEL = 
OBJDIR = build/obj/
LINKER = $(AR) crv $(TAR)
endif

OBJ = $(SRC:%.cpp=$(OBJDIR)%.o) 
COBJ = $(CSRC:%.c=$(OBJDIR)%.co) 

all:$(OBJ) $(COBJ)
	$(LINKER) $(LSEL) $(COBJ) $(OBJ)

$(OBJ): $(OBJDIR)%.o:%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CSEL) $(INC) $(DEBUG) -c -o $@ $< 

$(COBJ): $(OBJDIR)%.co:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CSEL) $(INC) $(DEBUG) -c -o $@ $< 

clean:
	rm $(OBJ) $(COBJ) $(TAR) $(LIBTAR)
