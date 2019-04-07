#include"GameLogo1.h"
#include"GameLoading.h"
CGameLogo::CGameLogo()
{
}

CGameLogo::~CGameLogo()
{
}

Scene * CGameLogo::createScene()
{
	//创建空场景
	Scene* pScene = Scene::create();
	//创建Logo层
	CGameLogo* pGameLogo = CGameLogo::create();
	//层挂载到场景
	pScene->addChild(pGameLogo);
	return pScene;
}

bool CGameLogo::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//取得源点
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//获得屏幕尺寸
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//创建精灵帧承载图片
	Sprite* pSprite = Sprite::create("bg1.jpg");
	//设置位置
	pSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	//缩小图片
	pSprite->setScale(0.5, 0.6);
	//挂载到层上
	this->addChild(pSprite);
	this->scheduleOnce(CC_CALLBACK_0(CGameLogo::changeScene, this), 2.0f, "call");
	return true;
}

void CGameLogo::CGameLogoCallBack(Ref * pSender)
{
}

void CGameLogo::changeScene()
{
	CCLOG("ChangeScene");
	TransitionCrossFade* pTran = TransitionCrossFade::create(2.0f, CGameLoading::createScene());
	Director::getInstance()->replaceScene(pTran);
}
