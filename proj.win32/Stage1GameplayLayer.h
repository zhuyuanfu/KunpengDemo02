#pragma once
#include "cocos2d.h"
#include "HeroSprite.h"
#include "GeneralUnit.h"


USING_NS_CC;
class Stage1GameplayLayer :	public Layer
{
public:

	HeroSprite * kunpeng = nullptr;
	Sprite * background = nullptr;
	static Stage1GameplayLayer * create();


	Vector<GeneralUnit * > enemyList = Vector<GeneralUnit *>();

	void onEnter();
	
	void updateLayerPositionToMaintainHeroInCamera(float positionRatioLeft, float positionRatioRight, float screenScrollingSpeedRatio);
	void lockHeroWithinCamera();
	void lockHeroWithinLandscape();


	Stage1GameplayLayer();
	~Stage1GameplayLayer();
};

