#pragma once
#include "GeneralUnit.h"
//#include <math.h>


class Zhurong :public GeneralUnit
{
public:

	const int FULL_HP = 4000;

	float ground_left = 11500;//地面的最左边
	float ground_right = 11997;//地面的最右边（我觉得这一段距离很短，所以只有向右走和近身攻击有右边，其他都是向左攻击）
	int health = FULL_HP;//10000

	int awake = 5000;

	int camp = 2;
	int yyh = 0;

	int alertRange = 800;

	int close_fight = 150;
	int remote_fight = 600;
	float firerain_scope = 1500;
	float firerain_need;
	Sprite* sea;
	Sprite* fire_con;//一个指针，会不会有问题呢目前没看出来
	Sprite* boom;

	int time_flag = 0;
	int dieflagforzhongrong = 0;

	//受伤扣的血量
	int hockblood = 20;//挥砍时
	int firerainblood = 10; //火球雨
	int bigfireballblood = 20;//大火球攻击

	float ANIMATION_FRAME_INTERVAL = 0.3f;

	int heatwater_flag = 0;


	bool acceptCall = true;///
	bool facingRight = false;
	int romote_flag = 0;
	int aoe_flag = 0;
	int heat_flag = 0;
	int weak_flag = 1;
	int weak = FULL_HP;
	Sprite* s; 
	Vector <Sprite *>fireball;// = {};

	//动画。只是动画，没有位移
	Animation * walkingLeftWhileFacingLeftAnimation;//面向左边前进
	Animation * walkingRightWhileFacingLeftAnimation;//面向左边后退

	Animation * walkingRightWhileFacingRightAnimation;//面向右边前进
	Animation * walkingLeftWhileFacingRightAnimation;//面向右边后退

	//技能动画
	Animation * shootingFireBallWhileFacingLeftAnimation;
	Animation * firerainAnimation;
	Animation * closeAnimation;
	Animation * closerightAnimation;
	Animation * heatupAnimation;
	Animation * heldAnimation;

	//技能效果和技能道具动画
	Animation * fireballSpinningAnimation;//火球旋转动画。注意只是旋转动画，飞行位移放在函数里。在火球旋转的每一Animation帧判断它是否与主角相撞
	Animation * fireballExplosionAnimation;//火焰爆炸动画

	Animation * waterSplashingAnimation;

	Animation * weakfightAnimation;

	//挨打动画
	Animation * hurtleftAnimation;
	Animation * hurtrightAnimation;
	//死亡动画
	Animation * dieleftAnimation;
	Animation * dierightAnimation;

	Animation * thrownAnimation;


	//动作，既包含动画又包含位移。
	void walkLeftWhileFacingLeft();
	void walkrightWhileFacingright();
	void prepareAndLaunchAFireballWhileFacingLeft();
	void firerain();
	void firerainsmall(float dt);
	void closeattack();
	void heatwater();



	void update(float dt);
	void wanderAbout();
	void getHeld();
	void getThrown();
	void getSlamDunkOnGround(int damage);
	void getSlamDunkOnWater(int damage);
	void getCollided(int damage);
	void getHurt(int damage);
	void getHurtByWind(int damage);
	void getHurtByPaw(int damage);
	void getHurtByCrush(int damage);

	void getHurtByWater(int damage);
	void getHurtByFin(int damage);

	void die();

	//void getSlamDunkOnGround(int damage);

	//void getSlamDunkOnWater(int damage);

	void idle();//呆站着，什么也不做

	static Zhurong * create(const std::string & filename);



	Zhurong();
	~Zhurong();
};

