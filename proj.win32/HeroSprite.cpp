#include "HeroSprite.h"
#include "Stage1GameplayLayer.h"//Nastiest design ever!

HeroSprite::HeroSprite()
{


	//��ʼ��10���絯������ʹ�������Խ�ʡ��Դ
	for (int i = 0; i < this->NUM_OF_WIND_BULLETS; i++){
		WindBullet * wb = WindBullet::create("characters/kunpeng/wind_bullet_00.png");
		//wb->setPosition(wb->magazineX, wb->magazineY);
		wb->retain();
		//this->getParent()->addChild(wb);
		this->windBullets[i] = wb;
	}
	//��ʼ��10���絯��ըЧ��������ʹ���Խ�ʡ��Դ
	for (int i = 0; i < NUM_OF_WIND_BULLET_EXPLOSIONS; i++){
		Sprite * wbe = Sprite::create("characters/kunpeng/wind_bullet_exploding_00.png");
		//wb->setPosition(wb->magazineX, wb->magazineY);
		wbe->retain();
		//this->getParent()->addChild(wb);
		this->windBulletExplosions[i] = wbe;
	}


	//��ʼ��10��ˮ��������ʹ�������Խ�ʡ��Դ
	for (int i = 0; i < this->NUM_OF_WATER_BULLETS; i++){
		WaterBullet * waterBullet = WaterBullet::create("characters/kunpeng/water_bullet_00.png");
		//waterBullet->setPosition(wb->magazineX, wb->magazineY);
		waterBullet->retain();
		//this->getParent()->addChild(wb);
		this->waterBullets[i] = waterBullet;
	}
	//��ʼ��10��ˮ����ը��Ч������ʹ�������Խ�ʡ��Դ
	for (int i = 0; i < this->NUM_OF_WATER_BULLET_EXPLOSIONS; i++){
		Sprite * waterBulletExplosion = Sprite::create("characters/kunpeng/water_bullet_exploding_00.png");
		//wb->setPosition(wb->magazineX, wb->magazineY);
		waterBulletExplosion->retain();
		//this->getParent()->addChild(wb);
		this->waterBulletExplosions[i] = waterBulletExplosion;
	}

	//�Ƚϴ��ˮ�������ǳ���ˮ��ʱ��ˮ�洦����һ���������߱Ƚϴ�ĵ��˵���ˮ��ʱҲ����һ��������Ҫ�ڽ�β����removeFromParent��TODO
	this->waterSplashingAnimation_big = Animation::create();
	this->waterSplashingAnimation_big->addSpriteFrameWithFileName("landscapes/splash_big_00.png");
	this->waterSplashingAnimation_big->addSpriteFrameWithFileName("landscapes/splash_big_01.png");
	this->waterSplashingAnimation_big->addSpriteFrameWithFileName("landscapes/splash_big_02.png");
	this->waterSplashingAnimation_big->addSpriteFrameWithFileName("landscapes/splash_big_03.png");
	this->waterSplashingAnimation_big->addSpriteFrameWithFileName("landscapes/splash_big_03.png");
	this->waterSplashingAnimation_big->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->waterSplashingAnimation_big->setRestoreOriginalFrame(true);
	this->waterSplashingAnimation_big->retain();

	ValueMap waterSplashingEndInfo;

	waterSplashingEndInfo["-3"] = Value(-3);

	this->waterSplashingAnimation_big->getFrames().at(4)->setUserInfo(waterSplashingEndInfo);

	EventListenerCustom * waterBigSplashingFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, waterSplashingEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == waterSplashingEndInfo){
			userData->target->removeFromParent();
		}


	});

	//�����¼���ӵ��¼��ַ���
	_eventDispatcher->addEventListenerWithFixedPriority(waterBigSplashingFrameEventListener, -1);


	// bird's hovering animation
	this->hoveringRightAnimation = Animation::create();
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_00.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_01.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_02.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_03.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_04.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_04.png");
	this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_05.png");
	//this->hoveringRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_right_06.png");

	this->hoveringRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringRightAnimation->setRestoreOriginalFrame(true);
	this->hoveringRightAnimation->retain();

	this->hoveringLeftAnimation = Animation::create();
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_00.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_01.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_02.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_03.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_04.png");
	this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_05.png");
	//this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_06.png");
	//this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_07.png");
	//this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_08.png");
	//this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_09.png");
	//this->hoveringLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_hovering_facing_left_10.png");
	this->hoveringLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringLeftAnimation->setRestoreOriginalFrame(true);
	this->hoveringLeftAnimation->retain();



	//�������ڵ�1֡�͵�3֡�ϼ��¼������ӣ����лص�������lambda��������ʽ����
	ValueMap hoveringAnimationFrame01info;
	ValueMap hoveringAnimationFrame03info;
	ValueMap hoveringAnimationChekcInTheWaterInfo;


	hoveringAnimationFrame01info["1"] = Value(1);//�����ø�infoָ��һ���µ�ַ��û�б���ô�
	hoveringAnimationFrame03info["2"] = Value(2);//�����ø�infoָ��һ���µ�ַ��û�б���ô�
	hoveringAnimationChekcInTheWaterInfo["-1ppp"] = Value(-1231231);
	//log("here three = %s,", hoveringAnimationFrame04info["FrameId"].asString());//��֪Ϊʲô�������string��string���ɣ�����ֻ����ȷ������֡�

	hoveringRightAnimation->getFrames().at(1)->setUserInfo(hoveringAnimationFrame01info);
	hoveringRightAnimation->getFrames().at(3)->setUserInfo(hoveringAnimationFrame03info);
	hoveringRightAnimation->getFrames().at(0)->setUserInfo(hoveringAnimationChekcInTheWaterInfo);


	hoveringLeftAnimation->getFrames().at(1)->setUserInfo(hoveringAnimationFrame01info);
	hoveringLeftAnimation->getFrames().at(3)->setUserInfo(hoveringAnimationFrame03info);
	hoveringLeftAnimation->getFrames().at(0)->setUserInfo(hoveringAnimationChekcInTheWaterInfo);


	EventListenerCustom * hoveringAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hoveringAnimationFrame03info, hoveringAnimationFrame01info, hoveringAnimationChekcInTheWaterInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		//log("Target %p with data %s , if this frame added 03 = %d. ", userData->target, Value(userData->userInfo).getDescription().c_str(), *userData->userInfo == hoveringAnimationFrame03info);
		//log("Value(userData->userInfo).asString = %s",Value(userData->userInfo).asString());
		if (*userData->userInfo == hoveringAnimationFrame03info){
			this->setPositionY(this->getPositionY() + 3);
		}
		if (*userData->userInfo == hoveringAnimationFrame01info){
			this->setPositionY(this->getPositionY() - 3);
			this->invincible = false;


			if (this->getPositionY() < ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY()){
				this->transformFromBirdToFish();
			}
		}
		if (*userData->userInfo == hoveringAnimationChekcInTheWaterInfo){
			if (this->getPositionY() < ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY()){
				this->transformFromBirdToFish();
			}
			this->enableAllAbilities();
			this->invincible = false;
		}

	});

	//�����¼���ӵ��¼��ַ���
	_eventDispatcher->addEventListenerWithFixedPriority(hoveringAnimationFrameEventListener, -1);
	//֡�¼����ӽ�����

	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));



	//Moving events won't need frame events. However, slight up-down swings during horizontal flights would be welcome.


	ValueMap movingCheckIfToTransferBTFInfo;

	movingCheckIfToTransferBTFInfo["-2"] = Value(-2);


	EventListenerCustom * movingAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingCheckIfToTransferBTFInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		//log("Target %p with data %s , if this frame added 03 = %d. ", userData->target, Value(userData->userInfo).getDescription().c_str(), *userData->userInfo == hoveringAnimationFrame03info);
		//log("Value(userData->userInfo).asString = %s",Value(userData->userInfo).asString());
		if (*userData->userInfo == movingCheckIfToTransferBTFInfo){
			if (this->getPositionY() - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY()   < this->getContentSize().height * 45 / 100){
				this->transformFromBirdToFish();
				

			}
			this->invincible = false;

		}


	});

	
	_eventDispatcher->addEventListenerWithFixedPriority(movingAnimationFrameEventListener, -1);



	this->movingRightAnimation = Animation::create(); 
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_right_00.png");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_right_01.png");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_right_02.png");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_right_03.png");
	this->movingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_right_04.png");
	this->movingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingRightAnimation->setRestoreOriginalFrame(true);
	this->movingRightAnimation->retain();

	this->movingRightAnimation->getFrames().at(0)->setUserInfo(movingCheckIfToTransferBTFInfo);


	this->movingUpRightAnimation = Animation::create();
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_upright_00.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_upright_01.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_upright_02.png");
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_upright_03.png"); 
	this->movingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_upright_04.png");

	this->movingUpRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpRightAnimation->setRestoreOriginalFrame(true);
	this->movingUpRightAnimation->retain();

	this->movingDownRightAnimation = Animation::create();
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_downright_00.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_downright_01.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_downright_02.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_downright_03.png");
	this->movingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_downright_04.png");

	this->movingDownRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownRightAnimation->setRestoreOriginalFrame(true);
	this->movingDownRightAnimation->retain();

	this->movingDownRightAnimation->getFrames().at(0)->setUserInfo(movingCheckIfToTransferBTFInfo);
	this->movingDownRightAnimation->getFrames().at(1)->setUserInfo(movingCheckIfToTransferBTFInfo);
	this->movingDownRightAnimation->getFrames().at(2)->setUserInfo(movingCheckIfToTransferBTFInfo);
	this->movingDownRightAnimation->getFrames().at(3)->setUserInfo(movingCheckIfToTransferBTFInfo);

	this->movingLeftAnimation = Animation::create();
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_left_00.png");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_left_01.png");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_left_02.png");
	this->movingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_left_03.png");
	this->movingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingLeftAnimation->setRestoreOriginalFrame(true);
	this->movingLeftAnimation->retain();

	this->movingLeftAnimation->getFrames().at(0)->setUserInfo(movingCheckIfToTransferBTFInfo);


	this->movingDownLeftAnimation = Animation::create();
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_downleft_00.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_downleft_01.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_downleft_02.png");
	this->movingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_downleft_03.png");
	this->movingDownLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->movingDownLeftAnimation->retain();


	this->movingDownLeftAnimation->getFrames().at(0)->setUserInfo(movingCheckIfToTransferBTFInfo);
	this->movingDownLeftAnimation->getFrames().at(1)->setUserInfo(movingCheckIfToTransferBTFInfo);
	this->movingDownLeftAnimation->getFrames().at(2)->setUserInfo(movingCheckIfToTransferBTFInfo);
	this->movingDownLeftAnimation->getFrames().at(3)->setUserInfo(movingCheckIfToTransferBTFInfo);

	this->movingUpLeftAnimation = Animation::create();
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_upleft_00.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_upleft_01.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_upleft_02.png");
	this->movingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_moving_upleft_03.png");
	this->movingUpLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->movingUpLeftAnimation->retain();


	//���Զ�̹�������
	this->blowingWindRightAnimation = Animation::create();
	this->blowingWindRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_right_00.png");
	this->blowingWindRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_right_01.png");
	this->blowingWindRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_right_02.png");
	this->blowingWindRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_right_03.png");
	this->blowingWindRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_right_03.png");
	this->blowingWindRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->blowingWindRightAnimation->setRestoreOriginalFrame(true);
	this->blowingWindRightAnimation->retain();

	ValueMap blowingStartInfo;
	ValueMap blowingLaunchingWindBulletInfo;
	ValueMap blowingRecoverAllAbilitiesInfo;
	ValueMap blowingEndInfo;

	blowingStartInfo["10"] = Value(10);
	blowingLaunchingWindBulletInfo["11"] = Value(11);
	blowingRecoverAllAbilitiesInfo["12"] = Value(12);
	blowingEndInfo["13"] = Value(13);

	this->blowingWindRightAnimation->getFrames().at(0)->setUserInfo(blowingStartInfo);
	this->blowingWindRightAnimation->getFrames().at(1)->setUserInfo(blowingLaunchingWindBulletInfo);
	this->blowingWindRightAnimation->getFrames().at(3)->setUserInfo(blowingRecoverAllAbilitiesInfo);
	this->blowingWindRightAnimation->getFrames().at(4)->setUserInfo(blowingEndInfo);

	EventListenerCustom * blowingWindAnimationFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, blowingStartInfo, blowingLaunchingWindBulletInfo, blowingRecoverAllAbilitiesInfo, blowingEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == blowingStartInfo){
			//log("Hitting first frame of blowing. ");
			this->disableAllAbilities();
		}
		if (*userData->userInfo == blowingLaunchingWindBulletInfo){
			int windBulletNumber = this->launchedWindBulletCount % this->NUM_OF_WIND_BULLETS;
			if (this->facingRight){
				//this->setPositionX(this->getPositionX() - 30);
				this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(-10, 0)), MoveBy::create(0.2f, Vec2(-10, 0)), nullptr));
				Sprite * windBullet = this->windBullets[windBulletNumber];
				windBullet->setPosition(this->getPosition());
				this->getParent()->addChild(windBullet);
				windBullet->runAction(Spawn::create(MoveBy::create(0.4f, Vec2(300, 0)), Repeat::create(Animate::create(this->windBulletFlyingAnimation), 2), nullptr));
			}
			else if (this->facingLeft){
				//this->setPositionX(this->getPositionX()+ 30);
				this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(10, 0)), MoveBy::create(0.2f, Vec2(10, 0)), nullptr));
				Sprite * windBullet = this->windBullets[windBulletNumber];
				windBullet->setPosition(this->getPosition());
				this->getParent()->addChild(windBullet);
				windBullet->runAction(Spawn::create(MoveBy::create(0.4f, Vec2(-300, 0)), Repeat::create(Animate::create(this->windBulletFlyingAnimation), 2), nullptr));
			}
			this->launchedWindBulletCount++;
			log("%dth bullet launched.",this->launchedWindBulletCount);
			this->windAttackable = true;
		}
		if (*userData->userInfo == blowingRecoverAllAbilitiesInfo){
			this->enableAllAbilities();
			this->spittable = false;
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}
		}
		if (*userData->userInfo == blowingEndInfo){
			log("Hitting last frame of blowing. Hovering.");
			this->hover();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(blowingWindAnimationFrameEventListener, -1);

	this->blowingWindLeftAnimation = Animation::create();
	this->blowingWindLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_left_00.png");
	this->blowingWindLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_left_01.png");
	this->blowingWindLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_left_02.png");
	this->blowingWindLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_left_03.png");
	this->blowingWindLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_windattacking_left_03.png");
	this->blowingWindLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->blowingWindLeftAnimation->setRestoreOriginalFrame(true);
	this->blowingWindLeftAnimation->retain();


	this->blowingWindLeftAnimation->getFrames().at(0)->setUserInfo(blowingStartInfo);
	this->blowingWindLeftAnimation->getFrames().at(1)->setUserInfo(blowingLaunchingWindBulletInfo);
	this->blowingWindLeftAnimation->getFrames().at(3)->setUserInfo(blowingRecoverAllAbilitiesInfo);
	this->blowingWindLeftAnimation->getFrames().at(4)->setUserInfo(blowingEndInfo);


	//�絯��תȦ������Ӧ��Ϊ����֡����������˾ͱ�ը�Ķ���
	this->windBulletFlyingAnimation = Animation::create();
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_00.png");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_01.png");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_02.png");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_03.png");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_00.png");
	this->windBulletFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_01.png");
	this->windBulletFlyingAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->windBulletFlyingAnimation->setRestoreOriginalFrame(true);
	this->windBulletFlyingAnimation->retain();

	ValueMap windBulletCheckHitInfo;
	ValueMap windBulletEndInfo;
	windBulletCheckHitInfo["19"] = Value(19);
	windBulletEndInfo["20"] = Value(20);

	this->windBulletFlyingAnimation->getFrames().at(0)->setUserInfo(windBulletCheckHitInfo);
	this->windBulletFlyingAnimation->getFrames().at(1)->setUserInfo(windBulletCheckHitInfo);
	this->windBulletFlyingAnimation->getFrames().at(2)->setUserInfo(windBulletCheckHitInfo);
	this->windBulletFlyingAnimation->getFrames().at(3)->setUserInfo(windBulletCheckHitInfo);
	this->windBulletFlyingAnimation->getFrames().at(4)->setUserInfo(windBulletCheckHitInfo);
	this->windBulletFlyingAnimation->getFrames().at(5)->setUserInfo(windBulletEndInfo);

	EventListenerCustom * windBulletFlyingAnimationFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, windBulletCheckHitInfo, windBulletEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == windBulletCheckHitInfo){
			//userData���target��������run��һ֡�Ķ�������A->runAction(Animate::...)��A���������target
			WindBullet*  wb = (WindBullet *)(userData->target);
			int windBulletPositionX = wb->getPositionX();
			int windBulletPositionY = wb->getPositionY();



			int heightDifference = windBulletPositionY - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY();
			if (-wb->getContentSize().height / 2 < heightDifference && heightDifference < wb->getContentSize().height / 2){
				Sprite * bigSplash = Sprite::create("landscapes/splash_big_00.png");
				bigSplash->setPositionX(windBulletPositionX);
				bigSplash->setPositionY(((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY());
				this->getParent()->addChild(bigSplash);
				bigSplash->runAction(Animate::create(this->waterSplashingAnimation_big));
			}


			//log("Here is windbullet running 1st frame of windbulletflyinganimation. Some data from wb = %d",wb->magazineX);
			Vector < GeneralUnit * > elist = ((Stage1GameplayLayer *)(this->getParent()))->enemyList;
			for (GeneralUnit * enemy : elist){
				int deltax = enemy->getPositionX() - windBulletPositionX;
				int deltay = enemy->getPositionY() - windBulletPositionY;

				double distance = sqrt(deltax*deltax + deltay*deltay);
				if (distance < wb->getContentSize().width/2+enemy->getContentSize().width/2){
					int windBulletExplosionNumber = this->windBulletExplosionCount % this->NUM_OF_WIND_BULLET_EXPLOSIONS;

					Sprite * explosion = this->windBulletExplosions[windBulletExplosionNumber];
					explosion->setPosition(windBulletPositionX,windBulletPositionY);
					this->getParent()->addChild(explosion);
					explosion->runAction(Animate::create(this->windBulletExplosionAnimation));

					this->windBulletExplosionCount++;
					
					//enemy->getHurtByPaw(10);
					wb->removeFromParent();
					break;
				}
			}

		}
		if (*userData->userInfo == windBulletEndInfo){
			WindBullet*  wb = (WindBullet *)(userData->target);
			wb->removeFromParent();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(windBulletFlyingAnimationFrameEventListener,-1);


	//�絯��ը��Ч����ֻ�е�һ֡���й����ж�������֡�����걬ըЧ���� ���һ֡��target�Ӹ��ڵ��Ƴ���
	this->windBulletExplosionAnimation = Animation::create();
	this->windBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_exploding_00.png");
	this->windBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_exploding_01.png");
	this->windBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_exploding_02.png");
	this->windBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_exploding_03.png");
	this->windBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_exploding_04.png");
	this->windBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_exploding_05.png");
	this->windBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/wind_bullet_exploding_05.png");
	this->windBulletExplosionAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->windBulletExplosionAnimation->setRestoreOriginalFrame(true);
	this->windBulletExplosionAnimation->retain();

	ValueMap windBulletExplosionDealDamageInfo;
	ValueMap windBulletExplosionEndInfo;

	windBulletExplosionDealDamageInfo["21"] = Value(21);
	windBulletExplosionEndInfo["22"] = Value(22);

	this->windBulletExplosionAnimation->getFrames().at(0)->setUserInfo(windBulletExplosionDealDamageInfo);
	this->windBulletExplosionAnimation->getFrames().at(6)->setUserInfo(windBulletExplosionEndInfo);

	EventListenerCustom * windBulletExplosionFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, windBulletExplosionDealDamageInfo,windBulletExplosionEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == windBulletExplosionDealDamageInfo){
			Sprite*  windBulletExplosion = (Sprite *)(userData->target);

			Vector < GeneralUnit * > elist = ((Stage1GameplayLayer *)(this->getParent()))->enemyList;
			for (GeneralUnit * enemy : elist){
				int deltax = enemy->getPositionX() - windBulletExplosion->getPositionX();
				int deltay = enemy->getPositionY() - windBulletExplosion->getPositionY();

				double distance = sqrt(deltax*deltax + deltay*deltay);
				if (distance < (windBulletExplosion->getContentSize().width + enemy->getContentSize().width) * 75 / 100){
					enemy->getHurtByWind(this->DAMAGE_WIND);
				}
			}


			//windBulletExplosion->removeFromParent();
		}
		if (*userData->userInfo == windBulletExplosionEndInfo){
			Sprite*  windBulletExplosion = (Sprite *)(userData->target);
			windBulletExplosion->removeFromParent();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(windBulletExplosionFrameEventListener, -1);

	//dashing animations would need frame events.
	this->dashingRightAnimation = Animation::create();
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_00.png");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_01.png");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_02.png");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_03.png");
	this->dashingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_right_04.png");
	this->dashingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingRightAnimation->setRestoreOriginalFrame(true);
	this->dashingRightAnimation->retain();


	ValueMap dashingRightFrame00Info;
	ValueMap dashingCheckIfToTransformInfo;
	ValueMap dashingRightFrame02Info;
	ValueMap dashingRightFrame03Info;

	dashingRightFrame00Info["3"] = Value(3);
	dashingCheckIfToTransformInfo["-33"] = Value(-33);
	dashingRightFrame02Info["4"] = Value(4);
	dashingRightFrame03Info["333"] = Value(333);

	this->dashingRightAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingRightAnimation->getFrames().at(1)->setUserInfo(dashingCheckIfToTransformInfo);

	this->dashingRightAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingRightAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);

	EventListenerCustom * dashingRightAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, dashingRightFrame00Info, dashingCheckIfToTransformInfo, dashingRightFrame02Info, dashingRightFrame03Info](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dashingRightFrame00Info){
			this->disableAllAbilities();
			if (this->getPositionY() < ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY()){
				this->enableAllAbilities();
				this->transformFromBirdToFish();
			}
		}
		if (*userData->userInfo == dashingCheckIfToTransformInfo){
			if (this->getPositionY() < ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY()){
				this->transformFromBirdToFish();
			}
		}
		
		if (*userData->userInfo == dashingRightFrame02Info){
			this->enableAllAbilities();
			if (this->getPositionY() < ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY()){

				this->transformFromBirdToFish();
			}
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}
		}
		if (*userData->userInfo == dashingRightFrame03Info){
			log("Hitting last frame of dashing. Hovering.");
			
			if (this->getPositionY() < ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY()){
				this->transformFromBirdToFish();
			}
			else{
				this->hover();
			}
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dashingRightAnimationFrameEventListener, -1);

	this->dashingDownRightAnimation = Animation::create();
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_00.png");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_01.png");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_02.png");
	this->dashingDownRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downright_03.png");
	this->dashingDownRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingDownRightAnimation->setRestoreOriginalFrame(true);
	this->dashingDownRightAnimation->retain();

	this->dashingDownRightAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingDownRightAnimation->getFrames().at(1)->setUserInfo(dashingCheckIfToTransformInfo);
	this->dashingDownRightAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingDownRightAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);



	this->dashingUpRightAnimation = Animation::create();
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_00.png");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_01.png");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_02.png");
	this->dashingUpRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upright_03.png");
	this->dashingUpRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingUpRightAnimation->setRestoreOriginalFrame(true);
	this->dashingUpRightAnimation->retain();

	this->dashingUpRightAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingUpRightAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingUpRightAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);




	this->dashingLeftAnimation = Animation::create();
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_00.png");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_01.png");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_02.png");
	this->dashingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_left_03.png");
	this->dashingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingLeftAnimation->retain();

	this->dashingLeftAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingLeftAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingLeftAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);



	this->dashingUpLeftAnimation = Animation::create();
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_00.png");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_01.png");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_02.png");
	this->dashingUpLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_upleft_03.png");
	this->dashingUpLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingUpLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingUpLeftAnimation->retain();

	this->dashingUpLeftAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingUpLeftAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingUpLeftAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);


	this->dashingDownLeftAnimation = Animation::create();
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_00.png");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_03.png");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_03.png");
	this->dashingDownLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_dashing_downleft_03.png");
	this->dashingDownLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingDownLeftAnimation->setRestoreOriginalFrame(true);
	this->dashingDownLeftAnimation->retain();

	this->dashingDownLeftAnimation->getFrames().at(0)->setUserInfo(dashingRightFrame00Info);
	this->dashingDownLeftAnimation->getFrames().at(1)->setUserInfo(dashingCheckIfToTransformInfo);

	this->dashingDownLeftAnimation->getFrames().at(2)->setUserInfo(dashingRightFrame02Info);
	this->dashingDownLeftAnimation->getFrames().at(3)->setUserInfo(dashingRightFrame03Info);





	//paws scratching right will need 2 animations: horizontal scratching and vertical scratching
	//same for scratching left.
	this->scratchingRightAnimation = Animation::create();
	this->scratchingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_right_00.png");
	this->scratchingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_right_01.png");
	this->scratchingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_right_02.png");
	this->scratchingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_right_03.png");
	this->scratchingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_right_04.png");
	this->scratchingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchingRightAnimation->setRestoreOriginalFrame(true);
	this->scratchingRightAnimation->retain();

	ValueMap scratchingStartInfo;
	ValueMap scratchingLoseAllAbilitiesInfo;
	ValueMap scratchingRecoverScratchabilityInfo;
	ValueMap scratchingRecoverAllAbilitiesInfo;
	ValueMap scratchingToHoveringInfo;

	scratchingStartInfo["5"] = Value(5);
	scratchingLoseAllAbilitiesInfo["6"] = Value(6);
	scratchingRecoverScratchabilityInfo["7"] = Value(7);
	scratchingRecoverAllAbilitiesInfo["8"] = Value(8);
	scratchingToHoveringInfo["9"] = Value(9);

	scratchingRightAnimation->getFrames().at(0)->setUserInfo(scratchingStartInfo);
	scratchingRightAnimation->getFrames().at(1)->setUserInfo(scratchingLoseAllAbilitiesInfo);
	scratchingRightAnimation->getFrames().at(2)->setUserInfo(scratchingRecoverScratchabilityInfo);
	scratchingRightAnimation->getFrames().at(3)->setUserInfo(scratchingRecoverAllAbilitiesInfo);
	scratchingRightAnimation->getFrames().at(4)->setUserInfo(scratchingToHoveringInfo);

	EventListenerCustom * scratchingFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, scratchingStartInfo, scratchingLoseAllAbilitiesInfo, scratchingRecoverScratchabilityInfo, scratchingRecoverAllAbilitiesInfo, scratchingToHoveringInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == scratchingStartInfo){
			this->disableAllAbilities();
			if (this->directionToMoveRight){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(this->DISTANCE_DURING_SCRATCHING, 0)));
			}
			else if (this->directionToMoveLeft){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(-this->DISTANCE_DURING_SCRATCHING, 0)));
			}
			else if (this->directionToMoveUp){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(0, this->DISTANCE_DURING_SCRATCHING)));
			}
			else if (this->directionToMoveDown){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(0, -this->DISTANCE_DURING_SCRATCHING)));
			}
			else if (this->directionToMoveUpRight){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(this->DISTANCE_DURING_SCRATCHING / 1.414, this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
			else if (this->directionToMoveUpLeft){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(-this->DISTANCE_DURING_SCRATCHING / 1.414, this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
			else if (this->directionToMoveDownRight){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(this->DISTANCE_DURING_SCRATCHING / 1.414, -this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
			else if (this->directionToMoveDownLeft){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(-this->DISTANCE_DURING_SCRATCHING / 1.414, -this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
		}
		if (*userData->userInfo == scratchingLoseAllAbilitiesInfo){
			log("scratch-attacking at frame2");

			if (this->scratchingType == 1){
				if (this->facingLeft){
					//����typeΪ1��������ߵĵ���
					Sprite * bladeEffect = Sprite::create("characters/kunpeng/peng_scratch_left_blade_effect_00.png");
					bladeEffect->setPositionX(this->getPositionX() - this->getContentSize().width/2);
					bladeEffect->setPositionY(this->getPositionY());
					this->getParent()->addChild(bladeEffect);
					bladeEffect->runAction(Animate::create(this->scratchLeftBladeEffectAnimation));
				}
				else{
					//����typeΪ1�������ұߵĵ���
					Sprite * bladeEffect = Sprite::create("characters/kunpeng/peng_scratch_right_blade_effect_00.png");
					bladeEffect->setPositionX(this->getPositionX() + this->getContentSize().width / 2);
					bladeEffect->setPositionY(this->getPositionY());
					this->getParent()->addChild(bladeEffect);
					bladeEffect->runAction(Animate::create(this->scratchRightBladeEffectAnimation));
				}
				this->scratchingType = 2;
			}
			else if (this->scratchingType == 2){
				if (this->facingLeft){
					//����typeΪ2��������ߵĵ���
					Sprite * bladeEffect = Sprite::create("characters/kunpeng/peng_scratch_left_blade_effect2_00.png");
					bladeEffect->setPositionX(this->getPositionX() - this->getContentSize().width / 2);
					bladeEffect->setPositionY(this->getPositionY());
					this->getParent()->addChild(bladeEffect);
					bladeEffect->runAction(Animate::create(this->scratchLeftBladeEffect2Animation));
				}
				else{
					//����typeΪ2�������ұߵĵ���
					Sprite * bladeEffect = Sprite::create("characters/kunpeng/peng_scratch_right_blade_effect2_00.png");
					bladeEffect->setPositionX(this->getPositionX() + this->getContentSize().width / 2);
					bladeEffect->setPositionY(this->getPositionY());
					this->getParent()->addChild(bladeEffect);
					bladeEffect->runAction(Animate::create(this->scratchRightBladeEffect2Animation));
				}
				this->scratchingType = 1;
			}
		}
		if (*userData->userInfo == scratchingRecoverScratchabilityInfo){
			this->scratchable = true;
		}
		if (*userData->userInfo == scratchingRecoverAllAbilitiesInfo){
			this->enableAllAbilities();
			this->moveableWithoutAnimation = false;
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move();
			}

		}
		if (*userData->userInfo == scratchingToHoveringInfo){
			this->hover();
			this->scratchingType = 1;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(scratchingFrameEventListener, -1);

	this->scratchingRightAnimation2 = Animation::create();
	this->scratchingRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_right_00.png");
	this->scratchingRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_right_01.png");
	this->scratchingRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_right_02.png");
	this->scratchingRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_right_03.png");
	this->scratchingRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_right_04.png");
	this->scratchingRightAnimation2->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchingRightAnimation2->setRestoreOriginalFrame(true);
	this->scratchingRightAnimation2->retain();

	this->scratchingRightAnimation2->getFrames().at(0)->setUserInfo(scratchingStartInfo);
	this->scratchingRightAnimation2->getFrames().at(1)->setUserInfo(scratchingLoseAllAbilitiesInfo);
	this->scratchingRightAnimation2->getFrames().at(2)->setUserInfo(scratchingRecoverScratchabilityInfo);
	this->scratchingRightAnimation2->getFrames().at(3)->setUserInfo(scratchingRecoverAllAbilitiesInfo);
	this->scratchingRightAnimation2->getFrames().at(4)->setUserInfo(scratchingToHoveringInfo);


	this->scratchingLeftAnimation = Animation::create();
	this->scratchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_left_00.png");
	this->scratchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_left_01.png");
	this->scratchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_left_02.png");
	this->scratchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_left_03.png");
	this->scratchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching_left_04.png");
	this->scratchingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchingLeftAnimation->setRestoreOriginalFrame(true);
	this->scratchingLeftAnimation->retain();

	this->scratchingLeftAnimation->getFrames().at(0)->setUserInfo(scratchingStartInfo);
	this->scratchingLeftAnimation->getFrames().at(1)->setUserInfo(scratchingLoseAllAbilitiesInfo);
	this->scratchingLeftAnimation->getFrames().at(2)->setUserInfo(scratchingRecoverScratchabilityInfo);
	this->scratchingLeftAnimation->getFrames().at(3)->setUserInfo(scratchingRecoverAllAbilitiesInfo);
	this->scratchingLeftAnimation->getFrames().at(4)->setUserInfo(scratchingToHoveringInfo);

	this->scratchingLeftAnimation2 = Animation::create();
	this->scratchingLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_left_00.png");
	this->scratchingLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_left_01.png");
	this->scratchingLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_left_02.png");
	this->scratchingLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_left_03.png");
	this->scratchingLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/peng_scratching2_left_04.png");
	this->scratchingLeftAnimation2->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchingLeftAnimation2->setRestoreOriginalFrame(true);
	this->scratchingLeftAnimation2->retain();

	this->scratchingLeftAnimation2->getFrames().at(0)->setUserInfo(scratchingStartInfo);
	this->scratchingLeftAnimation2->getFrames().at(1)->setUserInfo(scratchingLoseAllAbilitiesInfo);
	this->scratchingLeftAnimation2->getFrames().at(2)->setUserInfo(scratchingRecoverScratchabilityInfo);
	this->scratchingLeftAnimation2->getFrames().at(3)->setUserInfo(scratchingRecoverAllAbilitiesInfo);
	this->scratchingLeftAnimation2->getFrames().at(4)->setUserInfo(scratchingToHoveringInfo);


	//ץ�ӵĵ��⶯���� TM��Ҫ������
	this->scratchLeftBladeEffectAnimation = Animation::create();
	this->scratchLeftBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_left_blade_effect_00.png");
	this->scratchLeftBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_left_blade_effect_01.png");
	this->scratchLeftBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_left_blade_effect_02.png");
	this->scratchLeftBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_left_blade_effect_03.png");
	this->scratchLeftBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_left_blade_effect_04.png");
	this->scratchLeftBladeEffectAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchLeftBladeEffectAnimation->setRestoreOriginalFrame(true);
	this->scratchLeftBladeEffectAnimation->retain();

	ValueMap scratchBladeEffectDealDamageInfo;
	ValueMap scratchBladeEffectEndInfo;

	scratchBladeEffectDealDamageInfo["-6"] = Value(-6);
	scratchBladeEffectEndInfo["-7"] = Value(-7);

	this->scratchLeftBladeEffectAnimation->getFrames().at(0)->setUserInfo(scratchBladeEffectDealDamageInfo);
	this->scratchLeftBladeEffectAnimation->getFrames().at(4)->setUserInfo(scratchBladeEffectEndInfo);

	EventListenerCustom * scratchBladeEffectFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, scratchBladeEffectDealDamageInfo, scratchBladeEffectEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == scratchBladeEffectDealDamageInfo){
			Sprite*  bladeEffect = (Sprite *)(userData->target);

			Vector < GeneralUnit * > elist = ((Stage1GameplayLayer *)(this->getParent()))->enemyList;
			for (GeneralUnit * enemy : elist){
				int deltax = enemy->getPositionX() - bladeEffect->getPositionX();
				int deltay = enemy->getPositionY() - bladeEffect->getPositionY();

				double distance = sqrt(deltax*deltax + deltay*deltay);
				if (distance < (bladeEffect->getContentSize().width + enemy->getContentSize().width) * 60 / 100){
					enemy->getHurtByWind(this->DAMAGE_SCRATCH);//���Ҫ�ġ�
				}
			}


			//windBulletExplosion->removeFromParent();
		}
		if (*userData->userInfo == scratchBladeEffectEndInfo){
			Sprite*  bladeEffect = (Sprite *)(userData->target);
			bladeEffect->removeFromParent();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(scratchBladeEffectFrameEventListener, -1);


	this->scratchLeftBladeEffect2Animation = Animation::create();
	this->scratchLeftBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_left_blade_effect2_00.png");
	this->scratchLeftBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_left_blade_effect2_01.png");
	this->scratchLeftBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_left_blade_effect2_02.png");
	this->scratchLeftBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_left_blade_effect2_03.png");
	this->scratchLeftBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_left_blade_effect2_04.png");
	this->scratchLeftBladeEffect2Animation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchLeftBladeEffect2Animation->setRestoreOriginalFrame(true);
	this->scratchLeftBladeEffect2Animation->retain();

	this->scratchLeftBladeEffect2Animation->getFrames().at(0)->setUserInfo(scratchBladeEffectDealDamageInfo);
	this->scratchLeftBladeEffect2Animation->getFrames().at(4)->setUserInfo(scratchBladeEffectEndInfo);

	this->scratchRightBladeEffectAnimation = Animation::create();
	this->scratchRightBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_right_blade_effect_00.png");
	this->scratchRightBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_right_blade_effect_01.png");
	this->scratchRightBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_right_blade_effect_02.png");
	this->scratchRightBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_right_blade_effect_03.png");
	this->scratchRightBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_right_blade_effect_04.png");
	this->scratchRightBladeEffectAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchRightBladeEffectAnimation->setRestoreOriginalFrame(true);
	this->scratchRightBladeEffectAnimation->retain();

	this->scratchRightBladeEffectAnimation->getFrames().at(0)->setUserInfo(scratchBladeEffectDealDamageInfo);
	this->scratchRightBladeEffectAnimation->getFrames().at(4)->setUserInfo(scratchBladeEffectEndInfo);

	this->scratchRightBladeEffect2Animation = Animation::create();
	this->scratchRightBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_right_blade_effect2_00.png");
	this->scratchRightBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_right_blade_effect2_01.png");
	this->scratchRightBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_right_blade_effect2_02.png");
	this->scratchRightBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_right_blade_effect2_03.png");
	this->scratchRightBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/peng_scratch_right_blade_effect2_04.png");
	this->scratchRightBladeEffect2Animation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->scratchRightBladeEffect2Animation->setRestoreOriginalFrame(true);
	this->scratchRightBladeEffect2Animation->retain();

	this->scratchRightBladeEffect2Animation->getFrames().at(0)->setUserInfo(scratchBladeEffectDealDamageInfo);
	this->scratchRightBladeEffect2Animation->getFrames().at(4)->setUserInfo(scratchBladeEffectEndInfo);




	//���˶���
	this->gettingHurtGeneralAnimation = Animation::create();
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_00.png");
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_01.png");
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_02.png");
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_03.png");
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_00.png");
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_01.png");
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_02.png");
	this->gettingHurtGeneralAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_general_03.png");
	this->gettingHurtGeneralAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->gettingHurtGeneralAnimation->setRestoreOriginalFrame(true);
	this->gettingHurtGeneralAnimation->retain();

	ValueMap gettingHurtGeneralStartInfo;
	ValueMap gettingHurtGeneralRecoverMovabilityInfo;
	ValueMap gettingHurtGeneralEndInfo;

	gettingHurtGeneralStartInfo["14"] = Value(10);
	gettingHurtGeneralRecoverMovabilityInfo["14.5"] = Value(14.5);
	gettingHurtGeneralEndInfo["15"] = Value(11);


	this->gettingHurtGeneralAnimation->getFrames().at(0)->setUserInfo(gettingHurtGeneralStartInfo);
	this->gettingHurtGeneralAnimation->getFrames().at(5)->setUserInfo(gettingHurtGeneralRecoverMovabilityInfo);
	this->gettingHurtGeneralAnimation->getFrames().at(7)->setUserInfo(gettingHurtGeneralEndInfo);

	EventListenerCustom * gettingHurtGeneralFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, gettingHurtGeneralStartInfo, gettingHurtGeneralRecoverMovabilityInfo, gettingHurtGeneralEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == gettingHurtGeneralStartInfo){
			//log("get hurt");
			this->disableAllAbilities();
			this->invincible = true;
		}
		if (*userData->userInfo == gettingHurtGeneralRecoverMovabilityInfo){
			//log("get hurt");
			this->enableAllAbilities();
			this->invincible = false;
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move_forBothShapes();
			}

		}
		if (*userData->userInfo == gettingHurtGeneralEndInfo){
			//log("recovering from getting hurt");
			this->enableAllAbilities();
			this->invincible = false;
			if (this->isBird) this->hover();
			else this->hover_kun();
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move_forBothShapes();
			}
		}
	});

	_eventDispatcher->addEventListenerWithFixedPriority(gettingHurtGeneralFrameEventListener, -1);


	this->gettingHurtRightGeneralAnimation_peng = Animation::create();
	this->gettingHurtRightGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_right_00.png");
	this->gettingHurtRightGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_right_01.png");
	this->gettingHurtRightGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_right_02.png");
	this->gettingHurtRightGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_right_03.png");
	this->gettingHurtRightGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_right_00.png");

	this->gettingHurtRightGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_right_01.png");
	this->gettingHurtRightGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_right_02.png");
	this->gettingHurtRightGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_right_03.png");
	this->gettingHurtRightGeneralAnimation_peng->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->gettingHurtRightGeneralAnimation_peng->setRestoreOriginalFrame(true);
	this->gettingHurtRightGeneralAnimation_peng->retain();

	this->gettingHurtRightGeneralAnimation_peng->getFrames().at(0)->setUserInfo(gettingHurtGeneralStartInfo);
	this->gettingHurtRightGeneralAnimation_peng->getFrames().at(5)->setUserInfo(gettingHurtGeneralRecoverMovabilityInfo);
	this->gettingHurtRightGeneralAnimation_peng->getFrames().at(7)->setUserInfo(gettingHurtGeneralEndInfo);

	this->gettingHurtLeftGeneralAnimation_peng = Animation::create();
	this->gettingHurtLeftGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_left_00.png");
	this->gettingHurtLeftGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_left_01.png");
	this->gettingHurtLeftGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_left_02.png");
	this->gettingHurtLeftGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_left_03.png");	
	this->gettingHurtLeftGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_left_00.png");
	this->gettingHurtLeftGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_left_01.png");
	this->gettingHurtLeftGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_left_02.png");
	this->gettingHurtLeftGeneralAnimation_peng->addSpriteFrameWithFileName("characters/kunpeng/peng_getting_hurt_left_03.png");
	this->gettingHurtLeftGeneralAnimation_peng->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->gettingHurtLeftGeneralAnimation_peng->setRestoreOriginalFrame(true);
	this->gettingHurtLeftGeneralAnimation_peng->retain();

	this->gettingHurtLeftGeneralAnimation_peng->getFrames().at(0)->setUserInfo(gettingHurtGeneralStartInfo);
	this->gettingHurtLeftGeneralAnimation_peng->getFrames().at(5)->setUserInfo(gettingHurtGeneralRecoverMovabilityInfo);
	this->gettingHurtLeftGeneralAnimation_peng->getFrames().at(7)->setUserInfo(gettingHurtGeneralEndInfo);


	//�����Ķ���
	this->TransformingFromBirdToFishAnimation = Animation::create();  
	this->TransformingFromBirdToFishAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_transforming_to_kun_00.png");
	this->TransformingFromBirdToFishAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_transforming_to_kun_01.png");
	this->TransformingFromBirdToFishAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_transforming_to_kun_02.png");
	this->TransformingFromBirdToFishAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_transforming_to_kun_03.png");
	this->TransformingFromBirdToFishAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->TransformingFromBirdToFishAnimation->setRestoreOriginalFrame(true);
	this->TransformingFromBirdToFishAnimation->retain();

	ValueMap transformingBTFStartInfo;
	ValueMap transformingBTFRecoverAllAbilitiesInfo;
	ValueMap transformingBTFEndInfo;

	transformingBTFStartInfo["16"] = Value(16);
	transformingBTFRecoverAllAbilitiesInfo["17"] = Value(17);
	transformingBTFEndInfo["18"] = Value(18);

	this->TransformingFromBirdToFishAnimation->getFrames().at(0)->setUserInfo(transformingBTFStartInfo);
	this->TransformingFromBirdToFishAnimation->getFrames().at(2)->setUserInfo(transformingBTFRecoverAllAbilitiesInfo);
	this->TransformingFromBirdToFishAnimation->getFrames().at(3)->setUserInfo(transformingBTFEndInfo);

	EventListenerCustom * transformingFromBirdToFishAnimationFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, transformingBTFStartInfo, transformingBTFRecoverAllAbilitiesInfo, transformingBTFEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == transformingBTFStartInfo){
			this->disableAllAbilities();
		}
		if (*userData->userInfo == transformingBTFRecoverAllAbilitiesInfo){
			this->enableAllAbilities();

			this->isBird = false;
			this->isFish = true;
			this->transformable_BirdToFish = false;
			this->inTheAir = false;
			this->inTheWater = true;


			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move_forBothShapes();
			}


		}
		if (*userData->userInfo == transformingBTFEndInfo){
			if (this->isBird){
				this->hover();
			}
			else if (this->isFish){
				this->hover_kun();
			}
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(transformingFromBirdToFishAnimationFrameEventListener, -1);



	//��ץһ�µĶ���
	this->tryCatchingRightAnimation = Animation::create();
	this->tryCatchingRightAnimation->addSpriteFrameWithFile("characters/kunpeng/peng_trycatching_right_00.png");
	this->tryCatchingRightAnimation->addSpriteFrameWithFile("characters/kunpeng/peng_trycatching_right_01.png");
	this->tryCatchingRightAnimation->addSpriteFrameWithFile("characters/kunpeng/peng_trycatching_right_02.png");
	this->tryCatchingRightAnimation->addSpriteFrameWithFile("characters/kunpeng/peng_trycatching_right_03.png");
	this->tryCatchingRightAnimation->addSpriteFrameWithFile("characters/kunpeng/peng_trycatching_right_04.png");
	this->tryCatchingRightAnimation->addSpriteFrameWithFile("characters/kunpeng/peng_trycatching_right_05.png");
	this->tryCatchingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->tryCatchingRightAnimation->setRestoreOriginalFrame(true);
	this->tryCatchingRightAnimation->retain();

	this->tryCatchingLeftAnimation = Animation::create();
	this->tryCatchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_trycatching_left_00.png");
	this->tryCatchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_trycatching_left_01.png");
	this->tryCatchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_trycatching_left_02.png");
	this->tryCatchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_trycatching_left_03.png");
	this->tryCatchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_trycatching_left_04.png");
	this->tryCatchingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_trycatching_left_05.png");
	this->tryCatchingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->tryCatchingLeftAnimation->setRestoreOriginalFrame(true);
	this->tryCatchingLeftAnimation->retain();




	//��С������ȥ�Ķ���
	this->slamDunkingEnemyRightAnimation = Animation::create();
	this->slamDunkingEnemyRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_right_00.png");
	this->slamDunkingEnemyRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_right_01.png");
	this->slamDunkingEnemyRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_right_02.png");
	this->slamDunkingEnemyRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_right_03.png");
	this->slamDunkingEnemyRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_right_04.png");
	this->slamDunkingEnemyRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_right_05.png");
	this->slamDunkingEnemyRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->slamDunkingEnemyRightAnimation->setRestoreOriginalFrame(true);
	this->slamDunkingEnemyRightAnimation->retain();

	this->slamDunkingEnemyLeftAnimation = Animation::create();
	this->slamDunkingEnemyLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_left_00.png");
	this->slamDunkingEnemyLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_left_01.png");
	this->slamDunkingEnemyLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_left_02.png");
	this->slamDunkingEnemyLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_left_03.png");
	this->slamDunkingEnemyLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_left_04.png");
	this->slamDunkingEnemyLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_left_05.png");
	this->slamDunkingEnemyLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->slamDunkingEnemyLeftAnimation->setRestoreOriginalFrame(true);
	this->slamDunkingEnemyLeftAnimation->retain();



	//��Boss����ȥ�Ķ�������������¼�֡�������ٶ��ˡ�
	this->slamDunkingBossRightAnimation = Animation::create();
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_00.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_01.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_02.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_03.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_04.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_05.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_06.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_07.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_08.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_09.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_10.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_11.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_12.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_13.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_14.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_15.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_16.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_17.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_18.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_19.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_20.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_21.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_22.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_23.png");
	this->slamDunkingBossRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_right_24.png");
	this->slamDunkingBossRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->slamDunkingBossRightAnimation->setRestoreOriginalFrame(true);
	this->slamDunkingBossRightAnimation->retain();

	this->slamDunkingBossLeftAnimation = Animation::create();
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_00.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_01.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_02.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_03.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_04.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_05.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_06.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_07.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_08.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_09.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_10.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_11.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_12.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_13.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_14.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_15.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_16.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_17.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_18.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_19.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_20.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_21.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_22.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_23.png");
	this->slamDunkingBossLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/peng_slamdunking_boss_left_24.png");

	this->slamDunkingBossLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->slamDunkingBossLeftAnimation->setRestoreOriginalFrame(true);
	this->slamDunkingBossLeftAnimation->retain();
	/*
	*/



	//==============================�����ķֽ���=============================

	//�����˵Ķ���
	this->gettingHurtRightGeneralAnimation_kun = Animation::create();
	this->gettingHurtRightGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_right_00.png");
	this->gettingHurtRightGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_right_01.png");
	this->gettingHurtRightGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_right_02.png");
	this->gettingHurtRightGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_right_03.png");
	this->gettingHurtRightGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_right_00.png");
	this->gettingHurtRightGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_right_01.png");
	this->gettingHurtRightGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_right_02.png");
	this->gettingHurtRightGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_right_03.png");
	this->gettingHurtRightGeneralAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->gettingHurtRightGeneralAnimation_kun->setRestoreOriginalFrame(true);
	this->gettingHurtRightGeneralAnimation_kun->retain();

	this->gettingHurtRightGeneralAnimation_kun->getFrames().at(0)->setUserInfo(gettingHurtGeneralStartInfo);
	this->gettingHurtRightGeneralAnimation_kun->getFrames().at(5)->setUserInfo(gettingHurtGeneralRecoverMovabilityInfo);
	this->gettingHurtRightGeneralAnimation_kun->getFrames().at(7)->setUserInfo(gettingHurtGeneralEndInfo);


	this->gettingHurtLeftGeneralAnimation_kun = Animation::create();
	this->gettingHurtLeftGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_left_00.png");
	this->gettingHurtLeftGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_left_01.png");
	this->gettingHurtLeftGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_left_02.png");
	this->gettingHurtLeftGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_left_03.png");
	this->gettingHurtLeftGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_left_00.png");
	this->gettingHurtLeftGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_left_01.png");
	this->gettingHurtLeftGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_left_02.png");
	this->gettingHurtLeftGeneralAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_getting_hurt_left_03.png");
	this->gettingHurtLeftGeneralAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->gettingHurtLeftGeneralAnimation_kun->setRestoreOriginalFrame(true);
	this->gettingHurtLeftGeneralAnimation_kun->retain();

	this->gettingHurtLeftGeneralAnimation_kun->getFrames().at(0)->setUserInfo(gettingHurtGeneralStartInfo);
	this->gettingHurtLeftGeneralAnimation_kun->getFrames().at(5)->setUserInfo(gettingHurtGeneralRecoverMovabilityInfo);
	this->gettingHurtLeftGeneralAnimation_kun->getFrames().at(7)->setUserInfo(gettingHurtGeneralEndInfo);



	//�����Ķ���
	this->TransformingFromFishToBirdAnimation = Animation::create();
	this->TransformingFromFishToBirdAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_transforming_to_peng_00.png");
	this->TransformingFromFishToBirdAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_transforming_to_peng_01.png");
	this->TransformingFromFishToBirdAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_transforming_to_peng_02.png");
	this->TransformingFromFishToBirdAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_transforming_to_peng_03.png");
	this->TransformingFromFishToBirdAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->TransformingFromFishToBirdAnimation->setRestoreOriginalFrame(true);
	this->TransformingFromFishToBirdAnimation->retain();

	ValueMap transformingFTBStartInfo;
	ValueMap transformingFTBRecoverAllAbilitiesInfo;
	ValueMap transformingFTBEndInfo;

	transformingFTBStartInfo["35"] = Value(35);
	transformingFTBRecoverAllAbilitiesInfo["36"] = Value(36);
	transformingFTBEndInfo["37"] = Value(37);

	this->TransformingFromFishToBirdAnimation->getFrames().at(0)->setUserInfo(transformingFTBStartInfo);
	this->TransformingFromFishToBirdAnimation->getFrames().at(2)->setUserInfo(transformingFTBRecoverAllAbilitiesInfo);
	this->TransformingFromFishToBirdAnimation->getFrames().at(3)->setUserInfo(transformingFTBEndInfo);


	EventListenerCustom * transformingFromFishToBirdAnimationFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, transformingFTBStartInfo, transformingFTBRecoverAllAbilitiesInfo, transformingFTBEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == transformingFTBStartInfo){
			this->disableAllAbilities();
		}
		if (*userData->userInfo == transformingFTBRecoverAllAbilitiesInfo){
			this->enableAllAbilities();

			this->isBird = true;
			this->isFish = false;
			this->transformable_FishToBird = false;
			this->inTheAir = true;
			this->inTheWater = false;


			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move_forBothShapes();
			}


		}
		if (*userData->userInfo == transformingFTBEndInfo){
			this->hover();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(transformingFromFishToBirdAnimationFrameEventListener, -1);



	//�����ĵ��⶯����
	this->finRightBladeEffectAnimation = Animation::create();
	this->finRightBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_right_blade_effect_00.png");
	this->finRightBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_right_blade_effect_01.png");
	this->finRightBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_right_blade_effect_02.png");
	this->finRightBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_right_blade_effect_03.png");
	this->finRightBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_right_blade_effect_04.png");
	this->finRightBladeEffectAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->finRightBladeEffectAnimation->setRestoreOriginalFrame(true);
	this->finRightBladeEffectAnimation->retain();

	ValueMap finAttackBladeEffectDealDamageInfo;
	ValueMap finAttackBladeEffectEndInfo;

	finAttackBladeEffectDealDamageInfo["60"] = Value(60);
	finAttackBladeEffectEndInfo["61"] = Value(61);

	this->finRightBladeEffectAnimation->getFrames().at(0)->setUserInfo(finAttackBladeEffectDealDamageInfo);
	this->finRightBladeEffectAnimation->getFrames().at(4)->setUserInfo(finAttackBladeEffectEndInfo);

	EventListenerCustom * finAttackBladeEffectFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, finAttackBladeEffectDealDamageInfo, finAttackBladeEffectEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == finAttackBladeEffectDealDamageInfo){
			Sprite*  finAttackbladeEffect = (Sprite *)(userData->target);

			Vector < GeneralUnit * > elist = ((Stage1GameplayLayer *)(this->getParent()))->enemyList;
			for (GeneralUnit * enemy : elist){
				int deltax = enemy->getPositionX() - finAttackbladeEffect->getPositionX();
				int deltay = enemy->getPositionY() - finAttackbladeEffect->getPositionY();

				double distance = sqrt(deltax*deltax + deltay*deltay);
				if (distance < (finAttackbladeEffect->getContentSize().width + enemy->getContentSize().width) * 60 / 100){
					enemy->getHurtByWind(this->DAMAGE_SCRATCH);//���Ҫ�ġ�
				}
			}


			//windBulletExplosion->removeFromParent();
		}
		if (*userData->userInfo == finAttackBladeEffectEndInfo){
			Sprite*  finAttackbladeEffect = (Sprite *)(userData->target);
			finAttackbladeEffect->removeFromParent();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(finAttackBladeEffectFrameEventListener, -1);


	this->finRightBladeEffect2Animation = Animation::create();
	this->finRightBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_right_blade_effect2_00.png");
	this->finRightBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_right_blade_effect2_01.png");
	this->finRightBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_right_blade_effect2_02.png");
	this->finRightBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_right_blade_effect2_03.png");
	this->finRightBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_right_blade_effect2_04.png");
	this->finRightBladeEffect2Animation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->finRightBladeEffect2Animation->setRestoreOriginalFrame(true);
	this->finRightBladeEffect2Animation->retain();

	this->finRightBladeEffect2Animation->getFrames().at(0)->setUserInfo(finAttackBladeEffectDealDamageInfo);
	this->finRightBladeEffect2Animation->getFrames().at(4)->setUserInfo(finAttackBladeEffectEndInfo);



	this->finLeftBladeEffectAnimation = Animation::create();
	this->finLeftBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_left_blade_effect_00.png");
	this->finLeftBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_left_blade_effect_01.png");
	this->finLeftBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_left_blade_effect_02.png");
	this->finLeftBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_left_blade_effect_03.png");
	this->finLeftBladeEffectAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_left_blade_effect_04.png");
	this->finLeftBladeEffectAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->finLeftBladeEffectAnimation->setRestoreOriginalFrame(true);
	this->finLeftBladeEffectAnimation->retain();

	this->finLeftBladeEffectAnimation->getFrames().at(0)->setUserInfo(finAttackBladeEffectDealDamageInfo);
	this->finLeftBladeEffectAnimation->getFrames().at(4)->setUserInfo(finAttackBladeEffectEndInfo);




	this->finLeftBladeEffect2Animation = Animation::create();
	this->finLeftBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_left_blade_effect2_00.png");
	this->finLeftBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_left_blade_effect2_01.png");
	this->finLeftBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_left_blade_effect2_02.png");
	this->finLeftBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_left_blade_effect2_03.png");
	this->finLeftBladeEffect2Animation->addSpriteFrameWithFileName("characters/kunpeng/kun_finAttack_left_blade_effect2_04.png");
	this->finLeftBladeEffect2Animation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->finLeftBladeEffect2Animation->setRestoreOriginalFrame(true);
	this->finLeftBladeEffect2Animation->retain();

	this->finLeftBladeEffect2Animation->getFrames().at(0)->setUserInfo(finAttackBladeEffectDealDamageInfo);
	this->finLeftBladeEffect2Animation->getFrames().at(4)->setUserInfo(finAttackBladeEffectEndInfo);




	//�����������
	this->hoveringRightAnimation_kun = Animation::create();
	this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_00.png");
	this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_01.png");
	this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_02.png");
	//this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_03.png");
	this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_04.png");
	this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_05.png");
	this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_06.png");
	this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_07.png");
	//this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_08.png");
	//this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_09.png");
	this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_10.png");
	this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_11.png");
	//this->hoveringRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_right_12.png");
	this->hoveringRightAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringRightAnimation_kun->setRestoreOriginalFrame(true);
	this->hoveringRightAnimation_kun->retain();

	ValueMap hoveringAnimationCheckIfToTransformInfo_kun;
	ValueMap hoveringAnimationFrame01Info_kun;
	ValueMap hoveringAnimationFrame03Info_kun;

	hoveringAnimationCheckIfToTransformInfo_kun["-4"] = Value(-4);
	hoveringAnimationFrame01Info_kun["33"] = Value(33);//�����ø�infoָ��һ���µ�ַ��û�б���ô�
	hoveringAnimationFrame03Info_kun["34"] = Value(34);//�����ø�infoָ��һ���µ�ַ��û�б���ô�

	hoveringRightAnimation_kun->getFrames().at(0)->setUserInfo(hoveringAnimationCheckIfToTransformInfo_kun);
	hoveringRightAnimation_kun->getFrames().at(1)->setUserInfo(hoveringAnimationFrame01Info_kun);
	hoveringRightAnimation_kun->getFrames().at(3)->setUserInfo(hoveringAnimationFrame03Info_kun);


	EventListenerCustom * hoveringKunAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, hoveringAnimationCheckIfToTransformInfo_kun, hoveringAnimationFrame01Info_kun, hoveringAnimationFrame03Info_kun](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == hoveringAnimationCheckIfToTransformInfo_kun){
			this->moving = false;
			this->hovering = true;
			this->dashing = false;


			int heightDifference = this->getPositionY() - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY();

			if (heightDifference > 0){
				this->fallFromSky_kun();
			}
			else if (heightDifference > -this->getContentSize().height * 25 / 100){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(0, heightDifference)));
			}
			/*
			if (((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY() - this->getPositionY() < this->getContentSize().height * 25 / 100){
				//this->transformFromFishToBird();
				int heightDifference = ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY() - this->getPositionY() - this->getContentSize().height * 35 / 100;
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(0, heightDifference)));
			}
			*/
		}
		if (*userData->userInfo == hoveringAnimationFrame01Info_kun){
			this->setPositionY(this->getPositionY() + 3);
			int heightDifference = this->getPositionY() - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY();

			if (heightDifference > 0){
				this->fallFromSky_kun();
			}
			else if (heightDifference > -this->getContentSize().height * 25 / 100){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(0, heightDifference)));
			}

			this->invincible = false;

		}
		if (*userData->userInfo == hoveringAnimationFrame03Info_kun){
			this->setPositionY(this->getPositionY() - 3);
			int heightDifference = this->getPositionY() - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY();

			if (heightDifference > 0){
				this->fallFromSky_kun();
			}
			else if (heightDifference > -this->getContentSize().height * 25 / 100){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(0, heightDifference)));
			}
		}
		
	});

	_eventDispatcher->addEventListenerWithFixedPriority(hoveringKunAnimationFrameEventListener, -1);

	this->hoveringLeftAnimation_kun = Animation::create();
	this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_00.png");
	this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_01.png");
	this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_02.png");
	//this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_03.png");
	this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_04.png");
	this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_05.png");
	this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_06.png");
	this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_07.png");
	//this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_08.png");
	//this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_09.png");
	this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_10.png");
	this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_11.png");
	//this->hoveringLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_hovering_left_12.png");
	this->hoveringLeftAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->hoveringLeftAnimation_kun->setRestoreOriginalFrame(true);
	this->hoveringLeftAnimation_kun->retain();

	this->hoveringLeftAnimation_kun->getFrames().at(0)->setUserInfo(hoveringAnimationCheckIfToTransformInfo_kun);
	this->hoveringLeftAnimation_kun->getFrames().at(1)->setUserInfo(hoveringAnimationFrame01Info_kun);
	this->hoveringLeftAnimation_kun->getFrames().at(3)->setUserInfo(hoveringAnimationFrame03Info_kun);

	//�����ͨ�ƶ���������ʱ�ɽ�����һ����������һ���������
	this->movingRightAnimation_kun = Animation::create();
	this->movingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_right_00.png");
	this->movingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_right_01.png");
	this->movingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_right_02.png");
	this->movingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_right_03.png");
	this->movingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_right_04.png");
	this->movingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_right_05.png");
	this->movingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_right_06.png");
	this->movingRightAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingRightAnimation_kun->setRestoreOriginalFrame(true);
	this->movingRightAnimation_kun->retain();

	ValueMap movingCheckIfToStayInWaterInfo;

	movingCheckIfToStayInWaterInfo["-5"] = Value(-5);

	this->movingRightAnimation_kun->getFrames().at(0)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingRightAnimation_kun->getFrames().at(1)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingRightAnimation_kun->getFrames().at(2)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingRightAnimation_kun->getFrames().at(3)->setUserInfo(movingCheckIfToStayInWaterInfo);

	EventListenerCustom * movingKunAnimationFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, movingCheckIfToStayInWaterInfo](EventCustom * event){
		this->moving = true;
		this->hovering = false;
		this->dashing = true;
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == movingCheckIfToStayInWaterInfo){
			if (((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY() - this->getPositionY() < this->getContentSize().height * 20 / 100){

				int heightDifference = this->getPositionY() - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY();

				if (heightDifference > 0){
					this->fallFromSky_kun();
				}
				else if (heightDifference > -this->getContentSize().height * 25 / 100){
					//this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(0, heightDifference)));
					int distanceToDrop = ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY() - this->getPositionY() - this->getContentSize().height * 25 / 100;
					this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(0, distanceToDrop)));
				}

				/*
				int difference = ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY() - this->getPositionY() - this->getContentSize().height * 25 / 100;
				if (this->moving && this->directionToMoveUp ){
					this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL,Vec2(0,difference)));
				}
				else if (this->moving && this->directionToMoveUpRight){
					this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(0, difference)));
				}
				else if (this->moving && this->directionToMoveUpLeft){
					this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(0, difference)));
				}
				*/

			}
		}
		
	});

	_eventDispatcher->addEventListenerWithFixedPriority(movingKunAnimationFrameEventListener, -1);

	this->movingUpRightAnimation_kun = Animation::create();
	this->movingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upright_00.png");
	this->movingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upright_01.png");
	this->movingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upright_02.png");
	this->movingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upright_03.png");
	this->movingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upright_04.png");
	this->movingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upright_05.png");
	this->movingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upright_06.png");
	this->movingUpRightAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpRightAnimation_kun->setRestoreOriginalFrame(true);
	this->movingUpRightAnimation_kun->retain();

	this->movingUpRightAnimation_kun->getFrames().at(0)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpRightAnimation_kun->getFrames().at(1)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpRightAnimation_kun->getFrames().at(2)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpRightAnimation_kun->getFrames().at(3)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpRightAnimation_kun->getFrames().at(4)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpRightAnimation_kun->getFrames().at(5)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpRightAnimation_kun->getFrames().at(6)->setUserInfo(movingCheckIfToStayInWaterInfo);

	this->movingDownRightAnimation_kun = Animation::create();
	this->movingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downright_00.png");
	this->movingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downright_01.png");
	this->movingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downright_02.png");
	this->movingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downright_03.png");
	this->movingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downright_04.png");
	this->movingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downright_05.png");
	this->movingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downright_06.png");
	this->movingDownRightAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownRightAnimation_kun->setRestoreOriginalFrame(true);
	this->movingDownRightAnimation_kun->retain();



	this->movingLeftAnimation_kun = Animation::create();
	this->movingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_left_00.png");
	this->movingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_left_01.png");
	this->movingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_left_02.png");
	this->movingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_left_03.png");
	this->movingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_left_04.png");
	this->movingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_left_05.png");
	this->movingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_left_06.png");
	this->movingLeftAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingLeftAnimation_kun->setRestoreOriginalFrame(true);
	this->movingLeftAnimation_kun->retain();

	this->movingLeftAnimation_kun->getFrames().at(0)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingLeftAnimation_kun->getFrames().at(1)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingLeftAnimation_kun->getFrames().at(2)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingLeftAnimation_kun->getFrames().at(3)->setUserInfo(movingCheckIfToStayInWaterInfo);

	this->movingLeftAnimation_kun->getFrames().at(4)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingLeftAnimation_kun->getFrames().at(5)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingLeftAnimation_kun->getFrames().at(6)->setUserInfo(movingCheckIfToStayInWaterInfo);



	this->movingUpLeftAnimation_kun = Animation::create();
	this->movingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upleft_00.png");
	this->movingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upleft_01.png");
	this->movingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upleft_02.png");
	this->movingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upleft_03.png");
	this->movingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upleft_04.png");
	this->movingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upleft_05.png");
	this->movingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_upleft_06.png");
	this->movingUpLeftAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingUpLeftAnimation_kun->setRestoreOriginalFrame(true);
	this->movingUpLeftAnimation_kun->retain();

	this->movingUpLeftAnimation_kun->getFrames().at(0)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpLeftAnimation_kun->getFrames().at(1)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpLeftAnimation_kun->getFrames().at(2)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpLeftAnimation_kun->getFrames().at(3)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpLeftAnimation_kun->getFrames().at(4)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpLeftAnimation_kun->getFrames().at(5)->setUserInfo(movingCheckIfToStayInWaterInfo);
	this->movingUpLeftAnimation_kun->getFrames().at(6)->setUserInfo(movingCheckIfToStayInWaterInfo);

	this->movingDownLeftAnimation_kun = Animation::create();
	this->movingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downleft_00.png");
	this->movingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downleft_01.png");
	this->movingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downleft_02.png");
	this->movingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downleft_03.png");
	this->movingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downleft_04.png");
	this->movingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downleft_05.png");
	this->movingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_moving_downleft_06.png");
	this->movingDownLeftAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->movingDownLeftAnimation_kun->setRestoreOriginalFrame(true);
	this->movingDownLeftAnimation_kun->retain();

	//���dashing����
	this->dashingRightAnimation_kun = Animation::create();
	this->dashingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_right_00.png");
	this->dashingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_right_01.png");
	this->dashingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_right_02.png");
	this->dashingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_right_03.png");
	this->dashingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_right_04.png");
	this->dashingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_right_05.png");
	this->dashingRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_right_06.png");
	this->dashingRightAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingRightAnimation_kun->setRestoreOriginalFrame(true);
	this->dashingRightAnimation_kun->retain();

	ValueMap dashingStartFrameInfo_kun;
	ValueMap dashingCheckIfMakesAnySplash_kun;
	ValueMap dashingRecoverAllAbilitiesFrameInfo_kun;
	ValueMap dashingEndFrameInfo_kun;

	dashingStartFrameInfo_kun["30"] = Value(30);
	dashingCheckIfMakesAnySplash_kun["30.5"] = Value(30.5);
	dashingRecoverAllAbilitiesFrameInfo_kun["31"] = Value(31);
	dashingEndFrameInfo_kun["32"] = Value(32);

	this->dashingRightAnimation_kun->getFrames().at(0)->setUserInfo(dashingStartFrameInfo_kun);
	this->dashingRightAnimation_kun->getFrames().at(1)->setUserInfo(dashingCheckIfMakesAnySplash_kun);
	this->dashingRightAnimation_kun->getFrames().at(2)->setUserInfo(dashingRecoverAllAbilitiesFrameInfo_kun);
	this->dashingRightAnimation_kun->getFrames().at(4)->setUserInfo(dashingEndFrameInfo_kun);

	EventListenerCustom * dashingKunAnimationFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, dashingStartFrameInfo_kun, dashingCheckIfMakesAnySplash_kun, dashingRecoverAllAbilitiesFrameInfo_kun, dashingEndFrameInfo_kun](EventCustom * event){
		this->dashing = true;
		this->moving = false;
		this->hovering = false;
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == dashingStartFrameInfo_kun){
			this->disableAllAbilities();
			this->transformable_FishToBird = true;

			int heightDifference = this->getPositionY() - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY();
			if (-this->getContentSize().height / 2 < heightDifference && heightDifference < this->getContentSize().height / 2){
				Sprite * bigSplash = Sprite::create("landscapes/splash_big_00.png");
				bigSplash->setPositionX(this->getPositionX());
				bigSplash->setPositionY(((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY());
				this->getParent()->addChild(bigSplash);
				bigSplash->runAction(Animate::create(this->waterSplashingAnimation_big));
			}
		}
		if (*userData->userInfo == dashingCheckIfMakesAnySplash_kun){
			int heightDifference = this->getPositionY() - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY();
			if (-this->getContentSize().height / 2 < heightDifference && heightDifference < this->getContentSize().height / 2){
				Sprite * bigSplash = Sprite::create("landscapes/splash_big_00.png");
				bigSplash->setPositionX(this->getPositionX());
				bigSplash->setPositionY(((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY());
				this->getParent()->addChild(bigSplash);
				bigSplash->runAction(Animate::create(this->waterSplashingAnimation_big));
			}
		}
		if (*userData->userInfo == dashingRecoverAllAbilitiesFrameInfo_kun){
			this->enableAllAbilities();
			int heightDifference = this->getPositionY() - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY();

			if (-this->getContentSize().height / 2 < heightDifference && heightDifference < this->getContentSize().height / 2){
				Sprite * bigSplash = Sprite::create("landscapes/splash_big_00.png");
				bigSplash->setPositionX(this->getPositionX());
				bigSplash->setPositionY(((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY());
				this->getParent()->addChild(bigSplash);
				bigSplash->runAction(Animate::create(this->waterSplashingAnimation_big));
			}

			if (heightDifference > 0){

				this->dashable = false;
				this->vortexAttackable = false;
				this->scratchable = false;
			}
			else {
				//this->transformable_FishToBird = false;
				if (this->directionToMoveUpRight ||
					this->directionToMoveRight ||
					this->directionToMoveDownRight ||
					this->directionToMoveDown ||
					this->directionToMoveDownLeft ||
					this->directionToMoveLeft ||
					this->directionToMoveUpLeft ||
					this->directionToMoveUp){
					this->move_kun();
				}
			}
		}
		if (*userData->userInfo == dashingEndFrameInfo_kun){
			this->hover_kun();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(dashingKunAnimationFrameEventListener, -1);

	this->dashingDownRightAnimation_kun = Animation::create();
	this->dashingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downright_00.png");
	this->dashingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downright_01.png");
	this->dashingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downright_02.png");
	this->dashingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downright_03.png");
	this->dashingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downright_04.png");
	this->dashingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downright_05.png");
	this->dashingDownRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downright_06.png");
	this->dashingDownRightAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingDownRightAnimation_kun->setRestoreOriginalFrame(true);
	this->dashingDownRightAnimation_kun->retain();

	this->dashingDownRightAnimation_kun->getFrames().at(0)->setUserInfo(dashingStartFrameInfo_kun);
	this->dashingDownRightAnimation_kun->getFrames().at(2)->setUserInfo(dashingRecoverAllAbilitiesFrameInfo_kun);
	this->dashingDownRightAnimation_kun->getFrames().at(4)->setUserInfo(dashingEndFrameInfo_kun);




	this->dashingUpRightAnimation_kun = Animation::create();
	this->dashingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upright_00.png");
	this->dashingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upright_01.png");
	this->dashingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upright_02.png");
	this->dashingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upright_03.png");
	this->dashingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upright_04.png");
	this->dashingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upright_05.png");
	this->dashingUpRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upright_06.png");
	this->dashingUpRightAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingUpRightAnimation_kun->setRestoreOriginalFrame(true);
	this->dashingUpRightAnimation_kun->retain();

	this->dashingUpRightAnimation_kun->getFrames().at(0)->setUserInfo(dashingStartFrameInfo_kun);
	this->dashingUpRightAnimation_kun->getFrames().at(2)->setUserInfo(dashingRecoverAllAbilitiesFrameInfo_kun);
	this->dashingUpRightAnimation_kun->getFrames().at(4)->setUserInfo(dashingEndFrameInfo_kun);




	this->dashingLeftAnimation_kun = Animation::create();
	this->dashingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_left_00.png");
	this->dashingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_left_01.png");
	this->dashingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_left_02.png");
	this->dashingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_left_03.png");
	this->dashingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_left_04.png");
	this->dashingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_left_05.png");
	this->dashingLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_left_06.png");
	this->dashingLeftAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingLeftAnimation_kun->setRestoreOriginalFrame(true);
	this->dashingLeftAnimation_kun->retain();

	this->dashingLeftAnimation_kun->getFrames().at(0)->setUserInfo(dashingStartFrameInfo_kun);
	this->dashingLeftAnimation_kun->getFrames().at(2)->setUserInfo(dashingRecoverAllAbilitiesFrameInfo_kun);
	this->dashingLeftAnimation_kun->getFrames().at(4)->setUserInfo(dashingEndFrameInfo_kun);



	this->dashingUpLeftAnimation_kun = Animation::create();
	this->dashingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upleft_00.png");
	this->dashingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upleft_01.png");
	this->dashingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upleft_02.png");
	this->dashingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upleft_03.png");
	this->dashingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upleft_04.png");
	this->dashingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upleft_05.png");
	this->dashingUpLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_upleft_06.png");
	this->dashingUpLeftAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingUpLeftAnimation_kun->setRestoreOriginalFrame(true);
	this->dashingUpLeftAnimation_kun->retain(); 

	this->dashingUpLeftAnimation_kun->getFrames().at(0)->setUserInfo(dashingStartFrameInfo_kun);
	this->dashingUpLeftAnimation_kun->getFrames().at(2)->setUserInfo(dashingRecoverAllAbilitiesFrameInfo_kun);
	this->dashingUpLeftAnimation_kun->getFrames().at(4)->setUserInfo(dashingEndFrameInfo_kun);


	this->dashingDownLeftAnimation_kun = Animation::create();
	this->dashingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downleft_00.png");
	this->dashingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downleft_01.png");
	this->dashingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downleft_02.png");
	this->dashingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downleft_03.png");
	this->dashingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downleft_04.png");
	this->dashingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downleft_05.png");
	this->dashingDownLeftAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_dashing_downleft_06.png");
	this->dashingDownLeftAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->dashingDownLeftAnimation_kun->setRestoreOriginalFrame(true);
	this->dashingDownLeftAnimation_kun->retain();

	this->dashingDownLeftAnimation_kun->getFrames().at(0)->setUserInfo(dashingStartFrameInfo_kun);
	this->dashingDownLeftAnimation_kun->getFrames().at(2)->setUserInfo(dashingRecoverAllAbilitiesFrameInfo_kun);
	this->dashingDownLeftAnimation_kun->getFrames().at(4)->setUserInfo(dashingEndFrameInfo_kun);


	//��������ж�����
	this->blowingVortexRightAnimation = Animation::create();
	this->blowingVortexRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_blowing_vortex_right_00.png");
	this->blowingVortexRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_blowing_vortex_right_01.png");
	this->blowingVortexRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_blowing_vortex_right_02.png");
	this->blowingVortexRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_blowing_vortex_right_03.png");
	//this->blowingVortexRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_blowing_vortex_right_04.png");
	this->blowingVortexRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->blowingVortexRightAnimation->setRestoreOriginalFrame(true);
	this->blowingVortexRightAnimation->retain();

	ValueMap blowingVortexStartInfo;
	ValueMap blowingVortexLaunchingWaterBulletInfo;
	ValueMap blowingVortexRecoverAllAbilitiesInfo;
	ValueMap blowingVortexEndInfo;

	blowingVortexStartInfo["38"] = Value(38);
	blowingVortexLaunchingWaterBulletInfo["39"] = Value(39);
	blowingVortexRecoverAllAbilitiesInfo["40"] = Value(40);
	blowingVortexEndInfo["41"] = Value(41);

	this->blowingVortexRightAnimation->getFrames().at(0)->setUserInfo(blowingVortexStartInfo);
	this->blowingVortexRightAnimation->getFrames().at(1)->setUserInfo(blowingVortexLaunchingWaterBulletInfo);
	this->blowingVortexRightAnimation->getFrames().at(2)->setUserInfo(blowingVortexRecoverAllAbilitiesInfo);
	this->blowingVortexRightAnimation->getFrames().at(3)->setUserInfo(blowingVortexEndInfo);

	EventListenerCustom * blowingVortexFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, blowingVortexStartInfo, blowingVortexLaunchingWaterBulletInfo, blowingVortexRecoverAllAbilitiesInfo, blowingVortexEndInfo](EventCustom* event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == blowingVortexStartInfo){
			this->disableAllAbilities();
		}
		if (*userData->userInfo == blowingVortexLaunchingWaterBulletInfo){
			if (this->facingRight){
				//this->setPositionX(this->getPositionX() - 30);
				this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(-10, 0)), MoveBy::create(0.2f, Vec2(-10, 0)), nullptr));
				Sprite * waterBullet = Sprite::create();
				waterBullet->setPosition(this->getPosition());
				this->getParent()->addChild(waterBullet);
				waterBullet->runAction(Spawn::create(MoveBy::create(0.6f, Vec2(300, 0)), Repeat::create(Animate::create(this->waterBulletMarchingAnimation), 2), nullptr));
			}
			else if (this->facingLeft){
				//this->setPositionX(this->getPositionX()+ 30);
				this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(10, 0)), MoveBy::create(0.2f, Vec2(10, 0)), nullptr));
				Sprite * waterBullet = Sprite::create();
				waterBullet->setPosition(this->getPosition());
				this->getParent()->addChild(waterBullet);
				waterBullet->runAction(Spawn::create(MoveBy::create(0.6f, Vec2(-300, 0)), Repeat::create(Animate::create(this->waterBulletMarchingAnimation), 2), nullptr));
			}
			this->vortexAttackable = true;
		}
		if (*userData->userInfo == blowingVortexRecoverAllAbilitiesInfo){
			this->enableAllAbilities();
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move_kun();
			}
		}
		if (*userData->userInfo == blowingVortexEndInfo){
			this->hover_kun();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(blowingVortexFrameEventListener, -1);


	this->blowingVortexLeftAnimation = Animation::create();
	this->blowingVortexLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_blowing_vortex_left_00.png");
	this->blowingVortexLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_blowing_vortex_left_01.png");
	this->blowingVortexLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_blowing_vortex_left_02.png");
	this->blowingVortexLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_blowing_vortex_left_03.png");
	//this->blowingVortexLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_blowing_vortex_left_04.png");
	this->blowingVortexLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->blowingVortexLeftAnimation->setRestoreOriginalFrame(true);
	this->blowingVortexLeftAnimation->retain();

	this->blowingVortexLeftAnimation->getFrames().at(0)->setUserInfo(blowingVortexStartInfo);
	this->blowingVortexLeftAnimation->getFrames().at(1)->setUserInfo(blowingVortexLaunchingWaterBulletInfo);
	this->blowingVortexLeftAnimation->getFrames().at(2)->setUserInfo(blowingVortexRecoverAllAbilitiesInfo);
	this->blowingVortexLeftAnimation->getFrames().at(3)->setUserInfo(blowingVortexEndInfo);


	//ˮ��������Ӧ��Ϊ����֡����������˾ͱ�ը��֡�¼�
	this->waterBulletMarchingAnimation = Animation::create();
	this->waterBulletMarchingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_00.png");
	this->waterBulletMarchingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_01.png");
	this->waterBulletMarchingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_02.png");
	this->waterBulletMarchingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_03.png");
	this->waterBulletMarchingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_00.png");
	this->waterBulletMarchingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_01.png");
	this->waterBulletMarchingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_02.png");
	this->waterBulletMarchingAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->waterBulletMarchingAnimation->setRestoreOriginalFrame(true);
	this->waterBulletMarchingAnimation->retain();

	ValueMap waterBulletCheckHitEnemyInfo;
	ValueMap waterBulletEndInfo;

	waterBulletCheckHitEnemyInfo["47"] = Value(47);
	waterBulletEndInfo["48"] = Value(48);

	this->waterBulletMarchingAnimation->getFrames().at(0)->setUserInfo(waterBulletCheckHitEnemyInfo);
	this->waterBulletMarchingAnimation->getFrames().at(1)->setUserInfo(waterBulletCheckHitEnemyInfo);
	this->waterBulletMarchingAnimation->getFrames().at(2)->setUserInfo(waterBulletCheckHitEnemyInfo);
	this->waterBulletMarchingAnimation->getFrames().at(3)->setUserInfo(waterBulletCheckHitEnemyInfo);
	this->waterBulletMarchingAnimation->getFrames().at(4)->setUserInfo(waterBulletCheckHitEnemyInfo);
	this->waterBulletMarchingAnimation->getFrames().at(5)->setUserInfo(waterBulletCheckHitEnemyInfo);
	this->waterBulletMarchingAnimation->getFrames().at(6)->setUserInfo(waterBulletEndInfo);

	EventListenerCustom * waterBulletFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, waterBulletCheckHitEnemyInfo, waterBulletEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == waterBulletCheckHitEnemyInfo){
			//userData���target��������run��һ֡�Ķ�������A->runAction(Animate::...)��A���������target
			WaterBullet*  waterBullet = (WaterBullet *)(userData->target);
			int waterBulletPositionX = waterBullet->getPositionX();
			int waterBulletPositionY = waterBullet->getPositionY();


			int heightDifference = waterBulletPositionY - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY();
			if (-waterBullet->getContentSize().height / 2 < heightDifference && heightDifference < waterBullet->getContentSize().height / 2){
				Sprite * bigSplash = Sprite::create("landscapes/splash_big_00.png");
				bigSplash->setPositionX(waterBulletPositionX);
				bigSplash->setPositionY(((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY());
				this->getParent()->addChild(bigSplash);
				bigSplash->runAction(Animate::create(this->waterSplashingAnimation_big));
			}



			//log("Here is windbullet running 1st frame of windbulletflyinganimation. Some data from wb = %d",wb->magazineX);
			Vector < GeneralUnit * > elist = ((Stage1GameplayLayer *)(this->getParent()))->enemyList;
			for (GeneralUnit * enemy : elist){
				int deltax = enemy->getPositionX() - waterBulletPositionX;
				int deltay = enemy->getPositionY() - waterBulletPositionY;

				double distance = sqrt(deltax*deltax + deltay*deltay);
				if (distance < waterBullet->getContentSize().width / 2 + enemy->getContentSize().width / 2){
					int waterBulletExplosionNumber = this->waterBulletExplosionCount % this->NUM_OF_WATER_BULLET_EXPLOSIONS;

					Sprite * waterBulletExplosion = this->waterBulletExplosions[waterBulletExplosionNumber];
					
					waterBulletExplosion->setPosition(waterBulletPositionX, waterBulletPositionY);
					this->getParent()->addChild(waterBulletExplosion);
					waterBulletExplosion->runAction(Animate::create(this->waterBulletExplosionAnimation));

					this->waterBulletExplosionCount++;

					//enemy->getHurtByPaw(10);
					
					waterBullet->removeFromParent();
					break;
				}
			}

		}

		if (*userData->userInfo == waterBulletEndInfo){
			WaterBullet * waterBullet = (WaterBullet *)(userData->target);
			waterBullet->removeFromParent();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(waterBulletFrameEventListener,-1);


	//ˮ���ı�ը��Ч����һ֡��Ⱥ���Ĺ����ж�����������֡�ǲ���Ч���������£����һ֡��target��parent�Ƴ���
	this->waterBulletExplosionAnimation = Animation::create();
	this->waterBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_exploding_00.png");
	this->waterBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_exploding_01.png");
	this->waterBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_exploding_02.png");
	this->waterBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_exploding_03.png");
	this->waterBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_exploding_04.png");
	this->waterBulletExplosionAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_bullet_exploding_05.png");
	this->waterBulletExplosionAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->waterBulletExplosionAnimation->setRestoreOriginalFrame(true);
	this->waterBulletExplosionAnimation->retain();

	ValueMap waterBulletExplosionDealDamageInfo;
	ValueMap waterBulletExplosionEndInfo;

	waterBulletExplosionDealDamageInfo["49"] = Value(49);
	waterBulletExplosionEndInfo["50"] = Value(50);

	this->waterBulletExplosionAnimation->getFrames().at(0)->setUserInfo(waterBulletExplosionDealDamageInfo);
	this->waterBulletExplosionAnimation->getFrames().at(5)->setUserInfo(waterBulletExplosionEndInfo);

	EventListenerCustom * waterBulletExplosionFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, waterBulletExplosionDealDamageInfo, waterBulletExplosionEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == waterBulletExplosionDealDamageInfo){
			Sprite*  waterBulletExplosion = (Sprite *)(userData->target);

			Vector < GeneralUnit * > elist = ((Stage1GameplayLayer *)(this->getParent()))->enemyList;
			for (GeneralUnit * enemy : elist){
				int deltax = enemy->getPositionX() - waterBulletExplosion->getPositionX();
				int deltay = enemy->getPositionY() - waterBulletExplosion->getPositionY();

				double distance = sqrt(deltax*deltax + deltay*deltay);
				if (distance < (waterBulletExplosion->getContentSize().width + enemy->getContentSize().width) * 75 / 100){
					//enemy->getHurtByWater(this->DAMAGE_VORTEX);//TODO!!!�����������ٸ�
					enemy->getHurtByWind(this->DAMAGE_WIND);
				}
			}


			//windBulletExplosion->removeFromParent();
		}
		if (*userData->userInfo == waterBulletExplosionEndInfo){
			Sprite*  waterBulletExplosion = (Sprite *)(userData->target);
			waterBulletExplosion->removeFromParent();
		}
	});

	_eventDispatcher->addEventListenerWithFixedPriority(waterBulletExplosionFrameEventListener, -1);

	//��Ľ�ս�������������֡�¼�����TODO
	this->finAttackRightAnimation = Animation::create();
	this->finAttackRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking_right_00.png");
	this->finAttackRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking_right_01.png");
	this->finAttackRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking_right_02.png");
	this->finAttackRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking_right_03.png");
	this->finAttackRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking_right_04.png");
	this->finAttackRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->finAttackRightAnimation->setRestoreOriginalFrame(true);
	this->finAttackRightAnimation->retain();

	ValueMap finAttackingStartInfo;
	ValueMap finAttackingLoseAllAbilitiesInfo;
	ValueMap finAttackingRecoverScratchabilityInfo;
	ValueMap finAttackingRecoverAllAbilitiesInfo;
	ValueMap finAttackingToHoveringInfo;

	finAttackingStartInfo["42"] = Value(42);
	finAttackingLoseAllAbilitiesInfo["43"] = Value(43);
	finAttackingRecoverScratchabilityInfo["44"] = Value(44);
	finAttackingRecoverAllAbilitiesInfo["45"] = Value(45);
	finAttackingToHoveringInfo["46"] = Value(46);

	finAttackRightAnimation->getFrames().at(0)->setUserInfo(finAttackingStartInfo);
	finAttackRightAnimation->getFrames().at(1)->setUserInfo(finAttackingLoseAllAbilitiesInfo);
	finAttackRightAnimation->getFrames().at(2)->setUserInfo(finAttackingRecoverScratchabilityInfo);
	finAttackRightAnimation->getFrames().at(3)->setUserInfo(finAttackingRecoverAllAbilitiesInfo);
	finAttackRightAnimation->getFrames().at(4)->setUserInfo(finAttackingToHoveringInfo);

	EventListenerCustom * finAttackingFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, finAttackingStartInfo, finAttackingLoseAllAbilitiesInfo, finAttackingRecoverScratchabilityInfo, finAttackingRecoverAllAbilitiesInfo, finAttackingToHoveringInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == finAttackingStartInfo){
			this->disableAllAbilities();
			if (this->directionToMoveRight){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(this->DISTANCE_DURING_SCRATCHING, 0)));
			}
			else if (this->directionToMoveLeft){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(-this->DISTANCE_DURING_SCRATCHING, 0)));
			}
			else if (this->directionToMoveUp){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(0, this->DISTANCE_DURING_SCRATCHING)));
			}
			else if (this->directionToMoveDown){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(0, -this->DISTANCE_DURING_SCRATCHING)));
			}
			else if (this->directionToMoveUpRight){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(this->DISTANCE_DURING_SCRATCHING / 1.414, this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
			else if (this->directionToMoveUpLeft){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(-this->DISTANCE_DURING_SCRATCHING / 1.414, this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
			else if (this->directionToMoveDownRight){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(this->DISTANCE_DURING_SCRATCHING / 1.414, -this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
			else if (this->directionToMoveDownLeft){
				this->runAction(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(-this->DISTANCE_DURING_SCRATCHING / 1.414, -this->DISTANCE_DURING_SCRATCHING / 1.414)));
			}
		}
		if (*userData->userInfo == finAttackingLoseAllAbilitiesInfo){
			log("attacking at frame2");
			if (this->finAttackingType == 1){

				if (this->facingLeft){
					//����typeΪ1��������ߵĵ���
					Sprite * finAttackbladeEffect = Sprite::create("characters/kunpeng/kun_finAttack_left_blade_effect_00.png");
					finAttackbladeEffect->setPositionX(this->getPositionX() - this->getContentSize().width / 2);
					finAttackbladeEffect->setPositionY(this->getPositionY());
					this->getParent()->addChild(finAttackbladeEffect);
					finAttackbladeEffect->runAction(Animate::create(this->finLeftBladeEffectAnimation));
				}
				else{
					//����typeΪ1�������ұߵĵ���
					Sprite * finAttackbladeEffect = Sprite::create("characters/kunpeng/kun_finAttack_right_blade_effect_00.png");
					finAttackbladeEffect->setPositionX(this->getPositionX() + this->getContentSize().width / 2);
					finAttackbladeEffect->setPositionY(this->getPositionY());
					this->getParent()->addChild(finAttackbladeEffect);
					finAttackbladeEffect->runAction(Animate::create(this->finRightBladeEffectAnimation));
				}

				this->finAttackingType = 2;
			}
			else if (this->finAttackingType == 2){

				if (this->facingLeft){
					//����typeΪ2��������ߵĵ���
					Sprite * finAttackbladeEffect = Sprite::create("characters/kunpeng/kun_finAttack_left_blade_effect2_00.png");
					finAttackbladeEffect->setPositionX(this->getPositionX() - this->getContentSize().width / 2);
					finAttackbladeEffect->setPositionY(this->getPositionY());
					this->getParent()->addChild(finAttackbladeEffect);
					finAttackbladeEffect->runAction(Animate::create(this->finLeftBladeEffect2Animation));
				}
				else{
					//����typeΪ2�������ұߵĵ���
					Sprite * finAttackbladeEffect = Sprite::create("characters/kunpeng/kun_finAttack_right_blade_effect2_00.png");
					finAttackbladeEffect->setPositionX(this->getPositionX() + this->getContentSize().width / 2);
					finAttackbladeEffect->setPositionY(this->getPositionY());
					this->getParent()->addChild(finAttackbladeEffect);
					finAttackbladeEffect->runAction(Animate::create(this->finRightBladeEffect2Animation));
				}


				this->finAttackingType = 1;
			}
		}
		if (*userData->userInfo == finAttackingRecoverScratchabilityInfo){
			this->scratchable = true;
		}
		if (*userData->userInfo == finAttackingRecoverAllAbilitiesInfo){
			this->enableAllAbilities();
			this->moveableWithoutAnimation = false;
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move_forBothShapes();
				this->finAttackingType = 1;
			}

		}
		if (*userData->userInfo == finAttackingToHoveringInfo){
			this->hover_kun();
			this->finAttackingType = 1;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(finAttackingFrameEventListener, -1);


	this->finAttackRightAnimation2 = Animation::create();
	this->finAttackRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking2_right_00.png");
	this->finAttackRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking2_right_01.png");
	this->finAttackRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking2_right_02.png");
	this->finAttackRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking2_right_03.png");
	this->finAttackRightAnimation2->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking2_right_04.png");
	this->finAttackRightAnimation2->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->finAttackRightAnimation2->setRestoreOriginalFrame(true);
	this->finAttackRightAnimation2->retain();

	this->finAttackRightAnimation2->getFrames().at(0)->setUserInfo(finAttackingStartInfo);
	this->finAttackRightAnimation2->getFrames().at(1)->setUserInfo(finAttackingLoseAllAbilitiesInfo);
	this->finAttackRightAnimation2->getFrames().at(2)->setUserInfo(finAttackingRecoverScratchabilityInfo);
	this->finAttackRightAnimation2->getFrames().at(3)->setUserInfo(finAttackingRecoverAllAbilitiesInfo);
	this->finAttackRightAnimation2->getFrames().at(4)->setUserInfo(finAttackingToHoveringInfo);

	this->finAttackLeftAnimation = Animation::create();
	this->finAttackLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking_left_00.png");
	this->finAttackLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking_left_01.png");
	this->finAttackLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking_left_02.png");
	this->finAttackLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking_left_03.png");
	this->finAttackLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking_left_04.png");
	this->finAttackLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->finAttackLeftAnimation->setRestoreOriginalFrame(true);
	this->finAttackLeftAnimation->retain();

	this->finAttackLeftAnimation->getFrames().at(0)->setUserInfo(finAttackingStartInfo);
	this->finAttackLeftAnimation->getFrames().at(1)->setUserInfo(finAttackingLoseAllAbilitiesInfo);
	this->finAttackLeftAnimation->getFrames().at(2)->setUserInfo(finAttackingRecoverScratchabilityInfo);
	this->finAttackLeftAnimation->getFrames().at(3)->setUserInfo(finAttackingRecoverAllAbilitiesInfo);
	this->finAttackLeftAnimation->getFrames().at(4)->setUserInfo(finAttackingToHoveringInfo);

	this->finAttackLeftAnimation2 = Animation::create();
	this->finAttackLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking2_left_00.png");
	this->finAttackLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking2_left_01.png");
	this->finAttackLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking2_left_02.png");
	this->finAttackLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking2_left_03.png");
	this->finAttackLeftAnimation2->addSpriteFrameWithFileName("characters/kunpeng/kun_fin_attacking2_left_04.png");
	this->finAttackLeftAnimation2->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->finAttackLeftAnimation2->setRestoreOriginalFrame(true);
	this->finAttackLeftAnimation2->retain();

	this->finAttackLeftAnimation2->getFrames().at(0)->setUserInfo(finAttackingStartInfo);
	this->finAttackLeftAnimation2->getFrames().at(1)->setUserInfo(finAttackingLoseAllAbilitiesInfo);
	this->finAttackLeftAnimation2->getFrames().at(2)->setUserInfo(finAttackingRecoverScratchabilityInfo);
	this->finAttackLeftAnimation2->getFrames().at(3)->setUserInfo(finAttackingRecoverAllAbilitiesInfo);
	this->finAttackLeftAnimation2->getFrames().at(4)->setUserInfo(finAttackingToHoveringInfo);

	//����ܻ�����TODO

	//��ĳ�ײ����TODO���������ˡ���

	//����������ˮ�Ķ���throwwater��

	//��ĵ��䶯����
	this->fallingFromSkyRightAnimation = Animation::create();
	this->fallingFromSkyRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_falling_right_00.png");
	this->fallingFromSkyRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_falling_right_01.png");
	this->fallingFromSkyRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_falling_right_02.png");
	this->fallingFromSkyRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_falling_right_03.png");
	this->fallingFromSkyRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->fallingFromSkyRightAnimation->setRestoreOriginalFrame(true);
	this->fallingFromSkyRightAnimation->retain();

	ValueMap fallingFromSkyCheckIfInWaterInfo;

	fallingFromSkyCheckIfInWaterInfo["54"] = Value(54);

	this->fallingFromSkyRightAnimation->getFrames().at(0)->setUserInfo(fallingFromSkyCheckIfInWaterInfo);
	this->fallingFromSkyRightAnimation->getFrames().at(1)->setUserInfo(fallingFromSkyCheckIfInWaterInfo);
	this->fallingFromSkyRightAnimation->getFrames().at(2)->setUserInfo(fallingFromSkyCheckIfInWaterInfo);
	this->fallingFromSkyRightAnimation->getFrames().at(3)->setUserInfo(fallingFromSkyCheckIfInWaterInfo);

	EventListenerCustom * fallingFronSkyFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, fallingFromSkyCheckIfInWaterInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == fallingFromSkyCheckIfInWaterInfo){
			this->disableAllAbilities();
			//this->spittable = true;
			this->transformable_FishToBird = true;
			int heightDifference = this->getPositionY() - ((Stage1GameplayLayer *)(this->getParent()))->waterSurface->getPositionY();
			if (heightDifference < 0){
				this->enterWater_kun();
			}
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(fallingFronSkyFrameEventListener, -1);


	this->fallingFromSkyLeftAnimation = Animation::create();
	this->fallingFromSkyLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_falling_left_00.png");
	this->fallingFromSkyLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_falling_left_01.png");
	this->fallingFromSkyLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_falling_left_02.png");
	this->fallingFromSkyLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_falling_left_03.png");
	this->fallingFromSkyLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->fallingFromSkyLeftAnimation->setRestoreOriginalFrame(true);
	this->fallingFromSkyLeftAnimation->retain();

	this->fallingFromSkyLeftAnimation->getFrames().at(0)->setUserInfo(fallingFromSkyCheckIfInWaterInfo);
	this->fallingFromSkyLeftAnimation->getFrames().at(1)->setUserInfo(fallingFromSkyCheckIfInWaterInfo);
	this->fallingFromSkyLeftAnimation->getFrames().at(2)->setUserInfo(fallingFromSkyCheckIfInWaterInfo);
	this->fallingFromSkyLeftAnimation->getFrames().at(3)->setUserInfo(fallingFromSkyCheckIfInWaterInfo);

	//�����ˮ������
	this->enteringIntoWaterRightAnimation = Animation::create();
	this->enteringIntoWaterRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_entering_water_right_00.png");
	this->enteringIntoWaterRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_entering_water_right_01.png");
	this->enteringIntoWaterRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_entering_water_right_02.png");
	this->enteringIntoWaterRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_entering_water_right_03.png");
	this->enteringIntoWaterRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_entering_water_right_04.png");
	this->enteringIntoWaterRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->enteringIntoWaterRightAnimation->setRestoreOriginalFrame(true);
	this->enteringIntoWaterRightAnimation->retain();

	ValueMap enteringWaterFirstFrameInfo;
	ValueMap enteringWaterRecoverAllAbilitiesInfo;
	ValueMap enteringWaterLastFrameInfo;

	enteringWaterFirstFrameInfo["51"] = Value(51);
	enteringWaterRecoverAllAbilitiesInfo["52"] = Value(52);
	enteringWaterLastFrameInfo["53"] = Value(53);

	this->enteringIntoWaterRightAnimation->getFrames().at(0)->setUserInfo(enteringWaterFirstFrameInfo);
	this->enteringIntoWaterRightAnimation->getFrames().at(2)->setUserInfo(enteringWaterRecoverAllAbilitiesInfo);
	this->enteringIntoWaterRightAnimation->getFrames().at(4)->setUserInfo(enteringWaterLastFrameInfo);

	EventListenerCustom * enteringWaterFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, enteringWaterFirstFrameInfo, enteringWaterRecoverAllAbilitiesInfo, enteringWaterLastFrameInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == enteringWaterFirstFrameInfo){
			this->disableAllAbilities();
			Sprite * splash = Sprite::create("landscapes/splash_big_00.png");
			splash->setPosition(this->getPositionX(), ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY());
			this->getParent()->addChild(splash);
			splash->runAction(Animate::create(this->waterSplashingAnimation_big));
		}
		if (*userData->userInfo == enteringWaterRecoverAllAbilitiesInfo){
			this->enableAllAbilities();
			if (this->directionToMoveUpRight ||
				this->directionToMoveRight ||
				this->directionToMoveDownRight ||
				this->directionToMoveDown ||
				this->directionToMoveDownLeft ||
				this->directionToMoveLeft ||
				this->directionToMoveUpLeft ||
				this->directionToMoveUp){
				this->move_kun();
			}
		}
		if (*userData->userInfo == enteringWaterLastFrameInfo){
			this->hover_kun();
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(enteringWaterFrameEventListener, -1);


	this->enteringIntoWaterLeftAnimation = Animation::create();
	this->enteringIntoWaterLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_entering_water_left_00.png");
	this->enteringIntoWaterLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_entering_water_left_01.png");
	this->enteringIntoWaterLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_entering_water_left_02.png");
	this->enteringIntoWaterLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_entering_water_left_03.png");
	this->enteringIntoWaterLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_entering_water_left_04.png");
	this->enteringIntoWaterLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->enteringIntoWaterLeftAnimation->setRestoreOriginalFrame(true);
	this->enteringIntoWaterLeftAnimation->retain();

	this->enteringIntoWaterLeftAnimation->getFrames().at(0)->setUserInfo(enteringWaterFirstFrameInfo);
	this->enteringIntoWaterLeftAnimation->getFrames().at(2)->setUserInfo(enteringWaterRecoverAllAbilitiesInfo);
	this->enteringIntoWaterLeftAnimation->getFrames().at(4)->setUserInfo(enteringWaterLastFrameInfo);



	//�����������ˮ��Ķ��������и���������
	this->spittingRightAnimation = Animation::create();
	this->spittingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_spitting_waterBall_right_00.png");
	this->spittingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_spitting_waterBall_right_01.png");
	this->spittingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_spitting_waterBall_right_02.png");
	this->spittingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_spitting_waterBall_right_03.png");
	this->spittingRightAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_spitting_waterBall_right_04.png");
	this->spittingRightAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->spittingRightAnimation->setRestoreOriginalFrame(true);
	this->spittingRightAnimation->retain();

	ValueMap spittingThrowingWaterballInfo;
	ValueMap spittingEndInfo;

	spittingThrowingWaterballInfo["58"] = Value(58);
	spittingEndInfo["57"] = Value(57);
	
	this->spittingRightAnimation->getFrames().at(2)->setUserInfo(spittingThrowingWaterballInfo);
	this->spittingRightAnimation->getFrames().at(4)->setUserInfo(spittingEndInfo);

	EventListenerCustom * spittingFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, spittingThrowingWaterballInfo, spittingEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == spittingThrowingWaterballInfo){
			/**
			if (this->facingLeft){
				Sprite * waterBall = Sprite::create("characters/kunpeng/water_ball_flying_00.png");
				waterBall->setPosition(this->getPosition());
				this->getParent()->addChild(waterBall);
				waterBall->runAction(MoveBy::create(10, Vec2(-1111, -220)));
				waterBall->runAction(RepeatForever::create(Animate::create(this->waterBallFlyingAnimation)));
			}
			else{
				Sprite * waterBall = Sprite::create("characters/kunpeng/water_ball_flying_00.png");
				waterBall->setPosition(this->getPosition());
				this->getParent()->addChild(waterBall);
				waterBall->runAction(MoveBy::create(10, Vec2(1111, -220)));
				waterBall->runAction(Animate::create(this->waterBallFlyingAnimation));//������waterBallFlyingAnimation����

			}
			*/

			this->createWaterballAndFlyIt();
			this->spittable = false;
		}
		if (*userData->userInfo == spittingEndInfo){
			if (this->facingLeft){
				this->facingLeft = false;
				this->facingRight = true;
			}
			else{
				this->facingLeft = true;
				this->facingRight = false;
			}
			this->fallFromSky_kun();
		}


	});

	//�����¼���ӵ��¼��ַ���
	_eventDispatcher->addEventListenerWithFixedPriority(spittingFrameEventListener, -1);


	this->spittingLeftAnimation = Animation::create();
	this->spittingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_spitting_waterBall_left_00.png");
	this->spittingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_spitting_waterBall_left_01.png");
	this->spittingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_spitting_waterBall_left_02.png");
	this->spittingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_spitting_waterBall_left_03.png");
	this->spittingLeftAnimation->addSpriteFrameWithFileName("characters/kunpeng/kun_spitting_waterBall_left_04.png");
	this->spittingLeftAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->spittingLeftAnimation->setRestoreOriginalFrame(true);
	this->spittingLeftAnimation->retain();

	this->spittingLeftAnimation->getFrames().at(1)->setUserInfo(spittingThrowingWaterballInfo);
	this->spittingLeftAnimation->getFrames().at(4)->setUserInfo(spittingEndInfo);


	//ˮ����еĶ���������ѭ����ˮ����ܵ������������䵽ˮ�ÿ֡���ж�һ���Ƿ���ˡ�
	this->waterBallFlyingAnimation = Animation::create();
	this->waterBallFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_ball_flying_00.png");
	this->waterBallFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_ball_flying_01.png");
	this->waterBallFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_ball_flying_02.png");
	this->waterBallFlyingAnimation->addSpriteFrameWithFileName("characters/kunpeng/water_ball_flying_03.png");
	this->waterBallFlyingAnimation->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->waterBallFlyingAnimation->setRestoreOriginalFrame(true);
	this->waterBallFlyingAnimation->retain();

	ValueMap waterBallFlyingCheckIfHitEnemyOrInWaterInfo;

	waterBallFlyingCheckIfHitEnemyOrInWaterInfo["55"] = Value(55);

	this->waterBallFlyingAnimation->getFrames().at(0)->setUserInfo(waterBallFlyingCheckIfHitEnemyOrInWaterInfo);
	this->waterBallFlyingAnimation->getFrames().at(1)->setUserInfo(waterBallFlyingCheckIfHitEnemyOrInWaterInfo);
	this->waterBallFlyingAnimation->getFrames().at(2)->setUserInfo(waterBallFlyingCheckIfHitEnemyOrInWaterInfo);
	this->waterBallFlyingAnimation->getFrames().at(3)->setUserInfo(waterBallFlyingCheckIfHitEnemyOrInWaterInfo);

	EventListenerCustom * waterBallFlyingFrameEventListener = EventListenerCustom::create(AnimationFrameDisplayedNotification, [this, waterBallFlyingCheckIfHitEnemyOrInWaterInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == waterBallFlyingCheckIfHitEnemyOrInWaterInfo){
			Sprite * waterBall = (Sprite *)userData->target;
			int heightDifference = waterBall->getPositionY() - ((Stage1GameplayLayer *)(this->getParent()))->waterSurface->getPositionY();
			if (heightDifference < 0){
				Sprite * smallSplash = Sprite::create("landscapes/splash_small_00.png");
				smallSplash->setPositionX(waterBall->getPositionX());
				smallSplash->setPositionY(((Stage1GameplayLayer *)(this->getParent()))->waterSurface->getPositionY());
				this->getParent()->addChild(smallSplash);
				smallSplash->runAction(Animate::create(this->waterSplashingAnimation_small));

				waterBall->removeFromParent();
			}
			else{
				Vector<GeneralUnit *> enemyList = ((Stage1GameplayLayer *)(this->getParent()))->enemyList;
				for (GeneralUnit * enemy : enemyList){
					int deltax = enemy->getPositionX() - waterBall->getPositionX();
					int deltay = enemy->getPositionY() - waterBall->getPositionY();
					double distance = sqrt(pow(deltax,2) + pow(deltay,2));
					if (distance < (enemy->getContentSize().width + waterBall->getContentSize().width) / 2){
						Sprite * smallSplash = Sprite::create("landscapes/splash_small_00.png");
						smallSplash->setPosition(waterBall->getPosition());
						this->getParent()->addChild(smallSplash);
						smallSplash->runAction(Animate::create(this->waterSplashingAnimation_small));
						//waterBall->removeFromParent();
						//break;
					}
				}
			}
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(waterBallFlyingFrameEventListener, -1);




	//�Ƚ�С��ˮ����Ͷ�������ˮ���򵽵������ϵ���һ��������Ҫ�ڽ�β����removeFromParent��
	this->waterSplashingAnimation_small = Animation::create();
	this->waterSplashingAnimation_small->addSpriteFrameWithFileName("landscapes/splash_small_00.png");
	this->waterSplashingAnimation_small->addSpriteFrameWithFileName("landscapes/splash_small_01.png");
	this->waterSplashingAnimation_small->addSpriteFrameWithFileName("landscapes/splash_small_02.png");
	this->waterSplashingAnimation_small->addSpriteFrameWithFileName("landscapes/splash_small_03.png");
	this->waterSplashingAnimation_small->addSpriteFrameWithFileName("landscapes/splash_small_03.png");
	this->waterSplashingAnimation_small->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->waterSplashingAnimation_small->setRestoreOriginalFrame(true);
	this->waterSplashingAnimation_small->retain();

	
	ValueMap smallSplashingStartInfo;
	ValueMap smallSplashingEndInfo;

	smallSplashingStartInfo["59"] = Value(59);
	smallSplashingEndInfo["56"] = Value(56);

	this->waterSplashingAnimation_small->getFrames().at(0)->setUserInfo(smallSplashingStartInfo);
	this->waterSplashingAnimation_small->getFrames().at(4)->setUserInfo(smallSplashingEndInfo);

	EventListenerCustom * waterSmallSplashingFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, smallSplashingStartInfo, smallSplashingEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == smallSplashingStartInfo){
			Sprite * explosion =(Sprite * ) userData->target;
			Vector<GeneralUnit *> enemyList = ((Stage1GameplayLayer *)this->getParent())->enemyList;
			for (GeneralUnit * enemy : enemyList){
				int deltax = enemy->getPositionX() - explosion->getPositionX();
				int deltay = enemy->getPositionY() - explosion->getPositionY();
				double distance = sqrt(pow(deltax,2)+pow(deltay,2));
				if (distance < (enemy->getContentSize().width + explosion->getContentSize().width) / 2){
					enemy->getHurtByWind(this->DAMAGE_WATER_BALL);//TODOTODOTODO �����Ҫ�Ķ����˴���Ҫ�ĳ�getHurtByWater
				}
			}
		}
		if (*userData->userInfo == smallSplashingEndInfo){
			userData->target->removeFromParent();
		}



	});

	//�����¼���ӵ��¼��ַ���
	_eventDispatcher->addEventListenerWithFixedPriority(waterSmallSplashingFrameEventListener, -1);





	this->airSpinningRightAnimation_kun = Animation::create();
	this->airSpinningRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_air_spinning_right_00.png");
	this->airSpinningRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_air_spinning_right_01.png");
	this->airSpinningRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_air_spinning_right_02.png");
	this->airSpinningRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_air_spinning_right_03.png");
	this->airSpinningRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_air_spinning_right_04.png");
	this->airSpinningRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_air_spinning_right_05.png");
	this->airSpinningRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_air_spinning_right_06.png");
	this->airSpinningRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_air_spinning_right_07.png");
	//this->airSpinningRightAnimation_kun->addSpriteFrameWithFileName("characters/kunpeng/kun_air_spinning_right_08.png");
	this->airSpinningRightAnimation_kun->setDelayPerUnit(this->TIME_FOR_ANIMATION_FRAME_INTERVAL);
	this->airSpinningRightAnimation_kun->setRestoreOriginalFrame(true);
	this->airSpinningRightAnimation_kun->retain();

	ValueMap airSpinningStartInfo;
	ValueMap airSpinningEndInfo;

	airSpinningStartInfo["heroAirSpinning00"] = Value("heroAirSpinning00");
	airSpinningEndInfo["heroAirSpinning07"] = Value("heroAirSpinning07");

	this->airSpinningRightAnimation_kun->getFrames().at(0)->setUserInfo(airSpinningStartInfo);
	this->airSpinningRightAnimation_kun->getFrames().at(7)->setUserInfo(airSpinningEndInfo);

	EventListenerCustom * airSpinningFrameEventListener = EventListenerCustom::create("CCAnimationFrameDisplayedNotification", [this, airSpinningStartInfo, airSpinningEndInfo](EventCustom * event){
		AnimationFrame::DisplayedEventInfo * userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == airSpinningStartInfo){

		}
		if (*userData->userInfo == airSpinningEndInfo){
			this->hover_kun();
		}



	});
	_eventDispatcher->addEventListenerWithFixedPriority(airSpinningFrameEventListener, -1);








}


