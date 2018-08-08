#pragma once
#include "cocos2d.h"
#include "HeroSprite.h"
#include "GeneralUnit.h"
//#include "Bird_zwc.h"
#include "bird_yyh.h"
#include "Bullet.h"
#include "FishEnemy1.h"
#include "WaterSurface.h"
#include "WindBullet.h"
#include "Zhurong.h"

USING_NS_CC;
class Stage1GameplayLayer :	public Layer
{
public:

	bool enableAutoTrackingHero = true;
	bool enableHorizontalMotion = true;
	bool enableVerticalMotion = true;

	

	WaterSurface * waterSurface = nullptr;

	HeroSprite * kunpeng = nullptr;
	Zhurong * zhurong = nullptr;


	//��������Ƿ�ӽ�boss������
	const int detectBossX = 10500;
	bool heroHasTriggeredDetectBoss = false;

	//��������Ƿ�ӽ���һ����ʾ������
	const int detectHint1 = 1100;
	bool heroHasTriggeredHint1 = false;

	//��������Ƿ�ӽ��ڶ�����ʾ������
	const int detectHint2 = 2000;
	bool heroHasTriggeredHint2 = false;

	//��������Ƿ�ӽ���������ʾ������
	const int detectHint3 = 3000;
	bool heroHasTriggeredHint3 = false;

	Sprite * tutorial_motion ;
	Sprite * tutorial_jk ;
	Sprite * tutorial_trans_btf ;
	Sprite * tutorial_trans_ftb;
	Sprite * tutorial_delegate_explore;

	Sprite * background = nullptr;

	Sprite * waterBody = nullptr;
	static Stage1GameplayLayer * create();


	Vector<GeneralUnit * > enemyList = Vector<GeneralUnit *>();
	Vector<Sprite * > stoneList = Vector<Sprite *>();
	Vector<Sprite * > windList = Vector<Sprite *>();
	Vector<Sprite * > thunderCloudList = Vector<Sprite *>();
	Vector<Sprite * > vortexList = Vector<Sprite *>();


	void onEnter();
	
	float positionRatioLeft = 0.4f;
	float positionRatioRight = 0.4f;
	float positionRatioUp = 0.5f;
	float positionRatioDown = 0.5f;
	float screenScrollingSpeedRatio = 0.1f;

	void updateLayerPositionToMaintainHeroInCamera(float positionRatioLeft, float positionRatioRight, float screenScrollingSpeedRatio);
	void updateLayerPositionToMaintainHeroInCamera();
	void pauseflagHeroWithinCamera();
	void pauseflagHeroWithinLandscape();

	void cameraShake_slight();
	void cameraShake_significant();
	void cameraShake_vertical_slight();
	void cameraShake_vertical_significant();
	

	Stage1GameplayLayer();
	~Stage1GameplayLayer();
};

