#ifndef __PLANTMGR_H__
#define __PLANTMGR_H__

#include"Plant.h"
#include"cocos2d.h"
USING_NS_CC;
class CPlantMgr : public Layer
{
public:
	CPlantMgr();
	~CPlantMgr();
	virtual bool init();
	bool addPlant(int nID,Vec2 clickPos);
	void addAnimation(int nID);
	
	CREATE_FUNC(CPlantMgr);
	
private:
	int m_nAnimID;
	Sprite* m_pPlantSp;
};


#endif // !__PLANTMGR_H__
