# README for question 2 and question 3

## Makefile

### Compile

To compile all programs, run following command in root directory of submission
where Makefile file is present

       make build

After running make build command, executable files and related to source (.c) file
can be located in their respective directories i.e. in directory 

For solution of 2nd question directory is:

      solution2/

It contain two folders:


	1. 2a
	1. 2b

Folder **2a** contain sorce code for question 2 Recusive functions and their test and commands.
Folder **2b** contain sorce code for question 2 Greatest Common Divisor (GCD).

For solution of 3rd question directory is :

	solution3/

It contain source code for question 3 ADT Fraction and its related functions and filter functions.

In solution3

	*a4q3.c* contain source code for commands and test for question 3 functions and ADT Fraction.

	*a.c* contain function definition of question 3 functions related to Fractions.And *a.h* is It's corresponding header file.

	*functions.c* contain filter function with its recusive definition. It also contain map/reduce/etc functions . And *function.h* is it's corresponding  header file.

	*sorted_list.c* contain function related to Sorted List data type and its definition. *sorted_list.h * is it's corresponding header files.


### Run

For Solution2a (Recursive functions of questions 2) run following command after *make build*

      make run_solution2a

For Solution2b (GCD function of questions 2) run following command after *make build*

      make run_solution2b

For Solution3 run following command after *make build*

	make run_solution3

### Clean

To clean up the directories, run command
    
      make clean

## Manual compilation and run

### Solution1a

First go to directory solution1/1a using command:

      cd solution1/1a/
     
It has two files namely: a4q1a_int.c and a4q1a_char.c

#### Compile

      gcc a4q1a_int.c -o a4q1aint

This will make an executable file named a4q1aint

      gcc a4q1a_char.c -o a4q1achar

This will make an executable file named a4q1achar

#### Run

      ./a4q1aint cmd1.txt
      ./a4q1aint
      
(This will ask the commands from user and user can end giving input using ctrl+D)

      ./a4q1achar cmd2.txt
      ./a4q1achar

(Similar as ./a4q1aint)
      
The commands available are:

       - a = append with syntax: 
            a key value for a4q1a_int.c
            a string for a4q1a_int  
       - p = push similar to a but the command will contain p instead of a
       - rem_first 
       - rem_last
       - rem_small
       - rem_large
       - empty
       - size 
       - print_all 
       - print_sort

### Solution for 1b

First go to directory solution1/1b using command:

      cd solution1/1b/
     
It has file namely: a4q1b.c
#### Compile

      gcc a4q1b.c sorted_list.c sorted_list.h -o a4q1b

This will make an executable file named a4q1b

#### Run

      ./a4q1b cmd.txt
      ./a4q1b
      
(This will ask the commands from user and user can end giving input using ctrl+D)
     
The commands available are:

       - a|n = append with syntax: 
            a|n key value 
       - p|n = push similar to a but the command will contain p instead of a
       - rem_first|n 
       - rem_last|n
       - rem_small|n
       - rem_large|n
       - empty|n
       - size |n
       - print_all|n 
       - print_sort|n
       - sum|n
       - square|n
       - diff|n:m order
       - sum_sq_d|n:m order

       order specifies: INSERTED_ORDER or SORTED_ORDER
       n is the index of array of sorted list pointers
