BASE_DIR = .
SRC = 

CSRC = $(BASE_DIR)/list.c \
	   $(BASE_DIR)/list_iterator.c	  \


INC = -I $(BASE_DIR) 	  \
	  -I $(BASE_DIR)/../  \

CC = gcc
AR = ar
DEBUG = -g

ifdef SHARED
TAR = list.so
CSEL = -fpic -DLIB
LSEL = -shared -o $(TAR)
OBJDIR = build/sobj/
LINKER = $(CC)
else
TAR = list.a
CSEL = 
LSEL = 
OBJDIR = build/obj/
LINKER = $(AR) crv $(TAR)
endif

OBJ = $(SRC:%.cpp=$(OBJDIR)%.o) 
COBJ = $(CSRC:%.c=$(OBJDIR)%.co) 

$(TAR):$(OBJ) $(COBJ)
	$(LINKER) $(LSEL) $(COBJ) $(OBJ)

$(OBJ): $(OBJDIR)%.o:%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CSEL) $(INC) $(DEBUG) -c -o $@ $< 

$(COBJ): $(OBJDIR)%.co:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CSEL) $(INC) $(DEBUG) -c -o $@ $< 

clean:
	rm $(OBJ) $(COBJ) $(TAR) $(LIBTAR)
