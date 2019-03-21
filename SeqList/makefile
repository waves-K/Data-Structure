.PHONY : clean

main : Test.o SeqList.o
	gcc $^ -o $@ -std=c99 -g

%.o : %.c
		gcc -c $^ -o $@ -std=c99 -g

clean :
		rm -rf *.o main
