#pragma once
#include "cocos2d.h"
USING_NS_CC;
class GeneralUnit :public Sprite
{
public:

	//Ѫ��
	int health;


	//��Ӫ��ͬһ����Ӫ�ĵ�λ���������˴ˣ���ͬ��Ӫ�ĵ�λ�˴�Ϊ�С��ݶ�������Ӫ��1��С����Ӫ��2��
	int camp;


	//��4���ӿ�����Ҫ��¶������
	virtual void wanderAbout() {}//AI������д����ÿ֡�������������
	
	virtual void getHurt(int damage) {}
	void getHurtByWind(int damage);//����������
	virtual void getHurtByPaw(int damage){}
	void getHurtByCrush(int damage);

	void getHurtByWater(int damage);
	void getHurtByFin(int damage);

	virtual void die() {}

	static GeneralUnit * create(const std::string & filename);

	GeneralUnit();
	~GeneralUnit();
};

