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
	//�����ճ���
	Scene* pScene = Scene::create();
	//����Loading��
	CGameLoading* pGameLoading = CGameLoading::create();
	//����ص�����
	pScene->addChild(pGameLoading);
	return pScene;
}

bool CGameLoading::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//��ȡԴ������
	origin = Director::getInstance()->getVisibleOrigin();
	//��ȡ��Ļ��С
	visibleSize = Director::getInstance()->getVisibleSize();
	//��������
	Sprite* pSprite = Sprite::create("bg2.jpg");
	//����λ��
	pSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	//��С
	pSprite->setScale(0.5, 0.55);
	//�ҵ�����
	this->addChild(pSprite);

	//������Դ������
	m_vecPng = CDataMgr::getInstance()->getResDt()->vecPngs;
	m_vecPlist = CDataMgr::getInstance()->getResDt()->vecPlists;
	//��Դ����
	m_nTotalCount = m_vecPng.size() + m_vecPlist.size();
	//������
	//��������������
	Sprite* pProgressBg = Sprite::create("Image/Items/Welcome/fp_floor.png");
	pProgressBg->setPosition(origin.x + visibleSize.width / 2+5, origin.y + visibleSize.height / 8);
	//����
	pProgressBg->setScaleX(1.1);
	this->addChild(pProgressBg);
	//����������
	m_pProSprite = Sprite::create("Image/Items/Welcome/fp_grass.png");
	m_pProgress = ProgressTimer::create(m_pProSprite);
	m_pProgress->setPosition(origin.x + visibleSize.width / 2-5, origin.y + visibleSize.height / 8+18);
	this->addChild(m_pProgress);
	
	//��������
	m_pTag = Sprite::create("Image/Items/Welcome/fp_tag.png");
	RotateBy* pRotateBy = RotateBy::create(2.0f,360);
	m_pTag->runAction(RepeatForever::create(pRotateBy));
	this->addChild(m_pTag);
	m_pTag->setPosition(origin.x + visibleSize.width / 3+20, origin.y + visibleSize.height / 8 + 37);
	//���ý���������
	m_pProgress->setType(ProgressTimer::Type::BAR);
	//������ʼλ��
	m_pProgress->setMidpoint(Vec2(0, 0));
	//���ñ任�����������
	m_pProgress->setBarChangeRate(Vec2(1, 0));
	//�ٷֱ�
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
	//ÿ֡����һ��
	//��ȡpng
	//ȡ��������
	if (m_nCurCount < m_vecPng.size())//�����ǰ��ȡ����С��png�����ĸ���
	{//��ȡpng
		TextureCache* pCache = Director::getInstance()->getTextureCache();
		//��pngͼƬ��ȡ����������
		pCache->addImage(m_vecPng[m_nIndex]);
		//ÿ�ζ�ȡ��ϣ�������1
		m_nIndex++;
		m_nCurCount++;
		if (m_nIndex >= m_vecPng.size())
		{
			m_nIndex = 0;
		}
	}
	else//��ȡplist
	{
		if (m_nCurCount < m_nTotalCount)
		{
			SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
			pCache->addSpriteFramesWithFile(m_vecPlist[m_nIndex]);
			m_nIndex++;
			m_nCurCount++;
		}
	}

	//����ٷֱ�
	float fPercent = (float)m_nCurCount / m_nTotalCount;
	float fP = fPercent * 100;
	m_pProgress->setPercentage(fP);
	//���ñ�ǩ���ַ���
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
