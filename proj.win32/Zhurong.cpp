#include "Zhurong.h"
#include "Stage1GameplayLayer.h"
#include "AudioManager.h"
#include <iostream>
using namespace std;


Zhurong::Zhurong()
{
	//AllocConsole();                                          // 开辟控制台
	//freopen("CONOUT$", "w", stdout);
	//祝融移动动画，开始播放到播放完毕前，外面对wanderAbout的调用没有效果。
	this->walkingLeftWhileFacingLeftAnimation = Animation::create();
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_00.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_01.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_02.png");
	this->walkingLeftWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/walking_left_while_facing_left_03.png");
	
	this->walkingLeftWhileFacingLeftAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->walkingLeftWhileFacingLeftAnimation->setRestoreOriginalFrame(true);
	this->walkingLeftWhileFacingLeftAnimation->retain();

	ValueMap walkingAnimationStartInfo;
	ValueMap walkingAnimationEndInfo;

	walkingAnimationStartInfo["zhurong0"] = Value("zhurong0");
	walkingAnimationEndInfo["zhurong1"] = Value("zhurong1");

	this->walkingLeftWhileFacingLeftAnimation->getFrames().at(0)->setUserInfo(walkingAnimationStartInfo);//动画的第0帧携带“开始动画”的信息
	this->walkingLeftWhileFacingLeftAnimation->getFrames().at(3)->setUserInfo(walkingAnimationEndInfo);//动画的最后一帧携带“结束动画”的信息

	EventListenerCustom * walkingFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, walkingAnimationStartInfo, walkingAnimationEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == walkingAnimationStartInfo){
			this->acceptCall = false;//在动画开始的第一帧禁止外面调用wanderAbout()
		}
		if (*userData->userInfo == walkingAnimationEndInfo){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(walkingFrameEventListener, -1);

	//移动动画右
	this->walkingRightWhileFacingRightAnimation = Animation::create();
	this->walkingRightWhileFacingRightAnimation->addSpriteFrameWithFileName("characters/zhurong/walkright_0.png");
	this->walkingRightWhileFacingRightAnimation->addSpriteFrameWithFileName("characters/zhurong/walkright_1.png");
	this->walkingRightWhileFacingRightAnimation->addSpriteFrameWithFileName("characters/zhurong/walkright_2.png");
	this->walkingRightWhileFacingRightAnimation->addSpriteFrameWithFileName("characters/zhurong/walkright_3.png");

	this->walkingRightWhileFacingRightAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->walkingRightWhileFacingRightAnimation->setRestoreOriginalFrame(true);
	this->walkingRightWhileFacingRightAnimation->retain();

	ValueMap walkingrightAnimationStartInfo;
	ValueMap walkingrightAnimationEndInfo;

	walkingrightAnimationStartInfo["yyh10"] = Value("yyh10");
	walkingrightAnimationEndInfo["yyh11"] = Value("yyh11");

	this->walkingRightWhileFacingRightAnimation->getFrames().at(0)->setUserInfo(walkingrightAnimationStartInfo);//动画的第0帧携带“开始动画”的信息
	this->walkingRightWhileFacingRightAnimation->getFrames().at(3)->setUserInfo(walkingrightAnimationEndInfo);//动画的最后一帧携带“结束动画”的信息

	EventListenerCustom * walkingrightFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, walkingrightAnimationStartInfo, walkingrightAnimationEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == walkingrightAnimationStartInfo){
			this->acceptCall = false;//在动画开始的第一帧禁止外面调用wanderAbout()
		}
		if (*userData->userInfo == walkingrightAnimationEndInfo){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(walkingrightFrameEventListener, -1);

	//被抓动画
	this->heldAnimation = Animation::create();
	this->heldAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_00.png");
	this->heldAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_01.png");
	this->heldAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_02.png");
	this->heldAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_03.png");

	this->heldAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->heldAnimation->setRestoreOriginalFrame(true);
	this->heldAnimation->retain();

	ValueMap heldAnimationStartInfo;
	ValueMap heldAnimationEndInfo;

	heldAnimationStartInfo["held0"] = Value("held0");
	heldAnimationEndInfo["held1"] = Value("held1");

	this->heldAnimation->getFrames().at(0)->setUserInfo(walkingAnimationStartInfo);//动画的第0帧携带“开始动画”的信息
	this->heldAnimation->getFrames().at(3)->setUserInfo(walkingAnimationEndInfo);//动画的最后一帧携带“结束动画”的信息

	EventListenerCustom * heldEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, heldAnimationStartInfo, heldAnimationEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == heldAnimationStartInfo){
			this->acceptCall = false;//在动画开始的第一帧禁止外面调用wanderAbout()
		}
		if (*userData->userInfo == heldAnimationEndInfo){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(heldEventListener, -1);

	//扔的动画
	this->thrownAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_hurt, false);
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_0.png");
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_1.png");
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_2.png");
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_3.png");
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_4.png");
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_5.png");//开始不一样
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_6.png");
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_7.png");
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_8.png");
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_9.png");
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_10.png");
	this->thrownAnimation->addSpriteFrameWithFileName("characters/zhurong/fall_11.png");

	this->thrownAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->thrownAnimation->setRestoreOriginalFrame(true);
	this->thrownAnimation->retain();

	ValueMap thrown0AnimationStartInfo;
	ValueMap thrown1AnimationStartInfo;
	ValueMap thrown2AnimationStartInfo;
	ValueMap thrown3AnimationStartInfo;
	ValueMap thrown4AnimationStartInfo;
	ValueMap thrown10AnimationStartInfo;
	ValueMap thrown11AnimationStartInfo;

	thrown0AnimationStartInfo["yh10"] = Value("yh10");
	thrown1AnimationStartInfo["yh11"] = Value("yh11");
	thrown2AnimationStartInfo["yh12"] = Value("yh12");
	thrown3AnimationStartInfo["yh13"] = Value("yh13");
	thrown4AnimationStartInfo["yh14"] = Value("yh14");
	thrown11AnimationStartInfo["yh15"] = Value("yh15");
	thrown10AnimationStartInfo["yh16"] = Value("yh16");

	this->thrownAnimation->getFrames().at(0)->setUserInfo(thrown0AnimationStartInfo);//动画的第0帧携带“开始动画”的信息
	this->thrownAnimation->getFrames().at(1)->setUserInfo(thrown1AnimationStartInfo);
	this->thrownAnimation->getFrames().at(2)->setUserInfo(thrown2AnimationStartInfo);
	this->thrownAnimation->getFrames().at(3)->setUserInfo(thrown3AnimationStartInfo);
	this->thrownAnimation->getFrames().at(4)->setUserInfo(thrown4AnimationStartInfo);
	this->thrownAnimation->getFrames().at(11)->setUserInfo(thrown11AnimationStartInfo);
	this->thrownAnimation->getFrames().at(10)->setUserInfo(thrown10AnimationStartInfo);

	EventListenerCustom * thrownEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, thrown0AnimationStartInfo, thrown10AnimationStartInfo, thrown3AnimationStartInfo, thrown4AnimationStartInfo, thrown1AnimationStartInfo, thrown2AnimationStartInfo, thrown11AnimationStartInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == thrown0AnimationStartInfo){
			this->acceptCall = false;//在动画开始的第一帧禁止外面调用wanderAbout()
			this->runAction(MoveBy::create(this->ANIMATION_FRAME_INTERVAL, Vec2(0, 20)));
		}
		if (*userData->userInfo == thrown1AnimationStartInfo){
			this->runAction(MoveBy::create(this->ANIMATION_FRAME_INTERVAL, Vec2(0,20)));
			
			
		}
		if (*userData->userInfo == thrown2AnimationStartInfo){
			this->runAction(MoveBy::create(this->ANIMATION_FRAME_INTERVAL, Vec2(0,20)));
			//this->setRotation(-45);
		}
		if (*userData->userInfo == thrown3AnimationStartInfo){
			this->runAction(MoveBy::create(this->ANIMATION_FRAME_INTERVAL, Vec2(0,20)));
			//this->setRotation(-45);
		}
		if (*userData->userInfo == thrown4AnimationStartInfo){
			this->runAction(MoveBy::create(this->ANIMATION_FRAME_INTERVAL, Vec2(0,20)));
			//this->setRotation(0);
		}
		if (*userData->userInfo == thrown10AnimationStartInfo){

			
			this->runAction(MoveBy::create(this->ANIMATION_FRAME_INTERVAL, Vec2(0, -100)));
			//this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
			//this->weak_flag = 0;
		}
		if (*userData->userInfo == thrown11AnimationStartInfo){
			
			((Stage1GameplayLayer *)this->getParent())->cameraShake_vertical_significant();
			
			//this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
			//this->weak_flag = 0;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(thrownEventListener, -1);

	//左受伤
	this->hurtleftAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_hurt, false);
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_0.png");
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_1.png");
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_2.png");
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_3.png");
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_4.png");
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_5.png");

	this->hurtleftAnimation->setDelayPerUnit(0.1f);
	this->hurtleftAnimation->setRestoreOriginalFrame(true);
	this->hurtleftAnimation->retain();

	ValueMap hurtleftStartInfo;
	ValueMap hurtleftEndInfo;

	hurtleftStartInfo["yyh12"] = Value("yyh12");
	hurtleftEndInfo["yyh13"] = Value("yyh13");

	this->hurtleftAnimation->getFrames().at(0)->setUserInfo(hurtleftStartInfo);//动画的第0帧携带“开始动画”的信息
	this->hurtleftAnimation->getFrames().at(5)->setUserInfo(hurtleftEndInfo);//动画的最后一帧携带“结束动画”的信息

	EventListenerCustom * hurtleftFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hurtleftStartInfo, hurtleftEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == hurtleftStartInfo){
			this->acceptCall = false;//在动画开始的第一帧禁止外面调用wanderAbout()
		}
		if (*userData->userInfo == hurtleftEndInfo){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(hurtleftFrameEventListener, -1);

	//右受伤
	this->hurtrightAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_hurt, false);
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_0.png");
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_1.png");
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_2.png");
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_3.png");
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_4.png");
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_5.png");

	this->hurtrightAnimation->setDelayPerUnit(0.1f);
	this->hurtrightAnimation->setRestoreOriginalFrame(true);
	this->hurtrightAnimation->retain();

	ValueMap hurtrightStartInfo;
	ValueMap hurtrightEndInfo;

	hurtrightStartInfo["yyh14"] = Value("yyh14");
	hurtrightEndInfo["yyh15"] = Value("yyh15");

	this->hurtrightAnimation->getFrames().at(0)->setUserInfo(hurtrightStartInfo);//动画的第0帧携带“开始动画”的信息
	this->hurtrightAnimation->getFrames().at(5)->setUserInfo(hurtrightEndInfo);//动画的最后一帧携带“结束动画”的信息

	EventListenerCustom * hurtrightFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hurtrightStartInfo, hurtrightEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == hurtrightStartInfo){
			this->acceptCall = false;//在动画开始的第一帧禁止外面调用wanderAbout()
		}
		if (*userData->userInfo == hurtrightEndInfo){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(hurtrightFrameEventListener, -1);

	//左死亡
	this->dieleftAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_die, false);
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_0.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_1.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_2.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_3.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_4.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_5.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_6.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_7.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_8.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_9.png");

	this->dieleftAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->dieleftAnimation->setRestoreOriginalFrame(true);
	this->dieleftAnimation->retain();

	ValueMap dieleftStartInfo;
	ValueMap dieleftEndInfo;

	dieleftStartInfo["yyh20"] = Value("yyh20");
	dieleftEndInfo["yyh21"] = Value("yyh21");

	this->dieleftAnimation->getFrames().at(0)->setUserInfo(dieleftStartInfo);//动画的第0帧携带“开始动画”的信息
	this->dieleftAnimation->getFrames().at(9)->setUserInfo(dieleftEndInfo);//动画的最后一帧携带“结束动画”的信息

	EventListenerCustom * dieleftFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dieleftStartInfo, dieleftEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dieleftStartInfo){
			this->acceptCall = false;//在动画开始的第一帧禁止外面调用wanderAbout()
		}
		if (*userData->userInfo == dieleftEndInfo){
			
			Animation * iamhereleftanimation = Animation::create();
			iamhereleftanimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_9.png");

			iamhereleftanimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
			iamhereleftanimation->setRestoreOriginalFrame(true);
			iamhereleftanimation->retain();
			//this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
			this->runAction(RepeatForever::create(Animate::create(iamhereleftanimation)));
			
			
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dieleftFrameEventListener, -1);

	

	//右死亡
	this->dierightAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_die, false);
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_0.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_1.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_2.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_3.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_4.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_5.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_6.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_7.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_8.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_9.png");

	this->dierightAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->dierightAnimation->setRestoreOriginalFrame(true);
	this->dierightAnimation->retain();

	ValueMap dierightStartInfo;
	ValueMap dierightEndInfo;

	dierightStartInfo["yyh22"] = Value("yyh22");
	dierightEndInfo["yyh23"] = Value("yyh23");

	this->dierightAnimation->getFrames().at(0)->setUserInfo(dierightStartInfo);//动画的第0帧携带“开始动画”的信息
	this->dierightAnimation->getFrames().at(9)->setUserInfo(dierightEndInfo);//动画的最后一帧携带“结束动画”的信息

	EventListenerCustom * dierightFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dierightStartInfo, dierightEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dierightStartInfo){
			this->acceptCall = false;//在动画开始的第一帧禁止外面调用wanderAbout()
		}
		if (*userData->userInfo == dierightEndInfo){
			
			
			Animation * iamhererightanimation = Animation::create();
			iamhererightanimation->addSpriteFrameWithFileName("characters/zhurong/dieright_9.png");

			iamhererightanimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
			iamhererightanimation->setRestoreOriginalFrame(true);
			iamhererightanimation->retain();
			//this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
			this->runAction(RepeatForever::create(Animate::create(iamhererightanimation)));
			
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dierightFrameEventListener, -1);

	
	
	//近攻击
	this->closeAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_close, false);
	this->closeAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_0.png");//图片没改
	this->closeAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_1.png");
	this->closeAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_2.png");
	this->closeAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_3.png");
	this->closeAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_4.png");
	this->closeAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_5.png");
	


	this->closeAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->closeAnimation->setRestoreOriginalFrame(true);
	this->closeAnimation->retain();

	ValueMap attackcheckAnimation;
	ValueMap closestartAnimation;
	ValueMap closeendAnimation;



	attackcheckAnimation["yyh4"] = Value("yyh4");
	closestartAnimation["yyh5"] = Value("yyh5");
	closeendAnimation["yyh6"] = Value("yyh6");


	this->closeAnimation->getFrames().at(0)->setUserInfo(closestartAnimation);
	this->closeAnimation->getFrames().at(2)->setUserInfo(attackcheckAnimation);
	this->closeAnimation->getFrames().at(3)->setUserInfo(attackcheckAnimation);
	this->closeAnimation->getFrames().at(4)->setUserInfo(attackcheckAnimation);
	this->closeAnimation->getFrames().at(5)->setUserInfo(closeendAnimation);


	EventListenerCustom * closeEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, closestartAnimation, attackcheckAnimation, closeendAnimation](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == closestartAnimation){
			this->acceptCall = false;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
		if (*userData->userInfo == closeendAnimation){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}

		if (*userData->userInfo == attackcheckAnimation){
			auto temp = (Stage1GameplayLayer*)this->getParent();
			auto hero = temp->kunpeng;
			if (hero->boundingBox().intersectsRect(this->boundingBox()))
			{
				hero->getHurtGeneral(hockblood);
			}


		}

	});
	_eventDispatcher->addEventListenerWithFixedPriority(closeEventListener, -1);

	//近攻击—-右边
	
	this->closerightAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_close, false);
	this->closerightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootright_0.png");//图片没改
	this->closerightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootright_1.png");
	this->closerightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootright_2.png");
	this->closerightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootright_3.png");
	this->closerightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootright_4.png");
	this->closerightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootright_5.png");
	


	this->closerightAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->closerightAnimation->setRestoreOriginalFrame(true);
	this->closerightAnimation->retain();

	ValueMap rightattackcheckAnimation;
	ValueMap rightclosestartAnimation;
	ValueMap rightcloseendAnimation;



	rightattackcheckAnimation["yyh100"] = Value("yyh100");
	rightclosestartAnimation["yyh101"] = Value("yyh101");
	rightcloseendAnimation["yyh102"] = Value("yyh102");


	this->closerightAnimation->getFrames().at(0)->setUserInfo(rightclosestartAnimation);
	this->closerightAnimation->getFrames().at(2)->setUserInfo(rightattackcheckAnimation);
	this->closerightAnimation->getFrames().at(3)->setUserInfo(rightattackcheckAnimation);
	this->closerightAnimation->getFrames().at(4)->setUserInfo(rightattackcheckAnimation);
	this->closerightAnimation->getFrames().at(5)->setUserInfo(rightcloseendAnimation);


	EventListenerCustom * rightcloseEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, rightclosestartAnimation, rightattackcheckAnimation, rightcloseendAnimation](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == rightclosestartAnimation){
			this->acceptCall = false;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
		if (*userData->userInfo == rightcloseendAnimation){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}

		if (*userData->userInfo == rightattackcheckAnimation){
			auto temp = (Stage1GameplayLayer*)this->getParent();
			auto hero = temp->kunpeng;
			if (hero->boundingBox().intersectsRect(this->boundingBox()))
			{
				hero->getHurtGeneral(hockblood);
			}


		}

	});
	_eventDispatcher->addEventListenerWithFixedPriority(rightcloseEventListener, -1);

	this->weakfightAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_hurt, false);
	this->weakfightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_0.png");
	this->weakfightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_1.png");
	this->weakfightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_2.png");
	this->weakfightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_3.png");
	this->weakfightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_4.png");
	this->weakfightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_5.png");
	this->weakfightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_5.png");
	this->weakfightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_5.png");




	this->weakfightAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->weakfightAnimation->setRestoreOriginalFrame(true);
	this->weakfightAnimation->retain();

	ValueMap fightAnimation;
	ValueMap weakfightstartAnimation;
	ValueMap weakfightendAnimation;
	ValueMap boomAnimation;



	fightAnimation["yh1"] = Value("yh1");
	weakfightstartAnimation["yh2"] = Value("yh2");
	weakfightendAnimation["yh3"] = Value("yh3");
	boomAnimation["yh1"] = Value("boom1");


	this->weakfightAnimation->getFrames().at(0)->setUserInfo(weakfightstartAnimation);
	this->weakfightAnimation->getFrames().at(3)->setUserInfo(fightAnimation);
	this->weakfightAnimation->getFrames().at(4)->setUserInfo(fightAnimation);
	this->weakfightAnimation->getFrames().at(5)->setUserInfo(fightAnimation);
	this->weakfightAnimation->getFrames().at(6)->setUserInfo(fightAnimation);
	this->weakfightAnimation->getFrames().at(7)->setUserInfo(fightAnimation);
	this->weakfightAnimation->getFrames().at(3)->setUserInfo(boomAnimation);
	this->weakfightAnimation->getFrames().at(7)->setUserInfo(weakfightendAnimation);


	EventListenerCustom * weakfightEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, fightAnimation, boomAnimation, weakfightstartAnimation, weakfightendAnimation](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == weakfightstartAnimation){
			this->acceptCall = false;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
		if (*userData->userInfo == boomAnimation){
			Sprite * fireball = Sprite::create("characters/zhurong/fire_ball_00.png");
			//fireball->setScale(0.3);
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			Point zhu = this->getPosition();
			Point bigfireball = Vec2(zhu.x - 100, zhu.y + 70);
			fireball->setPosition(bigfireball);
			boom = fireball;
			this->getParent()->addChild(fireball);
			
			Animation * fireanimation = Animation::create();
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom1.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom2.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom3.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom4.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom5.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom6.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom7.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom8.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom9.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom9.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom9.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/boom9.png");

			fireanimation->setDelayPerUnit(0.1f);
			fireanimation->setRestoreOriginalFrame(true);
			fireanimation->retain();
			((Stage1GameplayLayer *)this->getParent())->cameraShake_vertical_significant();
			fireball->runAction(Animate::create(fireanimation));
		
		}
		if (*userData->userInfo == weakfightendAnimation){
			//this->setScale(1);
			boom->removeFromParent();
			this->weak_flag = 1;
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}

		if (*userData->userInfo == fightAnimation){
			auto temp = (Stage1GameplayLayer*)this->getParent();
			auto hero = temp->kunpeng;
			if (boom->boundingBox().intersectsRect(this->boundingBox()))
			{
				
				hero->getHurtGeneral(2*hockblood);
			}


		}

	});
	_eventDispatcher->addEventListenerWithFixedPriority(weakfightEventListener, -1);

	//海水温度升高动画
	this->heatupAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_sea, false);
	this->heatupAnimation->addSpriteFrameWithFileName("characters/zhurong/water_0.png");//图片没改
	this->heatupAnimation->addSpriteFrameWithFileName("characters/zhurong/water_1.png");
	this->heatupAnimation->addSpriteFrameWithFileName("characters/zhurong/water_2.png");
	this->heatupAnimation->addSpriteFrameWithFileName("characters/zhurong/water_3.png");
	this->heatupAnimation->addSpriteFrameWithFileName("characters/zhurong/water_2.png");
	this->heatupAnimation->addSpriteFrameWithFileName("characters/zhurong/water_1.png");
	this->heatupAnimation->addSpriteFrameWithFileName("characters/zhurong/water_2.png");
	this->heatupAnimation->addSpriteFrameWithFileName("characters/zhurong/water_3.png");


	this->heatupAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->heatupAnimation->setRestoreOriginalFrame(true);
	this->heatupAnimation->retain();

	ValueMap seacolorAnimation;
	ValueMap heatstartAnimation;
	ValueMap heatendAnimation;



	seacolorAnimation["yyh7"] = Value("yyh7");
	heatstartAnimation["yyh8"] = Value("yyh8");
	heatendAnimation["yyh9"] = Value("yyh9");


	this->heatupAnimation->getFrames().at(0)->setUserInfo(heatstartAnimation);
	this->heatupAnimation->getFrames().at(4)->setUserInfo(seacolorAnimation);
	this->heatupAnimation->getFrames().at(7)->setUserInfo(heatendAnimation);


	EventListenerCustom * heatwaterEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, heatstartAnimation, seacolorAnimation, heatendAnimation](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == heatstartAnimation){
			//this->acceptCall = false;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
		if (*userData->userInfo == heatendAnimation){
			//this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
			heatwater_flag = 1;
		}

		if (*userData->userInfo == seacolorAnimation){
			Sprite* sea1 = Sprite::create("characters/zhurong/red-3.png");
			sea1->setAnchorPoint(Point(0.5, 1));
			sea1->setPosition(Vec2(this->getPositionX(), 0));
			sea = sea1;
			//auto layer = (Stage1GameplayLayer *)this->getParent();
			this->getParent()->addChild(sea1);
			Animation * seaanimation = Animation::create();
			seaanimation->addSpriteFrameWithFileName("characters/zhurong/red-1.png");
			seaanimation->addSpriteFrameWithFileName("characters/zhurong/red-2.png");
			seaanimation->addSpriteFrameWithFileName("characters/zhurong/red-3.png");
			
			seaanimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
			seaanimation->setRestoreOriginalFrame(true);
			seaanimation->retain();
			sea1->runAction(Animate::create(seaanimation));


		}

	});
	_eventDispatcher->addEventListenerWithFixedPriority(heatwaterEventListener, -1);


	//水花
	this->waterSplashingAnimation = Animation::create();
	this->waterSplashingAnimation->addSpriteFrameWithFileName("landscapes/splash_big_00.png");
	this->waterSplashingAnimation->addSpriteFrameWithFileName("landscapes/splash_big_01.png");
	this->waterSplashingAnimation->addSpriteFrameWithFileName("landscapes/splash_big_02.png");
	this->waterSplashingAnimation->addSpriteFrameWithFileName("landscapes/splash_big_03.png");
	this->waterSplashingAnimation->addSpriteFrameWithFileName("landscapes/splash_big_03.png");
	this->waterSplashingAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->waterSplashingAnimation->setRestoreOriginalFrame(true);
	this->waterSplashingAnimation->retain();

	ValueMap waterSplashingEndInfo;

	waterSplashingEndInfo["-3"] = Value(-3);

	this->waterSplashingAnimation->getFrames().at(4)->setUserInfo(waterSplashingEndInfo);

	EventListenerCustom * waterBigSplashingFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, waterSplashingEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == waterSplashingEndInfo){
			userData->target->removeFromParent();
			//delete(userData->target);
		}


	});

	//将该事件添加到事件分发器
	_eventDispatcher->addEventListenerWithFixedPriority(waterBigSplashingFrameEventListener, -1);




	this->shootingFireBallWhileFacingLeftAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_fire, false);
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_00.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_01.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_02.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_03.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_04.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_05.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_06.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_07.png");

	this->shootingFireBallWhileFacingLeftAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->shootingFireBallWhileFacingLeftAnimation->setRestoreOriginalFrame(true);
	this->shootingFireBallWhileFacingLeftAnimation->retain();

	ValueMap shootingFireBallStartAnimation;
	ValueMap shootingFireBallLaunchingAnimation;
	ValueMap shootingFireBallEndAnimation;

	shootingFireBallStartAnimation["zhurong2"] = Value("zhurong2");
	shootingFireBallLaunchingAnimation["zhurong3"] = Value("zhurong3");
	shootingFireBallEndAnimation["zhurong4"] = Value("zhurong4");


	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(0)->setUserInfo(shootingFireBallStartAnimation);//动画的第0帧携带“开始动画”的信息
	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(6)->setUserInfo(shootingFireBallLaunchingAnimation);//动画的第8帧携带“火球脱手”的信息
	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(7)->setUserInfo(shootingFireBallEndAnimation);//动画的最后一帧携带“结束动画”的信息

	EventListenerCustom * shootingFireBallFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, shootingFireBallStartAnimation, shootingFireBallLaunchingAnimation, shootingFireBallEndAnimation](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == shootingFireBallStartAnimation){
			this->acceptCall = false;//在动画开始的第0帧开始禁止外面调用wanderAbout()
			Sprite * fireball = Sprite::create("characters/zhurong/fire_ball_00.png");
			//fireball->setScale(0.3);
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			Point zhu = this->getPosition();
			Point bigfireball = Vec2(zhu.x - 100, zhu.y + 70);
			//Point bigfireball = Vec2(zhu.x , zhu.y);
			fireball->setPosition(bigfireball);
			fire_con = fireball;
			this->getParent()->addChild(fireball);
			int deltax = hero->getPositionX() - fireball->getPositionX();
			int deltay = hero->getPositionY() - fireball->getPositionY();
			Animation * fireanimation = Animation::create();
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/fire1.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/fire2.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/fire3.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/fire4.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/fire5.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/fire6.png");
			fireanimation->addSpriteFrameWithFileName("characters/zhurong/fire7.png");

			fireanimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
			fireanimation->setRestoreOriginalFrame(true);
			fireanimation->retain();
			fireball->runAction(Animate::create(fireanimation));
			auto delayTime = DelayTime::create(this->ANIMATION_FRAME_INTERVAL * 7);
			auto func = CallFunc::create([this](){ 
				
				Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
				Point zhu = this->getPosition();
				Point bigfireball = Vec2(zhu.x - 100, zhu.y + 70);
				
				int deltax = hero->getPositionX() - fire_con->getPositionX();
				int deltay = hero->getPositionY() - fire_con->getPositionY();
				double distance = sqrt(pow(deltax, 2) + pow(deltax, 2));
				fire_con->runAction(RepeatForever::create(MoveBy::create(distance / 200, Vec2(deltax, deltay))));
				fire_con->runAction(RepeatForever::create(Animate::create(this->fireballSpinningAnimation))); });
			auto seq = Sequence::create(delayTime, func, nullptr);
			fireball->runAction(seq);

			
		}
		
		if (*userData->userInfo == shootingFireBallLaunchingAnimation){
			//创造一个火球，脱手飞向主角。 不妨令火球的飞行速度为200像素/秒。
			/*Sprite * fireball = Sprite::create("characters/zhurong/fire_ball_00.png");
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			Point zhu = this->getPosition();
			Point bigfireball = Vec2(zhu.x - 120, zhu.y + 150);
			fireball->setPosition(bigfireball);
			this->getParent()->addChild(fireball);
			int deltax = hero->getPositionX() - fireball->getPositionX();
			int deltay = hero->getPositionY() - fireball->getPositionY();

			double distance = sqrt(pow(deltax, 2) + pow(deltax, 2));
			fireball->runAction(RepeatForever::create(MoveBy::create(distance / 200, Vec2(deltax, deltay))));
			fireball->runAction(RepeatForever::create(Animate::create(this->fireballSpinningAnimation)));*/

		}
		
		if (*userData->userInfo == shootingFireBallEndAnimation){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(shootingFireBallFrameEventListener, -1);

	//不规范的yyh：火球雨动画
	this->firerainAnimation = Animation::create();
	AudioManager::getInstance()->play(boss_rain, false);
	this->firerainAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_00.png");
	this->firerainAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_01.png");
	this->firerainAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_02.png");
	this->firerainAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_03.png");
	this->firerainAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_04.png");
	this->firerainAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_05.png");
	this->firerainAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_06.png");
	this->firerainAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_07.png");
	this->firerainAnimation->addSpriteFrameWithFileName("characters/zhurong/firerain_while_facing_left_08.png");
	
	this->firerainAnimation->setDelayPerUnit(0.25);
	this->firerainAnimation->setRestoreOriginalFrame(true);
	this->firerainAnimation->retain();

	ValueMap firerainLaunchingAnimation;
	ValueMap firerainstartAnimation;
	ValueMap firerainendAnimation;
	


	firerainLaunchingAnimation["yyh1"] = Value("yyh1");
	firerainstartAnimation["yyh2"] = Value("yyh2");
	firerainendAnimation["yyh3"] = Value("yyh3");


	this->firerainAnimation->getFrames().at(0)->setUserInfo(firerainstartAnimation);
	this->firerainAnimation->getFrames().at(5)->setUserInfo(firerainLaunchingAnimation);
	this->firerainAnimation->getFrames().at(8)->setUserInfo(firerainendAnimation);
	

	EventListenerCustom * firerainEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, firerainstartAnimation, firerainLaunchingAnimation,firerainendAnimation](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == firerainstartAnimation){
			this->acceptCall = false;//动画结束时，允许祝融接受外面调用wanderAbout()
		}
		if (*userData->userInfo == firerainendAnimation){
			this->acceptCall = true;//动画结束时，允许祝融接受外面调用wanderAbout()
		}

		if (*userData->userInfo == firerainLaunchingAnimation){
			
			this->schedule(schedule_selector(Zhurong::firerainsmall), 1.0f, 8, 0);
		
		}
		
	});
	_eventDispatcher->addEventListenerWithFixedPriority(firerainEventListener, -1);


	//火球旋转动画。每个动画帧都判断一下是否撞到主角或掉进水里。
	this->fireballSpinningAnimation = Animation::create();
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_00.png");
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_01.png");
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_02.png");
	this->fireballSpinningAnimation->addSpriteFrameWithFileName("characters/zhurong/fire_ball_03.png");
	this->fireballSpinningAnimation->setDelayPerUnit(0.5f);
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
			//计算火球与主角的距离来判断是否击中。如果击中，调用主角的受伤方法并将火球从父节点上移除
			Sprite * fireBall = (Sprite *)userData->target; //userData是一个结构体，里面有个叫target的Node，该Node即为播放到这一帧的事主
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			int deltax = fireBall->getPositionX() - hero->getPositionX();
			int deltay = fireBall->getPositionY() - hero->getPositionY();;

			double distance = sqrt(pow(deltax,2)+pow(deltay,2));
			if (distance < (fireBall->getContentSize().width + (hero->getContentSize().width)) * 50 / 100){
				((HeroSprite*)hero)->getHurtGeneral(bigfireballblood);
				fireBall->stopAllActions();
				fireBall->removeFromParent();
			}
			//判断火球是否在水面下。如果在水面下就（溅起一个水花并）消失。TODO
			auto temp = (Stage1GameplayLayer*)this->getParent();
			float backgroundPositionInLayerY = temp->background->getPositionY();
			float fireball_y = fireBall->getPositionY();
			if (fireball_y < backgroundPositionInLayerY)
			{
				fireBall->runAction(Animate::create(this->waterSplashingAnimation));//
			}

			
		}
		
	});
	_eventDispatcher->addEventListenerWithFixedPriority(fireBallSpinningFrameEventListener, -1);

	scheduleUpdate();


}

