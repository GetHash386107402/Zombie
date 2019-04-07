#ifndef __BULLET_H__
#define __BULLET_H__
#include"cocos2d.h"
#include"StructData.h"
USING_NS_CC;
class CBullet : public Sprite
{
public:
	CBullet();
	~CBullet();
	bool initWithData(sBulletDt* pData);
	static CBullet* createWithData(sBulletDt* pData);
	void move(float nInterval,const Vec2& EndPos);
	void addAnimate();
	Animate* getAnimateBomb()
	{
		return m_pAnimateBomb;
	}
	CC_SYNTHESIZE(int, m_nRoleID, RoleID);
	CC_SYNTHESIZE(int, m_nType, Type);
	CC_SYNTHESIZE(int, m_nACK, ACK);
	CC_SYNTHESIZE(string, m_strImg, Img);
	CC_SYNTHESIZE(bool, m_bBombEffect, BombEffect);
private:
	Sprite* m_pSprite;
	Animate* m_pAnimateBomb;

};


#endif // !__BULLETMGR_H__
