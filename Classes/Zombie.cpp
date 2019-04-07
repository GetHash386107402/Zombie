#include"Zombie.h"
#include"GameMain.h"
CZombie::CZombie()
{
	m_nFullHp = 0;
	m_nHP = 0;
	m_nACK = 0;
	m_nState = 6;
	m_bEffect = true;
	m_bDieEffect = true;
	m_bAttack = false;
	m_finitX = 0;
	m_finitY = 0;
}

CZombie::~CZombie()
{
	m_pAnimateWalk->release();
	m_pAnimateAttack->release();
	m_pAniLostHead->release();
	m_pAniLostWalk->release();
	m_pAniLostAttack->release();
	m_pAnimateDir->release();
	m_pAnimateBoomDie->release();
}

bool CZombie::initWithData(sZombieDt * pData)
{
	if (!Sprite::init())
	{
		return false;
	}
	m_nID = pData->nID;
	m_nFullHp = pData->nHP;
	m_nHP = pData->nHP;
	m_nACK = pData->nACK;
	/*m_pSprite = Sprite::create();*/
	/*this->setAnchorPoint(Vec2(0.5,0.3));*/
	m_vecinitPos = CGameMain::getInstance()->getinitPos();
	m_vecendPos = CGameMain::getInstance()->getendPos();
	int index = rand() % 15;
	m_finitX = m_vecinitPos[index].x;
	m_finitY = m_vecinitPos[index].y;
	this->setPosition(m_finitX, m_finitY+40);
	this->addAnimtaion();
	//this->moveZombie();
	/*this->runAction(RepeatForever::create(m_pAnimateWalk));
	this->runAction(RepeatForever::create(m_pMoveBy));*/
	/*this->addChild(m_pSprite);*/
	this->changeState(E_STATE_PERFECT);
	this->schedule(CC_CALLBACK_0(CZombie::Attack,this, m_nID),3.f,"attack");
	return true;
}
//
//void CZombie::moveZombie()
//{
//	
//	
//	/*for (int i = 0; i < 100; i++)
//	{
//		m_nHP--;
//	}
//	if (900==m_nHP)
//	{
//		this->changeState(E_STATE_HERT);
//	}*/
//	
//	/*this->runAction(m_pAniLostHead);*/
//	/*this->stopAllActions();
//	this->runAction(RepeatForever::create(m_pAniLostWalk));*/
//}

