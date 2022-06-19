#pragma once
class ITickable {
private:
	bool tickable = true;

protected:
	virtual void On_Update(const float delta_time) = 0;
	virtual void On_Fixed_Update(const float delta_time) = 0;

public:
	bool Is_Tick_Enabled() const { return tickable; }
	void Enable() { tickable = true; }
	void Disable() { tickable = false; }
};