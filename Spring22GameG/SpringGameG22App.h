#pragma once
#include "../Space/Space.h"
#include "Game_Unit.h"
#include "MoveableUnit.h"
#include "InMoveableUnit.h"
//when we use the namespace, we need to add namespace prefix before GameApp
class springApp : public Space::SpaceApp
{
public:
	springApp();

	virtual void OnUpdate() override;

	bool Collide(const Game_Unit& one, const Game_Unit& two);
	void EnermyPath(MoveableUnit & Enermy, int dir);
private:
	
	MoveableUnit mHero{{"media/HeroMoveLeft1.png","media/HeroMoveLeft1.png","media/HeroMoveLeft1.png","media/HeroMoveLeft1.png","media/HeroMoveLeft2.png", "media/HeroMoveLeft2.png","media/HeroMoveLeft2.png","media/HeroMoveLeft2.png",},
		{"media/HeroMoveRight1.png", "media/HeroMoveRight1.png","media/HeroMoveRight1.png","media/HeroMoveRight1.png","media/HeroMoveRight2.png","media/HeroMoveRight2.png","media/HeroMoveRight2.png","media/HeroMoveRight2.png"},
		{"media/HeroMoveUp1.png", "media/HeroMoveUp1.png","media/HeroMoveUp1.png","media/HeroMoveUp1.png","media/HeroMoveUp2.png","media/HeroMoveUp2.png","media/HeroMoveUp2.png","media/HeroMoveUp2.png"},
		{"media/HeroMoveDown1.png", "media/HeroMoveDown1.png","media/HeroMoveDown1.png","media/HeroMoveDown1.png","media/HeroMoveDown2.png","media/HeroMoveDown2.png","media/HeroMoveDown2.png","media/HeroMoveDown2.png"},
		{"media/HeroStandLeft.png", "media/HeroStandRight.png","media/HeroStandUp.png","media/HeroStandDown.png"} };

	std::vector<InMoveableUnit> Immovables{ {"media/Wall2.png"},
		{"media/Wall2.png"} };
	std::vector<MoveableUnit>Enermy{{{"media/HeroMoveLeft1.png","media/HeroMoveLeft1.png","media/HeroMoveLeft1.png","media/HeroMoveLeft1.png","media/HeroMoveLeft2.png", "media/HeroMoveLeft2.png","media/HeroMoveLeft2.png","media/HeroMoveLeft2.png",},
		{"media/HeroMoveRight1.png", "media/HeroMoveRight1.png","media/HeroMoveRight1.png","media/HeroMoveRight1.png","media/HeroMoveRight2.png","media/HeroMoveRight2.png","media/HeroMoveRight2.png","media/HeroMoveRight2.png"},
		{"media/HeroMoveUp1.png", "media/HeroMoveUp1.png","media/HeroMoveUp1.png","media/HeroMoveUp1.png","media/HeroMoveUp2.png","media/HeroMoveUp2.png","media/HeroMoveUp2.png","media/HeroMoveUp2.png"},
		{"media/HeroMoveDown1.png", "media/HeroMoveDown1.png","media/HeroMoveDown1.png","media/HeroMoveDown1.png","media/HeroMoveDown2.png","media/HeroMoveDown2.png","media/HeroMoveDown2.png","media/HeroMoveDown2.png"},
		{"media/HeroStandLeft.png", "media/HeroStandRight.png","media/HeroStandUp.png","media/HeroStandDown.png"}},
		{{"media/HeroMoveLeft1.png","media/HeroMoveLeft1.png","media/HeroMoveLeft1.png","media/HeroMoveLeft1.png","media/HeroMoveLeft2.png", "media/HeroMoveLeft2.png","media/HeroMoveLeft2.png","media/HeroMoveLeft2.png",},
		{"media/HeroMoveRight1.png", "media/HeroMoveRight1.png","media/HeroMoveRight1.png","media/HeroMoveRight1.png","media/HeroMoveRight2.png","media/HeroMoveRight2.png","media/HeroMoveRight2.png","media/HeroMoveRight2.png"},
		{"media/HeroMoveUp1.png", "media/HeroMoveUp1.png","media/HeroMoveUp1.png","media/HeroMoveUp1.png","media/HeroMoveUp2.png","media/HeroMoveUp2.png","media/HeroMoveUp2.png","media/HeroMoveUp2.png"},
		{"media/HeroMoveDown1.png", "media/HeroMoveDown1.png","media/HeroMoveDown1.png","media/HeroMoveDown1.png","media/HeroMoveDown2.png","media/HeroMoveDown2.png","media/HeroMoveDown2.png","media/HeroMoveDown2.png"},
		{"media/HeroStandLeft.png", "media/HeroStandRight.png","media/HeroStandUp.png","media/HeroStandDown.png"}}

	};

	
	//std::vector<Game_Unit> Enermys{ {{"PHeroR.png"}} };


	int mHorizontalSpeed{ 0 };// speed in pixel perframe
	int mVerticalSpeed{ 0 };
	
	int mEnermySpeed{ 5 };

	enum movement { left = 0, right = 1, up = 2, down = 3, stop = 4 };
	
};
