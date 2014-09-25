objects = main.o card.o deck.o director.o game.o message.o player.o

main : $(objects)
	g++ -g -o main $(objects)

$(objects) : define.h

.PHONY : clean
clean :
	-rm main $(objects)
