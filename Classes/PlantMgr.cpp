#include"PlantMgr.h"
#include"DataMgr.h"
#include"GameMain.h"
CPlantMgr::CPlantMgr()
{
	m_nAnimID = 0;
}

CPlantMgr::~CPlantMgr()
{
}

bool CPlantMgr::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

bool CPlantMgr::addPlant(int nID,Vec2 clickPos)
{
	sPlantDt* pData = CDataMgr::getInstance()->getPlantDtMgr()->getDataByID(nID);
	CPlant* pPlant = CPlant::createWithData(pData);
	pPlant->setPosition(clickPos);
	this->addChild(pPlant);
	pPlant->setbaddPlant(true);
	bool badd = pPlant->getbaddPlant();
	return badd;
}