HeroSprite::~HeroSprite()
{
}


void HeroSprite::button1Hit(){

	if (this->isFish && this->getPositionY() - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY() > 0){
		spitWaterballAttack();
	}
	else{

		Vector<GeneralUnit *> enemyList1 = ((Stage1GameplayLayer *)this->getParent())->enemyList;
		bool enemyWithinScratch = false;
		for (GeneralUnit * enemy1 : enemyList1){
			int enemy_x = enemy1->getPositionX();
			int enemy_y = enemy1->getPositionY();
			if (enemy_y - this->getPositionY() < 50 && enemy_y - this->getPositionY() > -50){
				if (this->facingRight){
					if (enemy_x - this->getPositionX() < 100 && enemy_x - this->getPositionX() > 0){
						enemyWithinScratch = true;
						break;
					}
				}
				else if (this->facingLeft){
					if (enemy_x - this->getPositionX() > -100 && enemy_x - this->getPositionX() < 0){
						enemyWithinScratch = true;
						break;
					}
				}
				else{
					continue;
				}
			}
			else{
				continue;
			}


		}
		if (enemyWithinScratch){
			if (this->isBird){
				this->scratch();
			}
			else if (this->isFish){
				this->finAttack();
			}

		}
		else{
			if (this->isBird){
				this->windAttack();
			}
			else if (this->isFish){
				this->vortexAttack();
			}
		}
	}
}
void HeroSprite::button1Release(){

}
void HeroSprite::button2Hit(){
	if (this->isFish && this->transformable_FishToBird && this->getPositionY() - ((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY() > 0){
		this->transformFromFishToBird();
	}
	else{
		this->dash_forBothShapes();
	}
}
void HeroSprite::button2Release(){
	//do nothing
}

void HeroSprite::button3Hit(){

	//this->getHurtGeneral();//���Թ���û����

	//this->enterWater_kun();

	//spitWaterballAttack();

	log("now gamelayer is at (%d,%d)",this->getParent()->getPositionX(),this->getParent()->getPositionY());
	/*
	if (this->transformable_FishToBird &&this->isFish){
		this->transformFromFishToBird();
	}
	else if (this->transformable_BirdToFish &&this->isBird){
		this->transformFromBirdToFish();
	}
	*/

}
void HeroSprite::button3Release(){

}

HeroSprite * HeroSprite::create(const std::string &filename){
	HeroSprite *mySprite = new HeroSprite();
	if (mySprite &&mySprite->initWithFile(filename)){
		mySprite->autorelease();
		return mySprite;
	}
	CC_SAFE_DELETE(mySprite);
	return nullptr;
}

void HeroSprite::getHurtGeneral(){
	this->stopAllActions();
	this->runAction(Animate::create(this->gettingHurtGeneralAnimation));
}

void HeroSprite::getHurtGeneral(int damage){
	if (this->invincible){
		return;
	}
	this->health -= damage;
	this->stopAllActions();
	if (this->facingLeft){
		this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 1, Vec2(this->getContentSize().width * 1, 0)), MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 5, Vec2(this->getContentSize().width /2, 0)), nullptr));
		if (this->isBird){
			this->runAction(Animate::create(this->gettingHurtLeftGeneralAnimation_peng));
		}
		else{
			this->runAction(Animate::create(this->gettingHurtLeftGeneralAnimation_kun));
		}
	}
	else{
		this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 1, Vec2(-this->getContentSize().width * 1, 0)), MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 5, Vec2(-this->getContentSize().width /2, 0)), nullptr));
		if (this->isBird){
			this->runAction(Animate::create(this->gettingHurtRightGeneralAnimation_peng));
		}
		else{
			this->runAction(Animate::create(this->gettingHurtRightGeneralAnimation_kun));
		}
	}
}

