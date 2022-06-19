#pragma once
#include "..\Classes\Object.h"
#include "..\Classes\Itickable.h"


class GameObject;

class Component : public Object, public ITickable
{
	friend class GameObject;

private:
	GameObject* owner = nullptr;

protected:
	//Inherited via ITickable
	virtual void On_Update(const float delta_time) override;
	virtual void On_Fixed_Update(const float delta_time) override;

public:
	Component(const std::string name, const bool isActive = true) : Object(name, isActive) {}
	virtual ~Component() = default;

	[[nodiscard]] GameObject* Get_Owner() const { return owner; }

};