#include"ZombieMgr.h"
#include"GameMain.h"
CZombieMgr::CZombieMgr()
{
	m_naddCount = 0;
	m_nLevel = 1;
	m_vecZombieCount.clear();
	m_nIndex = 0;
	m_nTime = 0;
}

CZombieMgr::~CZombieMgr()
{
}

bool CZombieMgr::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	this->scheduleUpdate();
	//获取存放敌人数量容器长度
	int vecSize = CDataMgr::getInstance()->getLevelDtMgr()->getDataByLevel(m_nLevel)->m_pNumberCount.size();
	//根据关卡等级获取产生僵尸数量
	for (int i = 0; i < vecSize; i++)
	{
		m_naddCount = CDataMgr::getInstance()->getLevelDtMgr()->getDataByLevel(m_nLevel)->m_pNumberCount[i];
		m_vecZombieCount.push_back(m_naddCount);
	}
	
	//获取源点坐标
	origin = Director::getInstance()->getVisibleOrigin();
	//获取屏幕大小
	visibleSize = Director::getInstance()->getVisibleSize();
	m_nTime = CDataMgr::getInstance()->getLevelDtMgr()->getDataByLevel(m_nLevel)->nTotalTime;
	this->schedule(CC_CALLBACK_0(CZombieMgr::addZombie,this,),m_nTime/4,"addZombie");
	return true;
}

void CZombieMgr::addZombie()
{
	/*Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();*/
	if (m_nIndex>=m_vecZombieCount.size()) 
	{
		this->unschedule("addZombie");
		return;
	}
	for (int i = 0; i < m_vecZombieCount[m_nIndex]; i++)
	{
		sZombieDt* pZombieDt = CDataMgr::getInstance()->getZombieDtMgr()->getDataByID(2001);
		CZombie* pZombie = CZombie::createWithData(pZombieDt);
		Vec2 vecZombieinitPos = CGameMain::getInstance()->getTiledByPos(Vec2(pZombie->getinitX(), pZombie->getinitY()));
		this->addChild(pZombie, vecZombieinitPos.y);
	}
	m_nIndex++;
}





