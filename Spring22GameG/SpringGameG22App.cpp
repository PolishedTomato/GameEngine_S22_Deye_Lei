#include "SpringGameG22App.h"
#include "Irrklang/irrKlang.h"
#include "InMoveableUnit.h"
using namespace irrklang;


springApp::springApp()
{
	SetKeyPressCallBack([this](const Space::KeyPEvent& e) {
		switch (e.GetKeyCode())
		{
		case Space_KEY_LEFT:
			mHorizontalSpeed = -4;
			mVerticalSpeed = 0;
			mHero.SetActivemovement(left);//should be enum in real life situation
		
			break;
		case Space_KEY_RIGHT:
			mHorizontalSpeed = 4;
			mVerticalSpeed = 0;
			mHero.SetActivemovement(right);
		
			break;
		case Space_KEY_UP:
			mHorizontalSpeed = 0;
			mVerticalSpeed = 4;
			mHero.SetActivemovement(up);
			break;
		case Space_KEY_DOWN:
			mHorizontalSpeed = 0;
			mVerticalSpeed = -4;
			mHero.SetActivemovement(down);
			break;
		}
		});

	SetKeyReleaseCallBack([this](const Space::KeyREvent& e) {
		switch (e.GetKeyCode())
		{
		case Space_KEY_LEFT:
			mHorizontalSpeed = 0;
			mVerticalSpeed = 0;
			mHero.SetActivemovement(stop);//should be enum in real life situation
			mHero.SetmActiveSImage(0);
			break;
		case Space_KEY_RIGHT:
			mHorizontalSpeed = 0;
			mVerticalSpeed = 0;
			mHero.SetActivemovement(stop);
			mHero.SetmActiveSImage(1);
			break;
		case Space_KEY_UP:
			mHorizontalSpeed = 0;
			mVerticalSpeed = 0;
			mHero.SetActivemovement(stop);
			mHero.SetmActiveSImage(2);
			break;
		case Space_KEY_DOWN:
			mHorizontalSpeed = 0;
			mVerticalSpeed = 0;
			mHero.SetActivemovement(stop);
			mHero.SetmActiveSImage(3);
			break;
		}
		});

	//locations 

	Immovables[0].SetX(300);
	Immovables[0].SetY(300);
	
	Immovables[1].SetX(1150);
	Immovables[1].SetY(300);

	Counter.SetX(300);
	Counter.SetY(300);

	Complete.SetX(1150);
	Complete.SetY(300);

	Enermy[0].SetX(0);
	Enermy[0].SetY(1200);
	Enermy[0].SetActivemovement(down);

	Enermy[1].SetX(1700);
	Enermy[1].SetY(0);
	Enermy[1].SetActivemovement(up);

	Coins[0].SetX(0);
	Coins[0].SetY(1350);

	Coins[1].SetX(1800);
	Coins[1].SetY(1350);

	Coins[2].SetX(1800);
	Coins[2].SetY(0);

	Coins[3].SetX(1800);
	Coins[3].SetY(750);

	Coins[4].SetX(950);
	Coins[4].SetY(750);

	Coins[5].SetX(950);
	Coins[5].SetY(1350);

	Coins[6].SetX(950);
	Coins[6].SetY(0);
}

