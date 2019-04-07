#ifndef __GAMEMAIN_H__
#define __GAMEMAIN_H__
#include"cocos2d.h"
#include"ZombieMgr.h"
#include"PlantMgr.h"
#include"SunShineMgr.h"
#include"CardMgr.h"
#include"BulletMgr.h"
#include"Effect.h"
#include"MainMenu.h"

USING_NS_CC;
class CGameMain : public Layer 
{
public:
	CGameMain();
	~CGameMain();
	static Scene* createScene();
	static CGameMain* getInstance();
	void destroyInstance();
	virtual bool init();
	void CGaneMainCallBack(Ref* pSender);
	virtual void update(float delta);
	void Collision(float delta);
	void createFallSunShine();
	/*void GameOver();*/
	//像素坐标转换格子坐标函数
	Vec2 getTiledByPos(const Vec2& pos);
	Vec2 getCenterPosByTiled(const Vec2& tiledPos);
	void addTouch();
	bool changeAttackState();
	bool onTouchBegan(Touch* pTouch, Event* pEvent);
	void onTouchMoved(Touch* pTouch, Event* pEvent);
	void onTouchEnded(Touch* pTouch, Event* pEvent);
	void initPos();
	CMainMenu* getMainMenu()
	{
		return m_pMainMenu;
	}
	CCardMgr* getCardMgr()
	{
		return m_pCardMgr;
	}
	CBulletMgr* getBulletMgr()
	{
		return m_pBulletMgr;
	}
	CPlantMgr* getPlantMgr()
	{
		return m_pPlantMgr;
	}
	CZombieMgr* getZombieMgr()
	{
		return m_pZombieMgr;
	}
	CSunShineMgr* getSunShineMgr()
	{
		return m_pSunShineMgr;
	}
	vector<Vec2> getinitPos()
	{
		return m_vecinitPos;
	}
	vector<Vec2> getendPos()
	{
		return m_vecendPos;
	}
	CC_SYNTHESIZE(int, m_nCardScore, CardScore);
	CREATE_FUNC(CGameMain);
private:
	static CGameMain* m_spInstance;
	Vec2 m_origin;
	Size m_visibleSize;
	CZombieMgr* m_pZombieMgr;
	CPlantMgr* m_pPlantMgr;
	CBulletMgr* m_pBulletMgr;
	CSunShineMgr* m_pSunShineMgr;
	CEffect* m_pEffect;
	CMainMenu* m_pMainMenu;
	CCardMgr* m_pCardMgr;
	TMXTiledMap* m_pTileMap;
	TMXLayer* m_pPathLayer;
	Vec2 m_movePos;
	string m_strImg;
	bool m_bMoved;
	int m_nPlantID;
	bool m_bAttack;
	float m_fElapsed;
	vector<Vec2>m_vecinitPos;
	vector<Vec2>m_vecendPos;
};
#endif // !__GAMEMAIN_H__

