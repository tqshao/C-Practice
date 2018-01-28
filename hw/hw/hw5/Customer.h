#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <iostream>
#include <string>

class Customer {
private:
	int customerId;

public:
	inline Customer() {}

	inline Customer(int id) {
		customerId = id;
	}

	inline int getCustomerId() const {
		return customerId;
	}
};

inline ostream& operator<<(ostream &os, const Customer &obj) {
	os << obj.getCustomerId();
	return os;
}

#endif // !_CUSTOMER_H_
