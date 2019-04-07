#ifndef __STRUCTDATA_H__
#define __STRUCTDATA_H__
#include"cocos2d.h"
#include<vector>
#include<string>
USING_NS_CC;
using namespace std;
 
//资源数据
struct sResDt
{
	sResDt()
	{
		vecPngs.clear();
		vecPlists.clear();
	}
	vector<string>vecPngs;
	vector<string>vecPlists;
	void LoadFile(char* pFileName);
};

//关卡数据
struct sLevelDt
{
	sLevelDt()
	{
		nLevel = 0;
		/*memset(nNumberCount, 0, sizeof(nNumberCount));*/
		m_pNumberCount.clear();
	}
	int nLevel;
	/*int nNumberCount[4];*/
	vector<int>m_pNumberCount;
	string m_pMapImage;
	int nTotalTime;
};

class CLevelDtMgr
{
public:
	CLevelDtMgr();
	~CLevelDtMgr();
	void LoadFile(char* pFileName);
	sLevelDt* getDataByLevel(int nLevel);
	sLevelDt* getCurLevel();
	void setLevel(int nLevel)
	{
		m_nLevel = nLevel;
	}

private:
	vector<sLevelDt*>m_vecDatas;
	int m_nLevel;
};

/*---------------------------------------------*/
//僵尸数据
struct sZombieDt
{
	sZombieDt()
	{

	}
	int nID;
	int nHP;
	int nACK;
	string  strImg;
};

class CZombieDtMgr
{
public:
	CZombieDtMgr();
	~CZombieDtMgr();
	void LoadFile(char* pFileName);
	sZombieDt* getDataByID(int nID);
private:
	vector<sZombieDt*>m_vecDatas;
};



/*-----------------------------------*/
//植物数据
struct sPlantDt
{
	sPlantDt()
	{

	}
	int nID;
	int nHP;
	int nACK;
	int nScore;
	string strImg;
};

class CPlantDtMgr
{
public:
	CPlantDtMgr();
	~CPlantDtMgr();
	void LoadFile(char* pFileName);
	sPlantDt* getDataByID(int nID);
private:
	vector<sPlantDt*>m_vecDatas;
};

/*---------------------------------*/
struct sPlantAnimDt
{
	sPlantAnimDt()
	{

	}
	int nID;
	vector<string>vecstrImg;
};

class CPlantAnimDtMgr
{
public:
	CPlantAnimDtMgr();
	~CPlantAnimDtMgr();
	void LoadFile(char* pFileName);
	sPlantAnimDt* getDataByID(int nID);
private:
	vector<sPlantAnimDt*>m_vecDatas;
};

/*-----------------------------------------*/
//卡片数据
struct sCardDt
{
	sCardDt()
	{

	}
	int nCardID;
	int nPlantID;
	int nScore;
	string strImg;
};

class CCardDtMgr
{
public:
	CCardDtMgr();
	~CCardDtMgr();
	void LoadFile(char* pFileName);
	sCardDt* getDataByID(int nID);
private:
	vector<sCardDt*>m_vecDatas;
};
/*------------------------------------------*/
//子弹数据
struct sBulletDt
{
	sBulletDt()
	{

	}
	int nRoleID;
	int nACK;
	int nType;
	string strImg;
};

class CBulletDtMgr
{
public:
	CBulletDtMgr();
	~CBulletDtMgr();
	void LoadFile(char* pFileName);
	sBulletDt* getDataByID(int nID);
private:
	vector<sBulletDt*>m_vecDatas;
};

#endif // !__STRUCTDATA_H__
