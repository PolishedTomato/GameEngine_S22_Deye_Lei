#pragma once
#include "Game_Unit.h"
class MoveableUnit :
    public Game_Unit
{
public:
    MoveableUnit(const std::vector<std::string>& LMoveFilenames, 
        const std::vector<std::string>& RMoveFilenames,
        const std::vector<std::string>& UMoveFilenames,
        const std::vector<std::string>& DMoveFilenames,
        const std::vector<std::string>& StopMoveFilenames);

    virtual int GetX() const override;
    virtual int GetY() const override;
    virtual int GetZ() const override;
    virtual bool GetMoveable() const override;

    virtual int GetWidth() const override;
    virtual int GetHeight() const override;
    virtual void Draw() override;

    virtual void SetX(int newX) override;
    virtual void SetY(int newY) override;
    virtual void SetZ(int newZ) override;

    virtual void SetMoveable(bool newSolid) override;
    int GetActivemovement();
    void SetActivemovement(int dir);
    void SetmActiveSImage(int x);
private:
    std::vector<Space::Pic> mLImages;
    std::vector<Space::Pic> mRImages;
    std::vector<Space::Pic> mUImages;
    std::vector<Space::Pic> mDImages;
    std::vector<Space::Pic> mSImages;
    enum movement {left =0 , right = 1, up =2, down=3, stop = 4 };
    int mActivemovement = stop;

    int mActiveLImage{ 0 };
    int mActiveRImage{ 0 };
    int mActiveUImage{ 0 };
    int mActiveDImage{ 0 };
    int mActiveSImage{ 0 };

    int mXPos{ 0 };
    int mYPos{ 0 };
    int mZpos{ 0 };

    bool mMoveable{ true };

};

