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
	void wanderAbout();//AI������д����ÿ֡�������������
	
	void getHurtByWind(int damage);//����������
	void getHurtByPaw(int damage);
	void getHurtByCrush(int damage);

	void getHurtByWater(int damage);
	void getHurtByFin(int damage);

	void die();

	static GeneralUnit * create(const std::string & filename);

	GeneralUnit();
	~GeneralUnit();
};

