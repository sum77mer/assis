#pragma once

// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DRIVERDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ZHAOXINSOFTWAREDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef SV_SOFTWAREDLL_EXPORTS
#define SV_SOFTWAREDLL_API __declspec(dllexport)
#else
#define SV_SOFTWAREDLL_API __declspec(dllimport)
#endif

namespace SV_ASSIST
{
	namespace Software
	{
		SV_SOFTWAREDLL_API BOOL PowerManagement();
		SV_SOFTWAREDLL_API BOOL ChangeBlueCrash(BOOL AutoReboot);
		SV_SOFTWAREDLL_API BOOL FireWall(BOOL EnableFireWall);
		SV_SOFTWAREDLL_API BOOL EnumService(std::list<Service_Struct>& data);
		SV_SOFTWAREDLL_API BOOL AutoList(std::vector<RegKeyDetail>& ListEnumKeyValue);
		SV_SOFTWAREDLL_API BOOL EnumFolderTaskScheduler(std::list<TaskScheduler_Struct>& data);
		SV_SOFTWAREDLL_API BOOL EnumRuningTaskScheduler(std::list<TaskScheduler_Struct>& data);
		SV_SOFTWAREDLL_API BOOL GetTcpConnect(std::vector<ConnInfo>& connInfo);
		SV_SOFTWAREDLL_API BOOL GetUdpConnect(std::vector<ConnInfo>& connInfo);
	}
}