Reader : Reader.cpp SharedObject.h Semaphore.h
	g++ -o Reader Reader.cpp -pthread 

Writer : Writer.cpp SharedObject.h Semaphore.h
	g++ -o Writer Writer.cpp -pthread 