void Zhurong::update(float dt){
	auto temp = (Stage1GameplayLayer*)this->getParent();
	auto hero = temp->kunpeng;
	for (int i = 0; i < this->fireball.size(); i++)
	{
		if (hero->boundingBox().intersectsRect(fireball.at(i)->boundingBox())){
			fireball.at(i)->stopAllActions();
			temp->kunpeng->getHurtGeneral(firerainblood);
			fireball.at(i)->removeFromParent();
			s = fireball.at(i);
			fireball.eraseObject(fireball.at(i));
			//delete(s);
			
		}
	}
	for (int j = 0; j < this->fireball.size(); j++)
	{
		float backgroundPositionInLayerY = temp->background->getPositionY();
		float fireball_y = fireball.at(j)->getPositionY();
		if (fireball_y < backgroundPositionInLayerY)
		{
			fireball.at(j)->stopAllActions();
			fireball.at(j)->runAction(Animate::create(this->waterSplashingAnimation));
			fireball.eraseObject(fireball.at(j));
			//delete(fireball.at(i));
		}
	}

	if (heatwater_flag == 1)
	{
		if (hero->boundingBox().intersectsRect(sea->boundingBox()))
		{
			yyh = yyh + 1;
			if (yyh%100==0)
				temp->kunpeng->getHurtGeneral(firerainblood);//因为hero一受伤就会stopallactions
		}
		else{
			if (time_flag == 0){
				time_flag = 1;
				auto delayTime = DelayTime::create(2.0f);
				auto func = CallFunc::create([this](){
						sea->removeFromParent();
						heatwater_flag = 0;
						time_flag = 0;
						this->acceptCall = true;
				});
				auto seq = Sequence::create(delayTime, func, nullptr);
				this->runAction(seq);
			}
			
		}
	}
	if (this->weak - this->health >= 1000)
	{
		this->weak = this->health;
		this->stopAllActions();
		this->acceptCall = false;
		health = health - 20;
		Animation * waterflower = Animation::create();
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_0.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_1.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_2.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->setDelayPerUnit(0.2f);
		waterflower->setRestoreOriginalFrame(true);
		waterflower->retain();
		auto weak = Animate::create(waterflower);
		auto fight = Animate::create(weakfightAnimation);
		auto seq = Sequence::create( weak, fight, nullptr);
		this->runAction(seq);
	}
	/*
	if (this->weak_flag == 0)
	{
		//虚弱状态
		this->stopAllActions();
		cout << "come" << endl;
		cout << this->health << endl;
		
		this->acceptCall = false;
		this->weak_flag = 2;
		Animation * waterflower = Animation::create();
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_0.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_1.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_2.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_4.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_5.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_6.png");
		waterflower->setDelayPerUnit(0.5f);
		waterflower->setRestoreOriginalFrame(true);
		waterflower->retain();
		auto weak = Animate::create(waterflower);
		auto fight = Animate::create(weakfightAnimation);
		auto seq = Sequence::create(weak, fight, nullptr);
		this->runAction(seq);
		

	}
	*/
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
	this->runAction(MoveBy::create(this->ANIMATION_FRAME_INTERVAL, Vec2(-50,0)));
	this->runAction(Animate::create(this->walkingLeftWhileFacingLeftAnimation));
}

