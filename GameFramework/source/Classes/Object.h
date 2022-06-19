#pragma once
#include <string>

class Object {

protected:
	bool isActive = true;
	std::string name;

public:
	inline Object(){}
	inline Object(const std::string name, bool isActive = true) {
		this->name = name;
		this->isActive = isActive;
	}
	~Object() { delete this; }

	void Activate() { isActive = true; }
	void Deactivate() { isActive = false; }
	bool HasActivity() { return isActive; }
	const std::string GetName() { return name; }
};