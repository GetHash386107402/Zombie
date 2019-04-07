#include"StructData.h"
#include "rapidjson.h"
#include "document.h"

void sResDt::LoadFile(char * pFileName)
{
	//获得文件全路径
	string strPath = FileUtils::getInstance()->fullPathForFilename(pFileName);
	//取到文件信息
	string strData = FileUtils::getInstance()->getStringFromFile(strPath);
	//解析
	//创建DOC对象
	rapidjson::Document doc;
	//解析到DOC对象
	doc.Parse<0>(strData.c_str());

	rapidjson::Value& vPng = doc["png"];
	for (int i = 0; i < vPng.Size(); ++i)
	{
		vecPngs.push_back(vPng[i].GetString());
	}
	rapidjson::Value& vPlist = doc["plist"];
	for (int i = 0; i < vPlist.Size(); ++i)
	{
		vecPlists.push_back(vPlist[i].GetString());
	}
}
/*---------------------------------------------------*/
CLevelDtMgr::CLevelDtMgr()
{
}

CLevelDtMgr::~CLevelDtMgr()
{
}

void CLevelDtMgr::LoadFile(char * pFileName)
{
	//获取全路径
	string strPath = FileUtils::getInstance()->fullPathForFilename(pFileName);
	//json转换string
	string strData = FileUtils::getInstance()->getStringFromFile(strPath);
	//创建DOC对象
	rapidjson::Document doc;
	doc.Parse<0>(strData.c_str());
	for (int i = 0; i < doc.Size(); ++i)
	{
		sLevelDt* pData = new sLevelDt();
		rapidjson::Value & vData = doc[i];
		pData->nLevel = vData["Level"].GetInt();
		pData->m_pMapImage = vData["Map"].GetString();
		rapidjson::Value& vCount = vData["NumberCount"];
		for (int j = 0; j < vCount.Size(); ++j)
		{
			pData->m_pNumberCount.push_back(vCount[j].GetInt());
		}
		pData->nTotalTime = vData["TotalTime"].GetInt();
		m_vecDatas.push_back(pData);
	}
	doc.Clear();
}

sLevelDt * CLevelDtMgr::getDataByLevel(int nLevel)
{
	for (sLevelDt* pData : m_vecDatas)
	{
		if (nLevel == pData->nLevel)
		{
			return pData;
		}
	}
	return nullptr;
}

sLevelDt * CLevelDtMgr::getCurLevel()
{
	return m_vecDatas[m_nLevel - 1];
}

/*--------------------------------------------*/
CZombieDtMgr::CZombieDtMgr()
{
}

CZombieDtMgr::~CZombieDtMgr()
{
}

void CZombieDtMgr::LoadFile(char * pFileName)
{
	//获得全路径
	string strPath = FileUtils::getInstance()->fullPathForFilename(pFileName);
	//json转换string
	string strData = FileUtils::getInstance()->getStringFromFile(strPath);
	//创建DOC对象
	rapidjson::Document doc;
	doc.Parse<0>(strData.c_str());
	for (int i = 0; i < doc.Size(); ++i)
	{
		sZombieDt* pData = new sZombieDt();
		rapidjson::Value& vData = doc[i];
		pData->nID = vData["id"].GetInt();
		pData->nHP = vData["hp"].GetInt();
		pData->nACK = vData["ack"].GetInt();
		pData->strImg = vData["img"].GetString();
		m_vecDatas.push_back(pData);
	}
	doc.Clear();
}

sZombieDt * CZombieDtMgr::getDataByID(int nID)
{
	for (sZombieDt* pData : m_vecDatas)
	{
		if (nID == pData->nID)
		{
			return pData;
		}
	}
	return nullptr;
}
/*---------------------------------------------------*/
//植物数据
CPlantDtMgr::CPlantDtMgr()
{
}

CPlantDtMgr::~CPlantDtMgr()
{
}

void CPlantDtMgr::LoadFile(char * pFileName)
{
	//获取全路径
	string strPath = FileUtils::getInstance()->fullPathForFilename(pFileName);
	//把Json转换string
	string strData = FileUtils::getInstance()->getStringFromFile(strPath);
	//创建DOC
	rapidjson::Document doc;
	doc.Parse<0>(strData.c_str());
	for (int  i = 0; i < doc.Size(); ++i)
	{
		sPlantDt* pData = new sPlantDt;
		rapidjson::Value& vecData = doc[i];
		pData->nID = vecData["ID"].GetInt();
		pData->nHP = vecData["Hp"].GetInt();
		pData->nACK = vecData["Ack"].GetInt();
		pData->nScore = vecData["Score"].GetInt();
		pData->strImg = vecData["Img"].GetString();
		m_vecDatas.push_back(pData);
	}
	doc.Clear();
}

