#include "Hotel.h"

Hotel::Hotel(int hNum, string hName, string hCountry, string hCity, string hAddress, short hStars, string hContact) {
        setHotelNumber(hNum);
        setHotelName(hName);
        setCountry(hCountry);
        setCity(hCity);
        setAddress(hAddress);
        setAmountOfStars(hStars);
        setContactPerson(hContact);

	if (this->amountOfStars > 5 || this->amountOfStars < 1) {
		cout << "Hotel can't have more then 5 stars or less then 1.";
		exit(0);
	}

	if (this->amountOfStars <= 3) {
                setIsPremium(false);
	}

	else {
                setIsPremium(true);
	}
}

void Hotel::setHotelNumber(int number){
	this->hotelNumber = number;
}

int Hotel::getHotelNumber(){
	return this->hotelNumber;
}

void Hotel::setHotelName(string name){
	this->hotelName = name;
}

string Hotel::getHotelName(){
	return this->hotelName;
}

void Hotel::setCountry(string countryH){
	this->country = countryH;
}

string Hotel::getCountry(){
	return this->country;
}

void Hotel::setCity(string cityH){
	this->city = cityH;
}

string Hotel::getCity(){
	return this->city;
}

void Hotel::setAddress(string addressH){
	this->address = addressH;
}

string Hotel::getAddress(){
	return this->address;
}

void Hotel::setAmountOfStars(short starsH){
	this->amountOfStars = starsH;
}

short Hotel::getAmountOfStars(){
	return this->amountOfStars;
}

void Hotel::setContactPerson(string contactH){
	this->contactPerson = contactH;
}

string Hotel::getContactPerson(){
	return this->contactPerson;
}

void Hotel::setIsPremium(bool prem){
	this->isPremium = prem;
}

bool Hotel::getIsPremium(){
	return this->isPremium;
}

void Hotel::hotelInfo() {
	//cout info
	cout << "Information about hotel: " << endl;
	cout << "Hotel number: " << this->hotelNumber << endl;
	cout << "Hotel name: " << this->hotelName << endl;
	cout << "Country: " << this->country << endl;
	cout << "City: " << this->city << endl;
	cout << "Address: " << this->address << endl;
	cout << "Amount of stars: " << this->amountOfStars << endl;
	cout << "Contact person: " << this->contactPerson << endl;
	cout << endl;
}
