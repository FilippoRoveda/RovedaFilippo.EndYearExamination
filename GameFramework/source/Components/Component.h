#pragma once
#include "..\Classes\Object.h"
#include "..\Classes\Itickable.h"


class GameObject;


/**
 * \brief Base Component class.
 */
class Component : public Object, public ITickable
{
	friend class GameObject;

protected:
	GameObject* owner = nullptr;

protected:
	//Inherited via ITickable
	virtual void On_Update(const float delta_time) override;
	virtual void On_Fixed_Update(const float delta_time) override;

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	Component(const std::string name, const bool isActive = true) : Object(name, isActive) {}

	/// <summary>
	///Default destructor.
	/// </summary>
	virtual ~Component() = default;


	/// <summary>
	/// Return the GameObject that owns this component.
	/// </summary>
	[[nodiscard]] GameObject* GetOwner() { return owner; }


	/// <summary>
	/// Set the GameObject that owns this component.
	/// </summary>
	void SetOwner(GameObject* owner) { this->owner = owner; }

};