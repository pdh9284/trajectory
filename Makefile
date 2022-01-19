CC =gcc
CFLAGS = -W -Wall
AR =ar
INC = -I./lib/include

TARGET = test
LIB_MATRIX = ./lib/libmatrix.a
LIB_TRAJECTORY = ./lib/libtrajectory.a

LIB_SRC0= ./lib/SRC/D_to_R
LIB_SRC1= ./lib/SRC/motion
LIB_SRC2= ./lib/SRC/error_function
LIB_SRC3= ./lib/SRC/controller

all : $(TARGET)

$(TARGET): main.c $(LIB_MATRIX) $(LIB_TRAJECTORY)
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(LIB_TRAJECTORY): $(LIB_SRC0).o $(LIB_SRC1).o $(LIB_SRC2).o $(LIB_SRC3).o
	$(AR) rscv $@ $^

$(LIB_SRC0).o : $(LIB_SRC0).c
	$(CC) $(INC) $(CFLAGS) -c -o $@ $^

$(LIB_SRC1).o : $(LIB_SRC1).c
	$(CC) $(INC) $(CFLAGS) -c -o $@ $^

$(LIB_SRC2).o : $(LIB_SRC2).c
	$(CC) $(INC) $(CFLAGS) -c -o $@ $^ 

$(LIB_SRC3).o : $(LIB_SRC3).c
	$(CC) $(INC) $(CFLAGS) -c -o $@ $^

clean :
	rm -rf *.o $(Target)

