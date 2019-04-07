#include"SunShineMgr.h"
CSunShineMgr::CSunShineMgr()
{
}

CSunShineMgr::~CSunShineMgr()
{
}

bool CSunShineMgr::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void CSunShineMgr::addFullSunShine(const Vec2& startPos, const Vec2& endPos)
{
	CSunShine* pSunShine = CSunShine::create();
	pSunShine->setPosition(startPos);
	float fSpeed = 50;
	float finterval = (startPos.y - endPos.y) / fSpeed;
	MoveTo* pMoveTo = MoveTo::create(finterval, endPos);
	pSunShine->runAction(Sequence::create(pMoveTo,DelayTime::create(6.f), RemoveSelf::create(),NULL));
	this->addChild(pSunShine);
}

void CSunShineMgr::addCreateSunShine(const Vec2 & startPos, const Vec2 & endPos)
{
	CSunShine* pSunShine = CSunShine::create();
	pSunShine->setPosition(startPos);
	JumpBy* pJump = JumpBy::create(1.0f,Vec2(20,60),30,1);
	MoveTo* pMoveTo = MoveTo::create(1.0f, Vec2(startPos.x + 20, startPos.y));
	pSunShine->runAction(Sequence::create(pJump, pMoveTo,NULL));
	this->addChild(pSunShine);
}
