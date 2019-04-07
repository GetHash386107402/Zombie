#ifndef __SUNSHINEMGR_H__
#define __SUNSHINEMGR_H__
#include"cocos2d.h"
#include"SunShine.h"
USING_NS_CC;
class CSunShineMgr : public Layer
{
public:
	CSunShineMgr();
	~CSunShineMgr();
	bool init();
	void addFullSunShine(const Vec2& startPos,const Vec2& endPos);
	void addCreateSunShine(const Vec2& startPos, const Vec2& endPos);
	CREATE_FUNC(CSunShineMgr);
private:

};


#endif // !__SUNSHINEMGR_H__

