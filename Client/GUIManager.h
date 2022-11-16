#ifndef _GUIMAANGER_H_
#define _GUIMAANGER_H_

#include "Define.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <unordered_map>

class ChannelInfo;
class GUIManager
{
private:
	static GUIManager*				m_pInstance;
	char							m_chText[128];
	char							m_chEmail[128];
	char							m_chPassword[128];
	std::string						m_currentChannel;
	std::list<std::string>			m_listAllChannels;
	typedef std::unordered_map<std::string, ChannelInfo> ChannelMap;
	ChannelMap						m_mapJoinedChannels;

	bool							m_tabChange;
	bool							m_bAuthAccountWindow;
	bool							m_bConfirmPopup;
	std::string						m_confirmMsg;
	bool							m_bNetwork;

public:
	explicit GUIManager();
	~GUIManager();
	static GUIManager* GetInstance();
	void DestroyInstance();
public:
	void RenderUI();
	int Ready(GLFWwindow*);
	void Close();

public:
	void SetAuthAccountWindow(bool value)	{ m_bAuthAccountWindow = value; }
	void SetConfirmPopup(bool value, std::string message = "");

public:
	void AddAllChannelList(std::string name);
	void UpdateJoinedChannelMap(ChannelInfo& info);
	void UpdateSystemChannel(std::string name);
	void AddConvo(unsigned int clientId, std::string channelName, std::string clientName, std::string message);
	void RemoveFromAllChannel(std::string channelName);
	void RemoveJoinedChannel(std::string channelName);
	void InitAllInformation();
	void PressSendButton();
	void ClearConfirmPopupText(bool id, bool pass);
	void SetNetwork(bool value) { m_bNetwork = value; }

private:
	void UserList(float screenX, float screenY);
	void ContentArea(float screenX, float screenY);
	void TextInputArea(float screenX);
	void PopupAccount();
	void PopupConfirm();
};


#endif //_GUIMAANGER_H_