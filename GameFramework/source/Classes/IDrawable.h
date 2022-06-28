#pragma once
#include "Classes/Object.h"


/**
* \brief THIS CLASS IS NOT IMPLEMENTED IN THIS FRAMEWORK VERSION.
*Will be a class that decouple rendering phases from RectTransform class.
*/
class IDrawable
{
	friend class Application;

protected:
	bool can_draw = true;

protected:
	virtual void On_Draw() = 0;

public:
	IDrawable() {};
	IDrawable(bool isDrawable) { can_draw = isDrawable; }
	~IDrawable() {};

	void Set_Drawable(bool isDrawable) { can_draw = isDrawable; }
};