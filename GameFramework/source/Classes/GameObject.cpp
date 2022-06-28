#include "GameObject.h"
#include "..\Components\Component.h"


GameObject::GameObject(const std::string name, const bool isActive)
{
	this->name = name;
	this->isActive = isActive;
}

GameObject::GameObject(const std::string name, const std::vector<Component*> components, const bool isActive)
{
	this->name = name;
	this->components = components;
	this->isActive = isActive;
}

void GameObject::Add_Component(Component* component)
{
	component->owner = this;
	components.push_back(component);
}

void GameObject::Remove_Component(Component* component)
{
	for (auto item : components)
	{
		if (item == component)
		{
			std::vector<Component*> buffer;
			for (auto item : components)
			{
				if (item != component)
				{
					buffer.push_back(item);
				}
			}
			components = buffer;
			delete component;
		}
	}
}



void GameObject::On_Update(const float delta_time)
{
	for (auto item : components)
	{
		if (item->isActive && item->Is_Tick_Enabled()) { item->On_Update(delta_time); }
	}
}

void GameObject::On_Fixed_Update(const float delta_time)
{
	for (auto item : components)
	{
		if (item->isActive && item->Is_Tick_Enabled()) { item->On_Fixed_Update(delta_time); }
	}
}