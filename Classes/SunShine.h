#ifndef __SUNSHINE_H__
#define __SUNSHINE_H__
#include"cocos2d.h"
USING_NS_CC;
class CSunShine : public Sprite
{
public:
	CSunShine();
	~CSunShine();
	bool init();
	void addAnimate();
	CREATE_FUNC(CSunShine);
private:
	Sprite* m_pSunShineSprtie;
	Animate* m_pAniSunShine;
};


#endif // !__SUNSHINE_H__#pragma once
