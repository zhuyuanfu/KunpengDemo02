#include "Bird_zwc.h"
#include<iostream>
#include<math.h>
#include "Stage1GameplayLayer.h"
#include "Bullet.h"
#include "Stage1Scene.h"
using namespace std;
# define hitThreshold 150 //�����̵ľ�����ֵ
# define hurtThreshold 50 //���˵ľ�����ֵ
# define hitSpeed 20 //��̵��ٶ�
# define moveOutside 20 //�������ͷ����ֵ

Bird_zwc::Bird_zwc()
{
	//auto sprite = cocos2d::Sprite::create();
	//sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
	//sprite->setPosition(300, 200);
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-0left.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-1left.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-2left.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-3.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("characters/monster/fly-4.png");
	this->hoveringAnimation->setDelayPerUnit(0.5f);  // ���ö���֡��
	this->hoveringAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->hoveringAnimation->retain();

	this->leftAnimation = Animation::create();
	this->leftAnimation->addSpriteFrameWithFileName("characters/monster/fly-0left.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/monster/fly-1left.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/monster/fly-2left.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/monster/fly-3left.png");
	this->leftAnimation->addSpriteFrameWithFileName("characters/monster/fly-4left.png");
	this->leftAnimation->setDelayPerUnit(0.5f);  // ���ö���֡��
	this->leftAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->leftAnimation->retain();

	this->rightAnimation = Animation::create();
	this->rightAnimation->addSpriteFrameWithFileName("characters/monster/fly-0.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/monster/fly-1.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/monster/fly-2.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/monster/fly-3.png");
	this->rightAnimation->addSpriteFrameWithFileName("characters/monster/fly-4.png");
	this->rightAnimation->setDelayPerUnit(0.5f);  // ���ö���֡��
	this->rightAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->rightAnimation->retain();

	this->leftturnAnimation = Animation::create();
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/monster/fly-2.png");
	this->leftturnAnimation->addSpriteFrameWithFileName("characters/monster/fly-2left.png");
	//this->leftturnAnimation->addSpriteFrameWithFileName("characters/monster/leftturn3.png");
	this->leftturnAnimation->setDelayPerUnit(0.5f);  // ���ö���֡��
	this->leftturnAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->leftturnAnimation->retain();

	this->rightturnAnimation = Animation::create();
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/monster/fly-2left.png");
	this->rightturnAnimation->addSpriteFrameWithFileName("characters/monster/fly-2.png");
	//this->rightturnAnimation->addSpriteFrameWithFileName("characters/monster/rightturn3.png");
	this->rightturnAnimation->setDelayPerUnit(0.5f);  // ���ö���֡��
	this->rightturnAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->rightturnAnimation->retain();

	this->lefthurtAnimation = Animation::create();
	//this->lefthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-0left.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-1left.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-2left.png");
	this->lefthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-3left.png");
	this->lefthurtAnimation->setDelayPerUnit(0.2f);  // ���ö���֡��
	this->lefthurtAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->lefthurtAnimation->retain();




	this->righthurtAnimation = Animation::create();
	//this->righthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-0.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-1.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-2.png");
	this->righthurtAnimation->addSpriteFrameWithFileName("characters/monster/hurt-3.png");
	this->righthurtAnimation->setDelayPerUnit(0.2f);  // ���ö���֡��
	this->righthurtAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->righthurtAnimation->retain();

	this->leftdieAnimation = Animation::create();
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/monster/die-0left.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/monster/die-1left.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/monster/die-2left.png");
	this->leftdieAnimation->addSpriteFrameWithFileName("characters/monster/die-3left.png");
	this->leftdieAnimation->setDelayPerUnit(0.2f);  // ���ö���֡��
	this->leftdieAnimation->setRestoreOriginalFrame(false);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->leftdieAnimation->retain();

	this->rightdieAnimation = Animation::create();
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/monster/die-0.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/monster/die-1.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/monster/die-2.png");
	this->rightdieAnimation->addSpriteFrameWithFileName("characters/monster/die-3.png");
	this->rightdieAnimation->setDelayPerUnit(0.2f);  // ���ö���֡��
	this->rightdieAnimation->setRestoreOriginalFrame(false);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->rightdieAnimation->retain();

	this->leftfightAnimation = Animation::create();
	//this->leftfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-0left.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-1left.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-2left.png");
	this->leftfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-3left.png");
	this->leftfightAnimation->setDelayPerUnit(0.5f);  // ���ö���֡��
	this->leftfightAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->leftfightAnimation->retain();

	this->rightfightAnimation = Animation::create();
	//this->rightfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-0.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-1.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-2.png");
	this->rightfightAnimation->addSpriteFrameWithFileName("characters/monster/hit-3.png");
	this->rightfightAnimation->setDelayPerUnit(0.5f);  // ���ö���֡��
	this->rightfightAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->rightfightAnimation->retain();

	//auto action = Animate::create(hoveringAnimation);
	//this->runAction(RepeatForever::create(action));
	this->runAction(Animate::create(this->hoveringAnimation));
	//this->runAction(cocos2d::RepeatForever::create(action));
	
	
	//addChild(sprite);
	//this->addChild(sprite);
	//this->runAction(Animate::create(hoveringAnimation));

}

