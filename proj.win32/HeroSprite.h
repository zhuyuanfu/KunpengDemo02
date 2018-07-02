#pragma once
#include "cocos2d.h"
#include "GeneralUnit.h"
//#include "Stage1GameplayLayer.h"

USING_NS_CC;
class HeroSprite :	public Sprite
{

public:
	int health = 100;

	int camp = 1;

	float TIME_FOR_ANIMATION_FRAME_INTERVAL = 0.2f;

	int speed_flying_pixel_per_second = 266;
	int speed_swimming_pixel_per_second = 200;

	int SPEED_DURING_ATTACKING_FLYING = 133;

	int DISTANCE_DURING_SCRATCHING = 20;

	int DISTANCE_AIR_DASHING = 200;
	int DISTANCE_AIR_DASHING_BRAKING = 20;
	float TIME_FOR_AIR_DASHING = 0.3f;
	float TIME_FOR_AIR_DASHING_BRAKING = 0.2f;

	int scratchingType = 1;

	//��ͣ����
	Animation * hoveringRightAnimation;
	Animation * hoveringLeftAnimation;

	//��ͨ�ƶ��Ķ���
	Animation * movingUpAnimation;	
	Animation * movingUpRightAnimation;
	Animation * movingRightAnimation;
	Animation * movingDownRightAnimation;
	Animation * movingDownAnimation;
	Animation * movingDownLeftAnimation;
	Animation * movingLeftAnimation;
	Animation * movingUpLeftAnimation;




	//��̶���
	Animation * dashingUpAnimation;
	Animation * dashingUpRightAnimation;
	Animation * dashingRightAnimation;
	Animation * dashingDownRightAnimation;
	Animation * dashingDownAnimation;
	Animation * dashingDownLeftAnimation;
	Animation * dashingLeftAnimation;
	Animation * dashingUpLeftAnimation;

	//���ܶ���
	Animation * blowingWindRightAnimation;
	Animation * blowingWindLeftAnimation;
	Animation * scratchingRightAnimation;
	Animation * scratchingRightAnimation2;
	Animation * scratchingLeftAnimation;
	Animation * scratchingLeftAnimation2;

	Animation * tryCatchAnimation;//��ͼʹ��һ��Ͷ��
	Animation * holdingObjectAnimation;//ץס��Ʒ���ŵĶ���
	Animation * holdingEnemyAnimation;//ץס���˲��ŵĶ���
	Animation * throwingObjectAnimation;//�ӳ���Ʒ�Ķ���
	Animation * throwingEnemyAnimationi;//��С��ʹ��Ͷ���Ķ���

	Animation * throwingBossAnimation;//��Bossʹ��Ͷ���Ķ���

	Animation * windBulletFlyingAnimation;





	Animation * gettingHurtGeneralAnimation;

	RepeatForever * moveRightWithoutAnimationAction;
	RepeatForever * moveLeftWithoutAnimationAction;
	RepeatForever * moveUpWithoutAnimationAction;
	RepeatForever * moveDownWithoutAnimationAction;
	RepeatForever * moveUpRightWithoutAnimationAction;
	RepeatForever * moveDownRightWithoutAnimationAction;
	RepeatForever * moveUpLeftWithoutAnimationAction;
	RepeatForever * moveDownLeftWithoutAnimationAction;


	//���ǲ���������㣬û�е�����������
	bool isBird = true;
	bool isFish = false;

	//���ǵ��˶�״̬����Щ״̬�뼼��ʩ���йء����磬ֻ���ڷ���ʱ����ʩ�ŷ絯
	bool facingRight = true;
	bool facingLeft = false;
	bool flying = true;
	//bool walking = false;//�������ǽ����ڵ��沢���챼�ܵĹ���
	bool swimming = false;

	//�������ڸ��
	bool moving = false;
	bool windAttacking = false;
	bool scratching = false;
	bool pawTryingCatch = false;
	bool pawHolding = false;
	bool pawThrowing = false;
	bool pawThrowingBoss = false;

