#ifndef __ANIMATEMGR_H__
#define __ANIMATEMGR_H__
#include"cocos2d.h"
USING_NS_CC;
class CAnimateMgr
{
public:
	CAnimateMgr();
	~CAnimateMgr();
	void addAnimtaion();
	Animate* getAnimateWalk()
	{
		return m_pAnimateWalk;
	}
	Animate* getAnimateAttack()
	{
		return m_pAnimateAttack;
	}
	Animate* getAniLostHead()
	{
		return m_pAniLostHead;
	}
	Animate* getAniLostWalk()
	{
		return m_pAniLostWalk;
	}
	Animate* getAniLostAttack()
	{
		return m_pAniLostAttack;
	}
	Animate* getAnimateDir()
	{
		return m_pAnimateDir;
	}
	MoveBy* getMoveBy()
	{
		return m_pMoveBy;
	}
private:
	Animate* m_pAnimateWalk;
	Animate* m_pAnimateAttack;
	Animate* m_pAniLostHead;
	Animate* m_pAniLostWalk;
	Animate* m_pAniLostAttack;
	Animate* m_pAnimateDir;
	MoveBy* m_pMoveBy;
};


#endif // !__ANIMATEMGR_H

