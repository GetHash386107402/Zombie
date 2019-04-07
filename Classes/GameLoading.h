#ifndef __GAMELOADING_H__
#define __GAMELOADING_H__
#include"cocos2d.h"
#include"DataMgr.h"
#include"GameMenu.h"
USING_NS_CC;
class CGameLoading : public Layer
{
public:
	CGameLoading();
	~CGameLoading();
	//创建场景函数
	static Scene* createScene();
	//初始化函数
	virtual bool init();
	//数据更新
	virtual void update(float delta);
	//回调函数
	void CGameLoadingCallBack(Ref* pSender);
	//切换场景
	void changeScene(float fDela);
	CREATE_FUNC(CGameLoading);
private:
	int m_nIndex;//当前读取容器里面第几个资源
	int m_nTotalCount;//资源总数
	int m_nCurCount;//目前读取了多少个资源
	vector<string> m_vecPng;
	vector<string> m_vecPlist;
	ProgressTimer* m_pProgress;
	Label* m_pLabel;
	Sprite* m_pTag;
	Vec2 origin;
	Size visibleSize;
	Sprite* m_pProSprite;
};


#endif // !__GAMELOADING_H__


