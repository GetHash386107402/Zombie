#ifndef __MAINMENU_H__
#define __MAINMENU_H__
#include"cocos2d.h"

USING_NS_CC;
class CMainMenu : public Layer
{
public:
	CMainMenu();
	~CMainMenu();
	static Scene* createScene();
	virtual bool init();
	void Timing();
	virtual void update(float delta);
	int getTotalTime()
	{
		return m_nTotalTime;
	}
	CC_SYNTHESIZE(int, m_nSunShineCount, SunShineCount);
	CREATE_FUNC(CMainMenu);
private:
	Vec2 m_origin;
	Size m_visibleSize;
	Sprite* m_pProSprite0;
	int m_nTime;
	int m_nTotalTime;
	ProgressTimer* m_pTimer;
	Label* m_pLabel;
	
};


#endif // !__MAINMENU_H__