void HeroSprite::getHurtByWater(int damage){
	this->getHurtGeneral(damage);
}

void HeroSprite::disableAllAbilities(){
	this->catchable = false;
	this->dashable = false;
	this->moveable = false;
	this->windAttackable = false;
	this->scratchable = false;
	this->throwable = false;
	this->transformable_BirdToFish = false;
	this->transformable_FishToBird = false;

	this->vortexAttackable = false;
	//this->spittable = false;
}
void HeroSprite::enableAllAbilities(){
	this->catchable = true;
	this->dashable = true;
	this->moveable = true;
	this->windAttackable = true;
	this->scratchable = true;
	this->throwable = true;
	this->transformable_BirdToFish = true;
	this->transformable_FishToBird = true;

	this->vortexAttackable = true;
	this->spittable = true;
}

void HeroSprite::windAttack(){
	if (this->windAttackable){
		if (this->facingRight){
			this->stopAllActions();
			this->runAction(Animate::create(this->blowingWindRightAnimation));
		}
		else if (this->facingLeft){
			this->stopAllActions();
			this->runAction(Animate::create(this->blowingWindLeftAnimation));
		}
	}
}

void HeroSprite::vortexAttack(){
	if (this->vortexAttackable){
		if (this->facingRight){
			this->stopAllActions();
			this->runAction(Animate::create(this->blowingVortexRightAnimation));
		}
		else if (this->facingLeft){
			this->stopAllActions();
			this->runAction(Animate::create(this->blowingVortexLeftAnimation));
		}
	}
}

