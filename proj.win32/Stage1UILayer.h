#pragma once
//#include "D:\cocos_workspace\KunpengDemo02\cocos2d\cocos\2d\CCLayer.h"
#include "cocos2d.h"

USING_NS_CC;
class Stage1UILayer :	public Layer
{
public:
	int score = 0;

	void onEnter();

	Sprite * heroHPBar = nullptr;
	Sprite * heroHPBarShell = nullptr;
	Sprite * bossHPBar = nullptr;
	Sprite * bossHPBarShell = nullptr;
	Sprite * bossName = nullptr;

	static Stage1UILayer * create();
	Stage1UILayer();
	~Stage1UILayer();
};

