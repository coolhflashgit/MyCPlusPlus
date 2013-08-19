main:Compute_express.o run.o 
	g++ -o main Compute_express.o run.o
Compute_express.o:Compute_express.cpp Compute_express.h  
	g++ -c Compute_express.h Compute_express.cpp
run.o: Compute_express.h run.cpp
	g++ -c Compute_express.h run.cpp

clean:                             
	rm main Compute_express.o run.o