void HeroSprite::spitWaterballAttack(){
	if (this->spittable){
		if (this->facingLeft){
			this->stopAllActions();
			this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(0, 0)), MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(10, 10)), MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(10, 0)), nullptr));
			this->runAction(Animate::create(this->spittingLeftAnimation));
			this->spittable = false;
		}
		else{
			this->stopAllActions();
			this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(0, 0)), MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(-10, 10)), MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2(-10, 0)), nullptr));
			this->runAction(Animate::create(this->spittingRightAnimation));
			this->spittable = false;
		}
	}
}

void HeroSprite::createWaterballAndFlyIt(){
	Sprite * waterBall = Sprite::create("characters/kunpeng/water_ball_flying_00.png");
	waterBall->setPositionY(this->getPositionY());
	if (this->facingLeft){
		waterBall->setPositionX(this->getPositionX() - this->getContentSize().width / 2);
		this->getParent()->addChild(waterBall);
		waterBall->runAction(JumpBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 10, Vec2(-this->getContentSize().width * 8, -this->getContentSize().width * 3), this->getContentSize().height * 1.5, 1));
		waterBall->runAction(RepeatForever::create(Animate::create(this->waterBallFlyingAnimation)));
	}
	else{
		waterBall->setPositionX(this->getPositionX() + this->getContentSize().width / 2);
		this->getParent()->addChild(waterBall);
		waterBall->runAction(JumpBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 10, Vec2(this->getContentSize().width * 8, -this->getContentSize().width * 3), this->getContentSize().height * 1.5, 1));
		waterBall->runAction(RepeatForever::create(Animate::create(this->waterBallFlyingAnimation)));
	}
}


