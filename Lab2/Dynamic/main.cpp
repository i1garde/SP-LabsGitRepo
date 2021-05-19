#include "Hotel.h"
#include <stdint.h>

int main() {
        Hotel myHotelInStack = Hotel(1, "Grand Hotel", "England", "London", "Bedford St, Covent Garden", 5, "Ivan");
        myHotelInStack.hotelInfo();
        myHotelInStack.hotelToFile();

        Hotel* myHotelInHeap = new Hotel(2, "Olivia", "Greece", "Athens", "Zeus Triangle", 3, "Constantine");
        myHotelInHeap->hotelInfo();
        delete myHotelInHeap;
        return 0;
}

