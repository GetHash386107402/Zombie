#include"Plant.h"
#include"DataMgr.h"
#include"GameMain.h"
CPlant::CPlant()
{
	m_nState = E_STATE_NORMALL;
	m_baddPlant = false;
} 

CPlant::~CPlant()
{
	m_pAnimatePlant->release();
	m_pAnimateCracked1->release();
	m_pAnimateCracked1->release();
}

bool CPlant::initWithData(sPlantDt * pData)
{
	if (!Sprite::init())
	{
		return false;
	}
	m_nHP = pData->nHP;
	m_nACK = pData->nACK;
	m_nScore = pData->nScore;
	m_nID = pData->nID;
	/*m_strImg = pData->strImg;*/
	/*m_pSprite = Sprite::create();*/
	this->addAnimation(m_nID);
	/*this->addChild(m_pSprite);*/
	if (m_nID!=1006)
	{
		this->runAction(RepeatForever::create(m_pAnimatePlant));
	}
	else
	{
		this->runAction(Sequence::create(m_pAnimatePlant, RemoveSelf::create(),NULL));
	}
	this->runAction(RepeatForever::create(m_pAnimatePlant));
	this->schedule(CC_CALLBACK_0(CPlant::fire,this, m_nID), 1.5f, "fire");
	this->schedule(CC_CALLBACK_0(CPlant::createSunShine, this), 8.f, "createSunShine");
	this->changePlantState(E_STATE_NORMALL);
	return true;
} 

CPlant * CPlant::createWithData(sPlantDt * pData)
{
	CPlant* pPlant = new CPlant;
	if (nullptr != pPlant && pPlant->initWithData(pData))
	{
		pPlant->autorelease();
		return pPlant;
	}
	else
	{
		CC_SAFE_DELETE(pPlant);
		return nullptr;
	}
}

void CPlant::fire(int nID)
{
	if (nullptr != this->findZombie())
	{
		if (m_nACK!=0)
		{
			CGameMain::getInstance()->getBulletMgr()->addBullet(this->getPosition(), this->findZombie()->getPosition(), nID);
		}
	}
	
	
}

void CPlant::createSunShine()
{
	if (m_nID == 1005)
	{
		CGameMain::getInstance()->getSunShineMgr()->addCreateSunShine(this->getPosition(), this->getPosition());
	}
}

Node * CPlant::findZombie()
{
	Vector<Node*>VecZombie = CGameMain::getInstance()->getZombieMgr()->getChildren();
	//樱桃查找僵尸
	//取得所有怪物查找小于植物攻击范围的怪物
	for (Node* pNode:VecZombie)
	{
		Vec2 tiledZombie = CGameMain::getInstance()->getTiledByPos(pNode->getPosition());
		Vec2 tiledPlant = CGameMain::getInstance()->getTiledByPos(this->getPosition());
		float fDistance = tiledZombie.x - tiledPlant.x;
		if (tiledZombie.y == tiledPlant.y && fDistance <= 7 && fDistance >= 0)
		{
			return pNode;
		}

	}
	return nullptr;
}

void CPlant::addAnimation(int nID)
{
	//完整的状态行走动画
	Animation* pAnimationPlant = Animation::create();
	int nSize = CDataMgr::getInstance()->getPlantAnimDtMgr()->getDataByID(nID)->vecstrImg.size();
	for (int i = 0; i < nSize; i++)
	{
		string szName = CDataMgr::getInstance()->getPlantAnimDtMgr()->getDataByID(nID)->vecstrImg[i];
		m_vecAnimDt.push_back(szName);
	}
	
	for (int j = 0; j < m_vecAnimDt.size(); ++j)
	{
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(m_vecAnimDt[j]);
		pAnimationPlant->addSpriteFrame(pFrame);
	}
	//设置延迟
	pAnimationPlant->setDelayPerUnit(0.2);
	m_pAnimatePlant = Animate::create(pAnimationPlant);
	m_pAnimatePlant->retain();

	//添加WULLWALL
	Animation* pAnimationCracked1 = Animation::create();
	char szName[32] = {};
	for (int i = 0; i < 10; ++i)
	{
		sprintf_s(szName, "Wallnut_cracked1_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationCracked1->addSpriteFrame(pFrame);
	}
	//设置延迟
	pAnimationCracked1->setDelayPerUnit(0.2);
	m_pAnimateCracked1 = Animate::create(pAnimationCracked1);
	//RepeatForever* pRep = RepeatForever::create(m_pAnimateWalk);
	m_pAnimateCracked1->retain();

	//添加WULLWALL
	Animation* pAnimationCracked2 = Animation::create();
	for (int i = 0; i < 14; ++i)
	{
		sprintf_s(szName, "Wallnut_cracked2_%d.png", i);
		SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
		pAnimationCracked2->addSpriteFrame(pFrame);
	}
	//设置延迟
	pAnimationCracked2->setDelayPerUnit(0.2);
	m_pAnimateCracked2 = Animate::create(pAnimationCracked2);
	//RepeatForever* pRep = RepeatForever::create(m_pAnimateWalk);
	m_pAnimateCracked2->retain();
}

int CPlant::damage(int nDamage)
{
	m_nHP -= nDamage;
	return m_nHP;
}

bool CPlant::bDeath()
{
	if (m_nHP<=0)
	{
		return true;
	}
	return false;
}

void CPlant::changePlantState(int nState)
{
	if (m_nState == nState)
	{
		return;
	}
	switch (nState)
	{	
	case E_STATE_NORMALL:
		this->stopAllActions();
		this->runAction(RepeatForever::create(m_pAnimatePlant));
		break;
	case E_STATE_CRACKED1:
		this->stopAllActions();
		this->runAction(RepeatForever::create(m_pAnimateCracked1));
		break;
	case E_STATE_CRACKED2:
		this->stopAllActions();
		this->runAction(RepeatForever::create(m_pAnimateCracked2));
		break;
	}
	m_nState = nState;
}


