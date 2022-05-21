#include "InMoveableUnitMShape.h"

InMoveableUnitMShape::InMoveableUnitMShape(const std::vector<std::string>& FileNames)
	:Images(FileNames.begin(), FileNames.end())
{
}

int InMoveableUnitMShape::GetX() const
{
	return mXPos;
}

int InMoveableUnitMShape::GetY() const
{
	return mYPos;
}

int InMoveableUnitMShape::GetZ() const
{
	return mZPos;
}

int InMoveableUnitMShape::GetWidth() const
{
	return Images[mActiveImage].GetWidth();
}

int InMoveableUnitMShape::GetHeight() const
{
	return Images[mActiveImage].GetHeight();
}

bool InMoveableUnitMShape::GetDisappear() const
{
	return mDisappear;
}

void InMoveableUnitMShape::SetX(int newX)
{
	mXPos = newX;
}

void InMoveableUnitMShape::SetY(int newY)
{
	mYPos = newY;
}

void InMoveableUnitMShape::SetZ(int newZ)
{
	mZPos = newZ;
}

void InMoveableUnitMShape::SetDisappear(bool newV)
{
	mDisappear = newV;
	//get out of the screen
	if (mDisappear = true)
	{

		mXPos = -500;
		mYPos = -500;
	}
}

void InMoveableUnitMShape::SetMoveable(bool newSolid)
{
	mMoveable = newSolid;
}

bool InMoveableUnitMShape::GetMoveable() const
{
	return mMoveable;
}

void InMoveableUnitMShape::SetActiveImage(int x)
{
	mActiveImage = x;
}

int InMoveableUnitMShape::GetActiveImage()
{
	return mActiveImage;
}

void InMoveableUnitMShape::Draw()
{
	if (!mDisappear)
	{
		Space::Pic_Renderer::init();
		Space::Pic_Renderer::Draw(Images[mActiveImage], mXPos, mYPos, mZPos);
	}
}
