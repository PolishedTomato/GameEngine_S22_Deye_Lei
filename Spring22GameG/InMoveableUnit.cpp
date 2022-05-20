#include "InMoveableUnit.h"

InMoveableUnit::InMoveableUnit(const std::string& Filenames)
	:Images(Filenames)
{
}

int InMoveableUnit::GetX() const
{
	return mXPos;
}

int InMoveableUnit::GetY() const
{
	return mYPos;
}

int InMoveableUnit::GetZ() const
{
	return mZpos;
}

bool InMoveableUnit::GetMoveable() const
{
	return mMoveable;
}

int InMoveableUnit::GetWidth() const
{
	return Images.GetWidth();
}

int InMoveableUnit::GetHeight() const
{
	return Images.GetHeight();
}

void InMoveableUnit::Draw()
{
	if (!disapear)//when disapear dont draw it
	{
		Space::Pic_Renderer::init();
		Space::Pic_Renderer::Draw(Images, mXPos, mYPos, mZpos);
	}
}

void InMoveableUnit::SetX(int newX)
{
	mXPos = newX;
}

void InMoveableUnit::SetY(int newY)
{
	mYPos = newY;
}

void InMoveableUnit::SetZ(int newZ)
{
	mZpos = newZ;
}

void InMoveableUnit::SetMoveable(bool newSolid)
{
	mMoveable = newSolid;
}
