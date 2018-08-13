#pragma once
#include "Stage1GameplayLayer.h"
#include "HeroSprite.h"
#include "Stage1Scene.h"
#include "EnemyFish.h"
#include "Bullet.h"
#include "Bird_zwc.h"
#include "Rock.h"
#include "Storm.h"
#include "ThunderCloud.h"
#include "Whirlpool.h"

#define  ROCK			"landscapes/jiaoshi_2.png"
#define  STROM			"landscapes/longjuanf_0.png"
#define  WHIRLPOOL		"landscapes/xuanwo_0.png"
#define  THUNDERCLOUD	"landscapes/leidian_2.png"

Stage1GameplayLayer::Stage1GameplayLayer()
{
	this->kunpeng = HeroSprite::create("characters/kunpeng/kunpeng.jpg");
	this->background = Sprite::create("backgrounds/background_liuyikang.jpg");
	this->background->setAnchorPoint(Vec2(0, 0.5));

	this->waterSurface = WaterSurface::create("landscapes/water_surface.png");

	this->waterBody = Sprite::create("landscapes/water_body.png");
}


Stage1GameplayLayer::~Stage1GameplayLayer()
{
}

Stage1GameplayLayer * Stage1GameplayLayer::create(){
	Stage1GameplayLayer *ret = new (std::nothrow) Stage1GameplayLayer();
	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
}

