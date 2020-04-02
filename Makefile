.PHONY: solution run_solution2a 2a 2b q2 q3 run_solution2b run_solution3  build clean

build: solution

solution: q2 q3

q3: solution3/a4q3

q2: 2a 

2a: solution2/2a/a4q2

2b: solution2/2b/gcd


solution2/2a/a4q2: solution2/2a/a4q2.c solution2/2a/sorted_list.c solution2/2a/sorted_list.h
	gcc -Wall -DINT  $^ -o $@

solution2/2b/gcd: solution2/2b/a4q2b.c
	gcc -Wall -O3 $^ -o $@

solution3/a4q3: solution3/a4q3.c  solution3/sorted_list.c solution3/sorted_list.h solution3/a.c solution3/a.h solution3/functions.c solution3/functions.h
	gcc $^ -o $@ 

run_solution2a:
	@cd solution2/2a && chmod +x a4q2 && ./a4q2 cmd.txt

run_solution2b:
	@cd solution2/2b && chmod +x gcd && ./gcd cmd.txt

run_solution3:
	@cd solution3/   && chmod +x a4q3 && ./a4q3 cmd.txt

clean:
	rm solution2/2a/a4q2 solution2/2b/a4q2b
	rm solution3/a4q3