void Zhurong::walkrightWhileFacingright(){
	this->stopAllActions();
	this->runAction(MoveBy::create(this->ANIMATION_FRAME_INTERVAL, Vec2(50, 0)));
	this->runAction(Animate::create(this->walkingRightWhileFacingRightAnimation));
}

void Zhurong::prepareAndLaunchAFireballWhileFacingLeft(){
	this->stopAllActions();
	this->runAction(Animate::create(this->shootingFireBallWhileFacingLeftAnimation));
}


void Zhurong::idle(){

}

/**
 * 不接受别人调用时，这个对象不做事，直接返回
 * 接受别人调用时，该对象按一定规则进行一个动作
 */
void Zhurong::wanderAbout(){
	if (this->acceptCall)
	{
		srand((unsigned)time(NULL));
		int nextMovement = rand() % 11;
		
		
		if (nextMovement == 0){
			if (this->getPositionX() - 50 >= ground_left)
				this->walkLeftWhileFacingLeft();
			else
				this->walkrightWhileFacingright();
		}
		else if (nextMovement == 1)
		{
			if (this->getPositionX() + 50 <= ground_right)
				this->walkrightWhileFacingright();
			else
				this->walkrightWhileFacingright();
			
		}
		else if (nextMovement == 2)
		{
			//this->firerain();
		}
		else{
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			float  zhu_x = this->getPositionX();
			float  zhu_y = this->getPositionY();
			float  kun_x = hero->getPositionX();
			float  kun_y = hero->getPositionY();
			int deltax = kun_x - zhu_x;
			int deltay = kun_y - zhu_y;

			double distance = sqrt(pow(deltax, 2) + pow(deltax, 2));
			if (kun_y <= 0){
				if (heatwater_flag == 0)
				{
					heat_flag = heat_flag + 1;
					//if (heat_flag % 400 == 0)
					if(kun_x >= 10890)
						heatwater();
				}
					
			}
			else{
				if (distance <= close_fight)
				{
					if (zhu_x >= kun_x)
					{
						this->runAction(Animate::create(this->closeAnimation));
					}
					else{
						this->runAction(Animate::create(this->closerightAnimation));
					}
				}
				else{
					if (kun_x >= ground_left)
					{
						aoe_flag = aoe_flag + 1;
						if (aoe_flag % 100 == 0)
							firerain();
					}
					else{
						romote_flag = romote_flag + 1;
						if (romote_flag % 100 == 0 &&kun_x >= 10890)
						//if (romote_flag % 100 == 0)
							prepareAndLaunchAFireballWhileFacingLeft();
					}
				}
			}
		}
		
		/*if (zhurong_x - kun_x >= this->remote_fight)
		//{
			
			romote_flag = romote_flag + 1;
			if (romote_flag % 100 == 0)
			{
				prepareAndLaunchAFireballWhileFacingLeft();
			}
		
		
		*/
		/*
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
	*/

	}
}

