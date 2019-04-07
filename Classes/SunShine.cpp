#include"SunShine.h"
CSunShine::CSunShine()
{
}

CSunShine::~CSunShine()
{
	m_pAniSunShine->release();
}

bool CSunShine::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	m_pSunShineSprtie = Sprite::create();
	this->addChild(m_pSunShineSprtie);
	this->addAnimate();
	this->runAction(RepeatForever::create( m_pAniSunShine));
	return true;
}

void CSunShine::addAnimate()
{
	//��������
	Animation* pSunShineAnimation = Animation::create();
	//��������洢ͼƬ��
	char szName[32] = {};
	for (int i = 0; i < 21; ++i)
	{
		sprintf_s(szName, "Sun_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pSunShineAnimation->addSpriteFrame(pFrame);
	}
	//�����ӳ�
	pSunShineAnimation->setDelayPerUnit(0.2);
	m_pAniSunShine = Animate::create(pSunShineAnimation);
	m_pAniSunShine->retain();
}
