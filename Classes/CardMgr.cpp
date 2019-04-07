#include"CardMgr.h"
//#include"DataMgr.h"
CCardMgr::CCardMgr()
{
	m_nID = 0;
}

CCardMgr::~CCardMgr()
{
}

bool CCardMgr::init()
{
	if (!Layer::init())
	{
		return false;
	}

	this->createCard();
	//m_pDragSp = Sprite::create();
	//m_pDragSp->setVisible(false);
	////m_pDragSp->retain();
	//this->addChild(m_pDragSp,100);
	return true;
}

void CCardMgr::createCard()
{
	m_origin = Director::getInstance()->getVisibleOrigin();
	m_visibleSize = Director::getInstance()->getVisibleSize();
	
	for (int i = 0; i < 6; i++)
	{
		m_nID = 101 + i;
		sCardDt* pCardDt = CDataMgr::getInstance()->getCardDtMgr()->getDataByID(m_nID);
		CPlantCard* pPlantCard = CPlantCard::createWithData(pCardDt);
		pPlantCard->setPosition(m_origin.x + m_visibleSize.width / 8 * 2 + 100* i, m_origin.y + m_visibleSize.height / 8 * 7.5);
		int floatX = pPlantCard->getPosition().x;
		this->addChild(pPlantCard);
	}
	/*int nWx = pPlantCard->getWidth();
		pPlantCard->setPosition(m_origin.x + m_visibleSize.width /8*1.4+ nWx*i, m_origin.y + m_visibleSize.height / 8*7.5);
		pPlantCard->setScale(0.8);
		this->addChild(pPlantCard);*/
	
}
