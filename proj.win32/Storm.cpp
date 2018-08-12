#include "Storm.h"
//Nastiest designs ever!
#include "HeroSprite.h"
#include "Stage1GameplayLayer.h"
#include "AudioManager.h"
//Nastiest designs ever!
#define upY 0
#define downY 500
Storm::Storm()
{
	this->hoveringAnimation = Animation::create();
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/longjuanf_0.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/longjuanf_1.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/longjuanf_2.png");
	this->hoveringAnimation->addSpriteFrameWithFileName("landscapes/longjuanf_3.png");
	this->hoveringAnimation->setDelayPerUnit(0.1f);  // ���ö���֡��
	this->hoveringAnimation->setRestoreOriginalFrame(true);// ���ö���������Ϻ��Ƿ�ص���һ֡
	this->hoveringAnimation->retain();
}


Storm::~Storm()
{
}



Storm * Storm::create(const std::string &filename){
	Storm *storm = new Storm();

	if (storm && storm->initWithFile(filename)){
		storm->autorelease();
		return storm;
	}
	CC_SAFE_DELETE(storm);
	return nullptr;
}


void Storm::onEnter(){
	//this->setPositionY(this->getPositionY()+111);
	//this->schedule(schedule_selector(Storm::myUpdate));
	Sprite::onEnter();
}

void Storm::myUpdate(float dt){
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


void Storm::wanderAbout(){
	myUpdate(0);
}

void Storm::setPlace(int x, bool inTheSky){
	this->setPosition(x, inTheSky ? upY : downY);
}

void Storm::Lockhoving(){
	if (lock == 0){
		lock = 1;
		auto an = Animate::create(this->hoveringAnimation);
		this->runAction(Sequence::create(an, an, nullptr));
		auto delayTime = DelayTime::create(0.5f);
		auto func = CallFunc::create([this](){ lock = 0; });
		auto seq = Sequence::create(delayTime, func, nullptr);
		this->runAction(seq);
	}
}