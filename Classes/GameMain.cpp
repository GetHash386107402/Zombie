#include"GameMain.h"
#include"DataMgr.h"
CGameMain* CGameMain::m_spInstance = nullptr;
CGameMain::CGameMain()
{
	/*m_nIndex = 0;*/
	m_bMoved = false;
	m_bAttack = false;
	m_fElapsed = 0;
}

CGameMain::~CGameMain()
{
}

Scene * CGameMain::createScene()
{
	//�����ճ���
	Scene* pScene = Scene::create();
	//������
	CGameMain* pGameMain = CGameMain::getInstance();
	//�Ѳ���ص�������
	pScene->addChild(pGameMain);
	return pScene;
}

bool CGameMain::init()
{
	if (!Layer::init())
	{
		return false;
	}
	m_origin = Director::getInstance()->getVisibleOrigin();
	m_visibleSize = Director::getInstance()->getVisibleSize();
	//��������
	/*Sprite* pBackGround = Sprite::create(CDataMgr::getInstance()->getLevelDtMgr()->getCurLevel()->m_pMapImage);*/
	m_pTileMap = TMXTiledMap::create(CDataMgr::getInstance()->getLevelDtMgr()->getCurLevel()->m_pMapImage);
	/*pBackGround->setAnchorPoint(Vec2::ZERO);
	pBackGround->setPosition(m_origin);
	pBackGround->setScaleY(1.1);*/
	this->addChild(m_pTileMap);
	this->initPos();
	this->addTouch();
   //���·����-10.5
	m_pPathLayer = m_pTileMap->getLayer("Path");
	//�˵���
	m_pMainMenu = CMainMenu::create();
	this->addChild(m_pMainMenu,1);

	//��ʬ�����
	m_pZombieMgr = CZombieMgr::create();
	this->addChild(m_pZombieMgr,3);

	//ֲ������
	m_pPlantMgr = CPlantMgr::create();
	this->addChild(m_pPlantMgr,3);

	//�ӵ������
	m_pBulletMgr = CBulletMgr::create();
	this->addChild(m_pBulletMgr, 3);
	//��������
	m_pSunShineMgr = CSunShineMgr::create();
	this->addChild(m_pSunShineMgr, 4);
	//��Ч��
	m_pEffect = CEffect::create();
	this->addChild(m_pEffect, 3);
	//��Ƭ�����
	m_pCardMgr = CCardMgr::create();
	this->addChild(m_pCardMgr,4);
	this->schedule(CC_CALLBACK_0(CGameMain::createFallSunShine, this), 10.f, "FallSunShine");
	this->scheduleUpdate();
	return true;
	
}

void CGameMain::CGaneMainCallBack(Ref * pSender)
{
}

void CGameMain::update(float delta)
{
	this->Collision(delta);
}