//��ӿ��е���Ķ�����
void HeroSprite::fallFromSky_kun(){
	if (this->facingRight){
		this->stopAllActions();
		//this->runAction(RepeatForever::create(MoveBy::create(1.0f,Vec2(0,-400))));
		//this->runAction(JumpBy::create(1.0f, Vec2(100,-300), 0.0f, 1));
		
		this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2::ZERO),
						MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(5, -5)), 
						MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL  , Vec2(5, -15)),
						MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL , Vec2(5, -25)),
						MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL*10, Vec2(50, -500)),
						nullptr));
		
		/*
		this->runAction(Sequence::create(DelayTime::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2),
			JumpBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 10, Vec2(this->getContentSize().width * 1, -this->getContentSize().width * 3), this->getContentSize().height * 0.6, 1),
			nullptr));
		*/
		this->runAction(RepeatForever::create(Animate::create(this->fallingFromSkyRightAnimation)));
	}
	else {
		this->stopAllActions();
		//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, -400))));
		this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL, Vec2::ZERO),
						MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 2, Vec2(-5, -5)),
						MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL , Vec2(-5, -15)),
						MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL , Vec2(-5, -25)),
						MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 10, Vec2(-50, -500)),
						nullptr));
		this->runAction(RepeatForever::create(Animate::create(this->fallingFromSkyLeftAnimation)));
	}
}

