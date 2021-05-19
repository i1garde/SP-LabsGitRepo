# Makefile for lab1 project by Komarenko Ivan and Kashevar Constantin
all: lab2-static
	

lab2-static: main.o libHotel.a #Лінкер перетворює об'єктні файли у виконуваний файл
	g++ main.o libHotel.a -o lab2-static

main.o: main.cpp #Створює .o файл з вихідного коду програми
	g++ -c -Wall main.cpp
	
libHotel.a: Hotel.o
	ar cr libHotel.a Hotel.o
	
Hotel.o: Hotel.cpp
	g++ -c -Wall Hotel.cpp

do: #Надаємо необхідні права програмі та запускаємо її
	chmod a+x lab2-static
	./lab2-static

clean: #Видаляємо непотрібні файли
	rm -rf *.o *.a lab2-static
