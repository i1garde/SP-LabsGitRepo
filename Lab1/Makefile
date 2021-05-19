# Makefile for lab1 project by Komarenko Ivan and Kashevar Constantin
all: lab1
	

lab1: main.o Hotel.o #Лінкер перетворює об'єктні файли у виконуваний файл
	g++ main.o Hotel.o -o lab1

main.o: main.cpp #Створює .o файл з вихідного коду програми
	g++ -c -Wall main.cpp
	
Hotel.o: Hotel.cpp
	g++ -c -Wall Hotel.cpp

do: #Надаємо необхідні права програмі та запускаємо її
	chmod a+x lab1
	./lab1

clean: #Видаляємо непотрібні файли
	rm -rf *.o lab1
