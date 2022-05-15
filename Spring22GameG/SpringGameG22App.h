#pragma once
#include "../Space/SpaceApp.h"
#include "Game_Unit.h"

//when we use the namespace, we need to add namespace prefix before GameApp
class springApp : public Space::SpaceApp
{
public:
	/*
	virtual void OnUpdate() override;

	bool CollideX(const Game_Unit& one, const Game_Unit& two);
	bool CollideY(const Game_Unit& one, const Game_Unit& two);
private:
	
	Game_Unit mHero{ {"picture file location","picture file location","or more"} };
	std::vector<Game_Unit> Immovables;

	enum class HeroStates{Standing, Running, Jumping} mHeroState;

	enum class HeroDirection{Left, Right} mHeroDirection;

	int mHorizontalSpeed{ 0 };
	int mVerticalSpeed{ 0 }; 
	*/
};