void Stage1GameplayLayer::onEnter(){

	this->addChild(this->background, -1);


	this->tutorial_motion = Sprite::create("tutorial/tutorial_motion.png");
	this->tutorial_motion->setPosition(700, 200);
	this->addChild(tutorial_motion);

	this->tutorial_jk = Sprite::create("tutorial/tutorial_jk.png");
	this->tutorial_jk->setPosition(700, -100);
	this->addChild(tutorial_jk);

	this->tutorial_trans_btf = Sprite::create("tutorial/tutorial_trans_btf.png");
	this->tutorial_trans_btf->setPosition(1400, 100);
	this->tutorial_trans_btf->setOpacity(0);
	this->addChild(tutorial_trans_btf);

	this->tutorial_trans_ftb = Sprite::create("tutorial/tutorial_trans_ftb.png");
	this->tutorial_trans_ftb->setPosition(2400, -150);
	this->tutorial_trans_ftb->setOpacity(0);
	this->addChild(tutorial_trans_ftb);

	this->tutorial_delegate_explore = Sprite::create("tutorial/tutorial_delegate_explore.png");
	this->tutorial_delegate_explore->setPosition(3500, 0);
	this->tutorial_delegate_explore->setOpacity(0);
	this->addChild(tutorial_delegate_explore);

	/*
	Sprite * kunzhidabuzhiqijiqianliye = Sprite::create("tutorial/kunzhidabuzhiqijiqianliye.png");
	kunzhidabuzhiqijiqianliye->setPosition(2200,-250);
	this->addChild(kunzhidabuzhiqijiqianliye);

	Sprite * huaerwei = Sprite::create("tutorial/huaerwei.png");
	huaerwei->setPosition(2600,-50);
	this->addChild(huaerwei);

	Sprite * ftb_transform_t = Sprite::create("tutorial/transform_ftb_tutorial.png");
	ftb_transform_t->setPosition(3200,100);
	this->addChild(ftb_transform_t);


	Sprite * niao = Sprite::create("tutorial/niao.png");
	niao->setPosition(3800,200);
	this->addChild(niao);

	Sprite * qimingweipeng = Sprite::create("tutorial/qimingweipeng.png");
	qimingweipeng->setPosition(4000,200);
	this->addChild(qimingweipeng);

	Sprite * penzhibeibuzhiqijiqianliye = Sprite::create("tutorial/pengzhibeibuzhiqijiqianliye.png");
	penzhibeibuzhiqijiqianliye->setPosition(4400,300);
	this->addChild(penzhibeibuzhiqijiqianliye);

	Sprite * nuerfei = Sprite::create("tutorial/pengzhibeibuzhiqijiqianliye.png");
	nuerfei->setPosition(4800, 300);
	this->addChild(nuerfei);
	*/



	//Sprite * backgroundSprite = Sprite::create("backgrounds/sky_and_water_small.jpg");

	//HeroSprite * kp = HeroSprite::create("characters/kunpeng/peng.jpg");
	/*
	GeneralUnit * enemy1ForTest = GeneralUnit::create("characters/general_unit/general_unit.jpg");
	enemy1ForTest->camp = 2;
	enemy1ForTest->setPosition(300, 0);
	enemyList.pushBack(enemy1ForTest);
	this->addChild(enemy1ForTest);
	*/

	/*
	Bird_zwc * enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->camp = 2;
	enemyZWC->setPosition(600, 0);
	enemyList.pushBack(enemyZWC);
	enemyZWC->wanderAbout();
	this->addChild(enemyZWC);

	*/
	/*
	Bird_yyh * enemyYYH = Bird_yyh::create("characters/bat/fly-1.png");
	enemyYYH->camp = 2;
	enemyYYH->setPosition(600, 0);
	enemyList.pushBack(enemyYYH);
	enemyYYH->wanderAbout();
	this->addChild(enemyYYH);
	*/

	/*
	GeneralUnit *fish = FishEnemy1::create("enemyfish/enemyfish.png");
	fish->setPosition(Vec2(500, 0));
	this->addChild(fish);
	enemyList.pushBack(fish);
	*/

	/*
	GeneralUnit *fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(3876, -208));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	GeneralUnit *fishljj2 = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj2->setPosition(Vec2(4100, -153));
	this->addChild(fishljj2);
	enemyList.pushBack(fishljj2);

	GeneralUnit *fishljj3 = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj3->setPosition(Vec2(4486, -267));
	this->addChild(fishljj3);
	enemyList.pushBack(fishljj3);
	*/

	/*
	GeneralUnit *fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(4500, 0));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);

	GeneralUnit *fishcw1 = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw1->setPosition(Vec2(4700, 0));
	this->addChild(fishcw1);
	enemyList.pushBack(fishcw1);

	GeneralUnit *fishcw2 = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw2->setPosition(Vec2(4900, 0));
	this->addChild(fishcw2);
	enemyList.pushBack(fishcw2);
	*/

	Rock* rock2 = Rock::create(ROCK);//礁石障碍
	rock2->setPosition(2000, -100);
	this->addChild(rock2);
	enemyList.pushBack(rock2);

	Storm* storm = Storm::create(STROM);//龙卷风障碍
	storm->setPosition(1000, 300);
	this->addChild(storm);
	enemyList.pushBack(storm);

	Whirlpool* whirlpool = Whirlpool::create(WHIRLPOOL);//漩涡
	whirlpool->setPosition(3000, -200);
	this->addChild(whirlpool);
	enemyList.pushBack(whirlpool);

	ThunderCloud* thunderCloud = ThunderCloud::create(THUNDERCLOUD);//雷电
	thunderCloud->setPosition(4000, 300);
	this->addChild(thunderCloud);
	enemyList.pushBack(thunderCloud);

	Bird_yyh* bird1 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird1->setPosition(4500, 100);
	//bird1->setPosition(300, 100);
	this->addChild(bird1);
	enemyList.pushBack(bird1);

	Bird_yyh* bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(4600, 100);
	this->addChild(bird2);
	enemyList.pushBack(bird2);

	bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(4700, 100);
	this->addChild(bird2);
	enemyList.pushBack(bird2);

	bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(4800, 100);
	this->addChild(bird2);
	enemyList.pushBack(bird2);

	bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(4900, 100);
	this->addChild(bird2);
	enemyList.pushBack(bird2);

	bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(5000, 100);
	this->addChild(bird2);
	enemyList.pushBack(bird2);


	GeneralUnit *fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(6750, -200));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(6850, -200));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(6950, -200));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(6850, -100));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(6950, -100));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(6750, -100));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);


	Bird_zwc * enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(8400, 100);//使用setPlace，同时设置setPosition和guardPoint
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(8450, 200);//使用setPlace，同时设置setPosition和guardPoint
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(8500, 150);//使用setPlace，同时设置setPosition和guardPoint
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(8550, 250);//使用setPlace，同时设置setPosition和guardPoint
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(8550, 300);//使用setPlace，同时设置setPosition和guardPoint
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(8600, 450);//使用setPlace，同时设置setPosition和guardPoint
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(8650, 400);//使用setPlace，同时设置setPosition和guardPoint
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(8700, 320);//使用setPlace，同时设置setPosition和guardPoint
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);




	GeneralUnit *fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(10250, -100));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);

	fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(10350, -100));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);

	fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(10450, -100));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);

	fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(10550, -100));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);

	fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(10650, -100));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);

	fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(10750, -100));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);










	fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(11850, -100));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);

	fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(11750, -100));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);

	fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(11850, -200));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);

	fishcw = FishEnemy1::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishcw->setPosition(Vec2(11750, -200));
	this->addChild(fishcw);
	enemyList.pushBack(fishcw);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(11800, 100);
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(11700, 100);
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(11800, 200);
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(11700, 200);
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(11800, 300);
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	enemyZWC = Bird_zwc::create("characters/bat/fly-1.png");
	enemyZWC->setPlace(11700, 300);
	enemyList.pushBack(enemyZWC);
	this->addChild(enemyZWC);

	/**/
	fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(11800, -100));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(11700, -100));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(11800, -200));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	fishljj = EnemyFish::create("characters/enemyfish/enemyfish_hovering_facing_left_00.png");
	fishljj->setPosition(Vec2(11700, -200));
	this->addChild(fishljj);
	enemyList.pushBack(fishljj);

	bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(11800, 100);
	this->addChild(bird2);
	enemyList.pushBack(bird2);

	bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(11700, 100);
	this->addChild(bird2);
	enemyList.pushBack(bird2);

	bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(11800, 200);
	this->addChild(bird2);
	enemyList.pushBack(bird2);

	bird2 = Bird_yyh::create("characters/Bird_yyh/left1.png");
	bird2->setPosition(11800, 200);
	this->addChild(bird2);
	enemyList.pushBack(bird2);



	/*
	Bird_yyh* bird2 = Bird_yyh::create("characters/Bird_yyh/bird1.jpg");
	bird2->setPosition(700, 200);
	this->addChild(bird2);
	Bullet* bullet2 = Bullet::create(bird2);
	this->addChild(bullet2, 1, "bu");
	//bird1->wanderAbout();
	enemyList.pushBack(bird2);

	Bird_yyh* bird3 = Bird_yyh::create("characters/Bird_yyh/bird1.jpg");
	bird3->setPosition(1100, 200);
	this->addChild(bird3);
	Bullet* bullet3 = Bullet::create(bird3);
	this->addChild(bullet3, 1, "bu");
	//bird1->wanderAbout();
	enemyList.pushBack(bird3);

	Bird_yyh* bird4 = Bird_yyh::create("characters/Bird_yyh/bird1.jpg");
	bird4->setPosition(1400, 200);
	this->addChild(bird4);
	Bullet* bullet4 = Bullet::create(bird3);
	this->addChild(bullet4, 1, "bu");
	//bird1->wanderAbout();
	enemyList.pushBack(bird4);
	*/

	/**/
	this->zhurong = Zhurong::create("characters/zhurong/walking_left_while_facing_left_00.png");
	zhurong->setPosition(14500, 100);
	zhurong->isBoss = true;
	this->addChild(zhurong);
	enemyList.pushBack(zhurong);




	this->kunpeng->setTag(2);
	this->kunpeng->setPosition(400, 200);
	this->addChild(this->kunpeng);
	this->addChild(waterSurface, 1);

	this->waterBody->setAnchorPoint(Vec2(0, 1));
	this->waterBody->setScaleX(10);
	this->waterBody->setScaleY(2);
	this->waterBody->setOpacity(64);
	this->addChild(this->waterBody, 2);


	Layer::onEnter();
}

