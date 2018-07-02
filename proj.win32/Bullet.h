
#include "cocos2d.h"
#include "Bird_yyh.h"
USING_NS_CC;
const float BULLETVElOCITY =200;//�����ٶȣ������Լ����ƣ�ÿ�����ߵ�����
class Bullet :  public cocos2d::Sprite
{
public:
	Bullet(Bird_yyh* b);
	~Bullet();
	virtual bool init();

	//����Ӣ�۷ɻ������ӵ�
	static Bullet* create(Bird_yyh* b);

	//�Ƴ�������Ļ���ӷ�Χ���ӵ�������ײ����ӵ����
	void removeBullet(Node* bu);

	//�����ӵ��������н����ӵ�����Ⱦ���ӵ��ķ��ж�����Ĭ��Ϊ���ӵ�
	void ShootBullet(float dt);
	//void ShootBullet();
	//�����ӵ��б�
	Vector <Sprite *>& GetBullet();
public:
	Vector <Sprite *>vecBullet;//�ӵ�����
	SpriteBatchNode* bulletBatchNode;//������Ⱦ�ڵ�
	Bird_yyh* b;//�����Ӣ�۷ɻ�
};