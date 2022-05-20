#include "MoveableUnit.h"

MoveableUnit::MoveableUnit(const std::vector<std::string>& LMoveFilenames, const std::vector<std::string>& RMoveFilenames, const std::vector<std::string>& UMoveFilenames, const std::vector<std::string>& DMoveFilenames, const std::vector<std::string>& StopMoveFilenames)
	:mLImages(LMoveFilenames.begin(), LMoveFilenames.end()),
	mRImages(RMoveFilenames.begin(), RMoveFilenames.end()),
	mUImages(UMoveFilenames.begin(), UMoveFilenames.end()),
	mDImages(DMoveFilenames.begin(), DMoveFilenames.end()),
	mSImages(StopMoveFilenames.begin(), StopMoveFilenames.end())
{
	
}

int MoveableUnit::GetX() const
{
	return mXPos;
}

int MoveableUnit::GetY() const
{
	return mYPos;
}

int MoveableUnit::GetZ() const
{
	return mZpos;
}

bool MoveableUnit::GetMoveable() const
{
	return mMoveable;
}

int MoveableUnit::GetWidth() const
{
	switch (mActivemovement)
	{
	case left:
		return mLImages[mActiveLImage].GetWidth();
	case right:
		return mRImages[mActiveRImage].GetWidth();
	case up:
		return mUImages[mActiveUImage].GetWidth();
	case down:
		return mDImages[mActiveDImage].GetWidth();
	case stop:
		return mSImages[mActiveSImage].GetWidth();
	}
}

int MoveableUnit::GetHeight() const
{
	switch (mActivemovement)
	{
	case left:
		return mLImages[mActiveLImage].GetHeight();
	case right:
		return mRImages[mActiveRImage].GetHeight();
	case up:
		return mUImages[mActiveUImage].GetHeight();
	case down:
		return mDImages[mActiveDImage].GetHeight();
	case stop:
		return mSImages[mActiveSImage].GetHeight();
	}
}

void MoveableUnit::Draw()
{
	Space::Pic_Renderer::init();
	
	switch (mActivemovement)
	{
	case left:
		Space::Pic_Renderer::Draw(mLImages[mActiveLImage], mXPos, mYPos, mZpos);
		mActiveLImage = (mActiveLImage + 1) % mLImages.size();//update movement
		break;
	case right:
		Space::Pic_Renderer::Draw(mRImages[mActiveRImage], mXPos, mYPos, mZpos);
		mActiveRImage = (mActiveRImage + 1) % mRImages.size();
		break;
	case up:
		Space::Pic_Renderer::Draw(mUImages[mActiveUImage], mXPos, mYPos, mZpos);
		mActiveUImage = (mActiveUImage + 1) % mUImages.size();
		break;
	case down:
		Space::Pic_Renderer::Draw(mDImages[mActiveDImage], mXPos, mYPos, mZpos);
		mActiveDImage = (mActiveDImage + 1) % mDImages.size();
		break;
	case stop:
		Space::Pic_Renderer::Draw(mSImages[mActiveSImage], mXPos, mYPos, mZpos);
		break;
	}
	
}

void MoveableUnit::SetX(int newX)
{
	mXPos = newX;
}

void MoveableUnit::SetY(int newY)
{
	mYPos = newY;
}

void MoveableUnit::SetZ(int newZ)
{
	mZpos = newZ;
}

void MoveableUnit::SetMoveable(bool newSolid)
{
	mMoveable = newSolid;
}

int MoveableUnit::GetActivemovement()
{
	return mActivemovement;
}

void MoveableUnit::SetActivemovement(int dir)
{
	mActivemovement = dir;
}

void MoveableUnit::SetmActiveSImage(int x)
{
	mActiveSImage = x;
}
