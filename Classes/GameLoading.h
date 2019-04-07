#ifndef __GAMELOADING_H__
#define __GAMELOADING_H__
#include"cocos2d.h"
#include"DataMgr.h"
#include"GameMenu.h"
USING_NS_CC;
class CGameLoading : public Layer
{
public:
	CGameLoading();
	~CGameLoading();
	//������������
	static Scene* createScene();
	//��ʼ������
	virtual bool init();
	//���ݸ���
	virtual void update(float delta);
	//�ص�����
	void CGameLoadingCallBack(Ref* pSender);
	//�л�����
	void changeScene(float fDela);
	CREATE_FUNC(CGameLoading);
private:
	int m_nIndex;//��ǰ��ȡ��������ڼ�����Դ
	int m_nTotalCount;//��Դ����
	int m_nCurCount;//Ŀǰ��ȡ�˶��ٸ���Դ
	vector<string> m_vecPng;
	vector<string> m_vecPlist;
	ProgressTimer* m_pProgress;
	Label* m_pLabel;
	Sprite* m_pTag;
	Vec2 origin;
	Size visibleSize;
	Sprite* m_pProSprite;
};


#endif // !__GAMELOADING_H__


