#pragma once
#include <vector>

#include "Object.h"
#include "Itickable.h"
#include "dllclasses.h"

class Component;

/**
* \brief GameObject class represent a tickable object that can contain Components that define its behaviour
*  and its property.
*/
class DECLSPEC GameObject : public Object, public ITickable
{
	friend class Application;

private:
	std::vector<Component*> components;

protected:
	//Inherited from ITickable
	virtual void On_Update(const float delta_time) override;
	virtual void On_Fixed_Update(const float delta_time) override;


public:
	GameObject() {};
	GameObject(const std::string name, const bool isActive = true);
	GameObject(const std::string name, const std::vector<Component*> components, const bool isActive = true);
	virtual ~GameObject() = default;

	 /// <summary>
	/// add a components to this game object
	/// </summary>
	/// <param name="component">the component to add</param>
	 void Add_Component(Component* component);

	 /// <summary>
	/// removes a components from this object
	 /// </summary>
	 /// <param name="component">the components to remove</param>
	 void Remove_Component(Component* component);

	 /// <summary>
	/// Get the first components of the given type from the attached components
	 /// </summary>
	/// <typeparam name="T">the component to add</typeparam>
	/// <returns></returns>
	 template<class T, class = Component>  T* Get_Component() {

		 if (components.size() == 0) return nullptr;

		 for (Component* item : components)
		 {
			 const auto val = dynamic_cast<T*>(item);
			 if (!val) continue;

			 return val;
		 }

		 return nullptr;
	 }

	 /// <summary>
	/// Get all components of the given type from the attached components
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	 template<class T> std::vector<T*> Get_Components() 
	 {
		 std::vector<T*> result;

		 if (components.size() == 0) return result;

		 for (Component * component : components)
		 {
			 const auto val = dynamic_cast<T*>(component);
			 if (!val) continue;

			 result.push_back(val);
		 }

		 return result;
	 }
};