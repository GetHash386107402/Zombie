#include"MainMenu.h"
CMainMenu::CMainMenu()
{
	m_nTotalTime = 60;
	m_nTime = 0;
	m_nSunShineCount = 500;
}

CMainMenu::~CMainMenu()
{
}

Scene * CMainMenu::createScene()
{
	Scene* pScene = Scene::create();
	CMainMenu* pMainMenu = CMainMenu::create();
	pScene->addChild(pMainMenu);
	return pScene;
}

bool CMainMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}
	m_origin = Director::getInstance()->getVisibleOrigin();
	m_visibleSize = Director::getInstance()->getVisibleSize();
	//����������ر���ͼƬ
	Sprite* pSeedChooser = Sprite::create("Image/Items/Menu.atlas/SeedChooser_Background.png");
	pSeedChooser->setAnchorPoint(Vec2::ZERO);
	//����λ��
	pSeedChooser->setPosition(m_origin.x + m_visibleSize.width / 8*1.6, m_origin.y+m_visibleSize.height/8*7.2);
	//��4
	pSeedChooser->setScale(1.3, 0.1);
	//���ؾ��鵽�˵���                    
	this->addChild(pSeedChooser);

	//����������ر���ͼƬ
	Sprite* pSunBack = Sprite::create("Image/Items/Menu.atlas/SunBack.png");
	pSunBack->setAnchorPoint(Vec2::ZERO);
	//����λ��
	pSunBack->setPosition(m_origin.x , m_origin.y + m_visibleSize.height / 8 * 7.2);
	//��4
	pSunBack->setScale(1.5, 2.2);
	//���ؾ��鵽�˵���                    
	this->addChild(pSunBack);


	//������
	Sprite* pProTitle = Sprite::create("Image/Items/Menu.atlas/FlagMeterLevelProgress.png");
	pProTitle->setPosition(m_origin.x + m_visibleSize.width / 8 * 7, m_origin.y + m_visibleSize.height / 9);
	//����
	pProTitle->setScaleX(1.1);
	this->addChild(pProTitle);
	//��������������
	Sprite* pProgressBg = Sprite::create("Image/Items/Menu.atlas/FlagMeterEmpty.png");
	pProgressBg->setPosition(m_origin.x + m_visibleSize.width / 8*7, m_origin.y + m_visibleSize.height / 12);
	//����
	pProgressBg->setScaleX(1.1);
	this->addChild(pProgressBg);
	
	//����������
	m_pProSprite0 = Sprite::create("Image/Items/Menu.atlas/FlagMeterFull.png");
	m_pTimer = ProgressTimer::create(m_pProSprite0);
	m_pTimer->setPosition(m_origin.x + m_visibleSize.width / 8 * 7, m_origin.y + m_visibleSize.height / 12);
	//���ý���������
	m_pTimer->setType(ProgressTimer::Type::BAR);
	//������ʼλ��
	m_pTimer->setMidpoint(Vec2(1, 0));
	//���ñ任�����������
	m_pTimer->setBarChangeRate(Vec2(1, 0));
	m_pTimer->setPercentage(0);
	m_pLabel = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 24);
	// position the label on the center of the screen
	m_pLabel->setPosition(m_origin.x+ m_visibleSize.width / 10, m_origin.y + m_visibleSize.height / 8 * 7.6);
	m_pLabel->setColor(Color3B::BLACK);
	this->addChild(m_pLabel);
	this->addChild(m_pTimer);
	this->schedule(CC_CALLBACK_0(CMainMenu::Timing, this), 1.0f, "Timing");
	this->scheduleUpdate();
	return true;
}

void CMainMenu::Timing()
{
		m_nTime++;
		if (m_nTime >= m_nTotalTime)
		{
			this->unschedule("Timing");
		}

}

void CMainMenu::update(float delta)
{
	float fPercent = (float)m_nTime / m_nTotalTime;
	float fP = fPercent * 100;
	m_pTimer->setPercentage(fP);
	m_pLabel->setString(StringUtils::format("Count:%d", m_nSunShineCount));
}
