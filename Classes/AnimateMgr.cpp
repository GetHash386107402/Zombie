#include"AnimateMgr.h"
CAnimateMgr::CAnimateMgr()
{
}

CAnimateMgr::~CAnimateMgr()
{
	m_pAnimateWalk->release();
	m_pAnimateAttack->release();
	m_pAniLostHead->release();
	m_pAniLostWalk->release();
	m_pAniLostAttack->release();
	m_pAnimateDir->release();
}

void CAnimateMgr::addAnimtaion()
{
	m_pMoveBy = MoveBy::create(30.0f, Vec2(-800, 0));
	m_pMoveBy->retain();
	//������״̬���߶���
	Animation* pAnimationWalk = Animation::create();
	char szName[32] = {};
	for (int i = 0; i < 21; ++i)
	{
		sprintf_s(szName, "Zombie_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationWalk->addSpriteFrame(pFrame);
	}
	//�����ӳ�
	pAnimationWalk->setDelayPerUnit(0.2);
	m_pAnimateWalk = Animate::create(pAnimationWalk);
	//RepeatForever* pRep = RepeatForever::create(m_pAnimateWalk);
	m_pAnimateWalk->retain();
	//������״̬��������
	Animation* pAnimationAttack = Animation::create();
	for (int i = 0; i < 20; ++i)
	{
		sprintf_s(szName, "ZombieAttack_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationAttack->addSpriteFrame(pFrame);
	}
	//�����ӳ�
	pAnimationAttack->setDelayPerUnit(0.2);
	m_pAnimateAttack = Animate::create(pAnimationAttack);
	m_pAnimateAttack->retain();



	//RepeatForever* pRep = RepeatForever::create(m_pAnimateAttack);

	//��ʧͷ������
	Animation* pAnimationLostHead = Animation::create();

	for (int i = 0; i < 11; ++i)
	{
		sprintf_s(szName, "ZombieHead/ZombieHead_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationLostHead->addSpriteFrame(pFrame);
	}
	//�����ӳ�
	pAnimationLostHead->setDelayPerUnit(0.05);
	m_pAniLostHead = Animate::create(pAnimationLostHead);
	/*RepeatForever* pRep = RepeatForever::create(m_pAniLostHead);*/
	m_pAniLostHead->retain();

	//������״̬����·����
	Animation* pAnimationLostWalk = Animation::create();
	for (int i = 0; i < 17; ++i)
	{
		sprintf_s(szName, "ZombieLostHead_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationLostWalk->addSpriteFrame(pFrame);
	}
	//�����ӳ�
	pAnimationLostWalk->setDelayPerUnit(0.2);
	m_pAniLostWalk = Animate::create(pAnimationLostWalk);
	/*RepeatForever* pRep = RepeatForever::create(m_pAniLostWalk);*/
	m_pAniLostWalk->retain();
	m_pAniLostWalk->setTag(1);
	//��������״̬��������
	Animation* pAnimationLostAttack = Animation::create();
	for (int i = 0; i < 10; ++i)
	{
		sprintf_s(szName, "ZombieLostHeadAttack_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationLostAttack->addSpriteFrame(pFrame);
	}
	//�����ӳ�
	pAnimationLostAttack->setDelayPerUnit(0.2);
	m_pAniLostAttack = Animate::create(pAnimationLostAttack);
	/*RepeatForever* pRep = RepeatForever::create(m_pAniLostAttack);*/
	m_pAniLostAttack->retain();

	//��������
	Animation* pAnimationDir = Animation::create();
	for (int i = 0; i < 9; ++i)
	{
		sprintf_s(szName, "ZombieDie/ZombieDie_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationDir->addSpriteFrame(pFrame);
	}
	//�����ӳ�
	pAnimationDir->setDelayPerUnit(0.2);
	m_pAnimateDir = Animate::create(pAnimationDir);
	//RepeatForever* pRep = RepeatForever::create(m_pAnimateDir);
	m_pAnimateDir->retain();
}