void Zhurong::firerainsmall(float dt){
	
	Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
	float  zhurong_x = this->getPositionX();
	float  kun_x = firerain_need;
	Sprite* fire1 = Sprite::create("characters/zhurong/water-fire.png");
	Sprite* fire2 = Sprite::create("characters/zhurong/water-fire.png");
	Sprite* fire3 = Sprite::create("characters/zhurong/water-fire.png");
	Sprite* fire4 = Sprite::create("characters/zhurong/water-fire.png");
	Sprite* fire5 = Sprite::create("characters/zhurong/water-fire.png");
	Sprite* fire6 = Sprite::create("characters/zhurong/water-fire.png");

	float f = kun_x - firerain_scope / 2;
	float te = firerain_scope / 6;
	int fireballbeginheight = 800;
	srand((unsigned)time(NULL));
	int r1 = rand() % int(firerain_scope);
	int r2 = rand() % int(firerain_scope);
	int r3 = rand() % int(firerain_scope);
	int r4 = rand() % int(firerain_scope);
	int r5 = rand() % int(firerain_scope);
	int r6 = rand() % int(firerain_scope);
	/*fire1->setPosition(Vec2(f + 1 * te, fireballbeginheight));
	fire2->setPosition(Vec2(f + 2 * te, fireballbeginheight));
	fire3->setPosition(Vec2(f + 3 * te, fireballbeginheight));
	fire4->setPosition(Vec2(f + 4 * te, fireballbeginheight));
	fire5->setPosition(Vec2(f + 5 * te, fireballbeginheight));
	fire6->setPosition(Vec2(f + 6 * te, fireballbeginheight));*/
	
	int height = -10;
	auto time = 10.0f;
	fire1->setPosition(Vec2(f + r1, fireballbeginheight));
	fire2->setPosition(Vec2(f + r2, fireballbeginheight));
	fire3->setPosition(Vec2(f + r3, fireballbeginheight));
	fire4->setPosition(Vec2(f + r4, fireballbeginheight));
	fire5->setPosition(Vec2(f + r5, fireballbeginheight));
	fire6->setPosition(Vec2(f + r6, fireballbeginheight));

	auto actionMove1 = MoveTo::create(time, Vec2(f + r1 - 50, height));
	auto actionMove2 = MoveTo::create(time, Vec2(f + r2 - 50, height));
	auto actionMove3 = MoveTo::create(time, Vec2(f + r3 - 50, height));
	auto actionMove4 = MoveTo::create(time, Vec2(f + r4 - 50, height));
	auto actionMove5 = MoveTo::create(time, Vec2(f + r5 - 50, height));
	auto actionMove6 = MoveTo::create(time, Vec2(f + r6 - 50, height));
	

	fire1->runAction(actionMove1);
	fire2->runAction(actionMove2);
	fire3->runAction(actionMove3);
	fire4->runAction(actionMove4);
	fire5->runAction(actionMove5);
	fire6->runAction(actionMove6);

	auto temp = (Stage1GameplayLayer *)this->getParent();
	temp->addChild(fire1);
	temp->addChild(fire2);
	temp->addChild(fire3);
	temp->addChild(fire4);
	temp->addChild(fire5);
	temp->addChild(fire6);
	
	fireball.pushBack(fire1);
	fireball.pushBack(fire2);
	fireball.pushBack(fire3);
	fireball.pushBack(fire4);
	fireball.pushBack(fire5);
	fireball.pushBack(fire6);
	
	


}

