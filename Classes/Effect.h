#ifndef __EFFECT_H__
#define __EFFECT_H__
#include"cocos2d.h"
#include<string>
using namespace std;
USING_NS_CC;
class CEffect:public Layer
{
public:
	CEffect();
	~CEffect();
	bool init();
	void addEffect(const Vec2& Position, Animate* pAnimate);
	void addDragPic(string Img);
	void setDragPicPos(const Vec2& Position);
	void removeDrgPic();
	CREATE_FUNC(CEffect);
private:
	Sprite* m_DragImg;
};

#endif // !_EFFECT_H__
