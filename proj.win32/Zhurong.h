#pragma once
#include "GeneralUnit.h"
//#include <math.h>


class Zhurong :public GeneralUnit
{
public:

	const int FULL_HP = 4000;

	float ground_left = 11500;//����������
	float ground_right = 11997;//��������ұߣ��Ҿ�����һ�ξ���̣ܶ�����ֻ�������ߺͽ��������ұߣ������������󹥻���
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
	Sprite* fire_con;//һ��ָ�룬�᲻����������Ŀǰû������
	Sprite* boom;

	int time_flag = 0;
	int dieflagforzhongrong = 0;

	//���˿۵�Ѫ��
	int hockblood = 20;//�ӿ�ʱ
	int firerainblood = 10; //������
	int bigfireballblood = 20;//����򹥻�

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

	//������ֻ�Ƕ�����û��λ��
	Animation * walkingLeftWhileFacingLeftAnimation;//�������ǰ��
	Animation * walkingRightWhileFacingLeftAnimation;//������ߺ���

	Animation * walkingRightWhileFacingRightAnimation;//�����ұ�ǰ��
	Animation * walkingLeftWhileFacingRightAnimation;//�����ұߺ���

	//���ܶ���
	Animation * shootingFireBallWhileFacingLeftAnimation;
	Animation * firerainAnimation;
	Animation * closeAnimation;
	Animation * closerightAnimation;
	Animation * heatupAnimation;
	Animation * heldAnimation;

	//����Ч���ͼ��ܵ��߶���
	Animation * fireballSpinningAnimation;//������ת������ע��ֻ����ת����������λ�Ʒ��ں�����ڻ�����ת��ÿһAnimation֡�ж����Ƿ���������ײ
	Animation * fireballExplosionAnimation;//���汬ը����

	Animation * waterSplashingAnimation;

	Animation * weakfightAnimation;

	//���򶯻�
	Animation * hurtleftAnimation;
	Animation * hurtrightAnimation;
	//��������
	Animation * dieleftAnimation;
	Animation * dierightAnimation;

	Animation * thrownAnimation;


	//�������Ȱ��������ְ���λ�ơ�
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

	void idle();//��վ�ţ�ʲôҲ����

	static Zhurong * create(const std::string & filename);



	Zhurong();
	~Zhurong();
};

