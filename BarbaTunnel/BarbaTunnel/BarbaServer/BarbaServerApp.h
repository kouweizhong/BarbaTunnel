#pragma once
#include "BarbaApp.h"
#include "BarbaVirtualIp.h"
#include "BarbaServerConfig.h"
#include "BarbaServerConnection.h"
#include "BarbaHttpServer.h"

class BarbaServerApp : public BarbaApp
{
public:
	BarbaServerApp(void);
	virtual ~BarbaServerApp(void);

	BarbaHttpServer HttpServer;
	BarbaServerConfig Config;
	BarbaServerConnectionManager ConnectionManager;
	void Initialize();
	void ProcessPacket(INTERMEDIATE_BUFFER* packet);
	BarbaVirtualIpManager VirtualIpManager;

private:
	BarbaServerConfigItem* IsGrabPacket(PacketHelper* packet);
	void InitHttpServer();
};

extern BarbaServerApp* theServerApp;