# Model_HTTP_Server
A model http server capable of handling GET and POST requests from different clients simultaneously

Q.1. What are the pre-requisites for running the model http server ?
Ans.1. The pre-requisites are :-
    1. A Linux system
    2. Another machine with any modern web-browser

Q.2. How to run the program ?
Ans.2. Follow these steps :-
    1. Organize the files into directories (Explained in Q.3.)
    2. Run the server on a machine using commands (Explained in Q.4.)
    3. Open a webpage on any browser and connect to server (Explained in Q.5.)

Q.3. How to organize the files into directories ?
Ans.3. Follow these steps :-
1. Create the following directory structure in the Linux machine :-
Model_HTTP_Server
      bin
      include
      make
      obj
      src
The following commands can be used for creating the above directory structure :-
mkdir Model_HTTP_Server
cd Model_HTTP_Server
mkdir bin
mkdir include
mkdir make
mkdir obj
mkdir src

2. Now put the files into the corresponding directories :-
(a) bin directory should contain :- 
      error.html
      home.html
      index.html
      link1.html
      link2.html
      link3.html
      link4.html
      link5.html
      authenticate_user.txt
(b) include directory should contain :-
      http_header.h
      http_port_header.h
(c) make directory should contain :-
      makefile
(d) obj directory should be empty
(e) src directory should contain :-
      http_check_authentication.c
      http_connection.c
      http_error_trace.c
      http_generate_response_header.c
      http_get_method.c
      http_main.c
      http_post_method.c
      http_read_data.c
      http_signal_handler.c
      http_write_file.c

Q.4. How to run the server ?
Ans.4. Follow these steps :-
1. Goto bin
2. Type "make" without the quotes and hit enter
3. Check if a file named http_server is created or not
4. If http_server is created run the file using the following command :-
./http_server 2020
5. If everything goes fine, the following lines would be seen :-
		"I am waiting"
		"My port number is : 2020"
6. If the above 2 lines are visible, it indicates that the our http_server is up and running.
 
Q.5. How to connect to the server from a webpage ?
Ans.5. Follow these steps :-
1. Note the ip address of the machine where http_server is running.
2. Open any browser from another machine 
(another machine = any machine where the http_server is not running)
(any browser = latest version of Internet Explorer or Google Chrome or Mozilla Firefox)
3. Type the following url in the address bar and hit enter :-
http://"ip address of server machine":"port number on which the server is running"/
e.g. http://192.168.11.14:2020/
4. If everything goes fine, the welcome page is fetched from the server
