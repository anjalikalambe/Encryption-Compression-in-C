# Data Manipulation Assignment - Fundamentals of C
Find a customer with a real-world data manipulation need that involves data compression and/or encryption. The aim is to develop a C program that solves the problem found.
Develop own library (header files), runtime modes of program(using command line parsing), makefiles, provide debugging mode using preprocessor directives and advanced structures like queues and linked lists.

Project Idea - A secure compact notes storage system 
Allows users to store compressed files containing passwords in one specific directory.

To save a password: 
- Program takes inputs of website name and password.
    - Creates a file website name
    - Program first encrypts the password by passing it to an encrypt function and then saves the returned value in the file. 
    - Program sends the file to a compression function which compresses it and then saves it.

To retrieve the password: 
- Program takes input of which file it wants to open
     - If file is found then the file is then sent to a decompression function which decompresses it. 
     - Decompressed file content is saved in a variable and passed to a decryption function which decrypts it and returns actual value of password.