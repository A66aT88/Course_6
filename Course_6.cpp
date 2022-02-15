#include <iostream>
#include <optional>

struct Person {
	std::string first_name;
	std::string last_name;
	std::optional<std::string> third_name;
};

bool operator<(const Person& firstPerson, const Person& secondPerson) {
	return std::tie(firstPerson.first_name, firstPerson.last_name, firstPerson.third_name) < std::tie(secondPerson.first_name, secondPerson.last_name, secondPerson.third_name);
}

bool operator==(const Person& firstPerson, const Person& secondPerson) {
	return std::tie(firstPerson.first_name, firstPerson.last_name, firstPerson.third_name) == std::tie(secondPerson.first_name, secondPerson.last_name, secondPerson.third_name);
}

struct PhoneNumber {
	int phone_code;
	int city_code;
	std::string phone_number;
	std::optional<int> addtlNum;
};

std::ostream& operator<<(std::ostream &s, const PhoneNumber& phoneNumber) {
	s << "+" << phoneNumber.phone_code << "(" << phoneNumber.city_code << ")" << phoneNumber.phone_number;
	if (phoneNumber.addtlNum) {
		s << " " << * phoneNumber.addtlNum;
	}
	return s;
}

bool operator<(const PhoneNumber& phoneNumber1, const PhoneNumber& phoneNumber2) {
	return std::tie(phoneNumber1.phone_code, phoneNumber1.city_code, phoneNumber1.phone_number, phoneNumber1.addtlNum) < std::tie(phoneNumber2.phone_code, phoneNumber2.city_code, phoneNumber2.phone_number, phoneNumber2.addtlNum);
}

bool operator==(const PhoneNumber& phoneNumber1, const PhoneNumber& phoneNumber2) {
	return std::tie(phoneNumber1.phone_code, phoneNumber1.city_code, phoneNumber1.phone_number, phoneNumber1.addtlNum) == std::tie(phoneNumber2.phone_code, phoneNumber2.city_code, phoneNumber2.phone_number, phoneNumber2.addtlNum);
}

class PhoneBook {

};


int main()
{
	
	PhoneNumber p1;
	p1.city_code = 5;
	p1.phone_code = 12;
	p1.phone_number = "123456789";
	p1.addtlNum = 4002;

	std::cout << p1 << std::endl;


	return 0;
}
