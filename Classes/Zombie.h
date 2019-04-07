#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include"cocos2d.h"
#include"StructData.h"
USING_NS_CC;
enum
{
	E_STATE_PERFECT,
	E_STATE_HERT,
	E_STATE_ATTACK,
	E_STATE_LOSTATTACK
};
class CZombie : public Sprite
{
public:
	CZombie();
	~CZombie();
	bool initWithData(sZombieDt* pData);
	/*void moveZombie();*/
	void addAnimtaion();
	int damage(int nDamage);
	/*int attack(int nHP);*/
	void changeState(int nState);
	
	static CZombie* createWithData(sZombieDt* pData);
	
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
	Animate* getAnimateBoomDie()
	{
		return m_pAnimateBoomDie;
	}
	MoveTo* getMoveTo()
	{
		return m_pMoveTo;
	}
	void Attack(int nID);
	Node* findPlant();
	CC_SYNTHESIZE(int, m_nID, ID);
	CC_SYNTHESIZE(int, m_nFullHp, FullHp);
	CC_SYNTHESIZE(int, m_nHP, HP);
	CC_SYNTHESIZE(int, m_nACK, ACK);
	CC_SYNTHESIZE(bool, m_bEffect, BoolEffect);
	CC_SYNTHESIZE(bool, m_bAttack, BoolAttack);
	CC_SYNTHESIZE(bool, m_bDieEffect, DieEffect);
	CC_SYNTHESIZE(int, m_nState, State);
	CC_SYNTHESIZE(float, m_finitX, initX);
	CC_SYNTHESIZE(float, m_finitY, initY);
private:
	vector<Vec2>m_vecinitPos;
	vector<Vec2>m_vecendPos;
	Sprite* m_pSprite;
	Animate* m_pAnimateWalk;
	Animate* m_pAnimateAttack;
	Animate* m_pAniLostHead;
	Animate* m_pAniLostWalk;
	Animate* m_pAniLostAttack;
	Animate* m_pAnimateDir;
	Animate* m_pAnimateBoomDie;
	MoveTo* m_pMoveTo;

};

#endif // !__ZOMBIE_H__

