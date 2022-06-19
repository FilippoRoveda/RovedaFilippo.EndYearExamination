#pragma once
#include "Classes/Object.h"

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