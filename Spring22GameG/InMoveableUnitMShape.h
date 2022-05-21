#pragma once
#include "Game_Unit.h"
class InMoveableUnitMShape :
    public Game_Unit
{
public:

	InMoveableUnitMShape(const std::vector<std::string>& FileNames);
	
	virtual int GetX() const override;
	virtual int GetY() const override;
	virtual int GetZ() const override;
	bool GetDisappear() const;

	virtual int GetWidth() const override;
	virtual int GetHeight() const override;

	virtual void SetX(int newX) override;
	virtual void SetY(int newY) override;
	virtual void SetZ(int newZ) override;

	void SetDisappear(bool newSolid);
	virtual void SetMoveable(bool newSolid) override;
	virtual bool GetMoveable() const override;

	void SetActiveImage(int x);
	int GetActiveImage();

	virtual void Draw() override;
private:
	int mXPos{ 0 };
	int mYPos{ 0 };
	int mZPos{ 0 };

	bool mDisappear{ false };
	bool mMoveable{ false };

	int mActiveImage{ 0 };
	std::vector<Space::Pic> Images;

};