Bird_zwc * Bird_zwc::create(const std::string &filename){
	Bird_zwc *myEnemy = new Bird_zwc();
	if (myEnemy &&myEnemy->initWithFile(filename)){
		myEnemy->autorelease();
		return myEnemy;
	}
	CC_SAFE_DELETE(myEnemy);
	
	return nullptr;
}

void Bird_zwc::update(float dt){
	
}

void Bird_zwc::wanderAbout(){

	auto temp = (Stage1GameplayLayer*)this->getParent();
	auto realHero = temp->kunpeng;

	Point hero = realHero->getPosition();
	Point bird = this->getPosition();

	float distance = sqrt(pow(hero.x - bird.x, 2) + pow(hero.y - bird.y, 2));
	float x_dis = hero.x - bird.x;
	float y_dis = hero.y - bird.y;

	if (pauseflag == 0 && distance < battledistance){ //չ������

		distance = sqrt(pow(hero.x - bird.x, 2) + pow(hero.y - bird.y, 2));

		x_dis = hero.x - bird.x;
		y_dis = hero.y - bird.y;

		x_change = bird_step*(cos(atan(x_dis / y_dis)));
		y_change = bird_step*(sin(atan(x_dis / y_dis)));
		float random_scala = (rand() % 201 - 100) / 100.0;  //�Ȼ�ã�-1,1���İٷ�λ�����С��

		if (x_dis >= 0)//С�������ǵ���
		{
			x_scope = 1;
			Lockright();
		}
		else
		{
			x_scope = -1;
			Lockleft();

		}

		if (y_dis >= 0)
			y_scope = 1;
		else
			y_scope = -1;

		if (realHero->isBird){
			this->runAction(MoveBy::create(2.0f, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
		}
		else{
			this->runAction(MoveBy::create(2.0f, Vec2(x_scope * abs(x_change), random_scala * abs(y_change))));//���������ˮ��С�����Ͽ�����
		}

		if (distance < hitThreshold){

			//if (((int)rand_0_1() * 3) == 0){//3��֮һ�ĸ��ʽ��г�̹���
				//this->runAction(MoveBy::create(distance / hitSpeed, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
				//this->runAction(MoveBy::create(distance / hitSpeed, Vec2(x_dis/2, y_dis/2)));
				this->runAction(MoveBy::create(1.0f, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));
			//}

			if (distance < hurtThreshold){
				temp->kunpeng->getHurtGeneral(10);
			}

		}

		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		cout << "ATTACK!!!heroPointX:" << hero.x << "     heroPointY:" << hero.y << endl;
		cout << "ATTACK!!!birdPointX:" << bird.x << "     birdPointY:" << bird.y << endl;
		cout << "ATTACK!!!x_scope * abs(x_change):" << x_scope * abs(x_change) << "     y_scope * abs(y_change):" << y_scope * abs(y_change) << endl;
	}

	else if (pauseflag == 0 && distance >= battledistance){//����������Χ�������������㸽��

		//auto temp = (Stage1GameplayLayer*)this->getParent();
		//Point hero = temp->kunpeng->getPosition();
	
		distance = sqrt(pow(hero.x - guardPoint.x, 2) + pow(hero.y - guardPoint.y, 2));

		x_dis = guardPoint.x - bird.x;
		y_dis = guardPoint.y - bird.y;

		x_change = 10*(cos(atan(x_dis / y_dis)));
		y_change = 5*(sin(atan(x_dis / y_dis)));


			if (x_dis >= 0)//С�������������
			{
				x_scope = 1;
				Lockright();
			}
			else
			{
				x_scope = -1;
				Lockleft();

			}

			if (y_dis >= 0)//С�����������·�
				y_scope = 1;
			else
				y_scope = -1;

			if (x_dis != 0 && y_dis != 0)
			this->runAction(MoveBy::create(2.0f, Vec2(x_scope * abs(x_change), y_scope * abs(y_change))));

	}

	cout << "KEEP!!!heroPointX:" << hero.x << "     heroPointY:" << hero.y << endl;
	cout << "KEEP!!!birdPointX:" << bird.x << "     birdPointY:" << bird.y << endl;
	cout << "KEEP!!!guardPointX:" << guardPoint.x << "       guardPointY:" << guardPoint.y << endl;
	cout << "KEEP!!!x_scope * abs(x_change):" << x_scope * abs(x_change) << "     y_scope * abs(y_change):" << y_scope * abs(y_change) << endl;

	lockBirdWithinLandscape();

}


void Bird_zwc::f(){
	lock = 0;
}
void Bird_zwc::Lockright(){
	if (lock == 0){
		lock = 1;
		this->runAction(Animate::create(this->rightAnimation));
		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this -> runAction(seq);
	}
	
}

void Bird_zwc::Lockhurt(Animation* ani){
	if (lock == 0){
		lock = 1;
		this->runAction(Animate::create(ani));
		auto delayTime = DelayTime::create(1.5f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}

}

void Bird_zwc::Lockleft(){
	if (lock == 0){
		lock = 1;
		this->runAction(Animate::create(this->leftAnimation));
		auto delayTime = DelayTime::create(2.0f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}
}





void Bird_zwc::lockBirdWithinLandscape(){

	Stage1Scene * scene = (Stage1Scene *)this->getParent()->getParent();
		Size visibleSize = Director::getInstance()->getVisibleSize();

		int heroPositionInCameraX = this->getParent()->getPositionX() + this->getPositionX();
		int heroPositionInCameraY = this->getParent()->getPositionY() + this->getPositionY();

		if (heroPositionInCameraY > visibleSize.height + moveOutside){
			int difference = heroPositionInCameraY - visibleSize.height - moveOutside;
			this->setPositionY(this->getPositionY() - difference);
		}
		if (heroPositionInCameraY < 0 - moveOutside){
			int difference = heroPositionInCameraY + moveOutside;
			this->setPositionY(this->getPositionY() - difference);
		}

		//��ֹ����ˮ
		int backgroundDownBoundary = ((Stage1GameplayLayer*)this->getParent())->background->getPositionY() + 10;	
		if (this->getPositionY() < backgroundDownBoundary){
			this->setPositionY(backgroundDownBoundary);
		}

}


void Bird_zwc::getHurtByWind(int damage){
	//this->getHurt(damage);
	getHeld();//forTest
	//getThrown();//forTest
}

void Bird_zwc::getHurtByPaw(int damage){      //yyhyyh
	this->getHurt(damage);
}

void Bird_zwc::getHurtByCrush(int damage){
	this->getHurt(damage);
}

void Bird_zwc::getHurt(int damage){
	this->stopAllActions();
	pauseflag = 1;//1����������ͣ

	auto temp = (Stage1GameplayLayer*)this->getParent();
	Point hero = temp->kunpeng->getPosition();
	Point bird = this->getPosition();

	float x_dis = hero.x - bird.x;
	float y_dis = hero.y - bird.y;

	health = health - damage;
	if (health > 0)
	{
		if (x_dis < 0) {
			//С�ֻ������ơ����˶���
			this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(this->getContentSize().width / 2, 0)), MoveBy::create(0.5f, Vec2(this->getContentSize().width / 4, 0)), nullptr));
			this->runAction(Animate::create(lefthurtAnimation));
		}
		else{
			//С�ֻ������ơ����˶���
			this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(-this->getContentSize().width / 2, 0)), MoveBy::create(0.5f, Vec2(-this->getContentSize().width / 4, 0)), nullptr));
			this->runAction(Animate::create(righthurtAnimation));
		}

		auto delayTime = DelayTime::create(1.f);
		auto func = CallFunc::create([this](){pauseflag = 0; f(); wanderAbout(); });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);

	}

	else{
		die(x_dis < 0 ? true : false);
	}
}


