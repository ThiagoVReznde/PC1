OBJ = main.o leitura.o processamento.o sortdados.o saida.o

main: $(OBJ)
	gcc -Wall $(OBJ) -o main

main.o: main.c

leitura.o: processamento.o header.h

processamento.o: header.h

sortdados.o: header.h

saida.o: header.h

clean:
	rm main $(OBJ)