#include "Game_Unit.h"
#include "../Space/Space.h"
Game_Unit::Game_Unit(const std::vector<std::string>& filenames)
	:mImage(filenames.begin(), filenames.end())
{

}

int Game_Unit::GetX() const
{
	return mXPos;
}

int Game_Unit::GetY() const
{
	return mYPos;
}

int Game_Unit::GetZ() const
{
	return mZpos;
}

bool Game_Unit::GetSolid() const
{
	return mSolid;
}

int Game_Unit::GetImageIndex() const
{
	return mActiveImage;
}

int Game_Unit::GetWidth() const
{
	return mImage[mActiveImage].GetWidth();
}

int Game_Unit::GetHeight() const
{
	return mImage[mActiveImage].GetHeight();
}

void Game_Unit::SetX(int newX)
{
	mXPos = newX;
}

void Game_Unit::SetY(int newY)
{
	mYPos = newY;
}

void Game_Unit::SetZ(int newZ)
{
	mZpos = newZ;
}

void Game_Unit::SetSolid(bool newSolid)
{
	mSolid = newSolid;
}

void Game_Unit::SetActiveimage(int newActiveImage)
{
	mActiveImage = newActiveImage;
}

void Game_Unit::Draw()
{
	Space::Pic_Renderer::init();
	Space::Pic_Renderer::Draw(mImage[mActiveImage], mXPos,mYPos,mZpos);
}
