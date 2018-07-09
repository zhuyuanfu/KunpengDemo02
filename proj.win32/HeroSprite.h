//���ڱ���ɫ�����Ӵ󣬿������ճ־ã������˼ά�ͽ����˼ά����һ�����ϣ���˳����������������������Ĵ�ǲ�һ�µ����󣬺�����������������Ĵ�ǲ�һ�µ��������ʵ���ҿ��е���=������=�bird=peng��fish=kun��
//֣��������#define �� ��
//֣��������#define �� ��
//֣��������#define bird peng
//֣��������#define fish kun

#pragma once
#include "cocos2d.h"
#include "GeneralUnit.h"
#include "WindBullet.h"
#include "WaterBullet.h"

USING_NS_CC;
class HeroSprite :	public Sprite
{

public:


	//ʮ���絯�Ͷ�Ӧ�ı�ըЧ��
	const int NUM_OF_WIND_BULLETS = 10;
	(WindBullet *) windBullets[10];
	int launchedWindBulletCount = 0;

	const int NUM_OF_WIND_BULLET_EXPLOSIONS = 10;
	(Sprite *) windBulletExplosions[10];
	int windBulletExplosionCount = 0;

	//ʮ��ˮ���Ͷ�Ӧ�ı�ըЧ��
	const int NUM_OF_WATER_BULLETS = 10;
	(WaterBullet *)waterBullets[10];
	int launchedWaterBulletCount = 0;

	const int NUM_OF_WATER_BULLET_EXPLOSIONS = 10;
	(Sprite *) waterBulletExplosions[10];
	int waterBulletExplosionCount = 0;


	int health = 100;

	int camp = 1;


	int DAMAGE_WIND = 15;

	int DAMAGE_SCRATCH = 50;

	int DAMAGE_VORTEX = 20;

	int DAMAGE_FIN = 40;

	int DAMAGE_CRUSH = 100;

	float TIME_FOR_ANIMATION_FRAME_INTERVAL = 0.1f;

	int SPEED_FLYING_PIXEL_PER_SECOND = 266;
	int SPEED_SWIMMING_PIXEL_PER_SECOND = 166;

	int SPEED_DURING_ATTACKING_FLYING = 133;

	int DISTANCE_DURING_SCRATCHING = 20;

	int DISTANCE_AIR_DASHING = 200;
	int DISTANCE_AIR_DASHING_BRAKING = 20;
	int DISTANCE_WATER_DASHING = 120;
	int DISTANCE_WATER_DASHING_BRAKING = 60;

	float TIME_FOR_AIR_DASHING = 0.3f;
	float TIME_FOR_AIR_DASHING_BRAKING = 0.2f;
	float TIME_FOR_WATER_DASHING = 0.2f;
	float TIME_FOR_WATER_DASHING_BRAKING = 0.3f;

	int scratchingType = 1;
	int finAttackingType = 1;

	//����ͣ����
	Animation * hoveringRightAnimation;
	Animation * hoveringLeftAnimation;

	//����ͨ�ƶ��Ķ���
	Animation * movingUpAnimation;
	Animation * movingUpRightAnimation;
	Animation * movingRightAnimation;
	Animation * movingDownRightAnimation;
	Animation * movingDownAnimation;
	Animation * movingDownLeftAnimation;
	Animation * movingLeftAnimation;
	Animation * movingUpLeftAnimation;

	//����ͣ�Ķ���
	Animation * hoveringRightAnimation_kun;
	Animation * hoveringLeftAnimation_kun;

	//����ͨ�ƶ��Ķ���
	Animation * movingUpRightAnimation_kun;
	Animation * movingRightAnimation_kun;
	Animation * movingDownRightAnimation_kun;
	Animation * movingDownLeftAnimation_kun;
	Animation * movingLeftAnimation_kun;
	Animation * movingUpLeftAnimation_kun;


	//���̶���
	Animation * dashingUpAnimation;
	Animation * dashingUpRightAnimation;
	Animation * dashingRightAnimation;
	Animation * dashingDownRightAnimation;
	Animation * dashingDownAnimation;
	Animation * dashingDownLeftAnimation;
	Animation * dashingLeftAnimation;
	Animation * dashingUpLeftAnimation;

	//���̶���
	Animation * dashingUpAnimation_kun;
	Animation * dashingUpRightAnimation_kun;
	Animation * dashingRightAnimation_kun;
	Animation * dashingDownRightAnimation_kun;
	Animation * dashingDownAnimation_kun;
	Animation * dashingDownLeftAnimation_kun;
	Animation * dashingLeftAnimation_kun;
	Animation * dashingUpLeftAnimation_kun;

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

	//�㼼�ܶ���
	Animation * blowingVortexRightAnimation;
	Animation * blowingVortexLeftAnimation;
	Animation * finAttackRightAnimation;
	Animation * finAttackRightAnimation2;
	Animation * finAttackLeftAnimation;
	Animation * finAttackLeftAnimation2;

