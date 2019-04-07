#include"DataMgr.h"

CDataMgr* CDataMgr::m_spInstance = nullptr;
CDataMgr::CDataMgr()
{
	m_pResDt = new sResDt;
	m_pResDt->LoadFile("Data/ResDt.json");
	m_pLevelDtMgr = new CLevelDtMgr;
	m_pLevelDtMgr->LoadFile("Data/LevelDt.json");
	m_pZombieDtMgr = new CZombieDtMgr;
	m_pZombieDtMgr->LoadFile("Data/EnemyDt.json");
	m_pPlantDtMgr = new CPlantDtMgr;
	m_pPlantDtMgr->LoadFile("Data/PlanDt.json");
	m_PlantAnimDtMgr = new CPlantAnimDtMgr;
	m_PlantAnimDtMgr->LoadFile("Data/PlantAnimationDt.json");
	m_pCardDtMgr = new CCardDtMgr;
	m_pCardDtMgr->LoadFile("Data/CardDt.json");
	m_pBulletDtMgr = new CBulletDtMgr;
	m_pBulletDtMgr->LoadFile("Data/BulletDt.json");
}

CDataMgr::~CDataMgr()
{
}

CDataMgr * CDataMgr::getInstance()
{
	if (nullptr == m_spInstance)
	{
		m_spInstance = new CDataMgr;
	}
	return m_spInstance;
}
