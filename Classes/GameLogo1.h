#ifndef _GAMELOGO1_H__
#define _GAMELOGO1_H__
#include "cocos2d.h"
USING_NS_CC;
class CGameLogo : public Layer
{
public:
	CGameLogo();
	~CGameLogo();
	//��������
	static Scene* createScene();
	//��ʼ������
	virtual bool init();
	//�ص�����
	void CGameLogoCallBack(Ref* pSender);
	//�л�����
	void changeScene();
	CREATE_FUNC(CGameLogo);
private:

};

#endif // !_GAMELOGO1_H__

