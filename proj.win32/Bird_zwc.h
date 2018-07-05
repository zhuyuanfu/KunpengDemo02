#ifndef __Bird_zwc_H__
#define __Bird_zwc_H__
#include "GeneralUnit.h"
class Bird_zwc :
	public GeneralUnit
{
public:

	//ɢ������
	Animation * wanderAboutAnimation;

	Bird_zwc();
	~Bird_zwc();
	static Bird_zwc * create(const std::string & filename);

	void wanderAbout();//AI������д����ÿ֡�������������
	void update(float dt);
	void lockBirdWithinLandscape();

	void getHurtByWind(int damage);//����������
	void getHurtByPaw(int damage);
	void getHurtByCrush(int damage);

	void getHurtByWater(int damage);
	void getHurtByFin(int damage);

	void die();
};
#endif
