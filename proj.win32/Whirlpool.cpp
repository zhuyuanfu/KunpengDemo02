#include "Whirlpool.h"
//Nastiest designs ever!
#include "HeroSprite.h"
#include "Stage1GameplayLayer.h"
#include "AudioManager.h"
//Nastiest designs ever!
#define upY 200
#define downY -500
Whirlpool::Whirlpool()
{
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/xuanwo_0.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/xuanwo_1.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/xuanwo_2.png");
	this->hoveringAnimation->setDelayPerUnit(0.1f);  // ���ö���֡��
	this->hoveringAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->hoveringAnimation->retain();
}


Whirlpool::~Whirlpool()
{
}



Whirlpool * Whirlpool::create(const std::string &filename){
	Whirlpool *whirlpool = new Whirlpool();

	if (whirlpool && whirlpool->initWithFile(filename)){
		whirlpool->autorelease();
		return whirlpool;
	}
	CC_SAFE_DELETE(whirlpool);
	return nullptr;
}


void Whirlpool::onEnter(){
	//this->setPositionY(this->getPositionY()+111);
	//this->schedule(schedule_selector(Whirlpool::myUpdate));
	Sprite::onEnter();
}

void Whirlpool::myUpdate(float dt){
	//���Ŷ���
	//auto action = Animate::create(hoveringAnimation);
	//this->runAction(RepeatForever::create(action));
	//this->runAction(Animate::create(this->hoveringAnimation));
	Lockhoving();

	//������ǿ���
	auto tempGameplayLayer = (Stage1GameplayLayer*)this->getParent();
	auto hero = (HeroSprite*)tempGameplayLayer->kunpeng;
	if (this->getBoundingBox().intersectsRect(hero->getBoundingBox())){
		hero->getHurtGeneral(10);
	}
}


void Whirlpool::wanderAbout(){
	myUpdate(0);
}

void Whirlpool::setPlace(int x, bool inTheSky){
	this->setPosition(x, inTheSky ? upY : downY);
}

void Whirlpool::Lockhoving(){
	if (lock == 0){
		lock = 1;
		auto an = Animate::create(this->hoveringAnimation);
		this->runAction(Sequence::create(an, an, nullptr));
		auto delayTime = DelayTime::create(0.4f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}
}