//�����ˮ����������λ��Action�Ͷ������Ѹ������������ˮ�������£����£�������ˮ������ͷ���������ң���
void HeroSprite::enterWater_kun(){
	if (this->facingRight){
		this->stopAllActions();
		this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 1, Vec2(5, -30)), MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 1, Vec2(20, -5)), MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 1, Vec2(10, 0)), nullptr));
		this->runAction(Animate::create(this->enteringIntoWaterRightAnimation));
	}
	else{
		this->stopAllActions();
		this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 1, Vec2(-5, -30)), MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 1, Vec2(-20, -5)), MoveBy::create(this->TIME_FOR_ANIMATION_FRAME_INTERVAL * 1, Vec2(-10, 0)), nullptr));
		this->runAction(Animate::create(this->enteringIntoWaterLeftAnimation));
	}
}

//���ץ�Ӷ���������̫��ʱ�ʹӷ�үתսʿ��
void HeroSprite::scratch(){
	if (this->scratchable){
		if (this->scratchingType == 1){
			if (this->facingRight){
				this->scratchRight();
			}
			else if (this->facingLeft){
				this->scratchLeft();
			}
			//this->scratchingType = 2;
		}
		else{
			if (this->facingRight){
				this->scratchRight2();
			}
			else if (this->facingLeft){
				this->scratchLeft2();
			}
			//this->scratchingType = 1;
		}
	}
}



