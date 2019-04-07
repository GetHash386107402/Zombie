#include"BulletMgr.h"
#include"DataMgr.h"
CBulletMgr::CBulletMgr()
{
}

CBulletMgr::~CBulletMgr()
{
}

bool CBulletMgr::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void CBulletMgr::addBullet(const Vec2& StartPos, const Vec2& EndPos, int nID)
{
	CCLOG("ADD");
	sBulletDt* pData = CDataMgr::getInstance()->getBulletDtMgr()->getDataByID(nID);
	CBullet* pBullet = CBullet::createWithData(pData);
	pBullet->setPosition(StartPos.x, StartPos.y+10);
	this->addChild(pBullet);
	float fSpeed = 150;
	float finterval = abs(EndPos.x - StartPos.x)/fSpeed;
	if (pBullet->getType()==2)
	{
		pBullet->setVisible(false);
	}
	pBullet->move(finterval,EndPos);
}
