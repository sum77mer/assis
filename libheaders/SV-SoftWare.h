#pragma once
#include <list>
#include <string>
#include <vector>
#include "Softwaredefination.h"

// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 DRIVERDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// ZHAOXINSOFTWAREDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef SV_SOFTWAREDLL_EXPORTS
#define SV_SOFTWAREDLL_API __declspec(dllexport)
#else
#define SV_SOFTWAREDLL_API __declspec(dllimport)
#endif

namespace SV_ASSIST
{
	namespace Software
	{
		//自动设置成高性能及更改其他电源模式
		SV_SOFTWAREDLL_API BOOL PowerManagement();
		SV_SOFTWAREDLL_API BOOL ChangeBlueCrash(BOOL AutoReboot);
		SV_SOFTWAREDLL_API BOOL FireWall(BOOL EnableFireWall);
		SV_SOFTWAREDLL_API BOOL EnumService(std::list<Service_Struct>& data);
		SV_SOFTWAREDLL_API BOOL AutoList(std::vector<RegKeyDetail>& ListEnumKeyValue);
		SV_SOFTWAREDLL_API BOOL EnumFolderTaskScheduler(std::list<TaskScheduler_Struct>& data);
		SV_SOFTWAREDLL_API BOOL EnumRuningTaskScheduler(std::list<TaskScheduler_Struct>& data);
		SV_SOFTWAREDLL_API BOOL GetTcpConnect(std::vector<ConnInfo>& connInfo);
		SV_SOFTWAREDLL_API BOOL GetUdpConnect(std::vector<ConnInfo>& connInfo);
		SV_SOFTWAREDLL_API BOOL CloseWindowsUpdateService();
		//更改注册表的 不能停止defender;
		SV_SOFTWAREDLL_API BOOL WindowsDefender(bool EnableDefender);
		//不好使 用附件的软件
		SV_SOFTWAREDLL_API BOOL AutoLogin(bool EnableAutoLogin, const std::wstring& UserName, const std::wstring& UserPassword, const std::wstring UserDomin);
	}
}