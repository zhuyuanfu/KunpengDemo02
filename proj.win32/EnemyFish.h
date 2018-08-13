#pragma once
#include <stdlib.h> 
#include <time.h> 
#include "GeneralUnit.h"

//author：李佳杰
//小怪：鱼

#define FISHHEALTHY1 100
#define ALARMDISTANCE1 300
#define ATTACK_PROB 4
#define GUARD_POSTION_DISTANCE 500

class EnemyFish : public GeneralUnit
{
public:
	float TIME_FOR_ANIMATION_FRAME_INTERVAL = 0.2f;
	float ANIMATION_FRAME_INTERVAL = 0.3f;
	float speed_flying_pixel_per_second = 100;
	int damage = 10;

	Sprite* ink_con;

	bool acceptCall = true;
	//小怪状态
	bool facingRight = true;
	bool facingLeft = false;
	bool moving = false;

	//守卫点
	int guardPostionX = 6850;
	int guardPostionY = -200;

	//悬停动画
	Animation * hoveringRightAnimation;
	Animation * hoveringLeftAnimation;

	//普通移动的动画
	Animation * movingUpAnimation;
	Animation * movingUpRightAnimation;
	Animation * movingRightAnimation;
	Animation * movingDownRightAnimation;
	Animation * movingDownAnimation;
	Animation * movingDownLeftAnimation;
	Animation * movingLeftAnimation;
	Animation * movingUpLeftAnimation;

	//攻击动画
	Animation * attackAnimation;
	Animation * newAttackAnimation;
	Animation * inkBallAttackAnimation;

	//受伤动画
	Animation *getHurtAnimation;

	//死亡动画
	Animation *dieAnimation;

	EnemyFish();
	~EnemyFish();

	static EnemyFish * create(const std::string & filename);

	void setGuardPos(int guardPosX, int guardPosY);
	void wanderAbout();
	//void wanderAbout(int guardPosX, int guardPosY);
	void getHurt();
	void getHurt(int damage);
	void getHurtByWind(int damage);

	//鸟态主角
	void getHeld(int);
	void 	getThrown();
	void getSlamDunkOnGround(int);
	void getSlamDunkOnWater(int);

	//鱼态主角
	void 	getCollided(int);


	void die();
};
