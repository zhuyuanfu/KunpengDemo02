#include "Zhurong.h"
#include "Stage1GameplayLayer.h"
#include <iostream>
using namespace std;


Zhurong::Zhurong()
{
	
	//ף���ƶ���������ʼ���ŵ��������ǰ�������wanderAbout�ĵ���û��Ч����
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

	this->walkingLeftWhileFacingLeftAnimation->getFrames().at(0)->setUserInfo(walkingAnimationStartInfo);//�����ĵ�0֡Я������ʼ����������Ϣ
	this->walkingLeftWhileFacingLeftAnimation->getFrames().at(3)->setUserInfo(walkingAnimationEndInfo);//���������һ֡Я������������������Ϣ

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

	//�ƶ�������
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

	this->walkingRightWhileFacingRightAnimation->getFrames().at(0)->setUserInfo(walkingrightAnimationStartInfo);//�����ĵ�0֡Я������ʼ����������Ϣ
	this->walkingRightWhileFacingRightAnimation->getFrames().at(3)->setUserInfo(walkingrightAnimationEndInfo);//���������һ֡Я������������������Ϣ

	EventListenerCustom * walkingrightFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, walkingrightAnimationStartInfo, walkingrightAnimationEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == walkingrightAnimationStartInfo){
			this->acceptCall = false;//�ڶ�����ʼ�ĵ�һ֡��ֹ�������wanderAbout()
		}
		if (*userData->userInfo == walkingrightAnimationEndInfo){
			this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(walkingrightFrameEventListener, -1);

	//������
	this->hurtleftAnimation = Animation::create();
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_0.png");
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_1.png");
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_2.png");
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_3.png");
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_4.png");
	this->hurtleftAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtleft_5.png");

	this->hurtleftAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->hurtleftAnimation->setRestoreOriginalFrame(true);
	this->hurtleftAnimation->retain();

	ValueMap hurtleftStartInfo;
	ValueMap hurtleftEndInfo;

	hurtleftStartInfo["yyh12"] = Value("yyh12");
	hurtleftEndInfo["yyh13"] = Value("yyh13");

	this->hurtleftAnimation->getFrames().at(0)->setUserInfo(hurtleftStartInfo);//�����ĵ�0֡Я������ʼ����������Ϣ
	this->hurtleftAnimation->getFrames().at(5)->setUserInfo(hurtleftEndInfo);//���������һ֡Я������������������Ϣ

	EventListenerCustom * hurtleftFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hurtleftStartInfo, hurtleftEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == hurtleftStartInfo){
			this->acceptCall = false;//�ڶ�����ʼ�ĵ�һ֡��ֹ�������wanderAbout()
		}
		if (*userData->userInfo == hurtleftEndInfo){
			this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(hurtleftFrameEventListener, -1);

	//������
	this->hurtrightAnimation = Animation::create();
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_0.png");
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_1.png");
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_2.png");
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_3.png");
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_4.png");
	this->hurtrightAnimation->addSpriteFrameWithFileName("characters/zhurong/hurtright_5.png");

	this->hurtrightAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->hurtrightAnimation->setRestoreOriginalFrame(true);
	this->hurtrightAnimation->retain();

	ValueMap hurtrightStartInfo;
	ValueMap hurtrightEndInfo;

	hurtrightStartInfo["yyh14"] = Value("yyh14");
	hurtrightEndInfo["yyh15"] = Value("yyh15");

	this->hurtrightAnimation->getFrames().at(0)->setUserInfo(hurtrightStartInfo);//�����ĵ�0֡Я������ʼ����������Ϣ
	this->hurtrightAnimation->getFrames().at(5)->setUserInfo(hurtrightEndInfo);//���������һ֡Я������������������Ϣ

	EventListenerCustom * hurtrightFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hurtrightStartInfo, hurtrightEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == hurtrightStartInfo){
			this->acceptCall = false;//�ڶ�����ʼ�ĵ�һ֡��ֹ�������wanderAbout()
		}
		if (*userData->userInfo == hurtrightEndInfo){
			this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(hurtrightFrameEventListener, -1);

	//������
	this->dieleftAnimation = Animation::create();
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_0.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_1.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_2.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_3.png");
	this->dieleftAnimation->addSpriteFrameWithFileName("characters/zhurong/dieleft_4.png");

	this->dieleftAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->dieleftAnimation->setRestoreOriginalFrame(true);
	this->dieleftAnimation->retain();

	ValueMap dieleftStartInfo;
	ValueMap dieleftEndInfo;

	dieleftStartInfo["yyh20"] = Value("yyh20");
	dieleftEndInfo["yyh21"] = Value("yyh21");

	this->dieleftAnimation->getFrames().at(0)->setUserInfo(dieleftStartInfo);//�����ĵ�0֡Я������ʼ����������Ϣ
	this->dieleftAnimation->getFrames().at(4)->setUserInfo(dieleftEndInfo);//���������һ֡Я������������������Ϣ

	EventListenerCustom * dieleftFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dieleftStartInfo, dieleftEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dieleftStartInfo){
			this->acceptCall = false;//�ڶ�����ʼ�ĵ�һ֡��ֹ�������wanderAbout()
		}
		if (*userData->userInfo == dieleftEndInfo){
			this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dieleftFrameEventListener, -1);

	

	//������
	this->dierightAnimation = Animation::create();
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_0.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_1.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_2.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_3.png");
	this->dierightAnimation->addSpriteFrameWithFileName("characters/zhurong/dieright_4.png");

	this->dierightAnimation->setDelayPerUnit(this->ANIMATION_FRAME_INTERVAL);
	this->dierightAnimation->setRestoreOriginalFrame(true);
	this->dierightAnimation->retain();

	ValueMap dierightStartInfo;
	ValueMap dierightEndInfo;

	dierightStartInfo["yyh22"] = Value("yyh22");
	dierightEndInfo["yyh23"] = Value("yyh23");

	this->dierightAnimation->getFrames().at(0)->setUserInfo(dierightStartInfo);//�����ĵ�0֡Я������ʼ����������Ϣ
	this->dierightAnimation->getFrames().at(4)->setUserInfo(dierightEndInfo);//���������һ֡Я������������������Ϣ

	EventListenerCustom * dierightFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dierightStartInfo, dierightEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dierightStartInfo){
			this->acceptCall = false;//�ڶ�����ʼ�ĵ�һ֡��ֹ�������wanderAbout()
		}
		if (*userData->userInfo == dierightEndInfo){
			this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dierightFrameEventListener, -1);

	
	
	//������
	this->closeAnimation = Animation::create();
	this->closeAnimation->addSpriteFrameWithFileName("characters/zhurong/shootleft_0.png");//ͼƬû��
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
			this->acceptCall = false;//��������ʱ������ף�ڽ����������wanderAbout()
		}
		if (*userData->userInfo == closeendAnimation){
			this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
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

	//��������-�ұ�
	
	this->closerightAnimation = Animation::create();
	this->closerightAnimation->addSpriteFrameWithFileName("characters/zhurong/shootright_0.png");//ͼƬû��
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
			this->acceptCall = false;//��������ʱ������ף�ڽ����������wanderAbout()
		}
		if (*userData->userInfo == rightcloseendAnimation){
			this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
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

	//��ˮ�¶����߶���
	this->heatupAnimation = Animation::create();
	this->heatupAnimation->addSpriteFrameWithFileName("characters/zhurong/water_0.png");//ͼƬû��
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
			//this->acceptCall = false;//��������ʱ������ף�ڽ����������wanderAbout()
		}
		if (*userData->userInfo == heatendAnimation){
			//this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
			heatwater_flag = 1;
		}

		if (*userData->userInfo == seacolorAnimation){
			Sprite* sea1 = Sprite::create("characters/zhurong/red-3.png");
			sea1->setAnchorPoint(Point(0, 1));
			sea1->setPosition(Vec2(0, 0));
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


	//ˮ��
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

	//�����¼���ӵ��¼��ַ���
	_eventDispatcher->addEventListenerWithFixedPriority(waterBigSplashingFrameEventListener, -1);




	this->shootingFireBallWhileFacingLeftAnimation = Animation::create();
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_00.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_01.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_02.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_03.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_04.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_05.png");
	this->shootingFireBallWhileFacingLeftAnimation->addSpriteFrameWithFileName("characters/zhurong/shooting_fireball_while_facing_left_06.png");

	this->shootingFireBallWhileFacingLeftAnimation->setDelayPerUnit(0.3);
	this->shootingFireBallWhileFacingLeftAnimation->setRestoreOriginalFrame(true);
	this->shootingFireBallWhileFacingLeftAnimation->retain();

	ValueMap shootingFireBallStartAnimation;
	ValueMap shootingFireBallLaunchingAnimation;
	ValueMap shootingFireBallEndAnimation;

	shootingFireBallStartAnimation["zhurong2"] = Value("zhurong2");
	shootingFireBallLaunchingAnimation["zhurong3"] = Value("zhurong3");
	shootingFireBallEndAnimation["zhurong4"] = Value("zhurong4");


	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(0)->setUserInfo(shootingFireBallStartAnimation);//�����ĵ�0֡Я������ʼ����������Ϣ
	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(3)->setUserInfo(shootingFireBallLaunchingAnimation);//�����ĵ�8֡Я�����������֡�����Ϣ
	this->shootingFireBallWhileFacingLeftAnimation->getFrames().at(6)->setUserInfo(shootingFireBallEndAnimation);//���������һ֡Я������������������Ϣ

	EventListenerCustom * shootingFireBallFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, shootingFireBallStartAnimation, shootingFireBallLaunchingAnimation, shootingFireBallEndAnimation](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == shootingFireBallStartAnimation){
			this->acceptCall = false;//�ڶ�����ʼ�ĵ�0֡��ʼ��ֹ�������wanderAbout()
		}
		
		if (*userData->userInfo == shootingFireBallLaunchingAnimation){
			//����һ���������ַ������ǡ� ���������ķ����ٶ�Ϊ200����/�롣
			Sprite * fireball = Sprite::create("characters/zhurong/fire_ball_00.png");
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			Point zhu = this->getPosition();
			Point bigfireball = Vec2(zhu.x - 120, zhu.y + 150);
			fireball->setPosition(bigfireball);
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

	//���淶��yyh�������궯��
	this->firerainAnimation = Animation::create();
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
			this->acceptCall = false;//��������ʱ������ף�ڽ����������wanderAbout()
		}
		if (*userData->userInfo == firerainendAnimation){
			this->acceptCall = true;//��������ʱ������ף�ڽ����������wanderAbout()
		}

		if (*userData->userInfo == firerainLaunchingAnimation){
			
			this->schedule(schedule_selector(Zhurong::firerainsmall), 1.0f, 8, 0);
		
		}
		
	});
	_eventDispatcher->addEventListenerWithFixedPriority(firerainEventListener, -1);


	//������ת������ÿ������֡���ж�һ���Ƿ�ײ�����ǻ����ˮ�
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
			//������������ǵľ������ж��Ƿ���С�������У��������ǵ����˷�����������Ӹ��ڵ����Ƴ�
			Sprite * fireBall = (Sprite *)userData->target; //userData��һ���ṹ�壬�����и���target��Node����Node��Ϊ���ŵ���һ֡������
			Sprite * hero = ((Stage1GameplayLayer *)this->getParent())->kunpeng;
			int deltax = fireBall->getPositionX() - hero->getPositionX();
			int deltay = fireBall->getPositionY() - hero->getPositionY();;

			double distance = sqrt(pow(deltax,2)+pow(deltay,2));
			if (distance < (fireBall->getContentSize().width + (hero->getContentSize().width)) * 50 / 100){
				((HeroSprite*)hero)->getHurtGeneral(bigfireballblood);
				fireBall->stopAllActions();
				fireBall->removeFromParent();
			}
			//�жϻ����Ƿ���ˮ���¡������ˮ���¾ͣ�����һ��ˮ��������ʧ��TODO
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
				temp->kunpeng->getHurtGeneral(firerainblood);
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
 * �����ܱ��˵���ʱ������������£�ֱ�ӷ���
 * ���ܱ��˵���ʱ���ö���һ���������һ������
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
						if (romote_flag % 100 == 0)
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
	fire1->setPosition(Vec2(f + 1 * te, fireballbeginheight));
	fire2->setPosition(Vec2(f + 2 * te, fireballbeginheight));
	fire3->setPosition(Vec2(f + 3 * te, fireballbeginheight));
	fire4->setPosition(Vec2(f + 4 * te, fireballbeginheight));
	fire5->setPosition(Vec2(f + 5 * te, fireballbeginheight));
	fire6->setPosition(Vec2(f + 6 * te, fireballbeginheight));
	
	int height = -200;
	auto time = 10.0f;
	auto actionMove1 = MoveTo::create(time, Vec2(f - 1 * te, height));
	auto actionMove2 = MoveTo::create(time, Vec2(f + 0 * te, height));
	auto actionMove3 = MoveTo::create(time, Vec2(f + 1 * te, height));
	auto actionMove4 = MoveTo::create(time, Vec2(f + 2 * te, height));
	auto actionMove5 = MoveTo::create(time, Vec2(f + 3 * te, height));
	auto actionMove6 = MoveTo::create(time, Vec2(f + 4 * te, height));
	

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

void Zhurong::getHurt(int damage){

}
void Zhurong::getHurtByWind(int damage){
	this->stopAllActions();
	auto temp = (Stage1GameplayLayer*)this->getParent();
	auto hero = temp->kunpeng;
	float hero_x = hero->getPosition().x;
	float zhu_x = this->getPosition().x;
	health = health - damage;
	if (health >= 0)
	{
		if (hero_x - zhu_x > 0)
		{
			this->runAction(Animate::create(this->hurtleftAnimation));
		}
		else{
			this->runAction(Animate::create(this->hurtrightAnimation));
		}
	}
	else{
		if (hero_x - zhu_x > 0)
		{
			this->runAction(Animate::create(this->dieleftAnimation));
		}
		else{
			this->runAction(Animate::create(this->dierightAnimation));
		}

	}


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
