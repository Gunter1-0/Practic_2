Practic_2: Practic_2.o Trains.o  RManager.o ChekData.o libCheckSize.a libCheckCountElements.so
			gcc -oPractic_2 Practic_2.o Trains.o RManager.o ChekData.o -L. -lCheckSize -lCheckCountElements -Wl,-rpath,.
ChekData.o: ChekData.c
			gcc -c ChekData.c
RManager.o: RManager.c
			gcc -c RManager.c
Trains.o: Trains.c
			gcc -c Trains.c
Practic_2.o: Practic_2.c Trains.h RManager.h ChekData.h 
			gcc -c Practic_2.c	

CheckSize.o: CheckSize.c 
			gcc -c CheckSize.c
libCheckSize.a: CheckSize.o 
			ar cr libCheckSize.a CheckSize.o
libCheckCountElements.so: CheckCountElements.o
			gcc -fPIC -shared -olibCheckCountElements.so CheckCountElements.o

UnitTests.o: UnitTests.c Trains.h RManager.h ChekData.h
			gcc -c UnityTests.c
UnitTests: UnitTests.o Practic_2
			gcc -oUnitTests UnitTests.o Practic_2.o Unity/src/unity.c
runtests:	UnitTests
			./UnitTests
clean:		
			rm --force Practic_2 Trains RManager ChekData *.so *.a *.o