void HeroSprite::scratchRight(){
	this->stopAllActions();
	this->runAction(Animate::create(this->scratchingRightAnimation));
}
void HeroSprite::scratchRight2(){
	this->stopAllActions();
	this->runAction(Animate::create(this->scratchingRightAnimation2));
}
void HeroSprite::scratchLeft(){
	this->stopAllActions();
	this->runAction(Animate::create(this->scratchingLeftAnimation));
}
void HeroSprite::scratchLeft2(){
	this->stopAllActions();
	this->runAction(Animate::create(this->scratchingLeftAnimation2));
}

//��Ľ�ս����
void HeroSprite::finAttack(){
	if (this->scratchable){
		if (this->finAttackingType == 1){
			if (this->facingRight){
				this->finAttackRight();
			}
			else if (this->facingLeft){
				this->finAttackLeft();
			}
			//this->scratchingType = 2;
		}
		else{
			if (this->facingRight){
				this->finAttackRight2();
			}
			else if (this->facingLeft){
				this->finAttackLeft2();
			}
			//this->scratchingType = 1;
		}
	}


}

void HeroSprite::finAttackRight(){
	this->stopAllActions();
	this->runAction(Animate::create(this->finAttackRightAnimation));
}
void HeroSprite::finAttackRight2(){
	this->stopAllActions();
	this->runAction(Animate::create(this->finAttackRightAnimation2));
}
void HeroSprite::finAttackLeft(){
	this->stopAllActions();
	this->runAction(Animate::create(this->finAttackLeftAnimation));
}
void HeroSprite::finAttackLeft2(){
	this->stopAllActions();
	this->runAction(Animate::create(this->finAttackLeftAnimation2));
}


// bird dash
void HeroSprite::dash(){
	if (this->dashable){
		if (this->directionToMoveRight){
			dashRight();
		}
		else if (this->directionToMoveDown){
			dashDown();
		}
		else if (this->directionToMoveDownLeft){
			dashDownLeft();
		}
		else if (this->directionToMoveDownRight){
			dashDownRight();
		}
		else if (this->directionToMoveLeft){
			dashLeft();
		}
		else if (this->directionToMoveUp){
			dashUp();
		}
		else if (this->directionToMoveUpLeft){
			dashUpLeft();
		}
		else if (this->directionToMoveUpRight){
			dashUpRight();
		}
		if (this->directionToMoveDown == false &&
			this->directionToMoveUp == false &&
			this->directionToMoveRight == false &&
			this->directionToMoveLeft == false &&
			this->directionToMoveDownLeft == false &&
			this->directionToMoveDownRight == false &&
			this->directionToMoveUpLeft == false &&
			this->directionToMoveUpRight == false){

			if (this->facingRight){
				dashRight();
			}
			else if (this->facingLeft){
				dashLeft();
			}
		}

	}
}

//��Button2�õ�generaldash
void HeroSprite::dash_forBothShapes(){
	if (this->isBird){
		this->dash();
	}
	else{
		this->dash_kun();
	}
}

