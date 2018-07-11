#include "Zhurong.h"
#include "Stage1GameplayLayer.h"


Zhurong::Zhurong()
{
	//ף���ƶ���������ʼ���ŵ��������ǰ�������wanderAbout�ĵ���û��Ч����
	this->walkingLeftWhileFacingLeftAnimation = Animation::create();
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_00.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_01.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_02.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_03.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_04.png");
	this->walkingLeftWhileFacingLeftAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->walkingLeftWhileFacingLeftAnimation->setRestoreOriginalFrame(true);
	this->walkingLeftWhileFacingLeftAnimation->retain();

	ValueMap walkingAnimationStartInfo;
	ValueMap walkingAnimationEndInfo;

	walkingAnimationStartInfo["zhurong0"] = Value("zhurong0");
	walkingAnimationEndInfo["zhurong1"] = Value("zhurong1");

	this->walkingLeftWhileFacingLeftAnimation->getFrames().at(0)->setUserInfo(walkingAnimationStartInfo);//�����ĵ�0֡Я������ʼ����������Ϣ
	this->walkingLeftWhileFacingLeftAnimation->getFrames().at(4)->setUserInfo(walkingAnimationEndInfo);//���������һ֡Я������������������Ϣ

	EventListenerCustom * walkingFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, walkingAnimationStartInfo, walkingAnimationEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == walkingAnimationStartInfo){
			this->acceptCall = false;//�ڶ�����ʼ�ĵ�һ֡��ֹ�������wanderAbout()
		}
		if (*userData->userInfo == walkingAnimationEndInfo){
			this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(walkingFrameEventListener, -1);





	this->shootingFireBallWhileFacingLeftAnimation = Animation::create();
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_00.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_01.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_02.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_03.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_04.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_05.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_06.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_07.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_08.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_09.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_10.png");
	this->shootingFireBallWhileFacingLeftAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->shootingFireBallWhileFacingLeftAnimation->setRestoreOriginalFrame(true);
	this->shootingFireBallWhileFacingLeftAnimation->retain();

	ValueMap shootingFireBallStartAnimation;
	ValueMap shootingFireBallLaunchingAnimation;
	ValueMap shootingFireBallEndAnimation;

	shootingFireBallStartAnimation["zhurong2"] = Value("zhurong2");
	shootingFireBallLaunchingAnimation["zhurong3"] = Value("zhurong3");
	shootingFireBallEndAnimation["zhurong4"] = Value("zhurong4");


	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(0)->setUserInfo(shootingFireBallStartAnimation);//�����ĵ�0֡Я������ʼ����������Ϣ
	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(8)->setUserInfo(shootingFireBallLaunchingAnimation);//�����ĵ�8֡Я�����������֡�����Ϣ
	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(10)->setUserInfo(shootingFireBallEndAnimation);//���������һ֡Я������������������Ϣ

	EventListenerCustom * shootingFireBallFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, shootingFireBallStartAnimation, shootingFireBallLaunchingAnimation, shootingFireBallEndAnimation](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == shootingFireBallStartAnimation){
			this->acceptCall = false;//�ڶ�����ʼ�ĵ�0֡��ʼ��ֹ�������wanderAbout()
		}
		
		if (*userData->userInfo == shootingFireBallLaunchingAnimation){
			//����һ���������ַ������ǡ� ���������ķ����ٶ�Ϊ200����/�롣
			Sprite * fireball = Sprite::create("characters/zhurong/fire_ball_00.png");
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			fireball->setPosition(this->getPosition());
			this->getParent()->addChild(fireball);
			int deltax = hero->getPositionX() - fireball->getPositionX();
			int deltay = hero->getPositionY() - fireball->getPositionY();

			double distance = sqrt(pow(deltax, 2) + pow(deltax, 2));
			fireball->runAction(RepeatForever::create(MoveBy::create(distance / 200, Vec2(deltax, deltay))));
			fireball->runAction(RepeatForever::create(Animate::create(this->fireballSpinningAnimation)));

		}
		
		if (*userData->userInfo == shootingFireBallEndAnimation){
			this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(shootingFireBallFrameEventListener, -1);


	//������ת������ÿ������֡���ж�һ���Ƿ�ײ�����ǻ����ˮ�
	this->fireballSpinningAnimation = Animation::create();
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_00.png");
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_01.png");
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_02.png");
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_03.png");
	this->fireballSpinningAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->fireballSpinningAnimation->setRestoreOriginalFrame(true);
	this->fireballSpinningAnimation->retain();


	ValueMap fireballCheckIfHitHeroOrHitWaterInfo;

	fireballCheckIfHitHeroOrHitWaterInfo["zhurong5"] = Value("zhurong5");

	this->fireballSpinningAnimation->getFrames().at(0)->setUserInfo(fireballCheckIfHitHeroOrHitWaterInfo);
	this->fireballSpinningAnimation->getFrames().at(1)->setUserInfo(fireballCheckIfHitHeroOrHitWaterInfo);
	this->fireballSpinningAnimation->getFrames().at(2)->setUserInfo(fireballCheckIfHitHeroOrHitWaterInfo);
	this->fireballSpinningAnimation->getFrames().at(3)->setUserInfo(fireballCheckIfHitHeroOrHitWaterInfo);

	EventListenerCustom * fireBallSpinningFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, fireballCheckIfHitHeroOrHitWaterInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == fireballCheckIfHitHeroOrHitWaterInfo){
			//������������ǵľ������ж��Ƿ���С�������У��������ǵ����˷�����������Ӹ��ڵ����Ƴ�
			Sprite * fireBall = (Sprite *)userData->target; //userData��һ���ṹ�壬�����и���target��Node����Node��Ϊ���ŵ���һ֡������
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			int deltax = fireBall->getPositionX() - hero->getPositionX();
			int deltay = fireBall->getPositionY() - hero->getPositionY();;

			double distance = sqrt(pow(deltax,2)+pow(deltax,2));
			if (distance < (fireBall->getContentSize().width + (hero->getContentSize().width)) * 50 / 100){
				((HeroSprite*)hero)->getHurtGeneral(10);
				fireBall->stopAllActions();
				fireBall->removeFromParent();
			}
		}
		
	});
	_eventDispatcher->addEventListenerWithFixedPriority(fireBallSpinningFrameEventListener, -1);


}


