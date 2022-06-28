#pragma once
#include <string>


/**
* \brief Base Object class that contains all base feature of the framework entities.
*/
class Object {

protected:
	//Activity state if the object.
	bool isActive = true;
	//Name of the object.
	std::string name;

public:
	/**
	* \brief Default constructor.
	*/
	inline Object(){}
	/**
	* \brief Constructor that initialize name and activity status.
	*/
	inline Object(const std::string name, bool isActive = true) {
		this->name = name;
		this->isActive = isActive;
	}
	/**
	* \brief Default destructor.
	*/
	~Object() { delete this; }

	/**
* \brief Enable this GameObject.
*/
	void Activate() { isActive = true; }

	/**
	* \brief Disable this GameObject.
	*/
	void Deactivate() { isActive = false; }

	/**
* \brief Return true or false based on activity status.
*/
	bool HasActivity() { return isActive; }

	/**
* \brief Return name of the object.
*/
	const std::string GetName() { return name; }
};