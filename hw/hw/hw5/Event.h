#ifndef _EVENT_H_
#define _EVENT_H_
#include <string>
#include <iostream>

class Event {
private:
	std::string eventType;
	int timeStamp;

public:
	inline Event() {}

	inline Event(std::string eventType, int timeStamp) {
		this->eventType = eventType;
		this->timeStamp = timeStamp;
	}

	inline std::string getEventType() const {
		return eventType;
	}

	inline int getTimeStamp() const {
		return timeStamp;
	}

	inline bool operator<=(const Event &rhs) const {
		return this->timeStamp <= rhs.timeStamp;
	}

	inline bool operator<(const Event &rhs) const {
		return this->timeStamp < rhs.timeStamp;
	}
};

inline ostream& operator<<(ostream &os, const Event &obj) {
	os << obj.getTimeStamp();
	return os;
}

#endif // !_EVENT_H_