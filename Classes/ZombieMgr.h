#ifndef __ZOMBIEMGR_H__
#define __ZOMBIEMGR_H__
#include"cocos2d.h"
#include"Zombie.h"
#include"DataMgr.h"

USING_NS_CC;
class CZombieMgr : public Layer
{
public:
	CZombieMgr();
	~CZombieMgr();
	virtual bool init();
	void addZombie();
	
	CREATE_FUNC(CZombieMgr);
private:
	vector<int>m_vecZombieCount;
	
	int m_nIndex;
	int m_naddCount;
	int m_nLevel;
	Vec2 origin;
	Size visibleSize;
	int m_nTime;
};

#endif // !__ZOMBIEMGR_H__