void springApp::OnUpdate()
{
	//prevent hero go out of window
	if ((mHero.GetX() + mHorizontalSpeed) >= 0 && 
		(mHero.GetX() + mHorizontalSpeed+mHero.GetWidth() <= Space::GWindows::GetWindow()->GetWindowWidth()))
	{
		mHero.SetX(mHero.GetX() + mHorizontalSpeed);
	}
	
	if ((mHero.GetY() + mVerticalSpeed) >= 0 &&
		(mHero.GetY() + mVerticalSpeed + mHero.GetHeight() <= Space::GWindows::GetWindow()->GetWindowHeight()))
	{
		mHero.SetY(mHero.GetY() + mVerticalSpeed);
	}

	for (int i = 0; i < Immovables.size(); i++)
	{
		if (Collide(mHero, Immovables[i]))//if collide reverse update poistion
		{
			//std::cout << "Collide" << std::endl;
			mHero.SetX(mHero.GetX() - mHorizontalSpeed);
			mHero.SetY(mHero.GetY() - mVerticalSpeed);
			SoundEngine->play2D("media/bell.wav", false);
			
		}
	}
	
	for (int i = 0; i < Enermy.size(); i++)
	{
		EnermyPath(Enermy[i],Enermy[i].GetActivemovement());
	}
	//enermy collide
	for (int i = 0; i < Enermy.size(); i++)
	{
		if (Collide(mHero, Enermy[i]))//if collide reverse update poistion
		{
			SoundEngine->play2D("media/explosion.wav", false);
			GAME_LOG("PLAYER LOSE");
			//sleep for 1 sec then close
			std::chrono::seconds SleepTime(1);
			std::this_thread::sleep_for(SleepTime);

			Space::GWindows::GetWindow()->WindowShouldClose(true);
		}
	}

	//coin collide
	for (int i = 0; i < Coins.size(); i++)
	{
		if (Collide(mHero, Coins[i]))
		{
			Coins[i].SetDisappear(true);
			SoundEngine->play2D("media/GetGoodItem.mp3", false);
			CoinCollected++;
			Counter.SetActiveImage(CoinCollected);
			if (CoinCollected == 7)
			{
				SoundEngine->play2D("media/tada-fanfare-a-6313.mp3", false);
				GAME_LOG("Congratulations, you beat the game!");
			}
		}
	}
	mHero.Draw();
	Immovables[0].Draw();
	Immovables[1].Draw();
	Enermy[0].Draw();
	Enermy[1].Draw();
	for (int i = 0; i < Coins.size(); i++)
	{
		Coins[i].Draw();
	}
	Counter.Draw();
	if (CoinCollected == 7)
	{
		Complete.Draw();
	}
}

bool springApp::Collide(const Game_Unit& one, const Game_Unit& two)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int twoLeft{ two.GetX() };
	int twoRight{ two.GetX() + two.GetWidth() };
	
	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int twoBottom{ two.GetY() };
	int twoTop{ two.GetY() + two.GetHeight() };
	
	bool collideX{ false };
	if ((oneLeft <= twoLeft and twoLeft <= oneRight)||
		(twoLeft <= oneLeft and oneLeft <= twoRight))
		collideX = true;

	bool collideY{ false };
	if ((oneBottom <= twoBottom and twoBottom <= oneTop) or
		(twoBottom <= oneBottom and oneBottom <= twoTop))
		collideY = true;

	return collideX and collideY;

}

void springApp::EnermyPath(MoveableUnit& Enermy, int dir)
{
	int nextXPos = Enermy.GetX();
	int nextYPos = Enermy.GetY();

	switch (dir)
	{
	case left:
		nextXPos = nextXPos - mEnermySpeed;
		break;
	case right:
		nextXPos = nextXPos + mEnermySpeed;
		break;
	case up:
		nextYPos = nextYPos + mEnermySpeed;
		break;
	case down:
		nextYPos = nextYPos - mEnermySpeed;
		break;
	}

	if (nextXPos < 0)
	{
		Enermy.SetActivemovement(down);
		Enermy.SetX(0);
		Enermy.SetY(Space::GWindows::GetWindow()->GetWindowHeight()-Enermy.GetHeight());
	}
	else if (nextXPos > (Space::GWindows::GetWindow()->GetWindowWidth() - Enermy.GetWidth()))
	{
		Enermy.SetActivemovement(up);
		Enermy.SetX(Space::GWindows::GetWindow()->GetWindowWidth()-Enermy.GetWidth());
		Enermy.SetY(0);

	}
	else if (nextYPos < 0)
	{
		Enermy.SetActivemovement(right);
		Enermy.SetX(0);
		Enermy.SetY(0);
	}
	else if (nextYPos > (Space::GWindows::GetWindow()->GetWindowHeight() - Enermy.GetHeight()))
	{
		Enermy.SetActivemovement(left);
		Enermy.SetX(Space::GWindows::GetWindow()->GetWindowWidth() - Enermy.GetWidth());
		Enermy.SetY(Space::GWindows::GetWindow()->GetWindowHeight() - Enermy.GetHeight());
	}
	else
	{
		Enermy.SetX(nextXPos);
		Enermy.SetY(nextYPos);
		//GAME_LOG(nextXPos);
	}
}