void CZombie::addAnimtaion()
{
	float fSpeed = 20;
	for (int i = 0; i < m_vecendPos.size(); i++)
	{
		if (m_finitY == m_vecendPos[i].y)
		{
			float fDistance = this->getPosition().x - m_vecendPos[i].x;
			float finterval = fDistance / fSpeed;
			m_pMoveTo = MoveTo::create(finterval, m_vecendPos[i]);
			m_pMoveTo->retain();
		}
	}
	
	//完整的状态行走动画
	Animation* pAnimationWalk = Animation::create();
	char szName[32] = {};
	for (int i = 0; i < 21; ++i)
	{
		sprintf_s(szName, "Zombie_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationWalk->addSpriteFrame(pFrame);
	}
	//设置延迟
	pAnimationWalk->setDelayPerUnit(0.2);
	m_pAnimateWalk = Animate::create(pAnimationWalk);
	//RepeatForever* pRep = RepeatForever::create(m_pAnimateWalk);
	m_pAnimateWalk->retain();
	//完整的状态攻击动画
	Animation* pAnimationAttack = Animation::create();
	for (int i = 0; i < 20; ++i)
	{
		sprintf_s(szName, "ZombieAttack_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationAttack->addSpriteFrame(pFrame);
	}
	//设置延迟
	pAnimationAttack->setDelayPerUnit(0.2);
	m_pAnimateAttack = Animate::create(pAnimationAttack);
	m_pAnimateAttack->retain();


	
	//RepeatForever* pRep = RepeatForever::create(m_pAnimateAttack);

	//丢失头部动画
	Animation* pAnimationLostHead = Animation::create();
	
	for (int i = 0; i < 11; ++i)
	{
		sprintf_s(szName, "ZombieHead/ZombieHead_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationLostHead->addSpriteFrame(pFrame);
	}
	//设置延迟
	pAnimationLostHead->setDelayPerUnit(0.05);
	m_pAniLostHead = Animate::create(pAnimationLostHead);
	/*RepeatForever* pRep = RepeatForever::create(m_pAniLostHead);*/
	m_pAniLostHead->retain();

	//不完整状态的走路动画
    Animation* pAnimationLostWalk = Animation::create();
	for (int i = 0; i < 17; ++i)
	{
		sprintf_s(szName, "ZombieLostHead_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationLostWalk->addSpriteFrame(pFrame);
	}
	//设置延迟
	pAnimationLostWalk->setDelayPerUnit(0.2);
	m_pAniLostWalk = Animate::create(pAnimationLostWalk);
	/*RepeatForever* pRep = RepeatForever::create(m_pAniLostWalk);*/
	m_pAniLostWalk->retain();

	//不完整的状态攻击动画
	Animation* pAnimationLostAttack = Animation::create();
	for (int i = 0; i < 10; ++i)
	{
		sprintf_s(szName, "ZombieLostHeadAttack_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationLostAttack->addSpriteFrame(pFrame);
	}
	//设置延迟
	pAnimationLostAttack->setDelayPerUnit(0.2);
	m_pAniLostAttack = Animate::create(pAnimationLostAttack);
	/*RepeatForever* pRep = RepeatForever::create(m_pAniLostAttack);*/
	m_pAniLostAttack->retain();

	//死亡动画
	Animation* pAnimationDir = Animation::create();
	for (int i = 0; i < 9; ++i)
	{
		sprintf_s(szName, "ZombieDie/ZombieDie_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationDir->addSpriteFrame(pFrame);
	}
	//设置延迟
	pAnimationDir->setDelayPerUnit(0.2);
	m_pAnimateDir = Animate::create(pAnimationDir);
	/*RepeatForever* pRep = RepeatForever::create(m_pAnimateDir);*/
	m_pAnimateDir->retain();

	
	//爆炸死亡动画
	Animation* pAnimationBoomDie = Animation::create();
	for (int i = 0; i < 19; ++i)
	{
		sprintf_s(szName, "BoomDie1_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationBoomDie->addSpriteFrame(pFrame);
	}
	//设置延迟
	pAnimationBoomDie->setDelayPerUnit(0.2);
	m_pAnimateBoomDie = Animate::create(pAnimationBoomDie);
	m_pAnimateBoomDie->retain();
}

int CZombie::damage(int nDamage)
{
	m_nHP -= nDamage;
	return m_nHP;
	
}

//int CZombie::attack(int nHp)
//{
//	nHp -= m_nACK;
//	return nHp;
//}

void CZombie::changeState(int nState)
{
	if (m_nState==nState)
	{
		return;
	}
	switch (nState)
	{
	case E_STATE_PERFECT:
		this->stopAllActions();
		this->runAction(m_pMoveTo);
		this->runAction(RepeatForever::create(m_pAnimateWalk));
		break;
	case E_STATE_HERT:
		this->stopAllActions();
		this->runAction(m_pMoveTo);
		this->runAction(RepeatForever::create(m_pAniLostWalk));
		break;
	case E_STATE_ATTACK:
		this->stopAllActions();
		this->runAction(RepeatForever::create(m_pAnimateAttack));
		break;
	case E_STATE_LOSTATTACK:
		this->stopAllActions();
		this->runAction(RepeatForever::create(m_pAniLostAttack));
		break;
	}
	m_nState = nState;
}



CZombie * CZombie::createWithData(sZombieDt * pData)
{
	CZombie* pZombie = new CZombie;
	if (nullptr != pZombie && pZombie->initWithData(pData))
	{
		pZombie->autorelease();
		return pZombie;
	}
	else
	{
		CC_SAFE_DELETE(pZombie);
		return nullptr;
	}
}

void CZombie::Attack(int nID)
{
	if (nullptr != this->findPlant())
	{

		CGameMain::getInstance()->getBulletMgr()->addBullet(this->getPosition(), Vec2(this->findPlant()->getPosition().x - 1, this->findPlant()->getPosition().y), nID);
		/*m_bAttack = true;*/
			if (m_nHP <= 500)
			{
				this->changeState(E_STATE_LOSTATTACK);
			
			}
			else
			{
				this->changeState(E_STATE_ATTACK);
			}
		
		
	}
	else
	{
		if (m_nHP <= 500)
		{
			this->changeState(E_STATE_HERT);

		}
		else
		{
			this->changeState(E_STATE_PERFECT);
		}
	}
}

Node * CZombie::findPlant()
{
	//取得所有怪物查找小于植物攻击范围的怪物
	Vector<Node*>VecPlant = CGameMain::getInstance()->getPlantMgr()->getChildren();
	for (Node* pNode : VecPlant)
	{
		Vec2 tiledZombie = CGameMain::getInstance()->getTiledByPos(this->getPosition());
		Vec2 tiledPlant = CGameMain::getInstance()->getTiledByPos(pNode->getPosition());
		float fDistance = tiledZombie.x - tiledPlant.x;
		if (tiledZombie.y == tiledPlant.y && fDistance==0)
		{
			return pNode;
		}
	}
	return nullptr;
}