void Zhurong::getHeld(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(heldAnimation)));
}

void Zhurong::closeattack(){
	this->stopAllActions();
	this->runAction(Animate::create(this->closeAnimation));
}

void Zhurong::firerain(){
	this->stopAllActions();
	Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
	float  zhurong_x = this->getPositionX();
	firerain_need = hero->getPositionX();
	this->runAction(Animate::create(this->firerainAnimation));

}

void Zhurong::heatwater(){
	this->stopAllActions();
	this->acceptCall = false;
	if (heatwater_flag == 0) 
	{
		this->runAction(Animate::create(this->heatupAnimation));
	}
	

}

void Zhurong::getSlamDunkOnGround(int damage){
	
	if (weak_flag == 1)
	{
		weak_flag = 0;
		this->stopAllActions();
		this->acceptCall = false;
		health = health - damage;
		Animation * waterflower = Animation::create();
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_0.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_1.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_2.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->addSpriteFrameWithFileName("characters/zhurong/weak_3.png");
		waterflower->setDelayPerUnit(0.2f);
		waterflower->setRestoreOriginalFrame(true);
		waterflower->retain();
		auto thrown = Animate::create(this->thrownAnimation);
		auto weak = Animate::create(waterflower);
		auto fight = Animate::create(weakfightAnimation);
		auto seq = Sequence::create(thrown,weak, fight, nullptr);
		this->runAction(seq);
	}
		
}

