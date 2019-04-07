#include"PlantCard.h"
CPlantCard::CPlantCard()
{
}

CPlantCard::~CPlantCard()
{
}

bool CPlantCard::initWithData(sCardDt * pData)
{
	if (!Sprite::initWithSpriteFrameName(pData->strImg))
	{
		return false;
	}
	m_nCardID = pData->nCardID;
	m_nPlantID = pData->nPlantID;
	m_nScore = pData->nScore;
	m_nstrImg = pData->strImg;
	//m_pSprite = Sprite::createWithSpriteFrameName(m_nstrImg);
	m_nWidth = this->getContentSize().width;
	//this->addChild(m_pSprite);
	return true;
}

CPlantCard * CPlantCard::createWithData(sCardDt * pData)
{
	CPlantCard* pPlantCard = new CPlantCard;
	if (nullptr != pPlantCard && pPlantCard->initWithData(pData))
	{
		pPlantCard->autorelease();
		return pPlantCard;
	}
	else
	{
		CC_SAFE_DELETE(pPlantCard);
		return nullptr;
	}
}

//bool CPlantCard::getifContain(Vec2 pos)
//{
//	if (m_pSprite->getBoundingBox().containsPoint(pos))
//	{
//		return true;
//	}
//	return false;
//}
