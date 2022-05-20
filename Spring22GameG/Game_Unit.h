#pragma once
#include "../Space/Pic.h"
#include "vector"
#include "../Space/Space.h"
class Game_Unit
{
public:
	//Game_Unit(const std::vector<std::string>& filenames);//for continious movement, take multiple sprike
	virtual int GetX() const = 0;
	virtual int GetY() const = 0;
	virtual int GetZ() const = 0;
	virtual bool GetMoveable() const =0;

	virtual int GetWidth() const =0;
	virtual int GetHeight() const = 0;

	virtual void SetX(int newX) = 0;
	virtual void SetY(int newY) = 0;
	virtual void SetZ(int newZ) = 0;

	virtual void SetMoveable(bool newSolid) = 0;
	
	//void SetActiveimage(int newActiveImage);

	virtual void Draw() = 0;
};

