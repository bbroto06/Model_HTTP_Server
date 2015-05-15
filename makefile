# MAKEFILE 
# make clean 1>err
# make 1>err

CC = gcc
CFLAGS = -g -c -Wall -DTRACING -DERROR_HANDLING
BIN = ../bin/
INC = ../include/
OBJ = ../obj/
SRC = ../src/
OBJS = $(OBJ)http_main.o $(OBJ)http_connection.o $(OBJ)http_signal_handler.o $(OBJ)http_read_data.o $(OBJ)http_get_method.o $(OBJ)http_post_method.o $(OBJ)http_check_authentication.o $(OBJ)http_generate_response_header.o $(OBJ)http_write_file.o $(OBJ)http_error_trace.o

http_server : $(OBJS)
	$(CC) -o http_server $(OBJS)
	mv http_server $(BIN)

$(OBJ)http_main.o : $(SRC)http_main.c $(INC)http_header.h
	$(CC) $(CFLAGS) $(SRC)http_main.c -I$(INC)
	mv http_main.o $(OBJ)

$(OBJ)http_connection.o : $(SRC)http_connection.c $(INC)http_header.h
	$(CC) $(CFLAGS) $(SRC)http_connection.c -I$(INC)
	mv http_connection.o $(OBJ)

$(OBJ)http_signal_handler.o : $(SRC)http_signal_handler.c $(INC)http_header.h
	$(CC) $(CFLAGS) $(SRC)http_signal_handler.c -I$(INC)
	mv http_signal_handler.o $(OBJ)

$(OBJ)http_read_data.o : $(SRC)http_read_data.c $(INC)http_header.h
	$(CC) $(CFLAGS) $(SRC)http_read_data.c -I$(INC)
	mv http_read_data.o $(OBJ)

$(OBJ)http_get_method.o : $(SRC)http_get_method.c $(INC)http_header.h
	$(CC) $(CFLAGS) $(SRC)http_get_method.c -I$(INC)
	mv http_get_method.o $(OBJ)

$(OBJ)http_post_method.o : $(SRC)http_post_method.c $(INC)http_header.h
	$(CC) $(CFLAGS) $(SRC)http_post_method.c -I$(INC)
	mv http_post_method.o $(OBJ)

$(OBJ)http_check_authentication.o : $(SRC)http_check_authentication.c $(INC)http_header.h
	$(CC) $(CFLAGS) $(SRC)http_check_authentication.c -I$(INC)
	mv http_check_authentication.o $(OBJ)

$(OBJ)http_generate_response_header.o : $(SRC)http_generate_response_header.c $(INC)http_header.h
	$(CC) $(CFLAGS) $(SRC)http_generate_response_header.c -I$(INC)
	mv http_generate_response_header.o $(OBJ)

$(OBJ)http_write_file.o : $(SRC)http_write_file.c $(INC)http_header.h
	$(CC) $(CFLAGS) $(SRC)http_write_file.c -I$(INC)
	mv http_write_file.o $(OBJ)

$(OBJ)http_error_trace.o : $(SRC)http_error_trace.c $(INC)http_header.h
	$(CC) $(CFLAGS) $(SRC)http_error_trace.c -I$(INC)
	mv http_error_trace.o $(OBJ)

clean :
	rm $(BIN)http_server
	rm $(OBJ)*.o
	@echo MAKEFILE : removed all obj files and executables

val :
	valgrind --tool=memcheck --show-reachable=yes --leak-check=full $(BIN)http_server 12345 2