void Zhurong::getCollided(int damage){
	this->stopAllActions();
	if (dieflagforzhongrong == 0){

		auto temp = (Stage1GameplayLayer*)this->getParent();
		auto hero = temp->kunpeng;
		float hero_x = hero->getPosition().x;
		float zhu_x = this->getPosition().x;
		health = health - damage;
		if (health >= 0)
		{
			/*
			if (hero_x - zhu_x > 0)
			{
				this->runAction(Animate::create(this->hurtrightAnimation));
			}
			else{
				this->runAction(Animate::create(this->hurtleftAnimation));
			}

			*/
			if (hero_x - zhu_x > 0)
			{
				this->runAction(MoveBy::create(0.2f, Vec2(-100, 0)));
			}
			else{
				this->runAction(MoveBy::create(0.2f, Vec2(100, 0)));
			}

		}
		else{

			this->stopAllActions();
			this->acceptCall = false;
			dieflagforzhongrong = 1;
			if (hero_x - zhu_x > 0)
			{
				this->runAction(Animate::create(this->dierightAnimation));
			}
			else{
				this->runAction(Animate::create(this->dieleftAnimation));
			}

		}
	}

}
void Zhurong::getHurt(int damage){

}

void Zhurong::getHurtByWind(int damage){
	//this->stopAllActions();
	if (dieflagforzhongrong == 0){

		auto temp = (Stage1GameplayLayer*)this->getParent();
		auto hero = temp->kunpeng;
		float hero_x = hero->getPosition().x;
		float zhu_x = this->getPosition().x;
		health = health - damage;
		if (health >= 0)
		{	
			AudioManager::getInstance()->play(boss_hurt, false);
			/*
			if (hero_x - zhu_x > 0)
			{
			this->runAction(Animate::create(this->hurtrightAnimation));
			}
			else{
			this->runAction(Animate::create(this->hurtleftAnimation));
			}
			*/
			

		}
		else{
			
			this->stopAllActions();
			this->acceptCall = false;
			dieflagforzhongrong = 1;
			if (hero_x - zhu_x > 0)
			{
				this->runAction(Animate::create(this->dierightAnimation));
			}
			else{
				this->runAction(Animate::create(this->dieleftAnimation));
			}

		}
	}
	


}

void Zhurong::getHurtByPaw(int damage){
	this->getHurtByWind(damage);
}
void Zhurong::getHurtByCrush(int damage){
	this->getHurtByWind(damage);
}

void Zhurong::getHurtByWater(int damage){
	this->getHurtByWind(damage);
}
void Zhurong::getHurtByFin(int damage){
	this->getHurtByWind(damage);
}

void Zhurong::die(){

}

void Zhurong::getThrown(){
	//this->getHurtByWind(damage);
}

void Zhurong::getSlamDunkOnWater(int damage){
	this->getHurtByWind(damage);
}