Zhurong::~Zhurong()
{
}

Zhurong * Zhurong::create(const std::string & filename){
	Zhurong * myUnit = new Zhurong();
	if (myUnit && myUnit->initWithFile(filename)){
		myUnit->autorelease();
		return myUnit;
	}
	CC_SAFE_DELETE(myUnit);
	return nullptr;
}




void Zhurong::walkLeftWhileFacingLeft(){
	this->stopAllActions();
	this->runAction(MoveBy::create(this->ANIMATION_FRAME_INTERVAL*100, Vec2(-100,0)));
	this->runAction(Animate::create(this->walkingLeftWhileFacingLeftAnimation));
}

void Zhurong::prepareAndLaunchAFireballWhileFacingLeft(){
	this->stopAllActions();
	this->runAction(Animate::create(this->shootingFireBallWhileFacingLeftAnimation));
}


void Zhurong::idle(){

}

/**
 * �����ܱ��˵���ʱ������������£�ֱ�ӷ���
 * ���ܱ��˵���ʱ���ö���һ���������һ������
 */
void Zhurong::wanderAbout(){
	if (this->acceptCall){
		//do something like randomly calling some method here if this object accepts calls.
		srand((unsigned)time(NULL));
		int nextMovement = rand() % 11;

		if (nextMovement == 1){
			this->walkLeftWhileFacingLeft();
		}
		else if (nextMovement == 0){
			this->prepareAndLaunchAFireballWhileFacingLeft(); 
		}

	}
	else{
		return;
	}
}

void Zhurong::getHurt(int damage){

}
void Zhurong::getHurtByWind(int damage){

}
void Zhurong::getHurtByPaw(int damage){

}
void Zhurong::getHurtByCrush(int damage){

}

void Zhurong::getHurtByWater(int damage){

}
void Zhurong::getHurtByFin(int damage){

}

void Zhurong::die(){

}
