#ifndef __Bird_zwc_H__
#define __Bird_zwc_H__
#include "GeneralUnit.h"
class Bird_zwc :
	public GeneralUnit
{
public:
	Animation * hoveringAnimation;
	Animation * leftAnimation;
	Animation * rightAnimation;
	Animation * leftturnAnimation; //��ת��
	Animation * rightturnAnimation;//��ת��
	Animation * lefthurtAnimation;
	Animation * righthurtAnimation;
	Animation * leftdieAnimation;
	Animation * rightdieAnimation;
	Animation * leftfightAnimation;
	Animation * rightfightAnimation;

	float TIME_FOR_ANIMATION_FRAME_INTERVAL = 0.01f;
	float battledistance = 450;//ս����Χ
	int change = 10;//�ǻ���Χ

	Bird_zwc();
	~Bird_zwc();
	int health = 100;
	int flag = 0;
	int dir = 0;
	int lock = 0;

	int dieflag = 0;
	int pauseflag = 0;

	int x_scope, y_scope;
	float x_change, y_change;
	int bird_step = 8;
	static Bird_zwc * create(const std::string & filename);
	void update(float dt);
	void wanderAbout();
	void lockBirdWithinLandscape();

	//��
	void Lockright();
	void Lockleft();
	void Lockturnright(int type);
	void Lockturnleft(int type);
	void Lockhurt(Animation* ani);
	void f();

	void getHurt(int damage);
	void getHurtByWind(int damage);
	void getHurtByPaw(int damage);
	void getHurtByCrush(int damage);
	void getHurtByWater(int damage);
	void getHurtByFin(int damage);

	void setPlace(int x, int y);

	//new

	void getHeld();						//����ץס����צ���ϣ������ӱ���ӥץסһ�������ͣ�ѭ������
	void getThrown();					//�����������ӵĶ�����λ�ڰ���У��𾪺�ʧ�أ�ѭ������
	void getSlamDunkOnGround(int damage);	//���ڵ���Ķ���������и�С�����Ķ�����̱���������������������ж�״̬������һ�Σ���������������״̬��ֱ����������һ��die��dieOnSlamDunk
	void getSlamDunkOnWater(int damage);	//����ˮ��Ķ���������и�С�����Ķ�����̱���������������������ж�״̬���ǵ�����ˮ�ĵط����һ��ˮ��������һ�Σ���������������״̬��ֱ����������һ��die��dieOnSlamDunk
	void getCollided(int damage);		//�����ײ���Ķ�������Ҫ��һ��Сλ�ƣ����������߾����ұ�λ��һ�£���������ұ߾������λ��һ�£����߼�������������Զ����ķ���λ��һ�£�������һ�Σ���������������״̬��ֱ����������һ��die��dieOnCollision

	void die(bool facingLeft);		//��ͨ����
	void dieOnSlamDunk();			//���������������ɲ��������������������ſſ���ڵ��ϵ����ӡ������Ͷ��ֱ���������������������һ�㣬�������������Ե�Сtrick
	void dieOnCollision();			//ʷʫ�����������ɲ�����������������ɱ�ײ�������ӡ��������ײֱ��ײ�����������������һ�㣬�������������Ե�Сtrick

};
#endif