	Animation * fallingFromSkyRightAnimation;//�ӿ��е���ˮ�еĹ��̶��������Լ����ڿ��е���ʱ����������ʱÿʱÿ�̶�Ҫ�ж��Ƿ���ˮ�������Ҫ��������ѭ��������ÿ֡���ж��Ƿ���ˮ������ʱֻ�ܱ���Ϊ�����ˮ�ݡ�
	Animation * fallingFromSkyLeftAnimation;//�ӿ��е���ˮ�еĹ��̶��������Լ����ڿ��е���ʱ����������ʱÿʱÿ�̶�Ҫ�ж��Ƿ���ˮ�������Ҫ��������ѭ��������ÿ֡���ж��Ƿ���ˮ������ʱֻ�ܱ���Ϊ�����ˮ�ݡ�
	Animation * enteringIntoWaterRightAnimation;//��ˮ��������һ֡��ʼ����ȫ���������ŵ�һ��enableȫ������������з������move_kun�����һ֡ת��hover_kun��
	Animation * enteringIntoWaterLeftAnimation;//��ˮ��������һ֡��ʼ����ȫ���������ŵ�һ��enableȫ������������з������move_kun�����һ֡ת��hover_kun��

	//���ǵ���ʽ��Ч
	Animation * windBulletFlyingAnimation;
	Animation * waterBulletMarchingAnimation;
	
	Animation * windBulletExplosionAnimation;
	Animation * waterBulletExplosionAnimation;


	Animation * TransformingFromBirdToFishAnimation;
	Animation * TransformingFromFishToBirdAnimation;

	Animation * waterSplashingAnimation_big;
	Animation * waterSplashingAnimation_small;

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

	bool inTheAir = true;
	//bool walking = false;//�������ǽ����ڵ��沢���챼�ܵĹ���
	bool inTheWater = false;

	//�������ڸ��
	bool hovering = true;
	bool moving = false;
	bool dashing = false;
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
	bool spittable = false;//�ܷ��¿�ˮ��
	bool vortexAttackable = true;

	//�߼��Ͻ��������߲���ͬʱΪ�档
	bool transformable_BirdToFish = true;
	bool transformable_FishToBird = true;//Ϊ������ԣ���ʱ�����߾���Ϊ�档


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
	




	void disableAllAbilities();
	void enableAllAbilities();


	void hover();
	void hover_kun();

	void transformFromBirdToFish();
	void transformFromFishToBird();


	void move_forBothShapes();
	void move();
	void move_kun();

	void moveWithoutAnimationBrake();

	void moveBrake();
	void moveBrake_kun();

	void moveRight();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveUpRight();
	void moveUpLeft();
	void moveDownRight();
	void moveDownLeft();

	void moveRight_kun();
	void moveUp_kun();
	void moveDown_kun();
	void moveLeft_kun();
	void moveUpRight_kun();
	void moveUpLeft_kun();
	void moveDownRight_kun();
	void moveDownLeft_kun();

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

	


	void dash_forBothShapes();

	void dash();
	void dashRight();
	void dashUp();
	void dashDown();
	void dashLeft();
	void dashUpRight();
	void dashUpLeft();
	void dashDownRight();
	void dashDownLeft();

	void dash_kun();
	void dashRight_kun();
	void dashUp_kun();
	void dashDown_kun();
	void dashLeft_kun();
	void dashUpRight_kun();
	void dashUpLeft_kun();
	void dashDownRight_kun();
	void dashDownLeft_kun();


	void scratch();
	void scratchRight();
	void scratchRight2();
	void scratchLeft();
	void scratchLeft2();

	void finAttack();
	void finAttackRight();
	void finAttackRight2();
	void finAttackLeft();
	void finAttackLeft2();



	void windAttack();//�������
	void pawAttack();
	void pawHold();//����**����һ����ʱ����**����
	void pawThrowObject();
	void pawThrowEnemy();
	void pawThrowBoss();//�������

	void vortexAttack();

	void fallFromSky_kun();
	void enterWater_kun();


	void getHurt();//�������
	void getHurtGeneral();
	void getHurtByThunder();//���׵���У��Ǽ���˸+ԭ�����
	void getHurtByFire();//��������У���ë�ս���˸+����
	void getHurtByWater();//��ˮ�����У���������+����
	void getHurtByHammer();//�����������ɣ������������һ���ָ��ȶ�
	void getHurtByHammer(double direction);//���ɷ���Ϊdirection��0�������ϴ��ɣ�90�������Ҵ��ɣ�180�������´��ɣ�270�������󴵷ɡ�
	void getHurtByWind();//��������У���ë������

	HeroSprite();
	~HeroSprite();
};