sPlantDt * CPlantDtMgr::getDataByID(int nID)
{
	for (sPlantDt* pData : m_vecDatas)
	{
		if (nID == pData->nID )
		{
			return pData;
		}
	}
	return nullptr;
}
/*-----------------------------------------*/
CPlantAnimDtMgr::CPlantAnimDtMgr()
{
}

CPlantAnimDtMgr::~CPlantAnimDtMgr()
{
}
void CPlantAnimDtMgr::LoadFile(char * pFileName)
{
	//获取全路径
	string strPath = FileUtils::getInstance()->fullPathForFilename(pFileName);
	//把Json转换string
	string strData = FileUtils::getInstance()->getStringFromFile(strPath);
	//创建DOC
	rapidjson::Document doc;
	doc.Parse<0>(strData.c_str());
	for (int i = 0; i < doc.Size(); ++i)
	{
		sPlantAnimDt* pData = new sPlantAnimDt;
		rapidjson::Value& vecData = doc[i];
		pData->nID = vecData["PlantID"].GetInt();
		rapidjson::Value& vecImg = vecData["Img"];
		for (int j = 0; j < vecImg.Size(); ++j)
		{
			pData->vecstrImg.push_back(vecImg[j].GetString());
		}
		m_vecDatas.push_back(pData);
	}
	doc.Clear();

}
sPlantAnimDt * CPlantAnimDtMgr::getDataByID(int nID)
{
	for (sPlantAnimDt* pData : m_vecDatas)
	{
		if (nID == pData->nID)
		{
			return pData;
		}
	}
	return nullptr;
}
/*-----------------------------------------*/
//卡片数据
CCardDtMgr::CCardDtMgr()
{
}

CCardDtMgr::~CCardDtMgr()
{
}

void CCardDtMgr::LoadFile(char * pFileName)
{
	//获取全路径
	string strPath = FileUtils::getInstance()->fullPathForFilename(pFileName);
	//把Json转换string
	string strData = FileUtils::getInstance()->getStringFromFile(strPath);
	//创建DOC
	rapidjson::Document doc;
	doc.Parse<0>(strData.c_str());
	for (int i = 0; i < doc.Size(); ++i)
	{
		sCardDt* pData = new sCardDt;
		rapidjson::Value& vecData = doc[i];
		pData->nCardID = vecData["CardID"].GetInt();
		pData->nPlantID = vecData["PlantID"].GetInt();
		pData->nScore = vecData["Score"].GetInt();
		pData->strImg = vecData["Img"].GetString();
		m_vecDatas.push_back(pData);
	}
	doc.Clear();
}

sCardDt * CCardDtMgr::getDataByID(int nID)
{
	for (sCardDt* pData : m_vecDatas)
	{
		if (nID == pData->nCardID)
		{
			return pData;
		}
	}
	return nullptr;
}
/*--------------------------------------*/
//子弹数据
CBulletDtMgr::CBulletDtMgr()
{
}

CBulletDtMgr::~CBulletDtMgr()
{
}

void CBulletDtMgr::LoadFile(char * pFileName)
{
	//获取全路径
	string strPath = FileUtils::getInstance()->fullPathForFilename(pFileName);
	//把Json转换string
	string strData = FileUtils::getInstance()->getStringFromFile(strPath);
	//创建DOC
	rapidjson::Document doc;
	doc.Parse<0>(strData.c_str());
	for (int i = 0; i < doc.Size(); ++i)
	{
		sBulletDt* pData = new sBulletDt;
		rapidjson::Value& vecData = doc[i];
		pData->nRoleID = vecData["RoleID"].GetInt();
		pData->nACK = vecData["Ack"].GetInt();
		pData->nType = vecData["Type"].GetInt();
		pData->strImg = vecData["Img"].GetString();
		m_vecDatas.push_back(pData);
	}
	doc.Clear();
}

sBulletDt* CBulletDtMgr::getDataByID(int nID)
{
	for (sBulletDt* pData : m_vecDatas)
	{
		if (nID == pData->nRoleID)
		{
			return pData;
		}
	}
	return nullptr;
}