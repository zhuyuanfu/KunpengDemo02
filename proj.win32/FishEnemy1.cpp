#include "FishEnemy1.h"
#include "Stage1GameplayLayer.h"

const static int STATE_DEFAULT = 0;
const static int STATE_ATTACK = 1;
const static int STATE_BE_ATTACKED = 2;
const static int STATE_DEAD = 3;
const static float FRAME_RATE = 0.2;
const static float ANIMATION_DURATION = 0.3;
const static float PADDING = 100;

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

	beAttackedAnimation = Animation::create();
	beAttackedAnimation->addSpriteFrameWithFileName("crab/beattacked0.png");
	beAttackedAnimation->addSpriteFrameWithFileName("crab/beattacked1.png");
	beAttackedAnimation->addSpriteFrameWithFileName("crab/beattacked2.png");
	beAttackedAnimation->addSpriteFrameWithFileName("crab/beattacked3.png");
	beAttackedAnimation->setDelayPerUnit(FRAME_RATE);
	beAttackedAnimation->setRestoreOriginalFrame(true);
	beAttackedAnimation->retain();

	deadAnimation = Animation::create();
	deadAnimation->addSpriteFrameWithFileName("crab/dead0.png");
	deadAnimation->addSpriteFrameWithFileName("crab/dead1.png");
	deadAnimation->addSpriteFrameWithFileName("crab/dead2.png");
	deadAnimation->addSpriteFrameWithFileName("crab/dead3.png");
	deadAnimation->setDelayPerUnit(FRAME_RATE);
	deadAnimation->setRestoreOriginalFrame(true);
	deadAnimation->retain();

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
			int forward = heroPos.x > getPositionX() ? 1 : -1;

			auto bg = ((Stage1GameplayLayer *) getParent())->background;
			auto anchorPt = bg->getAnchorPoint();
			auto contentSize = bg->getContentSize();
			float deltaX = forward * speed * cos(angle);
			float deltaY = speed * sin(angle);

			if (getPositionX() + deltaX < -anchorPt.x * contentSize.width + PADDING
				|| getPositionX() + deltaX > (1 - anchorPt.x) * contentSize.width - PADDING) deltaX = -deltaX;
			if (getPositionY() + deltaY < -anchorPt.y * contentSize.height + PADDING
				|| getPositionY() + deltaY >(1 - anchorPt.y) * contentSize.height - contentSize.height / 2 - PADDING)
			{
				deltaY = -deltaY;
			}

			runAction(Sequence::create(
				MoveTo::create(ANIMATION_DURATION,
					Point(getPositionX() + deltaX, getPositionY() + deltaY)),
				CallFunc::create([this, anchorPt, contentSize]() {
				if (this->getPositionX() < -anchorPt.x * contentSize.width + PADDING)
					this->setPositionX(-anchorPt.x * contentSize.width + PADDING);
				if (this->getPositionX() >(1 - anchorPt.x) * contentSize.width - PADDING)
					this->setPositionX((1 - anchorPt.x) * contentSize.width - PADDING);
				if (this->getPositionY() < -anchorPt.y * contentSize.height + PADDING)
					this->setPositionY(-anchorPt.y * contentSize.height + PADDING);
				if (this->getPositionY() > (1 - anchorPt.y) * contentSize.height - contentSize.height / 2 - PADDING)
					this->setPositionY((1 - anchorPt.y) * contentSize.height - contentSize.height / 2 - PADDING);
				this->state = STATE_DEFAULT;
			}), NULL));
			return;
		}
	}
	wander(); // ����ж�
}

void FishEnemy1::getHurt(int h)
{
	if (STATE_DEAD == state) return;

	state = STATE_BE_ATTACKED;
	health -= h;
	if (health <= 0) die();
	else
	{
		stopAllActions();
		runAction(Sequence::create(Animate::create(beAttackedAnimation), CallFunc::create([this]() {
			this->state = STATE_DEFAULT;
			this->stopAllActions();
			this->runAction(RepeatForever::create(Animate::create(this->defaultAnimation)));
		}), NULL));
	}
}

void FishEnemy1::getHurtByWind(int d)
{
	this->getHurt(d);
}

void FishEnemy1::die()
{
	state = STATE_DEAD;
	stopAllActions();
	runAction(Sequence::create(Animate::create(deadAnimation), CallFunc::create([this]() {
		this->runAction(Sequence::create(FadeOut::create(ANIMATION_DURATION),
			CallFunc::create([this]() { this->setPositionY(-11111); this->removeFromParent(); }), NULL));
	}), NULL));
}

void FishEnemy1::wander()
{
	if (rand() % 12 / 11.0 < runProb) // ��������߶��ĸ���
	{
		float angle = (rand() % 361) * M_PI / 180; // �����ȡһ���Ƕ�

		auto bg = ((Stage1GameplayLayer *) getParent())->background;
		auto anchorPt = bg->getAnchorPoint();
		auto contentSize = bg->getContentSize();
		float deltaX = speed * cos(angle);
		float deltaY = speed * sin(angle);

		if (getPositionX() + deltaX < -anchorPt.x * contentSize.width + PADDING
			|| getPositionX() + deltaX >(1 - anchorPt.x) * contentSize.width - PADDING) deltaX = -deltaX;
		if (getPositionY() + deltaY < -anchorPt.y * contentSize.height + PADDING
			|| getPositionY() + deltaY >(1 - anchorPt.y) * contentSize.height - contentSize.height / 2 - PADDING)
		{
			deltaY = -deltaY;
		}

		runAction(Sequence::create(
			MoveTo::create(ANIMATION_DURATION,
				Point(getPositionX() + deltaX, getPositionY() + deltaY)),
			CallFunc::create([this, anchorPt, contentSize]() {
			if (this->getPositionX() < -anchorPt.x * contentSize.width + PADDING)
				this->setPositionX(-anchorPt.x * contentSize.width + PADDING);
			if (this->getPositionX() >(1 - anchorPt.x) * contentSize.width - PADDING)
				this->setPositionX((1 - anchorPt.x) * contentSize.width - PADDING);
			if (this->getPositionY() < -anchorPt.y * contentSize.height + PADDING)
				this->setPositionY(-anchorPt.y * contentSize.height + PADDING);
			if (this->getPositionY() > (1 - anchorPt.y) * contentSize.height - contentSize.height / 2 - PADDING)
				this->setPositionY((1 - anchorPt.y) * contentSize.height - contentSize.height / 2 - PADDING);
			this->state = STATE_DEFAULT;
		}), NULL));
	}
}

void FishEnemy1::attack(Vec2 pos)
{
	if (state != STATE_DEFAULT) return;

	state = STATE_ATTACK;
	stopAllActions();
	runAction(Sequence::create(Animate::create(attackAnimation), CallFunc::create([this]() {
		Stage1GameplayLayer *gamePlayer = (Stage1GameplayLayer *) this->getParent();
		Sprite *hero = gamePlayer->kunpeng;
		if (hero->getPosition().distance(this->getPosition()) <= this->attackDist)
		{
			// ���Ǳ�����
		}
		this->state = STATE_DEFAULT;
		this->stopAllActions();
		this->runAction(RepeatForever::create(Animate::create(this->defaultAnimation)));
	}), NULL));
}