//当地图增加纵向面积时，这里需要更改
void Stage1GameplayLayer::updateLayerPositionToMaintainHeroInCamera(float positionRatioLeft, float positionRatioRight, float screenScrollingSpeedRatio){
	if (!this->enableAutoTrackingHero) return;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int heroPositionInCameraX = this->getPositionX() + this->kunpeng->getPositionX();
	if (heroPositionInCameraX > visibleSize.width * positionRatioRight){
		int difference = heroPositionInCameraX - visibleSize.width * positionRatioRight;
		this->setPositionX(this->getPositionX() - screenScrollingSpeedRatio * difference);
	}

	if (heroPositionInCameraX < visibleSize.width * positionRatioLeft){
		int difference = heroPositionInCameraX - visibleSize.width * positionRatioLeft;
		this->setPositionX(this->getPositionX() - screenScrollingSpeedRatio * difference);
	}

}

void Stage1GameplayLayer::updateLayerPositionToMaintainHeroInCamera(){
	if (!this->enableAutoTrackingHero) return;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int heroPositionInCameraX = this->getPositionX() + this->kunpeng->getPositionX();
	if (heroPositionInCameraX > visibleSize.width * this->positionRatioRight){
		int difference = heroPositionInCameraX - visibleSize.width * this->positionRatioRight;
		this->setPositionX(this->getPositionX() - this->screenScrollingSpeedRatio * difference);
	}

	if (heroPositionInCameraX < visibleSize.width * this->positionRatioLeft){
		int difference = heroPositionInCameraX - visibleSize.width * this->positionRatioLeft;
		this->setPositionX(this->getPositionX() - this->screenScrollingSpeedRatio * difference);
	}


	int heroPositionInCameraY = this->getPositionY() + this->kunpeng->getPositionY();

	if (heroPositionInCameraY > visibleSize.height * this->positionRatioUp){
		int heightDifference = heroPositionInCameraY - visibleSize.height * this->positionRatioUp;
		this->setPositionY(this->getPositionY() - this->screenScrollingSpeedRatio * heightDifference);
	}

	if (heroPositionInCameraY < visibleSize.height * this->positionRatioDown){
		int heightDifference = heroPositionInCameraY - visibleSize.height * this->positionRatioDown;
		this->setPositionY(this->getPositionY() - this->screenScrollingSpeedRatio * heightDifference);
	}

	int backgroundPositionInLayerX = background->getPositionX();
	int backgroundPositionInLayerY = background->getPositionY();

	int backgroundWidth = background->getContentSize().width;
	int backgroundHeight = background->getContentSize().height;

	Vec2 backgroundAnchor = background->getAnchorPoint();
	float backgroundAnchorX = backgroundAnchor.x;
	float backgroundAnchorY = backgroundAnchor.y;

	int backgroundLeftBoundaryInLayer = backgroundPositionInLayerX - backgroundWidth * backgroundAnchorX;
	int backgroundRightBoundaryInLayer = backgroundPositionInLayerX + backgroundWidth *(1 - backgroundAnchorX);
	int backgroundUpBoundaryInLayer = backgroundPositionInLayerY + backgroundHeight * (1 - backgroundAnchorY);
	int backgroundDownBoundaryInLayer = backgroundPositionInLayerY - backgroundHeight *  backgroundAnchorY;


	int backgroundLeftBoundaryInCamera = backgroundLeftBoundaryInLayer + this->getPositionX();
	int backgroundRightBoundaryInCamera = backgroundRightBoundaryInLayer + this->getPositionX();
	int backgroundUpBoundaryInCamera = backgroundUpBoundaryInLayer + this->getPositionY();
	int backgroundDownBoundaryInCamera = backgroundDownBoundaryInLayer + this->getPositionY();




	if (backgroundLeftBoundaryInCamera > -20){
		int difference = backgroundLeftBoundaryInCamera + 20;
		this->setPositionX(this->getPositionX() - difference);
	}
	else if (backgroundRightBoundaryInCamera < visibleSize.width + 20){
		int difference = backgroundRightBoundaryInCamera - visibleSize.width - 20;
		this->setPositionX(this->getPositionX() - difference);
	}


	if (backgroundUpBoundaryInCamera < visibleSize.height + 20){
		int difference = backgroundUpBoundaryInCamera - visibleSize.height - 20;
		this->setPositionY(this->getPositionY() - difference);
	}
	else if (backgroundDownBoundaryInCamera > -20){
		int difference = backgroundDownBoundaryInCamera + 20;
		this->setPositionY(this->getPositionY() - difference);
	}

}


