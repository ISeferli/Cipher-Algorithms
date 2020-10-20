all:
	@gcc -Wall simple_crypto.c -c 
	@gcc -Wall simple_crypto.o demo.c -o demo

clean:
	@rm -f simple_crypto.o demo.o demo