	//���ǵ�ǰ�ܸ����״̬��
	bool moveableWithoutAnimation = false;
	bool moveable = true;//�������ƶ�
	bool windAttackable = true;//���δ��ռ�ã��ܷ���絯
	bool scratchable = true;//צ��δ��ռ�ã���˺����������ʹ��צ��������Ʒ�����ʱ������Ϊfalse������Ϊfalseʱ��ʹ���˽���Ҳ�޷�������սצ�ӹ���
	bool dashable = true;//�ܷ��̡�
	bool catchable = true;//צ���ܷ�ץ�������������鰲�Ż�����˺��ʱ����Ϊfalse��
	bool throwable = true;//�ܷ�צ���ϵĶ����ӳ����������ǲ���һ�Ķ��á������ǰ����ʹ�ó����絯�������Ϊfalse������Ϊfalseʱ����throw���������ᴥ�����˱����µĶ��������������˴�צ������˳ë���·��������Ķ�����

	bool invincible = false;//�Ƿ��޵С�Ϊ����������峡���������µ��������������޵У�Ϊ�������ˬ������Ͷbossʱ����������Ϊ�޵С�



	bool directionToMoveRight = false;
	bool directionToMoveLeft = false;
	bool directionToMoveUp = false;
	bool directionToMoveDown = false;
	bool directionToMoveUpRight = false;
	bool directionToMoveUpLeft = false;
	bool directionToMoveDownRight = false;
	bool directionToMoveDownLeft = false;

	bool directionToHoldSomething = false;

	int lastDirection = 0;//0����1�J��2����3�K��4����5�L��6����7�I

	bool DirectionToPawhold = false;

	static HeroSprite * create(const std::string & filename);


	//���ڼ��ܣ����Ⱪ¶�������ӿڼ��ɣ����ͨͨ��private����
	void button1Hit();
	void button2Hit();
	void button3Hit();

	void button1Release();
	void button2Release();
	void button3Release();
	

	void scratch();
	void scratchRight();
	void scratchRight2();
	void scratchLeft();
	void scratchLeft2();


	void disableAllAbilities();
	void enableAllAbilities();


	void hover();

	void move();//������ء�����**����һ����ʱ����**����

	void moveWithoutAnimationBrake();

	void moveBrake();

	void moveRight();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveUpRight();
	void moveUpLeft();
	void moveDownRight();
	void moveDownLeft();

	void moveRightWithoutAnimation();
	void moveUpWithoutAnimation();
	void moveDownWithoutAnimation();
	void moveLeftWithoutAnimation();
	void moveUpRightWithoutAnimation();
	void moveUpLeftWithoutAnimation();
	void moveDownRightWithoutAnimation();
	void moveDownLeftWithoutAnimation();


	void moveRightBrake();
	void moveUpBrake();
	void moveDownBrake();
	void moveLeftBrake();
	void moveUpRightBrake();
	void moveUpLeftBrake();
	void moveDownRightBrake();
	void moveDownLeftBrake();

	


	void dash();
	void dashRight();
	void dashUp();
	void dashDown();
	void dashLeft();
	void dashUpRight();
	void dashUpLeft();
	void dashDownRight();
	void dashDownLeft();

	void windAttack();//�������
	void pawAttack();
	void pawHold();//����**����һ����ʱ����**����
	void pawThrowObject();
	void pawThrowEnemy();
	void pawThrowBoss();//�������

	void getHurt();//�������
	void getHurtGeneral();
	void getHurtByThunder();
	void getHurtByFire();
	void getHurtByWater();
	void getHurtByHammer();//������������
	void getHurtByHammer(double direction);//���ɷ���Ϊdirection��0�������ϴ��ɣ�90�������Ҵ��ɣ�180�������´��ɣ�270�������󴵷ɡ�
	void getHurtByWind();

	HeroSprite();
	~HeroSprite();
};

