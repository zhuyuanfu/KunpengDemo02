#include "FishEnemy1.h"
#include "Stage1GameplayLayer.h"

const static int STATE_DEFAULT = 0;
const static int STATE_ATTACK = 1;
const static int STATE_BE_ATTACKED = 2;
const static int STATE_DEAD = 3;
const static float FRAME_RATE = 0.2;
const static float ANIMATION_DURATION = 0.3;

FishEnemy1::FishEnemy1()
{
	state = STATE_DEFAULT; // ��ǰ״̬
	health = 100; // Ѫ��
	camp = 2; // ��Ӫ
	speed = 5; // �ٶ�
	hurt = 10; // �˺�
	pauseflagDist = 500; // ���о��루�������ôԶ��ʱ��ſ��ܷ��ֵ��ˣ�
	attackDist = 100; // �������루�������ôԶ��ʱ��ſ��ܷ���������
	discoverProb = 0.7; // ���ֵ��˵ĸ���
	attackProb = 0.4; // ���������ĸ���
	runProb = 0.7; // �߶��ĸ��ʣ��п���ͣ��ԭ�ز��ߣ�

	defaultAnimation = Animation::create();
	defaultAnimation->addSpriteFrameWithFileName("crab/default0.png");
	defaultAnimation->addSpriteFrameWithFileName("crab/default1.png");
	defaultAnimation->addSpriteFrameWithFileName("crab/default2.png");
	defaultAnimation->addSpriteFrameWithFileName("crab/default3.png");
	defaultAnimation->addSpriteFrameWithFileName("crab/default4.png");
	defaultAnimation->addSpriteFrameWithFileName("crab/default5.png");
	defaultAnimation->addSpriteFrameWithFileName("crab/default6.png");
	defaultAnimation->addSpriteFrameWithFileName("crab/default7.png");
	defaultAnimation->setDelayPerUnit(FRAME_RATE);
	defaultAnimation->setRestoreOriginalFrame(true);
	defaultAnimation->retain();

	attackAnimation = Animation::create();
	attackAnimation->addSpriteFrameWithFileName("crab/attack0.png");
	attackAnimation->addSpriteFrameWithFileName("crab/attack1.png");
	attackAnimation->addSpriteFrameWithFileName("crab/attack2.png");
	attackAnimation->addSpriteFrameWithFileName("crab/attack3.png");
	attackAnimation->addSpriteFrameWithFileName("crab/attack4.png");
	attackAnimation->addSpriteFrameWithFileName("crab/attack5.png");
	attackAnimation->addSpriteFrameWithFileName("crab/attack6.png");
	attackAnimation->addSpriteFrameWithFileName("crab/attack7.png");
	attackAnimation->setDelayPerUnit(FRAME_RATE);
	attackAnimation->setRestoreOriginalFrame(true);
	attackAnimation->retain();
	ValueMap attackEndInfo;
	attackEndInfo["1"] = Value(120);
	attackAnimation->getFrames().at(7)->setUserInfo(attackEndInfo);

	beAttackedAnimation = Animation::create();
	beAttackedAnimation->addSpriteFrameWithFileName("crab/beattacked0.png");
	beAttackedAnimation->addSpriteFrameWithFileName("crab/beattacked1.png");
	beAttackedAnimation->addSpriteFrameWithFileName("crab/beattacked2.png");
	beAttackedAnimation->addSpriteFrameWithFileName("crab/beattacked3.png");
	beAttackedAnimation->setDelayPerUnit(FRAME_RATE);
	beAttackedAnimation->setRestoreOriginalFrame(true);
	beAttackedAnimation->retain();
	ValueMap beAttackedInfo;
	beAttackedInfo["1"] = Value(121);
	beAttackedAnimation->getFrames().at(3)->setUserInfo(beAttackedInfo);

	deadAnimation = Animation::create();
	deadAnimation->addSpriteFrameWithFileName("crab/dead0.png");
	deadAnimation->addSpriteFrameWithFileName("crab/dead1.png");
	deadAnimation->addSpriteFrameWithFileName("crab/dead2.png");
	deadAnimation->addSpriteFrameWithFileName("crab/dead3.png");
	deadAnimation->setDelayPerUnit(FRAME_RATE);
	deadAnimation->setRestoreOriginalFrame(true);
	deadAnimation->retain();
	ValueMap deadInfo;
	deadInfo["1"] = Value(122);
	deadAnimation->getFrames().at(3)->setUserInfo(deadInfo);

	EventListenerCustom *animationListener = EventListenerCustom::create(AnimationFrameDisplayedNotification,
		[this, attackEndInfo, beAttackedInfo, deadInfo](EventCustom *event) {
		auto userData = static_cast<AnimationFrame::DisplayedEventInfo *> (event->getUserData());
		if (*userData->userInfo == attackEndInfo || *userData->userInfo == beAttackedInfo)
		{
			if (*userData->userInfo == attackEndInfo)
			{
				Stage1GameplayLayer *gamePlayer = (Stage1GameplayLayer *)getParent();
				Sprite *hero = gamePlayer->kunpeng;
				if (hero->getPosition().distance(getPosition()) <= attackDist)
				{
					// ���Ǳ�����
				}
			}
			this->state = STATE_DEFAULT;
			this->stopAllActions();
			this->runAction(RepeatForever::create(Animate::create(this->defaultAnimation)));
		}

		if (*userData->userInfo == deadInfo)
		{
			this->runAction(Sequence::create(FadeOut::create(ANIMATION_DURATION),
				CallFunc::create([this]() { this->removeFromParent(); }), NULL));
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(animationListener, -1);

	runAction(RepeatForever::create(Animate::create(defaultAnimation)));
}

FishEnemy1::~FishEnemy1() {}

GeneralUnit * FishEnemy1::create(const std::string & filename)
{
	GeneralUnit *myUnit = new FishEnemy1();
	if (myUnit && myUnit->initWithFile(filename)) {
		myUnit->autorelease();
		return myUnit;
	}
	CC_SAFE_DELETE(myUnit);
	return nullptr;
}

void FishEnemy1::wanderAbout()
{
	if (state != STATE_DEFAULT) return;

	Stage1GameplayLayer *gamePlayer = (Stage1GameplayLayer *) getParent();
	Sprite *hero = gamePlayer->kunpeng;

	Vec2 heroPos = hero->getPosition();
	float dist = heroPos.distance(getPosition());
	srand((unsigned int)time(0));
	if (dist < pauseflagDist) // ������˽��������о���
	{
		if (dist < attackDist && rand() % 12 / 11.0 < attackProb) // ������˽����˹������������㹥������
		{
			attack(heroPos);
			return;
		}
		if (rand() % 12 / 11.0 < discoverProb) // ������㷢�ֵ��˵ĸ���
		{
			float angle = asin((heroPos.y - getPositionY()) / dist); // ���������֮��ĽǶ�
			runAction(Sequence::create(
				MoveTo::create(ANIMATION_DURATION, // Ȼ�󳯵����ƶ�
					Point(getPositionX() + (heroPos.x > getPositionX() ? 1 : -1) * speed * cos(angle),
					getPositionY() + speed * sin(angle))),
				CallFunc::create([this]() { this->state = STATE_DEFAULT; }), // ���״̬��ΪĬ��
				NULL));
			return;
		}
	}
	wander(); // ����ж�
}

void FishEnemy1::getHurt(int h)
{
	if (STATE_DEAD == state) return;

	log("be attacked");

	state = STATE_BE_ATTACKED;
	health -= h;
	if (health <= 0) die();
	else
	{
		stopAllActions();
		runAction(Animate::create(beAttackedAnimation));
	}
}

void FishEnemy1::die()
{
	log("dead");
	state = STATE_DEAD;
	stopAllActions();
	runAction(Animate::create(deadAnimation));
}

void FishEnemy1::wander()
{
	if (rand() % 12 / 11.0 < runProb) // ��������߶��ĸ���
	{
		float angle = (rand() % 361) * M_PI / 180; // �����ȡһ���Ƕ�
		runAction(Sequence::create(
			MoveTo::create(ANIMATION_DURATION, // ��
				Point(getPositionX() - speed * cos(angle), getPositionY() + speed * sin(angle))),
			CallFunc::create([this]() { this->state = STATE_DEFAULT; }), // ״̬��ΪĬ��
			NULL));
	}
}

void FishEnemy1::attack(Vec2 pos)
{
	if (state != STATE_DEFAULT) return;

	state = STATE_ATTACK;
	stopAllActions();
	runAction(Animate::create(attackAnimation));
}
