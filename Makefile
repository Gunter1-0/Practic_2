Practic_2: Trains.o Practic_2.o RManager.o ChekData.o
			gcc -oPractic_2 Trains.o RManager.o ChekData.o Practic_2.o 
ChekData.o: ChekData.c
			gcc -c ChekData.c
RManager.o: RManager.c
			gcc -c RManager.c
Trains.o: Trains.c
			gcc -c Trains.c
Practic_2.o: Practic_2.c Trains.h RManager.h ChekData.h 
			gcc -c Practic_2.c	
