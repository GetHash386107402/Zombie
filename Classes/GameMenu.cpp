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
	//�����˵��ճ���
	Scene* pScene = Scene::create();
	//������
	CGameMenu* pGameMenu = CGameMenu::create();
	//���ص�����
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
	//��ȡ����֡����
	SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
	//����������ر���ͼƬ
	Sprite* pBackground = Sprite::createWithSpriteFrameName("main_background.png");
	//����λ��
	pBackground->setPosition(m_origin.x + m_visibleSize.width / 2, m_visibleSize.height/ 2);
	//�Ŵ�
	pBackground->setScale(1.1, 1.1);
	//���ؾ��鵽�˵���                    
	this->addChild(pBackground);


	//ð�հ�ť
	m_pBtnAdventure = MenuItemImage::create("", "", CC_CALLBACK_1(CGameMenu::CGameMenuCallBack, this));
	//�����Ҫ�ľ���֡
	SpriteFrame* pFrame = pCache->getSpriteFrameByName("select10.png");
	//��������ͼƬ
	m_pBtnAdventure->setNormalSpriteFrame(pFrame);
	//����ѡ��ͼƬ
	m_pBtnAdventure->setSelectedSpriteFrame(pCache->getSpriteFrameByName("select11.png"));
	//����λ��
	m_pBtnAdventure->setPosition(m_origin.x + m_visibleSize.width/8*5.7, m_origin.y + m_visibleSize.height/8*6.5);
	m_pBtnAdventure->setScale(2, 2);
	m_pBtnAdventure->setTag(1);

	//���㰴ť
	m_pBtnMini = MenuItemImage::create("", "", CC_CALLBACK_1(CGameMenu::CGameMenuCallBack, this));
	//��������ͼƬ
	m_pBtnMini->setNormalSpriteFrame(pCache->getSpriteFrameByName("select20.png"));
	//����ѡ��ͼƬ
	m_pBtnMini->setSelectedSpriteFrame(pCache->getSpriteFrameByName("select21.png"));
	//����λ��
	m_pBtnMini->setPosition(m_origin.x + m_visibleSize.width / 8 * 5.6, m_origin.y + m_visibleSize.height / 8 * 5.2);
	m_pBtnMini->setScale(1.9, 1.9);
	m_pBtnMini->setTag(2);

	//���ǰ�ť
	m_pBtnPuzzle = MenuItemImage::create("", "", CC_CALLBACK_1(CGameMenu::CGameMenuCallBack, this));
	//��������ͼƬ
	m_pBtnPuzzle->setNormalSpriteFrame(pCache->getSpriteFrameByName("select30.png"));
	//����ѡ��ͼƬ
	m_pBtnPuzzle->setSelectedSpriteFrame(pCache->getSpriteFrameByName("select31.png"));
	//����λ��
	m_pBtnPuzzle->setPosition(m_origin.x + m_visibleSize.width / 8 * 5.5, m_origin.y + m_visibleSize.height / 8 * 4);
	m_pBtnPuzzle->setScale(1.8, 1.8);
	

	//���水ť
	m_pBtnSurvival = MenuItemImage::create("", "", CC_CALLBACK_1(CGameMenu::CGameMenuCallBack, this));
	//��������ͼƬ
	m_pBtnSurvival->setNormalSpriteFrame(pCache->getSpriteFrameByName("select40.png"));
	//����ѡ��ͼƬ
	m_pBtnSurvival->setSelectedSpriteFrame(pCache->getSpriteFrameByName("select41.png"));
	//����λ��
	m_pBtnSurvival->setPosition(m_origin.x + m_visibleSize.width / 8 * 5.4, m_origin.y + m_visibleSize.height / 8 * 3);
	m_pBtnSurvival->setScale(1.75, 1.75);
	

	//�˵�ͷ
	Sprite* pTitle = Sprite::createWithSpriteFrame( pCache->getSpriteFrameByName("PlayerScreen.png"));
	this->addChild(pTitle);
	pTitle->setPosition(m_origin.x + m_visibleSize.width / 8*1.7, m_origin.y + m_visibleSize.height /8*7.2);
	
	
	//��ť
	m_pBtnUser = MenuItemImage::create("", "", CC_CALLBACK_1(CGameMenu::CGameMenuCallBack, this));
	//��������ͼƬ
	m_pBtnUser->setNormalSpriteFrame(pCache->getSpriteFrameByName("changePlayer1.png"));
	//����ѡ��ͼƬ
	m_pBtnUser->setSelectedSpriteFrame(pCache->getSpriteFrameByName("changePlayer2.png"));
	//����λ��
	m_pBtnUser->setPosition(m_origin.x + m_visibleSize.width / 8 * 1.7, m_origin.y + m_visibleSize.height / 8 * 5.95);
	
	
	//�˵�PS
	Sprite* pPS = Sprite::createWithSpriteFrame(pCache->getSpriteFrameByName("ps.png"));
	this->addChild(pPS);
	pPS->setPosition(m_origin.x + m_visibleSize.width / 8 * 1.7, m_origin.y + m_visibleSize.height / 8 * 5.21);

	//�����˵�
	Menu* pMenu = Menu::create(m_pBtnAdventure, m_pBtnMini, m_pBtnPuzzle, m_pBtnSurvival, m_pBtnUser,NULL);
	pMenu->setPosition(Vec2::ZERO);
	this->addChild(pMenu);
	
	return true;
}

void CGameMenu::CGameMenuCallBack(Ref * pSender)
{
	Node* pNode = static_cast<Node*>(pSender);
	//���ùؿ�����һ�أ�ѡ��   getCurLevel(�ڼ���)
	CDataMgr::getInstance()->getLevelDtMgr()->setLevel(pNode->getTag());
	/*CGameMain::getInstance()->destroyInstance();*/
	TransitionCrossFade* pTran = TransitionCrossFade::create(1.0f, CGameMain::createScene());
	Director::getInstance()->replaceScene(pTran);
}
