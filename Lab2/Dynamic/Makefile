# Makefile for lab1 project by Komarenko Ivan and Kashevar Constantin
all: lab2-dynamic
	

lab2-dynamic: main.o libHotel.so #Лінкер перетворює об'єктні файли у виконуваний файл
	g++ -L./ -Wall -o lab2-dynamic main.o -lHotel -Wl,-rpath,.

main.o: main.cpp #Створює .o файл з вихідного коду програми
	g++ -c -Wall main.cpp

libHotel.so: Hotel.o
	g++ -shared Hotel.o -o libHotel.so
	
Hotel.o: Hotel.cpp
	g++ -c -fPIC Hotel.cpp

do: #Надаємо необхідні права програмі та запускаємо її
	chmod a+x lab2-dynamic
	./lab2-dynamic

clean: #Видаляємо непотрібні файли
	rm -rf *.o *.so lab2-dynamic
