#include <iostream>
#include <string>

using namespace std;

class Hotel {
private:
	int hotelNumber;
	string hotelName;
	string country;
	string city;
	string address;
	short amountOfStars;
	string contactPerson;
	bool isPremium;
public:
	Hotel(int hNum, string hName, string hCountry, string hCity, string hAddress, short hStars, string hContact);

	void setHotelNumber(int number);
	int getHotelNumber();

	void setHotelName(string name);
	string getHotelName();

	void setCountry(string country);
	string getCountry();

	void setCity(string city);
	string getCity();

	void setAddress(string address);
	string getAddress();

	void setAmountOfStars(short stars);
	short getAmountOfStars();

	void setContactPerson(string contact);
	string getContactPerson();

	void setIsPremium(bool prem);
	bool getIsPremium();

	void hotelInfo();
};