//bird dashing in 8 directions.
void HeroSprite::dashUp(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(0, this->DISTANCE_AIR_DASHING)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(0, this->DISTANCE_AIR_DASHING_BRAKING)), nullptr));
	if (this->facingRight){
		this->runAction(Animate::create(this->dashingUpRightAnimation));
	}
	else if (this->facingLeft){
		this->runAction(Animate::create(this->dashingUpLeftAnimation));
	}
}
void HeroSprite::dashDown(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(0, -this->DISTANCE_AIR_DASHING)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(0, -this->DISTANCE_AIR_DASHING_BRAKING)), nullptr));
	if (this->facingRight){
		this->runAction(Animate::create(this->dashingDownRightAnimation));
	}
	else if (this->facingLeft){
		this->runAction(Animate::create(this->dashingDownLeftAnimation));
	}
}
void HeroSprite::dashLeft(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(-this->DISTANCE_AIR_DASHING, 0)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(-this->DISTANCE_AIR_DASHING_BRAKING, 0)), nullptr));
	this->runAction(Animate::create(this->dashingLeftAnimation));
}
void HeroSprite::dashRight(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING, 0)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING, 0)), nullptr));
	this->runAction(Animate::create(this->dashingRightAnimation));
	//FiniteTimeAction * moveAction = Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING, 0)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING, 0)), nullptr);
	//FiniteTimeAction * animationAction = Animate::create(this->dashingRightAnimation);
	//this->runAction(Spawn::create(moveAction, animationAction));
}
void HeroSprite::dashUpRight(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING / 1.414, this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING / 1.414, this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingUpRightAnimation));
}
void HeroSprite::dashUpLeft(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(-this->DISTANCE_AIR_DASHING / 1.414, this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(-this->DISTANCE_AIR_DASHING_BRAKING / 1.414, this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingUpLeftAnimation));
}
void HeroSprite::dashDownRight(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(this->DISTANCE_AIR_DASHING / 1.414, -this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(this->DISTANCE_AIR_DASHING_BRAKING / 1.414, -this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingDownRightAnimation));
}
void HeroSprite::dashDownLeft(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_AIR_DASHING, Vec2(-this->DISTANCE_AIR_DASHING / 1.414, -this->DISTANCE_AIR_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_AIR_DASHING_BRAKING, Vec2(-this->DISTANCE_AIR_DASHING_BRAKING / 1.414, -this->DISTANCE_AIR_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingDownLeftAnimation));
}


//���dash
void HeroSprite::dash_kun(){
	if (this->dashable){
		if (this->directionToMoveRight){
			dashRight_kun();
		}
		else if (this->directionToMoveDown){
			dashDown_kun();
		}
		else if (this->directionToMoveDownLeft){
			dashDownLeft_kun();
		}
		else if (this->directionToMoveDownRight){
			dashDownRight_kun();
		}
		else if (this->directionToMoveLeft){
			dashLeft_kun();
		}
		else if (this->directionToMoveUp){
			dashUp_kun();
		}
		else if (this->directionToMoveUpLeft){
			dashUpLeft_kun();
		}
		else if (this->directionToMoveUpRight){
			dashUpRight_kun();
		}
		if (this->directionToMoveDown == false &&
			this->directionToMoveUp == false &&
			this->directionToMoveRight == false &&
			this->directionToMoveLeft == false &&
			this->directionToMoveDownLeft == false &&
			this->directionToMoveDownRight == false &&
			this->directionToMoveUpLeft == false &&
			this->directionToMoveUpRight == false){

			if (this->facingRight){
				dashRight_kun();
			}
			else if (this->facingLeft){
				dashLeft_kun();
			}
		}

	}
}
void HeroSprite::dashRight_kun(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_WATER_DASHING, Vec2(this->DISTANCE_WATER_DASHING, 0)), MoveBy::create(this->TIME_FOR_WATER_DASHING_BRAKING, Vec2(this->DISTANCE_WATER_DASHING_BRAKING, 0)), nullptr));
	this->runAction(Animate::create(this->dashingRightAnimation_kun));
}
void HeroSprite::dashUp_kun(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_WATER_DASHING, Vec2(0, this->DISTANCE_WATER_DASHING)), MoveBy::create(this->TIME_FOR_WATER_DASHING_BRAKING, Vec2(0, this->DISTANCE_WATER_DASHING_BRAKING)), nullptr));
	if (this->facingRight){
		this->runAction(Animate::create(this->dashingUpRightAnimation_kun));
	}
	else {
		this->runAction(Animate::create(this->dashingUpLeftAnimation_kun));
	}
}
void HeroSprite::dashDown_kun(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_WATER_DASHING, Vec2(0, -this->DISTANCE_WATER_DASHING)), MoveBy::create(this->TIME_FOR_WATER_DASHING_BRAKING, Vec2(0, -this->DISTANCE_WATER_DASHING_BRAKING)), nullptr));
	if (this->facingRight){
		this->runAction(Animate::create(this->dashingDownRightAnimation_kun));
	}
	else {
		this->runAction(Animate::create(this->dashingDownLeftAnimation_kun));
	}
}
void HeroSprite::dashLeft_kun(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_WATER_DASHING, Vec2(-this->DISTANCE_WATER_DASHING, 0)), MoveBy::create(this->TIME_FOR_WATER_DASHING_BRAKING, Vec2(-this->DISTANCE_WATER_DASHING_BRAKING, 0)), nullptr));
	this->runAction(Animate::create(this->dashingLeftAnimation_kun));
}
void HeroSprite::dashUpRight_kun(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_WATER_DASHING, Vec2(this->DISTANCE_WATER_DASHING / 1.414, this->DISTANCE_WATER_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_WATER_DASHING_BRAKING, Vec2(this->DISTANCE_WATER_DASHING_BRAKING / 1.414, this->DISTANCE_WATER_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingUpRightAnimation_kun));
}
void HeroSprite::dashUpLeft_kun(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_WATER_DASHING, Vec2(-this->DISTANCE_WATER_DASHING / 1.414, this->DISTANCE_WATER_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_WATER_DASHING_BRAKING, Vec2(-this->DISTANCE_WATER_DASHING_BRAKING / 1.414, this->DISTANCE_WATER_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingUpLeftAnimation_kun));
}
void HeroSprite::dashDownRight_kun(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_WATER_DASHING, Vec2(this->DISTANCE_WATER_DASHING / 1.414, -this->DISTANCE_WATER_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_WATER_DASHING_BRAKING, Vec2(this->DISTANCE_WATER_DASHING_BRAKING / 1.414, -this->DISTANCE_WATER_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingDownRightAnimation_kun));
}
void HeroSprite::dashDownLeft_kun(){
	this->stopAllActions();
	this->runAction(Sequence::create(MoveBy::create(this->TIME_FOR_WATER_DASHING, Vec2(-this->DISTANCE_WATER_DASHING / 1.414, -this->DISTANCE_WATER_DASHING / 1.414)), MoveBy::create(this->TIME_FOR_WATER_DASHING_BRAKING, Vec2(-this->DISTANCE_WATER_DASHING_BRAKING / 1.414, -this->DISTANCE_WATER_DASHING_BRAKING / 1.414)), nullptr));
	this->runAction(Animate::create(this->dashingDownLeftAnimation_kun));
}




void HeroSprite::transformFromBirdToFish(){
	if (this->isBird){
		this->stopAllActions();
		this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(0, -50)), MoveBy::create(0.2f, Vec2(0, -20)), nullptr));
		this->runAction(Animate::create(this->TransformingFromBirdToFishAnimation));
		Sprite * bigSplash = Sprite::create("landscapes/splash_big_00.png");
		bigSplash->setPositionX(this->getPositionX());
		bigSplash->setPositionY(((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY());
		this->getParent()->addChild(bigSplash);
		bigSplash->runAction(Animate::create(this->waterSplashingAnimation_big));
	}
}
void HeroSprite::transformFromFishToBird(){
	if (this->isFish){
		this->stopAllActions();
		this->runAction(Sequence::create(MoveBy::create(0.1f, Vec2(0, 50)), MoveBy::create(0.2f, Vec2(0, 20)), nullptr));
		this->runAction(Animate::create(this->TransformingFromFishToBirdAnimation));
		//Sprite * bigSplash = Sprite::create("landscapes/splash_big_00.png");
		//bigSplash->setPositionX(this->getPositionX());
		//bigSplash->setPositionY(((Stage1GameplayLayer *)this->getParent())->waterSurface->getPositionY());
		//this->getParent()->addChild(bigSplash);
		//bigSplash->runAction(Animate::create(this->waterSplashingAnimation_big));
	}
}


void HeroSprite::move_forBothShapes(){
	if (this->moveable){
		if (this->isBird){
			this->move();
		}
		else{
			this->move_kun();
		}
	}
}

//���move���⿪�ţ����ǵ���ͨ�ƶ�ֻ��������Ϊ�˵��Է��㣬����ϸ��Ŀǰ����public���˷����ƶ�������ʱ��public�����Ӧ��Ϊprivate��
//�ڴ���֤�������ڵ���move����ʱ�Ŀ��ƶ��ԡ�
//one more �ϻ���move��˵����ť��ɵ�λ�ƣ�dash��˵��̼�����ɵ�λ�ơ�
void HeroSprite::move(){
	if (this->moveable){
		if (this->isBird){
			if (this->directionToMoveRight) {
				moveRight();
			}
			if (this->directionToMoveLeft){
				moveLeft();
			}
			if (this->directionToMoveUp){
				moveUp();
			}
			if (this->directionToMoveDown){
				moveDown();
			}
			if (this->directionToMoveUpRight){
				moveUpRight();
			}
			if (this->directionToMoveUpLeft){
				moveUpLeft();
			}
			if (this->directionToMoveDownRight){
				moveDownRight();
			}
			if (this->directionToMoveDownLeft){
				moveDownLeft();
			}
			if (this->directionToMoveUpRight == false &&
				this->directionToMoveRight == false &&
				this->directionToMoveDownRight == false &&
				this->directionToMoveDown == false &&
				this->directionToMoveDownLeft == false &&
				this->directionToMoveLeft == false &&
				this->directionToMoveUpLeft == false &&
				this->directionToMoveUp == false){
				moveBrake();
			}
		}
	}
}


//����ƶ���
//�����������ƶ��Ͳ����ƶ�����һ��runһ�£�û���Ƿ���ƶ�����֤��ʣ�µ��߸�������Ȼ���Ժ�Ҫ�����˴��������
void HeroSprite::moveRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();

	//this->runAction(Spawn::create(RepeatForever::create(MoveBy::create(2.0f,Vec2(33,0))),RepeatForever::create(Animate::create(this->movingRightAnimation)),nullptr));//��֪Ϊ�Σ������ò��ˣ���ʾ[Action update] override me
	/*
	Sequence��Spawn���ǲ��ܺ�RepeatForeverһ���õġ����ɼ�Դ�룬RepeatForever��interval = 0��������������������һ���̡�
	*/
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->SPEED_FLYING_PIXEL_PER_SECOND, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingRightAnimation)));
}
void HeroSprite::moveLeft(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_FLYING_PIXEL_PER_SECOND, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingLeftAnimation)));
}
void HeroSprite::moveUp(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, this->SPEED_FLYING_PIXEL_PER_SECOND))));
	if (this->facingLeft){
		this->runAction(RepeatForever::create(Animate::create(this->movingUpLeftAnimation)));
	}
	else{
		this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation)));

	}
}
void HeroSprite::moveDown(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, -this->SPEED_FLYING_PIXEL_PER_SECOND))));
	if (this->facingLeft){
		this->runAction(RepeatForever::create(Animate::create(this->movingDownLeftAnimation)));
	}
	else{
		this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation)));
	}
}
void HeroSprite::moveUpRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->SPEED_FLYING_PIXEL_PER_SECOND / 1.4142, this->SPEED_FLYING_PIXEL_PER_SECOND / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation)));
}
void HeroSprite::moveUpLeft(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_FLYING_PIXEL_PER_SECOND / 1.4142, this->SPEED_FLYING_PIXEL_PER_SECOND / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpLeftAnimation)));
}
void HeroSprite::moveDownRight(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->SPEED_FLYING_PIXEL_PER_SECOND / 1.4142, -this->SPEED_FLYING_PIXEL_PER_SECOND / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation)));
}
void HeroSprite::moveDownLeft(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_FLYING_PIXEL_PER_SECOND / 1.4142, -this->SPEED_FLYING_PIXEL_PER_SECOND / 1.4142))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownLeftAnimation)));
}


void HeroSprite::move_kun(){
	if (this->moveable){
		if (this->isFish){
			if (this->directionToMoveRight) {
				moveRight_kun();
			}
			if (this->directionToMoveLeft){
				moveLeft_kun();
			}
			if (this->directionToMoveUp){
				moveUp_kun();
			}
			if (this->directionToMoveDown){
				moveDown_kun();
			}
			if (this->directionToMoveUpRight){
				moveUpRight_kun();
			}
			if (this->directionToMoveUpLeft){
				moveUpLeft_kun();
			}
			if (this->directionToMoveDownRight){
				moveDownRight_kun();
			}
			if (this->directionToMoveDownLeft){
				moveDownLeft_kun();
			}
			if (this->directionToMoveUpRight == false &&
				this->directionToMoveRight == false &&
				this->directionToMoveDownRight == false &&
				this->directionToMoveDown == false &&
				this->directionToMoveDownLeft == false &&
				this->directionToMoveLeft == false &&
				this->directionToMoveUpLeft == false &&
				this->directionToMoveUp == false){
				moveBrake_kun();
			}
		}
	}
}

//�����ͨ�ƶ�������û���жϡ�
void HeroSprite::moveRight_kun(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->SPEED_SWIMMING_PIXEL_PER_SECOND, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingRightAnimation_kun)));
}
void HeroSprite::moveUp_kun(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, this->SPEED_SWIMMING_PIXEL_PER_SECOND))));
	if (this->facingLeft){
		this->runAction(RepeatForever::create(Animate::create(this->movingUpLeftAnimation_kun)));
	}
	else{
		this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation_kun)));
	}
}
void HeroSprite::moveDown_kun(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, -this->SPEED_SWIMMING_PIXEL_PER_SECOND))));
	if (this->facingLeft){
		this->runAction(RepeatForever::create(Animate::create(this->movingDownLeftAnimation_kun)));
	}
	else{
		this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation_kun)));
	}
}
void HeroSprite::moveLeft_kun(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_SWIMMING_PIXEL_PER_SECOND, 0))));
	this->runAction(RepeatForever::create(Animate::create(this->movingLeftAnimation_kun)));
}
void HeroSprite::moveUpRight_kun(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->SPEED_SWIMMING_PIXEL_PER_SECOND / 1.414, this->SPEED_SWIMMING_PIXEL_PER_SECOND / 1.414))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpRightAnimation_kun)));
}
void HeroSprite::moveUpLeft_kun(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_SWIMMING_PIXEL_PER_SECOND / 1.414, this->SPEED_SWIMMING_PIXEL_PER_SECOND / 1.414))));
	this->runAction(RepeatForever::create(Animate::create(this->movingUpLeftAnimation_kun)));
}
void HeroSprite::moveDownRight_kun(){
	this->facingRight = true;
	this->facingLeft = false;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->SPEED_SWIMMING_PIXEL_PER_SECOND / 1.414, -this->SPEED_SWIMMING_PIXEL_PER_SECOND / 1.414))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownRightAnimation_kun)));
}
void HeroSprite::moveDownLeft_kun(){
	this->facingRight = false;
	this->facingLeft = true;
	this->stopAllActions();
	this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_SWIMMING_PIXEL_PER_SECOND / 1.414, -this->SPEED_SWIMMING_PIXEL_PER_SECOND / 1.414))));
	this->runAction(RepeatForever::create(Animate::create(this->movingDownLeftAnimation_kun)));
}

void HeroSprite::moveRightWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveRightWithoutAnimation);
}
void HeroSprite::moveUpWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveUpWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, this->SPEED_DURING_ATTACKING_FLYING))));
}
void HeroSprite::moveDownWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveDownWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(0, -this->SPEED_DURING_ATTACKING_FLYING))));
}
void HeroSprite::moveLeftWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveLeftWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_DURING_ATTACKING_FLYING, 0))));
}
void HeroSprite::moveUpRightWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveUpRightWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->SPEED_DURING_ATTACKING_FLYING / 1.4142, this->SPEED_DURING_ATTACKING_FLYING / 1.4142))));
}
void HeroSprite::moveUpLeftWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveUpLeftWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_DURING_ATTACKING_FLYING / 1.4142, this->SPEED_DURING_ATTACKING_FLYING / 1.4142))));
}
void HeroSprite::moveDownRightWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveDownRightWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(this->SPEED_DURING_ATTACKING_FLYING / 1.4142, -this->SPEED_DURING_ATTACKING_FLYING / 1.4142))));
}
void HeroSprite::moveDownLeftWithoutAnimation(){
	this->moveWithoutAnimationBrake();
	//this->runAction(this->moveDownLeftWithoutAnimation);
	//this->runAction(RepeatForever::create(MoveBy::create(1.0f, Vec2(-this->SPEED_DURING_ATTACKING_FLYING / 1.4142, -this->SPEED_DURING_ATTACKING_FLYING / 1.4142))));
}

void HeroSprite::moveWithoutAnimationBrake(){
	//this->stopAction(this->moveRightWithoutAnimation);
	//this->stopAction(this->moveLeftWithoutAnimation);
	//this->stopAction(this->moveUpWithoutAnimation);
	//this->stopAction(this->moveDownWithoutAnimation);
	//this->stopAction(this->moveUpRightWithoutAnimation);
	//this->stopAction(this->moveDownRightWithoutAnimation);
	//this->stopAction(this->moveUpLeftWithoutAnimation);
	//this->stopAction(this->moveDownLeftWithoutAnimation);
}



//brakes after moving����Ȼ��ʱû���꣬����һ��Ҫ���ġ����ϵ������������
void HeroSprite::moveRightBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
}
void HeroSprite::moveLeftBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringLeftAnimation)));
}
void HeroSprite::moveDownBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
}
void HeroSprite::moveUpBrake(){
	this->stopAllActions();
	this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
}
void HeroSprite::moveBrake(){
	this->stopAllActions();
	if (this->facingRight){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
	}
	else if (this->facingLeft){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringLeftAnimation)));

	}
}

void HeroSprite::moveBrake_kun(){
	this->stopAllActions();
	if (this->facingRight){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation_kun)));
	}
	else if (this->facingLeft){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringLeftAnimation_kun)));

	}
}

void HeroSprite::hover(){
	this->stopAllActions();
	if (this->facingRight){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation)));
	}
	else if (this->facingLeft){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringLeftAnimation)));
	}
}

void HeroSprite::hover_kun(){
	this->stopAllActions();
	if (this->facingRight){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringRightAnimation_kun)));
	}
	else if (this->facingLeft){
		this->runAction(RepeatForever::create(Animate::create(this->hoveringLeftAnimation_kun)));
	}
}







void HeroSprite::tryCatch(){

}
void HeroSprite::hold(){

}
void HeroSprite::release(){

}
void HeroSprite::slamDunk(){

}