//需要主角不超出镜头范围的时候，调用它。如果主角在视野外，则将主角挪到镜头内。
void Stage1GameplayLayer::pauseflagHeroWithinCamera(){
	if (!this->enableAutoTrackingHero) return;
	Stage1Scene * scene = (Stage1Scene *)this->getParent();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	int heroPositionInCameraX = this->getPositionX() + this->kunpeng->getPositionX();
	int heroPositionInCameraY = this->getPositionY() + this->kunpeng->getPositionY();

	if (heroPositionInCameraX > visibleSize.width){
		int difference = heroPositionInCameraX - visibleSize.width;
		this->kunpeng->setPositionX(this->kunpeng->getPositionX() - difference);
	}
	if (heroPositionInCameraX < 0){
		int difference = heroPositionInCameraX;
		this->kunpeng->setPositionX(this->kunpeng->getPositionX() - difference);
	}
	if (heroPositionInCameraY > visibleSize.height){
		int difference = heroPositionInCameraY - visibleSize.height;
		this->kunpeng->setPositionY(this->kunpeng->getPositionY() - difference);
	}
	if (heroPositionInCameraY < 0){
		int difference = heroPositionInCameraY;
		this->kunpeng->setPositionY(this->kunpeng->getPositionY() - difference);
	}
}

