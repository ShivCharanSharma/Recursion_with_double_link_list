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

	The tail recursive implementation means that the recursive call statement must be the last
	statement of the function. The gcd function made in 2b program is also tail recursive. The 
	reason is that the recursive statement **return gcd(b, a%b);** is the last statement executed 
	by the function and after that the function is called again for the different values of a and
	b as calculated in the function. Thus, the implementation of gcd is tail recursive.

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
      
### Commands

#### For 2a

      All the commands from q1a along with some other mentioned below:
      - count_up n: from 0 to 2n by 2
      - count_down n: from n to 0 by 1
      - nth order: print the nth node according to the order (INSERTED OR SORTED)
      - remove_nth order: remove the nth node according to the order(INSERTED OR SORTED)
      
### For 2b

     For 2b no specific command. Only the task is that the program will ask the user to enter 2 numbers
     and will find the gcd (greatest common divisor)
      
### For 3a

     All the commands from q1a are available but with some modifications in push and append:
     - p key value becomes p n/d
     - a key value becomes a n/d
     Rest commands from q1a are same.
     
     The other available commands are:
     - sum
     - fract 
     - whole_num
     - rem_mixed
     
     all along with the mode of output as SIMPLE or MIXED.
