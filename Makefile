bbs : Step.o TempSensor.o
	g++ Step.o TempSensor.o -o bbs -lwiringPi
Step.o : Step.cpp
	g++ -c Step.cpp

TempSensor.o : TempSensor.cpp
	g++ -c TempSensor.cpp

