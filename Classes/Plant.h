#ifndef __PLANT_H__
#define __PLANT_H__
#include"cocos2d.h"
#include"StructData.h"
#include"AnimateMgr.h"
USING_NS_CC;
enum
{
	E_STATE_NORMALL,
	E_STATE_CRACKED1,
	E_STATE_CRACKED2
};
class CPlant : public Sprite
{
public:
	CPlant();
	~CPlant();
	bool initWithData(sPlantDt* pData);
	static CPlant* createWithData(sPlantDt* pData);
	void fire(int nID);
	void createSunShine();
	Node* findZombie();
	void addAnimation(int nID);
	int damage(int nDamage);
	bool bDeath();
	void changePlantState(int nState);
	CC_SYNTHESIZE(int, m_nHP, HP);
	CC_SYNTHESIZE(int, m_nID, ID);
	CC_SYNTHESIZE(int, m_nACK, ACK);
	CC_SYNTHESIZE(int, m_nScore, Score);
	CC_SYNTHESIZE(int, m_nState, State);
	CC_SYNTHESIZE(int, m_baddPlant, baddPlant);
	/*CC_SYNTHESIZE(string, m_strImg,Img);*/
private:
	Sprite* m_pSprite;
	Animate* m_pAnimatePlant;
	Animate* m_pAnimateCracked1;
	Animate* m_pAnimateCracked2;
	vector<string>m_vecAnimDt;
	CAnimateMgr* m_pAnimateMgr;
};


#endif // !__PLANT_H__

