#ifndef __GAMEMENU_H__
#define __GAMEMENU_H__
#include"cocos2d.h"

USING_NS_CC;
class CGameMenu : public Layer
{
public:
	CGameMenu();
	~CGameMenu();
	static Scene* createScene();
	virtual bool init();
	void CGameMenuCallBack(Ref* pSender);
	CREATE_FUNC(CGameMenu);
private:
	Vec2 m_origin;
	Size m_visibleSize;
	MenuItemImage* m_pBtnAdventure;
	MenuItemImage* m_pBtnSurvival;
	MenuItemImage* m_pBtnPuzzle;
	MenuItemImage* m_pBtnMini;
	MenuItemImage* m_pBtnUser;
};


#endif // !__GAMEMENU_H__

