#include"Bullet.h"
#include"DataMgr.h"
CBullet::CBullet()
{
	m_bBombEffect = true;
}

CBullet::~CBullet()
{
}

bool CBullet::initWithData(sBulletDt * pData)
{
	if (!Sprite::init())
	{
		return false;
	}
	m_nRoleID = pData->nRoleID;
	m_nType = pData->nType;
	m_nACK = pData->nACK;
	m_strImg = pData->strImg;
	m_pSprite = Sprite::create(m_strImg);
	this->addAnimate();
	this->addChild(m_pSprite);
	return true;
}

CBullet * CBullet::createWithData(sBulletDt * pData)
{
	CBullet* pBullet = new CBullet;
	if (nullptr != pBullet && pBullet->initWithData(pData))
	{
		pBullet->autorelease();
		return pBullet;
	}
	else
	{
		CC_SAFE_DELETE(pBullet);
		return nullptr;
	}
}

void CBullet::move(float nIterval ,const Vec2& EndPos)
{
	MoveTo* pMoveTo = MoveTo::create(nIterval, EndPos);
	Sequence* pSeq = Sequence::createWithTwoActions(pMoveTo, RemoveSelf::create());
	this->runAction(pSeq);
}

void CBullet::addAnimate()
{
	//完整的状态行走动画
	Animation* pAnimationBomb = Animation::create();
	pAnimationBomb->addSpriteFrameWithFileName("Image/Bullets/PB0_H.png");
	//设置延迟
	pAnimationBomb->setDelayPerUnit(0.2);
	m_pAnimateBomb = Animate::create(pAnimationBomb);
	//RepeatForever* pRep = RepeatForever::create(m_pAnimateWalk);
	m_pAnimateBomb->retain();
}
	