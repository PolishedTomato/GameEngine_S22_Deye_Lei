#pragma once
#include "Game_Unit.h"
class InMoveableUnit:public Game_Unit
{
public:
    InMoveableUnit(const std::string& Filenames);

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

private:
    Space::Pic Images;

    int mXPos{ 0 };
    int mYPos{ 0 };
    int mZpos{ 0 };

    bool mMoveable{ false };

    bool disapear{ false };

};

