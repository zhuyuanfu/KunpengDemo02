#pragma once
#include "cocos2d.h"
USING_NS_CC;
class GeneralUnit :public Sprite
{
public:

	//Ѫ��
	int health;

	//Bossר�á�С�ֲ�������������
	bool isBoss = false;
	//Bossר�ã����strong�۵�����ֵ�ͽ�������״̬����������״̬��һ��ʱ���뿪����״̬���뿪����״̬ʱstrongֵ������С�ֲ��ù����ֵ
	int strong = 0;
	//Bossר�á�С��ʼ����weak�ģ�Boss���󲿷�ʱ�䲻��weak��
	bool isWeak = true;

	Vec2 guardPoint = Vec2().ZERO;

	//��Ӫ��ͬһ����Ӫ�ĵ�λ���������˴ˣ���ͬ��Ӫ�ĵ�λ�˴�Ϊ�С��ݶ�������Ӫ��1��С����Ӫ��2��
	int camp;


	//��4���ӿ�����Ҫ��¶������
	virtual void wanderAbout() {}//AI������д����ÿ֡�������������
	
	virtual void getHurt(int damage) {}
	virtual void getHurtByWind(int damage){}
	virtual void getHurtByPaw(int damage){}
	virtual void getHurtByCrush(int damage){}

	virtual void getHurtByWater(int damage){}
	virtual void getHurtByFin(int damage){}
		
	virtual void getHeld(){}						//����ץס����צ���ϣ������ӱ���ӥץסһ�������ͣ�ѭ������
	virtual void getThrown(){}						//�����������ӵĶ�����λ�ڰ���У��𾪺�ʧ�أ�ѭ������
	virtual void getSlamDunkOnGround(int damage){}	//���ڵ���Ķ���������и�С�����Ķ�����̱���������������������ж�״̬������һ�Σ���������������״̬��ֱ����������һ��die��dieOnSlamDunk
	virtual void getSlamDunkOnWater(int damage){}	//����ˮ��Ķ���������и�С�����Ķ�����̱���������������������ж�״̬���ǵ�����ˮ�ĵط����һ��ˮ��������һ�Σ���������������״̬��ֱ����������һ��die��dieOnSlamDunk
	virtual void getCollided(int damage){}			//�����ײ���Ķ�������Ҫ��һ��Сλ�ƣ����������߾����ұ�λ��һ�£���������ұ߾������λ��һ�£����߼�������������Զ����ķ���λ��һ�£�������һ�Σ���������������״̬��ֱ����������һ��die��dieOnCollision


	virtual void die() {}							//��ͨ����
	virtual void dieOnSlamDunk() {}					//���������������ɲ��������������������ſſ���ڵ��ϵ����ӡ������Ͷ��ֱ���������������������һ�㣬�������������Ե�Сtrick
	virtual void dieOnCollision(){}					//ʷʫ�����������ɲ�����������������ɱ�ײ�������ӡ��������ײֱ��ײ�����������������һ�㣬�������������Ե�Сtrick

	static GeneralUnit * create(const std::string & filename);

	GeneralUnit();
	~GeneralUnit();
};

