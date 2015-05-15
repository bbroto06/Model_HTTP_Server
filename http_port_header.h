/*******************************************************
* FILE NAME : http_port_header.h
* 
* DESCRIPTION : contains 
* 		1. macro definitions
* 		to be used in all .c & .h for portability
* 
* DATE		AUTHOR			REASON 
* 8/12/2013	Broto			Project
*******************************************************/

#ifndef HTTP_PORT_HEADER_H
#define HTTP_PORT_HEADER_H

/*****************************************************
		MACRO DEFINITIONS
*****************************************************/
typedef 	unsigned char 	UCHAR ;
typedef 	char 		SCHAR;

#ifdef OS_LINUX64
typedef 	unsigned short	U32_INT;
typedef 	short		S32_INT;

#else
typedef 	unsigned int 	U32_INT;
typedef 	int 		S32_INT;
#endif

#endif