//当且仅当背景是长方形时，调用它可以让主角被限制在背景里
void Stage1GameplayLayer::pauseflagHeroWithinLandscape(){
	int heroPositionInLayerX = kunpeng->getPositionX();
	int heroPositionInLayerY = kunpeng->getPositionY();

	int backgroundPositionInLayerX = background->getPositionX();
	int backgroundPositionInLayerY = background->getPositionY();

	int backgroundWidth = background->getContentSize().width;
	int backgroundHeight = background->getContentSize().height;

	Vec2 backgroundAnchor = background->getAnchorPoint();
	float backgroundAnchorX = backgroundAnchor.x;
	float backgroundAnchorY = backgroundAnchor.y;

	int backgroundLeftBoundary = backgroundPositionInLayerX - backgroundWidth * backgroundAnchorX;
	int backgroundRightBoundary = backgroundPositionInLayerX + backgroundWidth *(1 - backgroundAnchorX);
	int backgroundUpBoundary = backgroundPositionInLayerY + backgroundHeight * (1 - backgroundAnchorY);
	int backgroundDownBoundary = backgroundPositionInLayerY - backgroundHeight *  backgroundAnchorY;

	if (heroPositionInLayerX > backgroundRightBoundary){
		int difference = heroPositionInLayerX - backgroundRightBoundary;
		kunpeng->setPositionX(kunpeng->getPositionX() - difference);
	}
	if (heroPositionInLayerX < backgroundLeftBoundary){
		int difference = heroPositionInLayerX - backgroundLeftBoundary;
		kunpeng->setPositionX(kunpeng->getPositionX() - difference);
	}
	if (heroPositionInLayerY > backgroundUpBoundary){
		int difference = heroPositionInLayerY - backgroundUpBoundary;
		kunpeng->setPositionY(kunpeng->getPositionY() - difference);
	}
	if (heroPositionInLayerY < backgroundDownBoundary){
		int difference = heroPositionInLayerY - backgroundDownBoundary;
		kunpeng->setPositionY(kunpeng->getPositionY() - difference);
	}


	if (this->zhurong->getPositionX() > backgroundRightBoundary){
		int difference = this->zhurong->getPositionX() - backgroundRightBoundary;
		this->zhurong->setPositionX(zhurong->getPositionX() - difference);
	}
}

void Stage1GameplayLayer::cameraShake_slight(){

}
void Stage1GameplayLayer::cameraShake_significant(){

}
void Stage1GameplayLayer::cameraShake_vertical_slight(){
	this->runAction(Sequence::create(CallFunc::create([this]{this->enableAutoTrackingHero = false; }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 8); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 7); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 6); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 5); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 4); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 3); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 2); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->enableAutoTrackingHero = true; }),
		nullptr));
}
void Stage1GameplayLayer::cameraShake_vertical_significant(){
	this->runAction(Sequence::create(CallFunc::create([this]{this->enableAutoTrackingHero = false; this->setPositionY(this->getPositionY() - 10); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 19); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 18); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 17); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 16); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 15); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 14); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 13); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 12); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 11); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 10); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 9); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 8); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 7); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 6); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 5); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 4); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() + 3); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionY(this->getPositionY() - 2); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->enableAutoTrackingHero = true; }),
		nullptr));
}
void Stage1GameplayLayer::cameraShake_horizontal_slight(){
	this->runAction(Sequence::create(/*CallFunc::create([this]{this->enableAutoTrackingHero = false; }),*/ DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 8); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 7); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 6); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 5); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 4); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 3); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 2); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->enableAutoTrackingHero = true; }),
		nullptr));
}
void Stage1GameplayLayer::cameraShake_horizontal_significant(){
	this->runAction(Sequence::create(CallFunc::create([this]{/*this->enableAutoTrackingHero = false;*/ this->setPositionX(this->getPositionX() - 10); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 19); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 18); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 17); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 16); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 15); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 14); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 13); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 12); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 11); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 10); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 9); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 8); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 7); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 6); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 5); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 4); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() + 3); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->setPositionX(this->getPositionX() - 2); }), DelayTime::create(1.0 / 60),
		CallFunc::create([this]{this->enableAutoTrackingHero = true; }),
		nullptr));
}