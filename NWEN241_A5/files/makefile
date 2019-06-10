 
a5: a5.o 
	gcc -o a5 a5.o
	


a5.o: a5.c a5.h
	gcc -c a5.c

 
task4: task4.o 
	gcc -o task4 task4.o
	


task4.o: task4.c a5.h
	gcc -c task4.c




	
clean:
	rm -rf *.o a5 task4
