#ifndef _GAMELOGO1_H__
#define _GAMELOGO1_H__
#include "cocos2d.h"
USING_NS_CC;
class CGameLogo : public Layer
{
public:
	CGameLogo();
	~CGameLogo();
	//创建场景
	static Scene* createScene();
	//初始化函数
	virtual bool init();
	//回调函数
	void CGameLogoCallBack(Ref* pSender);
	//切换场景
	void changeScene();
	CREATE_FUNC(CGameLogo);
private:

};

#endif // !_GAMELOGO1_H__

