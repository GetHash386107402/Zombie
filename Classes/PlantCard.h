#ifndef __PLANTCARD_H__
#define __PLANTCARD_H__
#include"cocos2d.h"
#include"DataMgr.h"
USING_NS_CC;
class CPlantCard : public Sprite
{
public:
	CPlantCard();
	~CPlantCard();
	bool initWithData(sCardDt* pData);
	static CPlantCard* createWithData(sCardDt* pData);
	Rect getSpriteBoundBox() { return m_pSprite->getBoundingBox(); }
	//bool getifContain(Vec2 pos);
	CC_SYNTHESIZE(int, m_nCardID, CardID);
	CC_SYNTHESIZE(int, m_nPlantID, PlantID);
	CC_SYNTHESIZE(int, m_nScore, Score);
	CC_SYNTHESIZE(string, m_nstrImg, strImg);
	CC_SYNTHESIZE(int, m_nWidth, Width);
	CC_SYNTHESIZE(Sprite*, m_pSprite, CadSprite);
private:
	 
};


#endif // !__PLANTCARD_H__

