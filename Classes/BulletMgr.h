#ifndef __BULLETMGR_H__
#define __BULLETMGR_H__
#include"cocos2d.h"
#include"Bullet.h"
USING_NS_CC;
class CBulletMgr : public Layer
{
public:
	CBulletMgr();
	~CBulletMgr();
	bool init();
	void addBullet(const Vec2& StartPos, const Vec2& EndPos, int nID);
	CREATE_FUNC(CBulletMgr);
private:

};


#endif // !__BULLETMGR_H__

