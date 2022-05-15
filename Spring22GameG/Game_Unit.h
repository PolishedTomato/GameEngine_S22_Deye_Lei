#pragma once
#include "../Space/Pic.h"
#include "vector"
class Game_Unit
{
public:
	Game_Unit(const std::vector<std::string>& filenames);

	int GetX() const;
	int GetY() const;
	int GetZ() const;
	bool GetSolid() const;
	int GetImageIndex()const;
	int GetWidth() const;
	int GetHeight() const;

	void SetX(int newX);
	void SetY(int newY);
	void SetZ(int newZ);
	void SetSolid(bool newSolid);
	void SetActiveimage(int newActiveImage);

	void Draw();
private:
	int mXPos{ 0 };
	int mYPos{ 0 };
	int mZpos{ 0 };

	bool mSolid{ true };
	int mActiveImage{ 0 };
	std::vector<Space::Pic> mImage;
};

