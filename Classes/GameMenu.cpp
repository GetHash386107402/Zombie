#include"GameMenu.h"
#include"DataMgr.h"
#include"GameMain.h"
CGameMenu::CGameMenu()
{
}

CGameMenu::~CGameMenu()
{
}

Scene * CGameMenu::createScene()
{
	//创建菜单空场景
	Scene* pScene = Scene::create();
	//创建层
	CGameMenu* pGameMenu = CGameMenu::create();
	//挂载到场景
	pScene->addChild(pGameMenu);
	return pScene;
}

bool CGameMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}
	m_origin = Director::getInstance()->getVisibleOrigin();
	m_visibleSize = Director::getInstance()->getVisibleSize();
	//获取精灵帧缓存
	SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
	//创建精灵承载背景图片
	Sprite* pBackground = Sprite::createWithSpriteFrameName("main_background.png");
	//设置位置
	pBackground->setPosition(m_origin.x + m_visibleSize.width / 2, m_visibleSize.height/ 2);
	//放大
	pBackground->setScale(1.1, 1.1);
	//挂载精灵到菜单层                    
	this->addChild(pBackground);


	//冒险按钮
	m_pBtnAdventure = MenuItemImage::create("", "", CC_CALLBACK_1(CGameMenu::CGameMenuCallBack, this));
	//获得需要的精灵帧
	SpriteFrame* pFrame = pCache->getSpriteFrameByName("select10.png");
	//设置正常图片
	m_pBtnAdventure->setNormalSpriteFrame(pFrame);
	//设置选中图片
	m_pBtnAdventure->setSelectedSpriteFrame(pCache->getSpriteFrameByName("select11.png"));
	//设置位置
	m_pBtnAdventure->setPosition(m_origin.x + m_visibleSize.width/8*5.7, m_origin.y + m_visibleSize.height/8*6.5);
	m_pBtnAdventure->setScale(2, 2);
	m_pBtnAdventure->setTag(1);

	//迷你按钮
	m_pBtnMini = MenuItemImage::create("", "", CC_CALLBACK_1(CGameMenu::CGameMenuCallBack, this));
	//设置正常图片
	m_pBtnMini->setNormalSpriteFrame(pCache->getSpriteFrameByName("select20.png"));
	//设置选中图片
	m_pBtnMini->setSelectedSpriteFrame(pCache->getSpriteFrameByName("select21.png"));
	//设置位置
	m_pBtnMini->setPosition(m_origin.x + m_visibleSize.width / 8 * 5.6, m_origin.y + m_visibleSize.height / 8 * 5.2);
	m_pBtnMini->setScale(1.9, 1.9);
	m_pBtnMini->setTag(2);

	//益智按钮
	m_pBtnPuzzle = MenuItemImage::create("", "", CC_CALLBACK_1(CGameMenu::CGameMenuCallBack, this));
	//设置正常图片
	m_pBtnPuzzle->setNormalSpriteFrame(pCache->getSpriteFrameByName("select30.png"));
	//设置选中图片
	m_pBtnPuzzle->setSelectedSpriteFrame(pCache->getSpriteFrameByName("select31.png"));
	//设置位置
	m_pBtnPuzzle->setPosition(m_origin.x + m_visibleSize.width / 8 * 5.5, m_origin.y + m_visibleSize.height / 8 * 4);
	m_pBtnPuzzle->setScale(1.8, 1.8);
	

	//生存按钮
	m_pBtnSurvival = MenuItemImage::create("", "", CC_CALLBACK_1(CGameMenu::CGameMenuCallBack, this));
	//设置正常图片
	m_pBtnSurvival->setNormalSpriteFrame(pCache->getSpriteFrameByName("select40.png"));
	//设置选中图片
	m_pBtnSurvival->setSelectedSpriteFrame(pCache->getSpriteFrameByName("select41.png"));
	//设置位置
	m_pBtnSurvival->setPosition(m_origin.x + m_visibleSize.width / 8 * 5.4, m_origin.y + m_visibleSize.height / 8 * 3);
	m_pBtnSurvival->setScale(1.75, 1.75);
	

	//菜单头
	Sprite* pTitle = Sprite::createWithSpriteFrame( pCache->getSpriteFrameByName("PlayerScreen.png"));
	this->addChild(pTitle);
	pTitle->setPosition(m_origin.x + m_visibleSize.width / 8*1.7, m_origin.y + m_visibleSize.height /8*7.2);
	
	
	//按钮
	m_pBtnUser = MenuItemImage::create("", "", CC_CALLBACK_1(CGameMenu::CGameMenuCallBack, this));
	//设置正常图片
	m_pBtnUser->setNormalSpriteFrame(pCache->getSpriteFrameByName("changePlayer1.png"));
	//设置选中图片
	m_pBtnUser->setSelectedSpriteFrame(pCache->getSpriteFrameByName("changePlayer2.png"));
	//设置位置
	m_pBtnUser->setPosition(m_origin.x + m_visibleSize.width / 8 * 1.7, m_origin.y + m_visibleSize.height / 8 * 5.95);
	
	
	//菜单PS
	Sprite* pPS = Sprite::createWithSpriteFrame(pCache->getSpriteFrameByName("ps.png"));
	this->addChild(pPS);
	pPS->setPosition(m_origin.x + m_visibleSize.width / 8 * 1.7, m_origin.y + m_visibleSize.height / 8 * 5.21);

	//创建菜单
	Menu* pMenu = Menu::create(m_pBtnAdventure, m_pBtnMini, m_pBtnPuzzle, m_pBtnSurvival, m_pBtnUser,NULL);
	pMenu->setPosition(Vec2::ZERO);
	this->addChild(pMenu);
	
	return true;
}

void CGameMenu::CGameMenuCallBack(Ref * pSender)
{
	Node* pNode = static_cast<Node*>(pSender);
	//设置关卡，哪一关，选关   getCurLevel(第几关)
	CDataMgr::getInstance()->getLevelDtMgr()->setLevel(pNode->getTag());
	/*CGameMain::getInstance()->destroyInstance();*/
	TransitionCrossFade* pTran = TransitionCrossFade::create(1.0f, CGameMain::createScene());
	Director::getInstance()->replaceScene(pTran);
}
