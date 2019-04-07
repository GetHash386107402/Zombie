#ifndef __DATAMGR_H__
#define __DATAMGR_H__
#include"cocos2d.h"
#include"StructData.h"
USING_NS_CC;

class CDataMgr
{
public:
	CDataMgr();
	~CDataMgr();
	static CDataMgr* getInstance();
	sResDt* getResDt()
	{
		return m_pResDt;
	}
	CLevelDtMgr* getLevelDtMgr()
	{
		return m_pLevelDtMgr;
	}
	CZombieDtMgr* getZombieDtMgr()
	{
		return m_pZombieDtMgr;
	}
	CPlantDtMgr* getPlantDtMgr()
	{
		return m_pPlantDtMgr;
	}
	CPlantAnimDtMgr* getPlantAnimDtMgr()
	{
		return m_PlantAnimDtMgr;
	}
	CCardDtMgr* getCardDtMgr()
	{
		return m_pCardDtMgr;
	}
	CBulletDtMgr* getBulletDtMgr()
	{
		return m_pBulletDtMgr;
	}
private:
	static CDataMgr* m_spInstance;
	sResDt* m_pResDt;
	CLevelDtMgr* m_pLevelDtMgr;
	CZombieDtMgr* m_pZombieDtMgr;
	CPlantDtMgr* m_pPlantDtMgr;
	CPlantAnimDtMgr* m_PlantAnimDtMgr;
	CCardDtMgr* m_pCardDtMgr;
	CBulletDtMgr* m_pBulletDtMgr;
};


#endif // !__DATAMGR_H__

