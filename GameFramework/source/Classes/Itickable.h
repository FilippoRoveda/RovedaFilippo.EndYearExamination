#pragma once

/**
* \brief ITickable generate an inteface for all the tickable GameObjects.
*/
class ITickable {
private:
	//True if this GameObject can be updated.
	bool tickable = true;

protected:
	
	/**
	* \brief Default On_Update method.
	*/
	virtual void On_Update(const float delta_time) = 0;
	/**
	* \brief Default On_Fixed_Update method.
	*/
	virtual void On_Fixed_Update(const float delta_time) = 0;

public:

	/**
* \brief Return true if this GameObject is Tickable.
*/
	bool Is_Tick_Enabled() const { return tickable; }

	/**
* \brief Enable tick for this GameObject.
*/
	void Enable() { tickable = true; }

	/**
* \brief Disable tick for this GameObject.
*/
	void Disable() { tickable = false; }
};