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
	//�����ճ���
	Scene* pScene = Scene::create();
	//����Logo��
	CGameLogo* pGameLogo = CGameLogo::create();
	//����ص�����
	pScene->addChild(pGameLogo);
	return pScene;
}

bool CGameLogo::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//ȡ��Դ��
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//�����Ļ�ߴ�
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//��������֡����ͼƬ
	Sprite* pSprite = Sprite::create("bg1.jpg");
	//����λ��
	pSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	//��СͼƬ
	pSprite->setScale(0.5, 0.6);
	//���ص�����
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
