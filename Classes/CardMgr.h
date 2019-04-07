#ifndef __CARDMGR_H__
#define __CARDMGR_H__
#include"cocos2d.h"
#include"PlantCard.h"
USING_NS_CC;
class CCardMgr : public Layer
{
public:
	CCardMgr();
	~CCardMgr();
	virtual bool init();
	void createCard();
	vector<CPlantCard*> getVec()
	{
		return m_vecPlantCard;
	}
	CPlantCard* getVecData(int nIndex)
	{
		return m_vecPlantCard[nIndex];
	}
	Sprite* getSprite()
	{
		return m_pDragSp;
	}
	CREATE_FUNC(CCardMgr);
private:
	vector<CPlantCard*>m_vecPlantCard;
	int m_nID;
	Vec2 m_origin;
	Size m_visibleSize;
	Sprite* m_pCardSprite;
	Sprite* m_pDragSp;
};
#endif // !__CARDMGR_H__