void CGameMain::Collision(float delta)
{
	Vector<Node*>VecBullet = m_pBulletMgr->getChildren();
	Vector<Node*>VecZombie = m_pZombieMgr->getChildren();
	Vector<Node*>VecPlant = m_pPlantMgr->getChildren();
	for (Node* pPlantNode : VecPlant)
	{
		CPlant* pPlant = static_cast<CPlant*>(pPlantNode);
		for (Node* pBulletNode : VecBullet)
		{
			CBullet* pBullet = static_cast<CBullet*>(pBulletNode);
			if (pBullet->getType()==1)
			{
				for (Node* pZombieNode : VecZombie)
				{
					CZombie* pZombie = static_cast<CZombie*>(pZombieNode);
					Vec2 tiledZombie = m_spInstance->getTiledByPos(pZombie->getPosition());
					Vec2 tiledBullet = m_spInstance->getTiledByPos(pBullet->getPosition());
					float fDistance = pBullet->getPosition().x - pZombie->getPosition().x;
					float fDistance1 = pZombie->getPosition().x - pPlant->getPosition().x;
					if (nullptr != pBullet && nullptr != pZombie && tiledZombie.y == tiledBullet.y && fDistance >= 0 && fDistance1 >= 0)
					{
						if (pBullet->getBombEffect())
						{
							m_pEffect->addEffect(pBullet->getPosition(), pBullet->getAnimateBomb());
							pBullet->setBombEffect(false);
						}

						pBullet->removeFromParent();
						if (pZombie->damage(pBullet->getACK()) <= 500)
						{
							pZombie->changeState(E_STATE_HERT);
							if (pZombie->getBoolEffect())
							{
								m_pEffect->addEffect(pZombie->getPosition(), pZombie->getAniLostHead());
								pZombie->setBoolEffect(false);
							}
						}
						if (pZombie->damage(pBullet->getACK()) <= 0)
						{
							if (pZombie->getDieEffect())
							{
								m_pEffect->addEffect(pZombie->getPosition(), pZombie->getAnimateDir());
								pZombie->setDieEffect(false);
							}

							pZombie->removeFromParent();
						}
					}
				}
			}
			
		}
		for (Node* pZombieNode : VecZombie)
		{
			CZombie* pZombie = static_cast<CZombie*>(pZombieNode);
			if (pPlant->getID() == 1006)
			{
				if (pPlant->getBoundingBox().intersectsRect(pZombie->getBoundingBox()))
				{
					
					pZombie->removeFromParent();
					m_pEffect->addEffect(pZombie->getPosition(), pZombie->getAnimateBoomDie());

				}
			}
		}
	}
	for (Node* pZombieNode : VecZombie)
	{
		CZombie* pZombie = static_cast<CZombie*>(pZombieNode);
		for (Node* pBulletNode : VecBullet)
		{
			CBullet* pBullet = static_cast<CBullet*>(pBulletNode);
			if (pBullet->getType() == 2)
			{
				for (Node* pPlantNode : VecPlant)
				{
					CPlant* pPlant = static_cast<CPlant*>(pPlantNode);
					Vec2 tiledPlant = m_spInstance->getTiledByPos(pPlant->getPosition());
					Vec2 tiledBullet = m_spInstance->getTiledByPos(pBullet->getPosition());
					float fDistance1 = pZombie->getPosition().x - pPlant->getPosition().x;
					bool bContain = pPlant->getBoundingBox().containsPoint(pBullet->getPosition());
					if (nullptr != pBullet && nullptr != pPlant && tiledPlant.y == tiledBullet.y && fDistance1<=0 && bContain)
					{
						
						if (pPlant->damage(pBullet->getACK()) <= 0)
						{
							if (pZombie->getHP() <= 500)
							{
								pZombie->changeState(E_STATE_HERT);
							}
							else
							{
								pZombie->changeState(E_STATE_PERFECT);
							}
							pPlant->removeFromParent();
						}
						if (pPlant->getID()==1004)
						{
							if (pPlant->getHP()<=8000)
							{
								if (pPlant->getHP() <= 5000)
								{
									pPlant->changePlantState(E_STATE_CRACKED2);
								}
								else
								{
									pPlant->changePlantState(E_STATE_CRACKED1);
								}
							}
						}
						
					}
				}
			}
		}
	}
	
}

void CGameMain::createFallSunShine()
{
	int nStartPosTileX = 3 + rand() % 8;
	int nStartPosTileY = 0;
	Vec2 startPos = this->getCenterPosByTiled(Vec2(nStartPosTileX, nStartPosTileY));
	int nEndPosTileY = 2+rand() % 5;
	Vec2 endPos = this->getCenterPosByTiled(Vec2(nStartPosTileX, nEndPosTileY));
	m_pSunShineMgr->addFullSunShine(startPos, endPos);
}
	
	
Vec2 CGameMain::getTiledByPos(const Vec2 & pos)
{
	//��ȡ���Ӵ�С
	Size tileSize = m_pTileMap->getTileSize();
	//��ȡ��ͼ��С
	Size mapSize = m_pTileMap->getMapSize();
	//��ȡ�������X����
	int nTileX = (int)pos.x / tileSize.width;
	//��ȡ�������Y����
	int nY = (int)pos.y / tileSize.height;
	int nTileY = mapSize.height - 1 - nY;
	return(Vec2(nTileX, nTileY));
}

Vec2 CGameMain::getCenterPosByTiled(const Vec2 & tiledPos)
{
	//��ȡ���Ӵ�С
	Size tileSize = m_pTileMap->getTileSize();
	//��ȡ��ͼ��С
	Size mapSize = m_pTileMap->getMapSize();
	//X
	float fX = tiledPos.x*tileSize.width + tileSize.width / 2;
	//Y
	float fY = (mapSize.height - 1 - tiledPos.y)*tileSize.height + tileSize.height / 2;
	return Vec2(fX, fY);
}



CGameMain* CGameMain::getInstance()
{
	if (nullptr == m_spInstance)
	{
		m_spInstance = CGameMain::create();
	}
	return m_spInstance;
}

void CGameMain::destroyInstance()
{
	m_spInstance = nullptr;
}

void CGameMain::addTouch()
{
	//1����ȡ������
	EventListenerTouchOneByOne* pListener = EventListenerTouchOneByOne::create();
	//2.���ü�����:���ûص�����
	pListener->onTouchBegan = CC_CALLBACK_2(CGameMain::onTouchBegan, this);
	/*pListener->onTouchMoved = CC_CALLBACK_2(CPlantMgr::onTouchMoved, this);
	pListener->onTouchEnded = CC_CALLBACK_2(CPlantMgr::onTouchEnded, this);*/
	pListener->onTouchMoved = CC_CALLBACK_2(CGameMain::onTouchMoved, this);
	pListener->onTouchEnded = CC_CALLBACK_2(CGameMain::onTouchEnded, this);
	//3.Ͷ����Ϣ
	_eventDispatcher->addEventListenerWithSceneGraphPriority(pListener, this);
}

