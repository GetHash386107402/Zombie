#include"GameLoading.h"
CGameLoading::CGameLoading()
:m_nCurCount(0)
, m_nTotalCount(0)
, m_nIndex(0)
{
}

CGameLoading::~CGameLoading()
{
}

Scene * CGameLoading::createScene()
{
	//创建空场景
	Scene* pScene = Scene::create();
	//创建Loading层
	CGameLoading* pGameLoading = CGameLoading::create();
	//层挂载到场景
	pScene->addChild(pGameLoading);
	return pScene;
}

bool CGameLoading::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//获取源点坐标
	origin = Director::getInstance()->getVisibleOrigin();
	//获取屏幕大小
	visibleSize = Director::getInstance()->getVisibleSize();
	//创建精灵
	Sprite* pSprite = Sprite::create("bg2.jpg");
	//设置位置
	pSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	//缩小
	pSprite->setScale(0.5, 0.55);
	//挂到层上
	this->addChild(pSprite);

	//两种资源的容器
	m_vecPng = CDataMgr::getInstance()->getResDt()->vecPngs;
	m_vecPlist = CDataMgr::getInstance()->getResDt()->vecPlists;
	//资源总数
	m_nTotalCount = m_vecPng.size() + m_vecPlist.size();
	//进度条
	//创建进度条背景
	Sprite* pProgressBg = Sprite::create("Image/Items/Welcome/fp_floor.png");
	pProgressBg->setPosition(origin.x + visibleSize.width / 2+5, origin.y + visibleSize.height / 8);
	//缩放
	pProgressBg->setScaleX(1.1);
	this->addChild(pProgressBg);
	//创建进度条
	m_pProSprite = Sprite::create("Image/Items/Welcome/fp_grass.png");
	m_pProgress = ProgressTimer::create(m_pProSprite);
	m_pProgress->setPosition(origin.x + visibleSize.width / 2-5, origin.y + visibleSize.height / 8+18);
	this->addChild(m_pProgress);
	
	//创建精灵
	m_pTag = Sprite::create("Image/Items/Welcome/fp_tag.png");
	RotateBy* pRotateBy = RotateBy::create(2.0f,360);
	m_pTag->runAction(RepeatForever::create(pRotateBy));
	this->addChild(m_pTag);
	m_pTag->setPosition(origin.x + visibleSize.width / 3+20, origin.y + visibleSize.height / 8 + 37);
	//设置进度条类型
	m_pProgress->setType(ProgressTimer::Type::BAR);
	//设置起始位置
	m_pProgress->setMidpoint(Vec2(0, 0));
	//设置变换后进度条比例
	m_pProgress->setBarChangeRate(Vec2(1, 0));
	//百分比
	m_pProgress->setPercentage(0);
	m_pLabel = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 24);
	// position the label on the center of the screen
	m_pLabel->setPosition(origin.x + visibleSize.width / 2 , origin.y + visibleSize.height / 8 );
	// add the label as a child to this layer
	this->addChild(m_pLabel, 1);
	this->scheduleUpdate();
	return true;
}

void CGameLoading::update(float delta)
{
	//每帧加载一张
	//读取png
	//取得文理缓存
	if (m_nCurCount < m_vecPng.size())//如果当前读取总数小于png容器的个数
	{//读取png
		TextureCache* pCache = Director::getInstance()->getTextureCache();
		//把png图片读取到缓存里面
		pCache->addImage(m_vecPng[m_nIndex]);
		//每次读取完毕，索引加1
		m_nIndex++;
		m_nCurCount++;
		if (m_nIndex >= m_vecPng.size())
		{
			m_nIndex = 0;
		}
	}
	else//读取plist
	{
		if (m_nCurCount < m_nTotalCount)
		{
			SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
			pCache->addSpriteFramesWithFile(m_vecPlist[m_nIndex]);
			m_nIndex++;
			m_nCurCount++;
		}
	}

	//计算百分比
	float fPercent = (float)m_nCurCount / m_nTotalCount;
	float fP = fPercent * 100;
	m_pProgress->setPercentage(fP);
	//设置标签的字符串
	m_pLabel->setString(StringUtils::format("Loading:%.2f%%", fP));
	if (100 <= fP)
	{
		this->unscheduleUpdate();
		this->changeScene(fP);
	}
	m_pTag->setPosition(origin.x + visibleSize.width / 3 + 20+ fPercent* m_pProSprite->getContentSize().width\
		, origin.y + visibleSize.height / 8 + 37);
}

void CGameLoading::CGameLoadingCallBack(Ref * pSender)
{

}

void CGameLoading::changeScene(float fDela)
{
	TransitionCrossFade* pTran = TransitionCrossFade::create(2.0f, CGameMenu::createScene());
	Director::getInstance()->replaceScene(pTran);
}
