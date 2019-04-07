#include"Effect.h"
#include"GameMain.h"
CEffect::CEffect()
{
}

CEffect::~CEffect()
{
}

bool CEffect::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void CEffect::addEffect(const Vec2 & Position, Animate* pAnimate)
{
	Sprite* pSprite = Sprite::create();
	pSprite->setPosition(Position);
	pSprite->runAction(CCSequence::create(pAnimate,RemoveSelf::create(),NULL));
	this->addChild(pSprite);
}

void CEffect::addDragPic(string Img)
{
	m_DragImg = Sprite::createWithSpriteFrameName(Img);
	this->addChild(m_DragImg,100);
}

void CEffect::setDragPicPos(const Vec2 & Position)
{
	m_DragImg->setPosition(Position);
}

void CEffect::removeDrgPic()
{
	m_DragImg->removeFromParent();
}