bool CGameMain::changeAttackState()
{
	m_bAttack = true;
	return m_bAttack;
}

bool CGameMain::onTouchBegan(Touch * pTouch, Event * pEvent)
{
	//��ȡ�����������
	Vec2 clickPos = pTouch->getLocation();
	//��Ƭ�������
	Vector<Node*>VecCard = m_pCardMgr->getChildren();
	for (Node* pCardNode : VecCard)
	{
		CPlantCard* pCard = static_cast<CPlantCard*>(pCardNode);
		Rect boundBox = pCard->getBoundingBox();
		if (boundBox.containsPoint(clickPos))
		{
			m_bMoved = true;
			m_nPlantID = pCard->getPlantID();
			m_nCardScore = pCard->getScore();
			m_strImg = CDataMgr::getInstance()->getPlantDtMgr()->getDataByID(m_nPlantID)->strImg;
			m_pEffect->addDragPic(m_strImg);
			return true;
		}
	}
	//����������
	Vector<Node*>VecSunShine = m_pSunShineMgr->getChildren();
	for (Node* pSunShineNode : VecSunShine)
	{
		CSunShine* pSunShine = static_cast<CSunShine*>(pSunShineNode);
		if (pSunShine->getBoundingBox().containsPoint(clickPos))
		{
			pSunShine->removeFromParent();
			int nCount = m_pMainMenu->getSunShineCount()+50;
			m_pMainMenu->setSunShineCount(nCount);
		}
	}
	return false;
}

void CGameMain::onTouchMoved(Touch * pTouch, Event * pEvent)
{
	if (m_bMoved)
	{
		m_movePos = pTouch->getLocation();
		
		m_pEffect->setDragPicPos(m_movePos);
	}
}

void CGameMain::onTouchEnded(Touch * pTouch, Event * pEvent)
{
	m_bMoved = false;
	//m_pCardMgr->getSprite()->setPosition(m_PosBk);
	//m_pCardMgr->getSprite()->setVisible(false);
	/*int nID = this->getCardMgr()->getVecData(m_nIndex)->getPlantID();*/
	m_pEffect->removeDrgPic();
	Vec2 tiledPos = this->getTiledByPos(m_movePos);

	Sprite* pPathSprite = m_pPathLayer->getTileAt(tiledPos);
	Vec2 newPos = this->getCenterPosByTiled(tiledPos);
	if ( NULL != pPathSprite)
	{
		Vector<Node*>VecPlant = CGameMain::getInstance()->getPlantMgr()->getChildren();
		Vector<Node*>VecZombie = CGameMain::getInstance()->getZombieMgr()->getChildren();
		for (Node* pPlantNode : VecPlant)
		{
			if (pPlantNode->getBoundingBox().containsPoint(newPos))
			{
				return;
			}
		}
		for (Node* pZombieNode : VecZombie)
		{
			if (pZombieNode->getBoundingBox().containsPoint(newPos))
			{
				return;
			}
		}
		//������ֲ��
		if (m_pMainMenu->getSunShineCount()>= m_nCardScore)
		{
			if (m_pPlantMgr->addPlant(m_nPlantID, newPos))
			{
				int nCount = m_pMainMenu->getSunShineCount() - m_nCardScore;
				m_pMainMenu->setSunShineCount(nCount);
			}
		}
		
	}
	else
	{
		return;
	}
}

void CGameMain::initPos()
{
	TMXObjectGroup* pObjGroup = m_pTileMap->getObjectGroup("initPos");
	ValueVector viniPos = pObjGroup->getObjects();
	for (int i = 0;i<viniPos.size();++i) 
	{
		ValueMap vMap = viniPos[i].asValueMap();
		float fX = vMap["x"].asFloat();
		float fY = vMap["y"].asFloat();
		Vec2 initPos = Vec2(fX, fY);
		Vec2 tiledPos = this->getTiledByPos(initPos);
		Vec2 centerPos = this->getCenterPosByTiled(tiledPos);
		m_vecinitPos.push_back(centerPos);
	}
	TMXObjectGroup* pObjGroup2 = m_pTileMap->getObjectGroup("endPos");
	ValueVector vendPos = pObjGroup2->getObjects();
	for (int i = 0; i < vendPos.size(); ++i)
	{
		ValueMap vMap2 = vendPos[i].asValueMap();
		float fX = vMap2["x"].asFloat();
		float fY = vMap2["y"].asFloat();
		Vec2 endPos = Vec2(fX, fY);
		Vec2 tiledPos = this->getTiledByPos(endPos);
		Vec2 centerPos = this->getCenterPosByTiled(tiledPos);
		m_vecendPos.push_back(centerPos);
	}
}
