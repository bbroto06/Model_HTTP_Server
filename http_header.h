/*******************************************************
* FILE NAME : http_header.h
* 
* DESCRIPTION : contains 
* 		1. header file inclusions
* 		2. macro definitions
* 		3. global variables
* 		4. function declarations
* 		to be used in main.c and func.c
* 
* DATE		AUTHOR			REASON 
* 8/12/2013	Broto			Project
*******************************************************/

#ifndef HTTP_HEADER_H
#define HTTP_HEADER_H

/*****************************************************
		HEADER FILE INCLUSIONS
*****************************************************/
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<errno.h>
#include	<sys/wait.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<signal.h>
#include	<time.h>
#include	"http_port_header.h"

/*****************************************************
		MACRO DEFINITIONS
*****************************************************/
#define         PATH_INDEX_HTML                 "../bin/index.html"
#define         PATH_LNK1_HTML                  "../bin/link1.html"
#define         PATH_LNK2_HTML                  "../bin/link2.html"
#define         PATH_LNK3_HTML                  "../bin/link3.html"
#define         PATH_LNK4_HTML                  "../bin/link4.html"
#define         PATH_LNK5_HTML                  "../bin/link5.html"
#define         PATH_HOME_HTML                  "../bin/home.html"
#define         PATH_ERROR_HTML                 "../bin/error.html"

#define         CHK_INDEX_HTML                  "/index.html"
#define         CHK_LNK1_HTML                   "/link1.html"
#define         CHK_LNK2_HTML                   "/link2.html"
#define         CHK_LNK3_HTML                   "/link3.html"
#define         CHK_LNK4_HTML                   "/link4.html"
#define         CHK_LNK5_HTML                   "/link5.html"
#define         CHK_HOME_HTML                   "/home.html"
#define         CHK_ERROR_HTML                  "/error.html"

#define		ZERO					0
#define		MAX_4					4
#define		MAX_5					5
#define		MAX_8					8
#define		MAX_9					9
#define		MAX_10					10
#define		MAX_50					50
#define		MAX_100					100
#define		MAX_CHR					10240

#define		IX_LOGIN_PG				0
#define		IX_LNK_1				1
#define		IX_LNK_2				2
#define		IX_LNK_3				3
#define		IX_LNK_4				4
#define		IX_LNK_5				5
#define		IX_HOME_PG				6
#define		IX_ERROR_PG				7

/********************************
	Error Handling
*********************************/
/****** Error Macros ************/
#define 	CRITICAL_ERROR 				1
#define 	MAJOR_ERROR 				2
#define 	MINOR_ERROR 				3	
#define 	NO_ERROR 				4

/****** Error Code *************/
#define 	ERROR_STARTING_SERVER 			0
#define 	ERROR_IN_SELECT 			1
#define 	ERROR_IN_ACCEPT 			2
#define 	ERROR_ACCEPT_BIND 			3
#define 	ERROR_LISTENING 			4
#define 	FILE_OPEN_ERROR 			5
#define 	READ_DATA_ERROR 			6
#define 	SOCKET_ERROR 				7
#define 	SETSOCKOPT_ERROR 			8
#define 	ERROR_PROCESSING_GET 			9
#define 	ERROR_PROCESSING_POST 			10
#define 	ERROR_WRITING_PAGE 			11
#define 	ERROR_PROCESSING_CHECK_DB 		12
#define 	ERROR_IN_LENGTH 			13
#define 	INVALID_NUM_ARGS	 		14
#define 	ERROR_CREATING_RESPONSE_HEADER 		15
#define 	NO_PORT_NUM 				17
#define		PORT_OUT_OF_RANGE			18
	
/****** Error variable **********/
extern 		S32_INT 	g_error_value;
extern 		SCHAR 		*g_error_code[];

/****** Error Definition *********/
#ifdef ERROR_HANDLING
#define ERROR(level, code)  http_error_handler(level, code)
#endif

/*******************************
		Tracing 
********************************/
/****** Trace Macros ***********/
#define 	NO_TRACE 				0
#define 	BRIEF_TRACE 				1
#define 	DETAILED_TRACE 				2

/****** Trace variable *********/
extern 		S32_INT 	g_trace_value;

/****** Trace Definition *******/
#ifdef TRACING
#define TRACE(value, level) if (g_trace_value >= value) printf level
#else
#define TRACE(value, level)
#endif

/*****************************************************
		GLOBAL VARIABLES
*****************************************************/
S32_INT		g_listener; 		/* listening socket descriptor */
S32_INT		g_newfd; 		/* newly accepted socket descriptor */

/*****************************************************
	STRUCTURE AND ENUM DECLARATIONS
*****************************************************/
typedef enum
{
	SUCCESS = 0, 
	FAILURE = -1
}server_return_et ;

/*****************************************************
		FUNCTION DECLARATIONS
*****************************************************/
extern	void 			http_signal_handler(S32_INT signum);				/* Signal handler for SIGINT */
extern  void 			http_set_trace_level(S32_INT level);				/* set the trace level */
extern  void 			http_error_handler(S32_INT level, S32_INT code);		/* print the error */
extern	server_return_et	http_read_data(SCHAR *chr);					/* Receive data from client */
extern	server_return_et	http_check_authenticate_db(SCHAR *username, SCHAR *password);	/* Check in database */
extern	server_return_et	http_write_page(S32_INT index, SCHAR *chr);			/* Send requested page to client */
extern	server_return_et	http_get(SCHAR * req_buffer); 					/* Handle GET request */
extern	server_return_et	http_post(SCHAR * message_send); 				/* Handle POST req */
extern  server_return_et	http_init_server(S32_INT PORT, struct sockaddr_in *myaddr);	/* initialize the server */
extern 	server_return_et	http_generate_response_header(SCHAR *buffer);			/* generate response header */

#endif