void Bird_zwc::getHurtByWater(int damage){
	this->getHurt(damage);
}

void Bird_zwc::getHurtByFin(int damage){
	this->getHurt(damage);
}

void Bird_zwc::setPlace(int x, int y){//���ó�����&������
	this->setPosition(x, y>=0 ? y : -y);//��ֹ�����������ˮ��
	this->guardPoint = Vec2(x, y>=0 ? y : -y);//������
}

void Bird_zwc::die(bool facingLeft) {
	this->stopAllActions();
	dieflag = 1;

	if (facingLeft){
		this->runAction(Animate::create(leftdieAnimation));
	}
	else
	{
		this->runAction(Animate::create(rightdieAnimation));
	}

	auto fallingDown = MoveTo::create(1.0f, Vec2(this->getPosition().x , 0));//�������䵽ˮ��Ķ���
	auto delayTime = DelayTime::create(1.0f);
	auto func = CallFunc::create([this](){
	auto temp = (Stage1GameplayLayer*)this->getParent();
	temp->removeChild(this);
	temp->enemyList.eraseObject(this); });
	auto seq = Sequence::create(fallingDown,delayTime, func, nullptr);
	this->runAction(seq);
}

		void  Bird_zwc::getHeld(){//����ץס����צ���ϣ������ӱ���ӥץסһ�������ͣ�ѭ������
			this->stopAllActions();
			pauseflag = 1;//1����������ͣ
			this->runAction((Animate::create(leftAnimation)));
			
			auto lefthurtAnimation2 = lefthurtAnimation->clone();
			lefthurtAnimation2->setDelayPerUnit(0.3f);
			lefthurtAnimation2->setRestoreOriginalFrame(false);
			auto hurt = Animate::create(lefthurtAnimation2);//���˶���
			
			auto delayTime = DelayTime::create(2.f);
			auto func = CallFunc::create([this](){ pauseflag = 0; f(); wanderAbout(); });
			auto seq = Sequence::create(delayTime, func, nullptr);
			this->runAction(seq);
			//this->runAction(Animate::create(this->leftAnimation));
		}						
		
		void Bird_zwc::getThrown(){//�����������ӵĶ�����λ�ڰ���У��𾪺�ʧ�أ�ѭ������
			this->stopAllActions();
			pauseflag = 1;//1����������ͣ

			auto fallingDown = MoveTo::create(1.0f, Vec2(this->getPosition().x, -10));//���䵽ˮ��Ķ���
			

			auto lefthurtAnimation2 = lefthurtAnimation->clone();
			lefthurtAnimation2->setDelayPerUnit(0.1f);
			//lefthurtAnimation2->setLoops(5);
			lefthurtAnimation2->setRestoreOriginalFrame(false);
			auto left = Animate::create(lefthurtAnimation2);//�𾪺�ʧ�ض���

			auto s = Spawn::create(fallingDown, left, nullptr);
			auto delayTime = DelayTime::create(2.f);
			auto func = CallFunc::create([this](){ pauseflag = 0; f(); wanderAbout(); });
			auto seq = Sequence::create(s,delayTime, func, nullptr);
			this->runAction(seq);


		}						
		
		void Bird_zwc::getSlamDunkOnGround(int damage){//���ڵ���Ķ���������и�С�����Ķ�����̱���������������������ж�״̬������һ�Σ���������������״̬��ֱ����������һ��die��dieOnSlamDunk
			return;
		}	

		void Bird_zwc::getSlamDunkOnWater(int damage){//����ˮ��Ķ���������и�С�����Ķ�����̱���������������������ж�״̬���ǵ�����ˮ�ĵط����һ��ˮ��������һ�Σ���������������״̬��ֱ����������һ��die��dieOnSlamDunk
			getHurt(damage);
		}

		void Bird_zwc::getCollided(int damage){//�����ײ���Ķ�������Ҫ��һ��Сλ�ƣ����������߾����ұ�λ��һ�£���������ұ߾������λ��һ�£����߼�������������Զ����ķ���λ��һ�£�������һ�Σ���������������״̬��ֱ����������һ��die��dieOnCollision
			return;
		}

		void Bird_zwc::dieOnSlamDunk(){ return; }			//���������������ɲ��������������������ſſ���ڵ��ϵ����ӡ������Ͷ��ֱ���������������������һ�㣬�������������Ե�Сtrick
		void Bird_zwc::dieOnCollision(){ return; }			//ʷʫ�����������ɲ�����������������ɱ�ײ�������ӡ��������ײֱ��ײ�����������������һ�㣬�������������Ե�Сtrick


Bird_zwc::~Bird_zwc()
{
}
