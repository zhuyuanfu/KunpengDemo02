#pragma once
#include "GeneralUnit.h"
//#include <math.h>


class Zhurong :public GeneralUnit
{
public:

	int health = 10000;

	int awake = 5000;

	int camp = 2;

	int alertRange = 800;

	float ANIMATION_FRAME_INTERVAL = 0.1f;


	bool acceptCall = true;///
	bool facingRight = false;

	//������ֻ�Ƕ�����û��λ��
	Animation * walkingLeftWhileFacingLeftAnimation;//�������ǰ��
	Animation * walkingRightWhileFacingLeftAnimation;//������ߺ���

	Animation * walkingRightWhileFacingRightAnimation;//�����ұ�ǰ��
	Animation * walkingLeftWhileFacingRightAnimation;//�����ұߺ���

	//���ܶ���
	Animation * shootingFireBallWhileFacingLeftAnimation;


	//����Ч���ͼ��ܵ��߶���
	Animation * fireballSpinningAnimation;//������ת������ע��ֻ����ת����������λ�Ʒ��ں�����ڻ�����ת��ÿһAnimation֡�ж����Ƿ���������ײ
	Animation * fireballExplosionAnimation;//���汬ը����

	//���򶯻�

	//��������



	//�������Ȱ��������ְ���λ�ơ�
	void walkLeftWhileFacingLeft();
	void prepareAndLaunchAFireballWhileFacingLeft();




	void wanderAbout();

	void getHurt(int damage);
	void getHurtByWind(int damage);
	void getHurtByPaw(int damage);
	void getHurtByCrush(int damage);

	void getHurtByWater(int damage);
	void getHurtByFin(int damage);

	void die();

	void idle();//��վ�ţ�ʲôҲ����

	static Zhurong * create(const std::string & filename);



	Zhurong();
	~Zhurong();
};

