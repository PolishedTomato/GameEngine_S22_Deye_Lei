#pragma once
#include "../Space/Space.h"
#include "Game_Unit.h"
#include "MoveableUnit.h"
#include "InMoveableUnit.h"
#include "InMoveableUnitMShape.h"
//when we use the namespace, we need to add namespace prefix before GameApp
class SpringGameG22App : public Space::SpaceApp
{
public:
	SpringGameG22App();

	virtual void OnUpdate() override;

	bool Collide(const Game_Unit& one, const Game_Unit& two);
	void EnermyPath(MoveableUnit & Enermy, int dir);
private:
	
	MoveableUnit mHero{{"media/HeroMoveLeft1.png","media/HeroMoveLeft1.png","media/HeroMoveLeft2.png","media/HeroMoveLeft2.png",},
		{"media/HeroMoveRight1.png","media/HeroMoveRight1.png","media/HeroMoveRight2.png","media/HeroMoveRight2.png"},
		{"media/HeroMoveUp1.png","media/HeroMoveUp1.png","media/HeroMoveUp2.png","media/HeroMoveUp2.png"},
		{"media/HeroMoveDown1.png","media/HeroMoveDown1.png","media/HeroMoveDown2.png","media/HeroMoveDown2.png"},
		{"media/HeroStandLeft.png", "media/HeroStandRight.png","media/HeroStandUp.png","media/HeroStandDown.png"} };

	std::vector<InMoveableUnit> Immovables{ {"media/Wall2.png"},
		{"media/Wall2.png"} };
	std::vector<MoveableUnit>Enermy{ {{"media/EnermyMoveLeft1.png","media/EnermyMoveLeft1.png","media/EnermyMoveLeft2.png","media/EnermyMoveLeft2.png",},
		{"media/EnermyMoveRight1.png","media/EnermyMoveRight1.png","media/EnermyMoveRight2.png","media/EnermyMoveRight2.png"},
		{"media/EnermyMoveUp1.png","media/EnermyMoveUp1.png","media/EnermyMoveUp2.png","media/EnermyMoveUp2.png"},
		{"media/EnermyMoveDown1.png","media/EnermyMoveDown1.png","media/EnermyMoveDown2.png","media/EnermyMoveDown2.png"},
		{"media/HeroStandLeft.png", "media/HeroStandRight.png","media/HeroStandUp.png","media/HeroStandDown.png"}},

		{{"media/EnermyMoveLeft1.png","media/EnermyMoveLeft1.png","media/EnermyMoveLeft2.png","media/EnermyMoveLeft2.png",},
		{"media/EnermyMoveRight1.png","media/EnermyMoveRight1.png","media/EnermyMoveRight2.png","media/EnermyMoveRight2.png"},
		{"media/EnermyMoveUp1.png","media/EnermyMoveUp1.png","media/EnermyMoveUp2.png","media/EnermyMoveUp2.png"},
		{"media/EnermyMoveDown1.png","media/EnermyMoveDown1.png","media/EnermyMoveDown2.png","media/EnermyMoveDown2.png"},
		{"media/HeroStandLeft.png", "media/HeroStandRight.png","media/HeroStandUp.png","media/HeroStandDown.png"}}
	};
	//7 coins
	std::vector<InMoveableUnit> Coins{{"media/Coin.png"},{"media/Coin.png"},{"media/Coin.png"},{"media/Coin.png"},{"media/Coin.png"},{"media/Coin.png"},{"media/Coin.png"} };
	
	//counter
	InMoveableUnitMShape Counter{ {"media/count00.png",
								"media/count01.png",
								"media/count02.png",
								"media/count03.png",
								"media/count04.png",
								"media/count05.png",
								"media/count06.png",
								"media/count07.png"} };

	InMoveableUnit Complete{"media/Complete.png"};

	int mHorizontalSpeed{ 0 };// speed in pixel perframe
	int mVerticalSpeed{ 0 };
	
	int mEnermySpeed{ 5 };

	enum movement { left = 0, right = 1, up = 2, down = 3, stop = 4 };
	
	int CoinCollected{ 0 };
};
