#include "getdata.h"
#include"libheaders\SV_Hardware.h"
#include"libheaders\SV-SoftWare.h"
#include <sstream>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QRegExp>
#include <QDateTime>
#include <QDebug>
using namespace SV_ASSIST;
GetData::GetData()
{
	initialize();
}
void GetData::initialize()
{
	//board
	auto smbiosRaw = DMI_SMBIOS::GetSMBIOSinfo();
	for (auto i : smbiosRaw.BaseBroadinfo)
	{
		TitleValue tvtemp;
		tvtemp.title = i.first;
		tvtemp.value = i.second;
		hardwareData.boardInfo.push_back(tvtemp);
	}
	//bios
	for (auto i : smbiosRaw.BIOSinfo)
	{
		TitleValue tvtemp;
		tvtemp.title = i.first;
		tvtemp.value = i.second;
		hardwareData.biosInfo.push_back(tvtemp);
	}
	for (auto i : smbiosRaw.BIOSLanginfo)
	{
		TitleValue tvtemp;
		tvtemp.title = i.first;
		tvtemp.value = i.second;
		hardwareData.biosInfo.push_back(tvtemp);
	}
	//chipset
	//cpu
	hardwareData.cpuInfo.cpuName = CPU::GetCPUName();
	hardwareData.cpuInfo.cpuSpecification = CPU::GetCPUSpecification();
	hardwareData.cpuInfo.processorID = CPU::GetProcessorID();
	hardwareData.cpuInfo.socketDescription = CPU::GetSocketDesignation();
	auto currentspeed = CPU::GetCurrentClockSpeed();
	hardwareData.cpuInfo.coreSpeed = currentspeed[0];
	hardwareData.cpuInfo.extSpeed = CPU::GetExtClock();
	hardwareData.cpuInfo.multiplier = hardwareData.cpuInfo.coreSpeed / hardwareData.cpuInfo.extSpeed;
	hardwareData.cpuInfo.maxSpeed = 0;
	hardwareData.cpuInfo.coreNum = CPU::GetCore();
	hardwareData.cpuInfo.threadNum = CPU::GetThread();
	hardwareData.cpuInfo.revision = CPU::GetRevision();
	hardwareData.cpuInfo.manufacture = CPU::GetManufacturer();
	hardwareData.cpuInfo.family = CPU::GetFamily();
	hardwareData.cpuInfo.model = CPU::GetModel();
	hardwareData.cpuInfo.stepping = CPU::GetStepping();
	hardwareData.cpuInfo.extFamily = CPU::GetExtFamily();
	hardwareData.cpuInfo.extModel = CPU::GetExtModel();
	CPUFeature cpuFeature = CPU::GetFeature();
	if (hardwareData.cpuInfo.manufacture.find("GenuineIntel") != string::npos)
	{
		if (cpuFeature.IntelFeature.SSE3)
			hardwareData.cpuInfo.instructionSets += "SSE3 ";
		if (cpuFeature.IntelFeature.PCLMULQDQ)
			hardwareData.cpuInfo.instructionSets += "PCLMULQDQ ";
		if (cpuFeature.IntelFeature.DTES64)
			hardwareData.cpuInfo.instructionSets += "DTES64 ";
		if (cpuFeature.IntelFeature.MONITOR)
			hardwareData.cpuInfo.instructionSets += "MONITOE ";
		if (cpuFeature.IntelFeature.DS_CPL)
			hardwareData.cpuInfo.instructionSets += "DS_CPL ";
		if (cpuFeature.IntelFeature.VMX)
			hardwareData.cpuInfo.instructionSets += "VMX ";
		if (cpuFeature.IntelFeature.SMX)
			hardwareData.cpuInfo.instructionSets += "SMX ";
		if (cpuFeature.IntelFeature.EIST)
			hardwareData.cpuInfo.instructionSets += "EIST ";
		if (cpuFeature.IntelFeature.TM2)
			hardwareData.cpuInfo.instructionSets += "TM2 ";
		if (cpuFeature.IntelFeature.SSSE3)
			hardwareData.cpuInfo.instructionSets += "SSSE3 ";
		if (cpuFeature.IntelFeature.CNXT_ID)
			hardwareData.cpuInfo.instructionSets += "CNXT_ID ";
		if (cpuFeature.IntelFeature.SDBG)
			hardwareData.cpuInfo.instructionSets += "SDBG ";
		if (cpuFeature.IntelFeature.FMA)
			hardwareData.cpuInfo.instructionSets += "FMA ";
		if (cpuFeature.IntelFeature.CMPXCHG16B)
			hardwareData.cpuInfo.instructionSets += "CMPXCHG16B ";
		if (cpuFeature.IntelFeature.xTPR_Update_Control)
			hardwareData.cpuInfo.instructionSets += "xTPR_Update_Control ";
		if (cpuFeature.IntelFeature.PDCM)
			hardwareData.cpuInfo.instructionSets += "PDCM ";
		if (cpuFeature.IntelFeature.PCID)
			hardwareData.cpuInfo.instructionSets += "PCID ";
		if (cpuFeature.IntelFeature.DCA)
			hardwareData.cpuInfo.instructionSets += "DCA ";
		if (cpuFeature.IntelFeature.SSE4_1)
			hardwareData.cpuInfo.instructionSets += "SSE4_1 ";
		if (cpuFeature.IntelFeature.SSE4_2)
			hardwareData.cpuInfo.instructionSets += "SSE4_2 ";
		if (cpuFeature.IntelFeature.x2APIC)
			hardwareData.cpuInfo.instructionSets += "x2APIC ";
		if (cpuFeature.IntelFeature.MOVBE)
			hardwareData.cpuInfo.instructionSets += "MOVBE ";
		if (cpuFeature.IntelFeature.POPCNT)
			hardwareData.cpuInfo.instructionSets += "POPCNT ";
		if (cpuFeature.IntelFeature.TSC_Deadline)
			hardwareData.cpuInfo.instructionSets += "TSC_Deadline ";
		if (cpuFeature.IntelFeature.AESNI)
			hardwareData.cpuInfo.instructionSets += "AESNI ";
		if (cpuFeature.IntelFeature.XSAVE)
			hardwareData.cpuInfo.instructionSets += "XSAVE ";
		if (cpuFeature.IntelFeature.OSXSAVE)
			hardwareData.cpuInfo.instructionSets += "OSXSAVE ";
		if (cpuFeature.IntelFeature.AVX)
			hardwareData.cpuInfo.instructionSets += "AVX ";
		if (cpuFeature.IntelFeature.F16C)
			hardwareData.cpuInfo.instructionSets += "F16C ";
		if (cpuFeature.IntelFeature.RDRAND)
			hardwareData.cpuInfo.instructionSets += "RDRAND";
	}
	else if (hardwareData.cpuInfo.manufacture.find("AMD") != string::npos)
	{
	}
	else if (hardwareData.cpuInfo.manufacture.find("ZHAOXIN") != string::npos)
	{
	}
	else
	{
		hardwareData.cpuInfo.instructionSets = "unknown CPU";
	}
	auto cache = CPU::GetCache();
	//recode
	for (unsigned int i = 0; i<4; i++)
	{
		Cache_info cache_temp = *(cache + i);
		if (cache_temp.Cache_level == 1)
		{
			if (cache_temp.Cache_type == 'D')
			{
				Cache cacheTemp;
				cacheTemp.level = cache_temp.Cache_level;
				cacheTemp.size = cache_temp.Cache_Size / 1024;
				cacheTemp.way = cache_temp.Cache_Ways;
				cacheTemp.partition = cache_temp.Cache_partitions;
				cacheTemp.set = cache_temp.Cache_Set;
				cacheTemp.lineSize = cache_temp.Cache_line_size;
				cacheTemp.type = cache_temp.Cache_type;
				hardwareData.cpuInfo.cache.push_back(cacheTemp);
			}
			else if (cache_temp.Cache_type == 'T')
			{
				Cache cacheTemp;
				cacheTemp.level = cache_temp.Cache_level;
				cacheTemp.size = cache_temp.Cache_Size / 1024;
				cacheTemp.way = cache_temp.Cache_Ways;
				cacheTemp.partition = cache_temp.Cache_partitions;
				cacheTemp.set = cache_temp.Cache_Set;
				cacheTemp.lineSize = cache_temp.Cache_line_size;
				cacheTemp.type = cache_temp.Cache_type;
				hardwareData.cpuInfo.cache.push_back(cacheTemp);
			}
		}
		else if (cache_temp.Cache_level == 2)
		{
			Cache cacheTemp;
			cacheTemp.level = cache_temp.Cache_level;
			cacheTemp.size = cache_temp.Cache_Size / 1024;
			cacheTemp.way = cache_temp.Cache_Ways;
			cacheTemp.partition = cache_temp.Cache_partitions;
			cacheTemp.set = cache_temp.Cache_Set;
			cacheTemp.lineSize = cache_temp.Cache_line_size;
			cacheTemp.type = cache_temp.Cache_type;
			hardwareData.cpuInfo.cache.push_back(cacheTemp);
		}
		else if (cache_temp.Cache_level == 3)
		{
			Cache cacheTemp;
			cacheTemp.level = cache_temp.Cache_level;
			cacheTemp.size = cache_temp.Cache_Size / 1024;
			cacheTemp.way = cache_temp.Cache_Ways;
			cacheTemp.partition = cache_temp.Cache_partitions;
			cacheTemp.set = cache_temp.Cache_Set;
			cacheTemp.lineSize = cache_temp.Cache_line_size;
			cacheTemp.type = cache_temp.Cache_type;
			hardwareData.cpuInfo.cache.push_back(cacheTemp);
		}
	}

	hardwareData.cpuInfo.southbridgeName = CPU::GetSouthbridgeName();
	hardwareData.cpuInfo.codeName = CPU::GetCodeName();
	hardwareData.cpuInfo.technology = CPU::GetTechnology();
	hardwareData.cpuInfo.maxTDP = CPU::GetMaxTDP();
	hardwareData.cpuInfo.temperature = CPU::GetTemperature();
	hardwareData.cpuInfo.packageTemperature = CPU::GetPackageTemperature();

	//dimm
	auto dimmRaw = Memory::GetMemoryGlobalInfomation();
	for (auto i : dimmRaw)
	{
		Memory_Information memtemp;
		memtemp.slot = i.first;
		memtemp.dramManufacture = i.second.DRAMManufacturer;
		memtemp.moduleManufacture = i.second.ModuleManufacturer;
		memtemp.moduleSize = i.second.ModuleSize;
		memtemp.modulType = i.second.ModuleType;
		memtemp.partNum = i.second.PartNumber;
		memtemp.productDate = i.second.ProductDate;
		memtemp.serialNum = i.second.SerialNumber;
		hardwareData.dimmInfo.push_back(memtemp);
	}
	//gpu
	GPU::UpdateDate();
	auto gpuRaw = GPU::GetGpuInfo();
	
	for (auto i = gpuRaw.begin(); i<gpuRaw.end(); i++)
	{
		GPU_Information temp;
		temp.gpuName = i->GetGPUName();
		temp.gpuBIOSVersion = i->GetGPUBiosVersion();
		temp.gpuDriverVersion = i->GetGPUDriverVersion();
		temp.gpuBranchVersion = i->GetGPUBranchVersion();
		temp.temperature = i->GetTemperature();
		temp.gpuClock = i->GetGPUClock();
		temp.gpuMemoryClock = i->GetGPUMemoryClock();
		temp.usage = i->GetGPUusage();
		temp.fans = i->GetGPUfans();
		temp.dedicatedVideoMemory = i->GetdedicatedVideoMemory();
		temp.systemVideoMemory = i->GetsystemVideoMemory();
		temp.sharedSystemMemory = i->GetsharedSystemMemory();
		hardwareData.gpuInfo.push_back(temp);
	}
	//monitor
	Display::UpdateData();
	hardwareData.monitorInfo.push_back(Display::GetMonitorName());
	//disk
	auto diskRaw = Storage::GetDiskSMARTInfo();
	for (auto i : diskRaw)
	{
		Disk_Information temp;
		temp.BufferSize = i.BufferSize;
		temp.CurrentTransferMode = i.CurrentTransferMode;
		temp.DeviceNominalFormFactor = i.DeviceNominalFormFactor;
		temp.DiskState = i.DiskState;
		temp.Enclosure = i.Enclosure;
		temp.Feature = i.Feature;
		temp.FirmwareRev = i.FirmwareRev;
		temp.GBytesErased = i.GBytesErased;
		temp.HostReads = i.HostReads;
		temp.Interface = i.Interface;
		temp.IsSsd = i.IsSsd;
		temp.LogicalDrive = i.LogicalDrive;
		temp.MajorVersion = i.MajorVersion;
		temp.MaxTransferMode = i.MaxTransferMode;
		temp.MinorVersion = i.MinorVersion;
		temp.Model = i.Model;
		temp.NandWrites = i.NandWrites;
		temp.NominalMediaRotationRate = i.NominalMediaRotationRate;
		temp.NvCacheSize = i.NvCacheSize;
		QString string = QString::fromStdWString(i.LogicalDrive);
		QRegExp regexp("[A-Z]");
		for (auto j : string)
		{
			if (regexp.exactMatch(j))
				hardwareData.drive.push_back(j);
		}
		temp.PowerOnCount = i.PowerOnCount;
		temp.PowerOnHours = i.PowerOnHours;
		temp.SerialNumber = i.SerialNumber;
		temp.Temperature = i.Temperature;
		temp.TotalDiskSize = i.TotalDiskSize;
		hardwareData.diskInfo.push_back(temp);
	}
	//pci
	auto pciRaw = Ring0::GetAllPciInfo();
	ULONG bus, dev, fun;
	for (auto &i : pciRaw.pciconfig)
	{
		PCI_Information temp;
		Ring0::PCIstringToBDF(i.first, bus, dev, fun);
		temp.bus = bus;
		temp.dev = dev;
		temp.fun = fun;
		temp.vendorID = i.second.VendorID;
		temp.deviceID = i.second.DeviceID;
		temp.command = i.second.Command;
		temp.status = i.second.Status;
		temp.cachelineSize = i.second.CacheLineSize;
		temp.latencyTimer = i.second.LatencyTimer;
		temp.revisionID = i.second.RevisionID;
		temp.classCode = 0;
		temp.interruptPin = i.second.u.type0.InterruptPin;
		temp.interruptLine = i.second.u.type0.InterruptLine;
		temp.baseclass = i.second.BaseClass;
		temp.subclass = i.second.SubClass;
		hardwareData.pciInfo.push_back(temp);
	}
	//net
	auto netData = Net::GetData();
	for (auto &i : netData)
	{
		Net_Information temp;
		temp.name = i.Name;
		temp.deviceName = i.DeviceName;
		temp.mediaType = i.MediaType;
		temp.state = i.state;
		hardwareData.netInfo.push_back(temp);
	}
	//audio
	AUDIO::UpdateData();
	auto audioData = AUDIO::GetOutputAudio();
	for (auto &i : audioData)
	{
		Audio_Information temp;
		temp.id = i.id;
		temp.state = i.state;
		temp.name = i.name;
		temp.desc = i.desc;
		temp.audioif = i.audioif;
		hardwareData.audioInfo.push_back(temp);
	}
	//mouse
	//keyboard	
	std::list<Service_Struct> serviceRaw;
	Software::EnumService(serviceRaw);
	for (auto i : serviceRaw)
	{
		Service_Information temp;
		temp.name = QString::fromStdWString(i.ServiceName);
		temp.disName = QString::fromStdWString(i.ServiceDisplayName);
		temp.path = QString::fromStdWString(i.ServicePath);
		temp.description = QString::fromStdWString(i.descripton);
		switch (i.CurrentStatus)
		{
		case SV_SERVICE_STATUS::CONTINUE_PENDING:
		{
			temp.status = "continue pending";
			break;
		}
		case SV_SERVICE_STATUS::PAUSED:
		{
			temp.status = "continue pending";
			break;
		}
		case SV_SERVICE_STATUS::PAUSE_PENDING:
		{
			temp.status = "pause pending";
			break;
		}
		case SV_SERVICE_STATUS::RUNNING:
		{
			temp.status = "running";
			break;
		}
		case SV_SERVICE_STATUS::SERVICE_UNKNOWN:
		{
			temp.status = "service unknown";
			break;
		}
		case SV_SERVICE_STATUS::START_PENDING:
		{
			temp.status = "start pending";
			break;
		}
		case SV_SERVICE_STATUS::STOPPED:
		{
			temp.status = "stopped";
			break;
		}
		default:
		{
			temp.status = "unknown";
			break;
		}
		}
		softwareData.serviceInfo.push_back(temp);
	}
	std::vector<RegKeyDetail> autolistRaw;
	Software::AutoList(autolistRaw);
	for (auto i : autolistRaw)
	{
		Auto_Information temp;
		temp.type = QString::fromStdWString(i.Type);
		temp.name = QString::fromStdWString(i.sRegKeyName);
		temp.data = QString::fromStdWString(i.sRegKeyData);
		softwareData.autolist.push_back(temp);
	}
	std::list<TaskScheduler_Struct> folderTaskRaw;
	Software::EnumFolderTaskScheduler(folderTaskRaw);
	for (auto i : folderTaskRaw)
	{
		Task_Information temp;
		temp.name = QString::fromStdWString(i.TaskName);
		switch (i.taskstate)
		{
		case TASK_STATE::TASK_STATE_DISABLED:
		{
			temp.state = "disabled";
			break;
		}
		case TASK_STATE::TASK_STATE_QUEUED:
		{
			temp.state = "queued";
			break;
		}
		case TASK_STATE::TASK_STATE_READY:
		{
			temp.state = "ready";
			break;
		}
		case TASK_STATE::TASK_STATE_RUNNING:
		{
			temp.state = "runnint";
			break;
		}
		case TASK_STATE::TASK_STATE_UNKNOWN:
		{
			temp.state = "state unknown";
			break;
		}
		default:
		{
			temp.state = "unknown";
			break;
		}
		}
		softwareData.folderTask.push_back(temp);
	}
	std::list<TaskScheduler_Struct> runningTaskRaw;
	Software::EnumRuningTaskScheduler(runningTaskRaw);
	for (auto i : runningTaskRaw)
	{
		Task_Information temp;
		temp.name = QString::fromStdWString(i.TaskName);
		switch (i.taskstate)
		{
		case TASK_STATE::TASK_STATE_DISABLED:
		{
			temp.state = "disabled";
			break;
		}
		case TASK_STATE::TASK_STATE_QUEUED:
		{
			temp.state = "queued";
			break;
		}
		case TASK_STATE::TASK_STATE_READY:
		{
			temp.state = "ready";
			break;
		}
		case TASK_STATE::TASK_STATE_RUNNING:
		{
			temp.state = "runnint";
			break;
		}
		case TASK_STATE::TASK_STATE_UNKNOWN:
		{
			temp.state = "state unknown";
			break;
		}
		default:
		{
			temp.state = "unknown";
			break;
		}
		}
		softwareData.runningTask.push_back(temp);
	}
	std::vector<ConnInfo> tcpRaw;
	Software::GetTcpConnect(tcpRaw);
	for (auto i : tcpRaw)
	{
		Connection_Information temp;
		temp.uPro = QString(QChar(i.uPro));
		temp.localIP = QString::fromStdString(i.dwLocalIp);
		temp.remoteIP = QString::fromStdString(i.dwRemoteIp);
		temp.PID = QString("%0").arg(i.nPId);
		temp.localPort = QString("%0").arg(i.nLocalPort);
		temp.remotePort = QString("%0").arg(i.nRemotePort);
		temp.state = QString::fromStdWString(i.uState);
		temp.strPath = QString::fromStdWString(i.strPath);
		softwareData.tcp.push_back(temp);
	}
	std::vector<ConnInfo> udpRaw;
	Software::GetUdpConnect(udpRaw);
	for (auto i : udpRaw)
	{
		Connection_Information temp;
		temp.uPro = QString(QChar(i.uPro));
		temp.localIP = QString::fromStdString(i.dwLocalIp);
		temp.remoteIP = QString::fromStdString(i.dwRemoteIp);
		temp.PID = QString("%0").arg(i.nPId);
		temp.localPort = QString("%0").arg(i.nLocalPort);
		temp.remotePort = QString("%0").arg(i.nRemotePort);
		temp.state = QString::fromStdWString(i.uState);
		temp.strPath = QString::fromStdWString(i.strPath);
		softwareData.udp.push_back(temp);
	}
}
void GetData::update()
{

}
void GetData::updateAll()
{
	
	hardwareData = {};
	//board
	auto smbiosRaw = DMI_SMBIOS::GetSMBIOSinfo();
	for (auto i : smbiosRaw.BaseBroadinfo)
	{
		TitleValue tvtemp;
		tvtemp.title = i.first;
		tvtemp.value = i.second;
		hardwareData.boardInfo.push_back(tvtemp);
	}
	//bios
	for (auto i : smbiosRaw.BIOSinfo)
	{
		TitleValue tvtemp;
		tvtemp.title = i.first;
		tvtemp.value = i.second;
		hardwareData.biosInfo.push_back(tvtemp);
	}
	for (auto i : smbiosRaw.BIOSLanginfo)
	{
		TitleValue tvtemp;
		tvtemp.title = i.first;
		tvtemp.value = i.second;
		hardwareData.biosInfo.push_back(tvtemp);
	}
	//chipset
	//cpu
	hardwareData.cpuInfo.cpuName = CPU::GetCPUName();
	hardwareData.cpuInfo.cpuSpecification = CPU::GetCPUSpecification();
	hardwareData.cpuInfo.processorID = CPU::GetProcessorID();
	hardwareData.cpuInfo.socketDescription = CPU::GetSocketDesignation();
	auto currentspeed = CPU::GetCurrentClockSpeed();
	hardwareData.cpuInfo.coreSpeed = currentspeed[0];
	hardwareData.cpuInfo.extSpeed = CPU::GetExtClock();
	hardwareData.cpuInfo.multiplier = hardwareData.cpuInfo.coreSpeed / hardwareData.cpuInfo.extSpeed;
	hardwareData.cpuInfo.maxSpeed = 0;
	hardwareData.cpuInfo.coreNum = CPU::GetCore();
	hardwareData.cpuInfo.threadNum = CPU::GetThread();
	hardwareData.cpuInfo.revision = CPU::GetRevision();
	hardwareData.cpuInfo.manufacture = CPU::GetManufacturer();
	hardwareData.cpuInfo.family = CPU::GetFamily();
	hardwareData.cpuInfo.model = CPU::GetModel();
	hardwareData.cpuInfo.stepping = CPU::GetStepping();
	hardwareData.cpuInfo.extFamily = CPU::GetExtFamily();
	hardwareData.cpuInfo.extModel = CPU::GetExtModel();
	CPUFeature cpuFeature = CPU::GetFeature();
	if (hardwareData.cpuInfo.manufacture.find("GenuineIntel") != string::npos)
	{
		if (cpuFeature.IntelFeature.SSE3)
			hardwareData.cpuInfo.instructionSets += "SSE3 ";
		if (cpuFeature.IntelFeature.PCLMULQDQ)
			hardwareData.cpuInfo.instructionSets += "PCLMULQDQ ";
		if (cpuFeature.IntelFeature.DTES64)
			hardwareData.cpuInfo.instructionSets += "DTES64 ";
		if (cpuFeature.IntelFeature.MONITOR)
			hardwareData.cpuInfo.instructionSets += "MONITOE ";
		if (cpuFeature.IntelFeature.DS_CPL)
			hardwareData.cpuInfo.instructionSets += "DS_CPL ";
		if (cpuFeature.IntelFeature.VMX)
			hardwareData.cpuInfo.instructionSets += "VMX ";
		if (cpuFeature.IntelFeature.SMX)
			hardwareData.cpuInfo.instructionSets += "SMX ";
		if (cpuFeature.IntelFeature.EIST)
			hardwareData.cpuInfo.instructionSets += "EIST ";
		if (cpuFeature.IntelFeature.TM2)
			hardwareData.cpuInfo.instructionSets += "TM2 ";
		if (cpuFeature.IntelFeature.SSSE3)
			hardwareData.cpuInfo.instructionSets += "SSSE3 ";
		if (cpuFeature.IntelFeature.CNXT_ID)
			hardwareData.cpuInfo.instructionSets += "CNXT_ID ";
		if (cpuFeature.IntelFeature.SDBG)
			hardwareData.cpuInfo.instructionSets += "SDBG ";
		if (cpuFeature.IntelFeature.FMA)
			hardwareData.cpuInfo.instructionSets += "FMA ";
		if (cpuFeature.IntelFeature.CMPXCHG16B)
			hardwareData.cpuInfo.instructionSets += "CMPXCHG16B ";
		if (cpuFeature.IntelFeature.xTPR_Update_Control)
			hardwareData.cpuInfo.instructionSets += "xTPR_Update_Control ";
		if (cpuFeature.IntelFeature.PDCM)
			hardwareData.cpuInfo.instructionSets += "PDCM ";
		if (cpuFeature.IntelFeature.PCID)
			hardwareData.cpuInfo.instructionSets += "PCID ";
		if (cpuFeature.IntelFeature.DCA)
			hardwareData.cpuInfo.instructionSets += "DCA ";
		if (cpuFeature.IntelFeature.SSE4_1)
			hardwareData.cpuInfo.instructionSets += "SSE4_1 ";
		if (cpuFeature.IntelFeature.SSE4_2)
			hardwareData.cpuInfo.instructionSets += "SSE4_2 ";
		if (cpuFeature.IntelFeature.x2APIC)
			hardwareData.cpuInfo.instructionSets += "x2APIC ";
		if (cpuFeature.IntelFeature.MOVBE)
			hardwareData.cpuInfo.instructionSets += "MOVBE ";
		if (cpuFeature.IntelFeature.POPCNT)
			hardwareData.cpuInfo.instructionSets += "POPCNT ";
		if (cpuFeature.IntelFeature.TSC_Deadline)
			hardwareData.cpuInfo.instructionSets += "TSC_Deadline ";
		if (cpuFeature.IntelFeature.AESNI)
			hardwareData.cpuInfo.instructionSets += "AESNI ";
		if (cpuFeature.IntelFeature.XSAVE)
			hardwareData.cpuInfo.instructionSets += "XSAVE ";
		if (cpuFeature.IntelFeature.OSXSAVE)
			hardwareData.cpuInfo.instructionSets += "OSXSAVE ";
		if (cpuFeature.IntelFeature.AVX)
			hardwareData.cpuInfo.instructionSets += "AVX ";
		if (cpuFeature.IntelFeature.F16C)
			hardwareData.cpuInfo.instructionSets += "F16C ";
		if (cpuFeature.IntelFeature.RDRAND)
			hardwareData.cpuInfo.instructionSets += "RDRAND";
	}
	else if (hardwareData.cpuInfo.manufacture.find("AMD") != string::npos)
	{
	}
	else if (hardwareData.cpuInfo.manufacture.find("ZHAOXIN") != string::npos)
	{
	}
	else
	{
		hardwareData.cpuInfo.instructionSets = "unknown CPU";
	}
	auto cache = CPU::GetCache();
	//recode
	for (unsigned int i = 0; i<4; i++)
	{
		Cache_info cache_temp = *(cache + i);
		if (cache_temp.Cache_level == 1)
		{
			if (cache_temp.Cache_type == 'D')
			{
				Cache cacheTemp;
				cacheTemp.level = cache_temp.Cache_level;
				cacheTemp.size = cache_temp.Cache_Size / 1024;
				cacheTemp.way = cache_temp.Cache_Ways;
				cacheTemp.partition = cache_temp.Cache_partitions;
				cacheTemp.set = cache_temp.Cache_Set;
				cacheTemp.lineSize = cache_temp.Cache_line_size;
				cacheTemp.type = cache_temp.Cache_type;
				hardwareData.cpuInfo.cache.push_back(cacheTemp);
			}
			else if (cache_temp.Cache_type == 'T')
			{
				Cache cacheTemp;
				cacheTemp.level = cache_temp.Cache_level;
				cacheTemp.size = cache_temp.Cache_Size / 1024;
				cacheTemp.way = cache_temp.Cache_Ways;
				cacheTemp.partition = cache_temp.Cache_partitions;
				cacheTemp.set = cache_temp.Cache_Set;
				cacheTemp.lineSize = cache_temp.Cache_line_size;
				cacheTemp.type = cache_temp.Cache_type;
				hardwareData.cpuInfo.cache.push_back(cacheTemp);
			}
		}
		else if (cache_temp.Cache_level == 2)
		{
			Cache cacheTemp;
			cacheTemp.level = cache_temp.Cache_level;
			cacheTemp.size = cache_temp.Cache_Size / 1024;
			cacheTemp.way = cache_temp.Cache_Ways;
			cacheTemp.partition = cache_temp.Cache_partitions;
			cacheTemp.set = cache_temp.Cache_Set;
			cacheTemp.lineSize = cache_temp.Cache_line_size;
			cacheTemp.type = cache_temp.Cache_type;
			hardwareData.cpuInfo.cache.push_back(cacheTemp);
		}
		else if (cache_temp.Cache_level == 3)
		{
			Cache cacheTemp;
			cacheTemp.level = cache_temp.Cache_level;
			cacheTemp.size = cache_temp.Cache_Size / 1024;
			cacheTemp.way = cache_temp.Cache_Ways;
			cacheTemp.partition = cache_temp.Cache_partitions;
			cacheTemp.set = cache_temp.Cache_Set;
			cacheTemp.lineSize = cache_temp.Cache_line_size;
			cacheTemp.type = cache_temp.Cache_type;
			hardwareData.cpuInfo.cache.push_back(cacheTemp);
		}
	}

	hardwareData.cpuInfo.southbridgeName = CPU::GetSouthbridgeName();
	hardwareData.cpuInfo.codeName = CPU::GetCodeName();
	hardwareData.cpuInfo.technology = CPU::GetTechnology();
	hardwareData.cpuInfo.maxTDP = CPU::GetMaxTDP();
	hardwareData.cpuInfo.temperature = CPU::GetTemperature();
	hardwareData.cpuInfo.packageTemperature = CPU::GetPackageTemperature();

	//dimm
	auto dimmRaw = Memory::GetMemoryGlobalInfomation();
	for (auto i : dimmRaw)
	{
		Memory_Information memtemp;
		memtemp.slot = i.first;
		memtemp.dramManufacture = i.second.DRAMManufacturer;
		memtemp.moduleManufacture = i.second.ModuleManufacturer;
		memtemp.moduleSize = i.second.ModuleSize;
		memtemp.modulType = i.second.ModuleType;
		memtemp.partNum = i.second.PartNumber;
		memtemp.productDate = i.second.ProductDate;
		memtemp.serialNum = i.second.SerialNumber;
		hardwareData.dimmInfo.push_back(memtemp);
	}
	//gpu
	GPU::UpdateDate();
	auto gpuRaw = GPU::GetGpuInfo();

	for (auto i = gpuRaw.begin(); i<gpuRaw.end(); i++)
	{
		GPU_Information temp;
		temp.gpuName = i->GetGPUName();
		temp.gpuBIOSVersion = i->GetGPUBiosVersion();
		temp.gpuDriverVersion = i->GetGPUDriverVersion();
		temp.gpuBranchVersion = i->GetGPUBranchVersion();
		temp.temperature = i->GetTemperature();
		temp.gpuClock = i->GetGPUClock();
		temp.gpuMemoryClock = i->GetGPUMemoryClock();
		temp.usage = i->GetGPUusage();
		temp.fans = i->GetGPUfans();
		temp.dedicatedVideoMemory = i->GetdedicatedVideoMemory();
		temp.systemVideoMemory = i->GetsystemVideoMemory();
		temp.sharedSystemMemory = i->GetsharedSystemMemory();
		hardwareData.gpuInfo.push_back(temp);
	}
	//monitor
	Display::UpdateData();
	hardwareData.monitorInfo.push_back(Display::GetMonitorName());
	//disk
	auto diskRaw = Storage::GetDiskSMARTInfo();
	for (auto i : diskRaw)
	{
		Disk_Information temp;
		temp.BufferSize = i.BufferSize;
		temp.CurrentTransferMode = i.CurrentTransferMode;
		temp.DeviceNominalFormFactor = i.DeviceNominalFormFactor;
		temp.DiskState = i.DiskState;
		temp.Enclosure = i.Enclosure;
		temp.Feature = i.Feature;
		temp.FirmwareRev = i.FirmwareRev;
		temp.GBytesErased = i.GBytesErased;
		temp.HostReads = i.HostReads;
		temp.Interface = i.Interface;
		temp.IsSsd = i.IsSsd;
		temp.LogicalDrive = i.LogicalDrive;
		temp.MajorVersion = i.MajorVersion;
		temp.MaxTransferMode = i.MaxTransferMode;
		temp.MinorVersion = i.MinorVersion;
		temp.Model = i.Model;
		temp.NandWrites = i.NandWrites;
		temp.NominalMediaRotationRate = i.NominalMediaRotationRate;
		temp.NvCacheSize = i.NvCacheSize;
		QString string = QString::fromStdWString(i.LogicalDrive);
		QRegExp regexp("[A-Z]");
		for (auto j : string)
		{
			if (regexp.exactMatch(j))
				hardwareData.drive.push_back(j);
		}
		temp.PowerOnCount = i.PowerOnCount;
		temp.PowerOnHours = i.PowerOnHours;
		temp.SerialNumber = i.SerialNumber;
		temp.Temperature = i.Temperature;
		temp.TotalDiskSize = i.TotalDiskSize;
		hardwareData.diskInfo.push_back(temp);
	}
	//pci
	auto pciRaw = Ring0::GetAllPciInfo();
	ULONG bus, dev, fun;
	for (auto &i : pciRaw.pciconfig)
	{
		PCI_Information temp;
		Ring0::PCIstringToBDF(i.first, bus, dev, fun);
		temp.bus = bus;
		temp.dev = dev;
		temp.fun = fun;
		temp.vendorID = i.second.VendorID;
		temp.deviceID = i.second.DeviceID;
		temp.command = i.second.Command;
		temp.status = i.second.Status;
		temp.cachelineSize = i.second.CacheLineSize;
		temp.latencyTimer = i.second.LatencyTimer;
		temp.revisionID = i.second.RevisionID;
		temp.interruptPin = i.second.u.type0.InterruptPin;
		temp.interruptLine = i.second.u.type0.InterruptLine;
		temp.baseclass = i.second.BaseClass;
		temp.subclass = i.second.SubClass;
		hardwareData.pciInfo.push_back(temp);
	}
	//net
	auto netData = Net::GetData();
	for (auto &i : netData)
	{
		Net_Information temp;
		temp.name = i.Name;
		temp.deviceName = i.DeviceName;
		temp.mediaType = i.MediaType;
		temp.state = i.state;
		hardwareData.netInfo.push_back(temp);
	}
	//audio
	AUDIO::UpdateData();
	auto audioData = AUDIO::GetOutputAudio();
	for (auto &i : audioData)
	{
		Audio_Information temp;
		temp.id = i.id;
		temp.state = i.state;
		temp.name = i.name;
		temp.desc = i.desc;
		temp.audioif = i.audioif;
		hardwareData.audioInfo.push_back(temp);
	}
	//mouse
	//keyboard	
	softwareData = {};
	std::list<Service_Struct> serviceRaw;
	Software::EnumService(serviceRaw);
	for (auto i : serviceRaw)
	{
		Service_Information temp;
		temp.name = QString::fromStdWString(i.ServiceName);
		temp.disName = QString::fromStdWString(i.ServiceDisplayName);
		temp.path = QString::fromStdWString(i.ServicePath);
		temp.description = QString::fromStdWString(i.descripton);
		switch (i.CurrentStatus)
		{
		case SV_SERVICE_STATUS::CONTINUE_PENDING:
		{
			temp.status = "continue pending";
			break;
		}
		case SV_SERVICE_STATUS::PAUSED:
		{
			temp.status = "continue pending";
			break;
		}
		case SV_SERVICE_STATUS::PAUSE_PENDING:
		{
			temp.status = "pause pending";
			break;
		}
		case SV_SERVICE_STATUS::RUNNING:
		{
			temp.status = "running";
			break;
		}
		case SV_SERVICE_STATUS::SERVICE_UNKNOWN:
		{
			temp.status = "service unknown";
			break;
		}
		case SV_SERVICE_STATUS::START_PENDING:
		{
			temp.status = "start pending";
			break;
		}
		case SV_SERVICE_STATUS::STOPPED:
		{
			temp.status = "stopped";
			break;
		}
		default:
		{
			temp.status = "unknown";
			break;
		}
		}
		softwareData.serviceInfo.push_back(temp);
	}
	std::vector<RegKeyDetail> autolistRaw;
	Software::AutoList(autolistRaw);
	for (auto i : autolistRaw)
	{
		Auto_Information temp;
		temp.type = QString::fromStdWString(i.Type);
		temp.name = QString::fromStdWString(i.sRegKeyName);
		temp.data = QString::fromStdWString(i.sRegKeyData);
		softwareData.autolist.push_back(temp);
	}
	std::list<TaskScheduler_Struct> folderTaskRaw;
	Software::EnumFolderTaskScheduler(folderTaskRaw);
	for (auto i : folderTaskRaw)
	{
		Task_Information temp;
		temp.name = QString::fromStdWString(i.TaskName);
		switch (i.taskstate)
		{
		case TASK_STATE::TASK_STATE_DISABLED:
		{
			temp.state = "disabled";
			break;
		}
		case TASK_STATE::TASK_STATE_QUEUED:
		{
			temp.state = "queued";
			break;
		}
		case TASK_STATE::TASK_STATE_READY:
		{
			temp.state = "ready";
			break;
		}
		case TASK_STATE::TASK_STATE_RUNNING:
		{
			temp.state = "runnint";
			break;
		}
		case TASK_STATE::TASK_STATE_UNKNOWN:
		{
			temp.state = "state unknown";
			break;
		}
		default:
		{
			temp.state = "unknown";
			break;
		}
		}
		softwareData.folderTask.push_back(temp);
	}
	std::list<TaskScheduler_Struct> runningTaskRaw;
	Software::EnumRuningTaskScheduler(runningTaskRaw);
	for (auto i : runningTaskRaw)
	{
		Task_Information temp;
		temp.name = QString::fromStdWString(i.TaskName);
		switch (i.taskstate)
		{
		case TASK_STATE::TASK_STATE_DISABLED:
		{
			temp.state = "disabled";
			break;
		}
		case TASK_STATE::TASK_STATE_QUEUED:
		{
			temp.state = "queued";
			break;
		}
		case TASK_STATE::TASK_STATE_READY:
		{
			temp.state = "ready";
			break;
		}
		case TASK_STATE::TASK_STATE_RUNNING:
		{
			temp.state = "runnint";
			break;
		}
		case TASK_STATE::TASK_STATE_UNKNOWN:
		{
			temp.state = "state unknown";
			break;
		}
		default:
		{
			temp.state = "unknown";
			break;
		}
		}
		softwareData.runningTask.push_back(temp);
	}
	std::vector<ConnInfo> tcpRaw;
	Software::GetTcpConnect(tcpRaw);
	for (auto i : tcpRaw)
	{
		Connection_Information temp;
		temp.uPro = QString(QChar(i.uPro));
		temp.localIP = QString::fromStdString(i.dwLocalIp);
		temp.remoteIP = QString::fromStdString(i.dwRemoteIp);
		temp.PID = QString("%0").arg(i.nPId);
		temp.localPort = QString("%0").arg(i.nLocalPort);
		temp.remotePort = QString("%0").arg(i.nRemotePort);
		temp.state = QString::fromStdWString(i.uState);
		temp.strPath = QString::fromStdWString(i.strPath);
		softwareData.tcp.push_back(temp);
	}
	std::vector<ConnInfo> udpRaw;
	Software::GetUdpConnect(udpRaw);
	for (auto i : udpRaw)
	{
		Connection_Information temp;
		temp.uPro = QString(QChar(i.uPro));
		temp.localIP = QString::fromStdString(i.dwLocalIp);
		temp.remoteIP = QString::fromStdString(i.dwRemoteIp);
		temp.PID = QString("%0").arg(i.nPId);
		temp.localPort = QString("%0").arg(i.nLocalPort);
		temp.remotePort = QString("%0").arg(i.nRemotePort);
		temp.state = QString::fromStdWString(i.uState);
		temp.strPath = QString::fromStdWString(i.strPath);
		softwareData.udp.push_back(temp);
	}
	
}
void GetData::updateHardware()
{

	hardwareData = {};
	//board
	auto smbiosRaw = DMI_SMBIOS::GetSMBIOSinfo();
	for (auto i : smbiosRaw.BaseBroadinfo)
	{
		TitleValue tvtemp;
		tvtemp.title = i.first;
		tvtemp.value = i.second;
		hardwareData.boardInfo.push_back(tvtemp);
	}
	//bios
	for (auto i : smbiosRaw.BIOSinfo)
	{
		TitleValue tvtemp;
		tvtemp.title = i.first;
		tvtemp.value = i.second;
		hardwareData.biosInfo.push_back(tvtemp);
	}
	for (auto i : smbiosRaw.BIOSLanginfo)
	{
		TitleValue tvtemp;
		tvtemp.title = i.first;
		tvtemp.value = i.second;
		hardwareData.biosInfo.push_back(tvtemp);
	}
	//chipset
	//cpu
	hardwareData.cpuInfo.cpuName = CPU::GetCPUName();
	hardwareData.cpuInfo.cpuSpecification = CPU::GetCPUSpecification();
	hardwareData.cpuInfo.processorID = CPU::GetProcessorID();
	hardwareData.cpuInfo.socketDescription = CPU::GetSocketDesignation();
	auto currentspeed = CPU::GetCurrentClockSpeed();
	hardwareData.cpuInfo.coreSpeed = currentspeed[0];
	hardwareData.cpuInfo.extSpeed = CPU::GetExtClock();
	hardwareData.cpuInfo.multiplier = hardwareData.cpuInfo.coreSpeed / hardwareData.cpuInfo.extSpeed;
	hardwareData.cpuInfo.maxSpeed = 0;
	hardwareData.cpuInfo.coreNum = CPU::GetCore();
	hardwareData.cpuInfo.threadNum = CPU::GetThread();
	hardwareData.cpuInfo.revision = CPU::GetRevision();
	hardwareData.cpuInfo.manufacture = CPU::GetManufacturer();
	hardwareData.cpuInfo.family = CPU::GetFamily();
	hardwareData.cpuInfo.model = CPU::GetModel();
	hardwareData.cpuInfo.stepping = CPU::GetStepping();
	hardwareData.cpuInfo.extFamily = CPU::GetExtFamily();
	hardwareData.cpuInfo.extModel = CPU::GetExtModel();
	CPUFeature cpuFeature = CPU::GetFeature();
	if (hardwareData.cpuInfo.manufacture.find("GenuineIntel") != string::npos)
	{
		if (cpuFeature.IntelFeature.SSE3)
			hardwareData.cpuInfo.instructionSets += "SSE3 ";
		if (cpuFeature.IntelFeature.PCLMULQDQ)
			hardwareData.cpuInfo.instructionSets += "PCLMULQDQ ";
		if (cpuFeature.IntelFeature.DTES64)
			hardwareData.cpuInfo.instructionSets += "DTES64 ";
		if (cpuFeature.IntelFeature.MONITOR)
			hardwareData.cpuInfo.instructionSets += "MONITOE ";
		if (cpuFeature.IntelFeature.DS_CPL)
			hardwareData.cpuInfo.instructionSets += "DS_CPL ";
		if (cpuFeature.IntelFeature.VMX)
			hardwareData.cpuInfo.instructionSets += "VMX ";
		if (cpuFeature.IntelFeature.SMX)
			hardwareData.cpuInfo.instructionSets += "SMX ";
		if (cpuFeature.IntelFeature.EIST)
			hardwareData.cpuInfo.instructionSets += "EIST ";
		if (cpuFeature.IntelFeature.TM2)
			hardwareData.cpuInfo.instructionSets += "TM2 ";
		if (cpuFeature.IntelFeature.SSSE3)
			hardwareData.cpuInfo.instructionSets += "SSSE3 ";
		if (cpuFeature.IntelFeature.CNXT_ID)
			hardwareData.cpuInfo.instructionSets += "CNXT_ID ";
		if (cpuFeature.IntelFeature.SDBG)
			hardwareData.cpuInfo.instructionSets += "SDBG ";
		if (cpuFeature.IntelFeature.FMA)
			hardwareData.cpuInfo.instructionSets += "FMA ";
		if (cpuFeature.IntelFeature.CMPXCHG16B)
			hardwareData.cpuInfo.instructionSets += "CMPXCHG16B ";
		if (cpuFeature.IntelFeature.xTPR_Update_Control)
			hardwareData.cpuInfo.instructionSets += "xTPR_Update_Control ";
		if (cpuFeature.IntelFeature.PDCM)
			hardwareData.cpuInfo.instructionSets += "PDCM ";
		if (cpuFeature.IntelFeature.PCID)
			hardwareData.cpuInfo.instructionSets += "PCID ";
		if (cpuFeature.IntelFeature.DCA)
			hardwareData.cpuInfo.instructionSets += "DCA ";
		if (cpuFeature.IntelFeature.SSE4_1)
			hardwareData.cpuInfo.instructionSets += "SSE4_1 ";
		if (cpuFeature.IntelFeature.SSE4_2)
			hardwareData.cpuInfo.instructionSets += "SSE4_2 ";
		if (cpuFeature.IntelFeature.x2APIC)
			hardwareData.cpuInfo.instructionSets += "x2APIC ";
		if (cpuFeature.IntelFeature.MOVBE)
			hardwareData.cpuInfo.instructionSets += "MOVBE ";
		if (cpuFeature.IntelFeature.POPCNT)
			hardwareData.cpuInfo.instructionSets += "POPCNT ";
		if (cpuFeature.IntelFeature.TSC_Deadline)
			hardwareData.cpuInfo.instructionSets += "TSC_Deadline ";
		if (cpuFeature.IntelFeature.AESNI)
			hardwareData.cpuInfo.instructionSets += "AESNI ";
		if (cpuFeature.IntelFeature.XSAVE)
			hardwareData.cpuInfo.instructionSets += "XSAVE ";
		if (cpuFeature.IntelFeature.OSXSAVE)
			hardwareData.cpuInfo.instructionSets += "OSXSAVE ";
		if (cpuFeature.IntelFeature.AVX)
			hardwareData.cpuInfo.instructionSets += "AVX ";
		if (cpuFeature.IntelFeature.F16C)
			hardwareData.cpuInfo.instructionSets += "F16C ";
		if (cpuFeature.IntelFeature.RDRAND)
			hardwareData.cpuInfo.instructionSets += "RDRAND";
	}
	else if (hardwareData.cpuInfo.manufacture.find("AMD") != string::npos)
	{
	}
	else if (hardwareData.cpuInfo.manufacture.find("ZHAOXIN") != string::npos)
	{
	}
	else
	{
		hardwareData.cpuInfo.instructionSets = "unknown CPU";
	}
	auto cache = CPU::GetCache();
	//recode
	for (unsigned int i = 0; i<4; i++)
	{
		Cache_info cache_temp = *(cache + i);
		if (cache_temp.Cache_level == 1)
		{
			if (cache_temp.Cache_type == 'D')
			{
				Cache cacheTemp;
				cacheTemp.level = cache_temp.Cache_level;
				cacheTemp.size = cache_temp.Cache_Size / 1024;
				cacheTemp.way = cache_temp.Cache_Ways;
				cacheTemp.partition = cache_temp.Cache_partitions;
				cacheTemp.set = cache_temp.Cache_Set;
				cacheTemp.lineSize = cache_temp.Cache_line_size;
				cacheTemp.type = cache_temp.Cache_type;
				hardwareData.cpuInfo.cache.push_back(cacheTemp);
			}
			else if (cache_temp.Cache_type == 'T')
			{
				Cache cacheTemp;
				cacheTemp.level = cache_temp.Cache_level;
				cacheTemp.size = cache_temp.Cache_Size / 1024;
				cacheTemp.way = cache_temp.Cache_Ways;
				cacheTemp.partition = cache_temp.Cache_partitions;
				cacheTemp.set = cache_temp.Cache_Set;
				cacheTemp.lineSize = cache_temp.Cache_line_size;
				cacheTemp.type = cache_temp.Cache_type;
				hardwareData.cpuInfo.cache.push_back(cacheTemp);
			}
		}
		else if (cache_temp.Cache_level == 2)
		{
			Cache cacheTemp;
			cacheTemp.level = cache_temp.Cache_level;
			cacheTemp.size = cache_temp.Cache_Size / 1024;
			cacheTemp.way = cache_temp.Cache_Ways;
			cacheTemp.partition = cache_temp.Cache_partitions;
			cacheTemp.set = cache_temp.Cache_Set;
			cacheTemp.lineSize = cache_temp.Cache_line_size;
			cacheTemp.type = cache_temp.Cache_type;
			hardwareData.cpuInfo.cache.push_back(cacheTemp);
		}
		else if (cache_temp.Cache_level == 3)
		{
			Cache cacheTemp;
			cacheTemp.level = cache_temp.Cache_level;
			cacheTemp.size = cache_temp.Cache_Size / 1024;
			cacheTemp.way = cache_temp.Cache_Ways;
			cacheTemp.partition = cache_temp.Cache_partitions;
			cacheTemp.set = cache_temp.Cache_Set;
			cacheTemp.lineSize = cache_temp.Cache_line_size;
			cacheTemp.type = cache_temp.Cache_type;
			hardwareData.cpuInfo.cache.push_back(cacheTemp);
		}
	}

	hardwareData.cpuInfo.southbridgeName = CPU::GetSouthbridgeName();
	hardwareData.cpuInfo.codeName = CPU::GetCodeName();
	hardwareData.cpuInfo.technology = CPU::GetTechnology();
	hardwareData.cpuInfo.maxTDP = CPU::GetMaxTDP();
	hardwareData.cpuInfo.temperature = CPU::GetTemperature();
	hardwareData.cpuInfo.packageTemperature = CPU::GetPackageTemperature();

	//dimm
	auto dimmRaw = Memory::GetMemoryGlobalInfomation();
	for (auto i : dimmRaw)
	{
		Memory_Information memtemp;
		memtemp.slot = i.first;
		memtemp.dramManufacture = i.second.DRAMManufacturer;
		memtemp.moduleManufacture = i.second.ModuleManufacturer;
		memtemp.moduleSize = i.second.ModuleSize;
		memtemp.modulType = i.second.ModuleType;
		memtemp.partNum = i.second.PartNumber;
		memtemp.productDate = i.second.ProductDate;
		memtemp.serialNum = i.second.SerialNumber;
		hardwareData.dimmInfo.push_back(memtemp);
	}
	//gpu
	GPU::UpdateDate();
	auto gpuRaw = GPU::GetGpuInfo();

	for (auto i = gpuRaw.begin(); i<gpuRaw.end(); i++)
	{
		GPU_Information temp;
		temp.gpuName = i->GetGPUName();
		temp.gpuBIOSVersion = i->GetGPUBiosVersion();
		temp.gpuDriverVersion = i->GetGPUDriverVersion();
		temp.gpuBranchVersion = i->GetGPUBranchVersion();
		temp.temperature = i->GetTemperature();
		temp.gpuClock = i->GetGPUClock();
		temp.gpuMemoryClock = i->GetGPUMemoryClock();
		temp.usage = i->GetGPUusage();
		temp.fans = i->GetGPUfans();
		temp.dedicatedVideoMemory = i->GetdedicatedVideoMemory();
		temp.systemVideoMemory = i->GetsystemVideoMemory();
		temp.sharedSystemMemory = i->GetsharedSystemMemory();
		hardwareData.gpuInfo.push_back(temp);
	}
	//monitor
	Display::UpdateData();
	hardwareData.monitorInfo.push_back(Display::GetMonitorName());
	//disk
	auto diskRaw = Storage::GetDiskSMARTInfo();
	for (auto i : diskRaw)
	{
		Disk_Information temp;
		temp.BufferSize = i.BufferSize;
		temp.CurrentTransferMode = i.CurrentTransferMode;
		temp.DeviceNominalFormFactor = i.DeviceNominalFormFactor;
		temp.DiskState = i.DiskState;
		temp.Enclosure = i.Enclosure;
		temp.Feature = i.Feature;
		temp.FirmwareRev = i.FirmwareRev;
		temp.GBytesErased = i.GBytesErased;
		temp.HostReads = i.HostReads;
		temp.Interface = i.Interface;
		temp.IsSsd = i.IsSsd;
		temp.LogicalDrive = i.LogicalDrive;
		temp.MajorVersion = i.MajorVersion;
		temp.MaxTransferMode = i.MaxTransferMode;
		temp.MinorVersion = i.MinorVersion;
		temp.Model = i.Model;
		temp.NandWrites = i.NandWrites;
		temp.NominalMediaRotationRate = i.NominalMediaRotationRate;
		temp.NvCacheSize = i.NvCacheSize;
		QString string = QString::fromStdWString(i.LogicalDrive);
		QRegExp regexp("[A-Z]");
		for (auto j : string)
		{
			if (regexp.exactMatch(j))
				hardwareData.drive.push_back(j);
		}
		temp.PowerOnCount = i.PowerOnCount;
		temp.PowerOnHours = i.PowerOnHours;
		temp.SerialNumber = i.SerialNumber;
		temp.Temperature = i.Temperature;
		temp.TotalDiskSize = i.TotalDiskSize;
		hardwareData.diskInfo.push_back(temp);
	}
	//pci
	auto pciRaw = Ring0::GetAllPciInfo();
	ULONG bus, dev, fun;
	for (auto &i : pciRaw.pciconfig)
	{
		PCI_Information temp;
		Ring0::PCIstringToBDF(i.first, bus, dev, fun);
		temp.bus = bus;
		temp.dev = dev;
		temp.fun = fun;
		temp.vendorID = i.second.VendorID;
		temp.deviceID = i.second.DeviceID;
		temp.command = i.second.Command;
		temp.status = i.second.Status;
		temp.cachelineSize = i.second.CacheLineSize;
		temp.latencyTimer = i.second.LatencyTimer;
		temp.revisionID = i.second.RevisionID;
		temp.interruptPin = i.second.u.type0.InterruptPin;
		temp.interruptLine = i.second.u.type0.InterruptLine;
		temp.baseclass = i.second.BaseClass;
		temp.subclass = i.second.SubClass;
		hardwareData.pciInfo.push_back(temp);
	}
	//net
	auto netData = Net::GetData();
	for (auto &i : netData)
	{
		Net_Information temp;
		temp.name = i.Name;
		temp.deviceName = i.DeviceName;
		temp.mediaType = i.MediaType;
		temp.state = i.state;
		hardwareData.netInfo.push_back(temp);
	}
	//audio
	AUDIO::UpdateData();
	auto audioData = AUDIO::GetOutputAudio();
	for (auto &i : audioData)
	{
		Audio_Information temp;
		temp.id = i.id;
		temp.state = i.state;
		temp.name = i.name;
		temp.desc = i.desc;
		temp.audioif = i.audioif;
		hardwareData.audioInfo.push_back(temp);
	}
	//mouse
	//keyboard	
	
}
void GetData::updateSoftware()
{
	
	softwareData = {};
	std::list<Service_Struct> serviceRaw;
	Software::EnumService(serviceRaw);
	for (auto i : serviceRaw)
	{
		Service_Information temp;
		temp.name = QString::fromStdWString(i.ServiceName);
		temp.disName = QString::fromStdWString(i.ServiceDisplayName);
		temp.path = QString::fromStdWString(i.ServicePath);
		temp.description = QString::fromStdWString(i.descripton);
		switch (i.CurrentStatus)
		{
		case SV_SERVICE_STATUS::CONTINUE_PENDING:
		{
			temp.status = "continue pending";
			break;
		}
		case SV_SERVICE_STATUS::PAUSED:
		{
			temp.status = "continue pending";
			break;
		}
		case SV_SERVICE_STATUS::PAUSE_PENDING:
		{
			temp.status = "pause pending";
			break;
		}
		case SV_SERVICE_STATUS::RUNNING:
		{
			temp.status = "running";
			break;
		}
		case SV_SERVICE_STATUS::SERVICE_UNKNOWN:
		{
			temp.status = "service unknown";
			break;
		}
		case SV_SERVICE_STATUS::START_PENDING:
		{
			temp.status = "start pending";
			break;
		}
		case SV_SERVICE_STATUS::STOPPED:
		{
			temp.status = "stopped";
			break;
		}
		default:
		{
			temp.status = "unknown";
			break;
		}
		}
		softwareData.serviceInfo.push_back(temp);
	}
	std::vector<RegKeyDetail> autolistRaw;
	Software::AutoList(autolistRaw);
	for (auto i : autolistRaw)
	{
		Auto_Information temp;
		temp.type = QString::fromStdWString(i.Type);
		temp.name = QString::fromStdWString(i.sRegKeyName);
		temp.data = QString::fromStdWString(i.sRegKeyData);
		softwareData.autolist.push_back(temp);
	}
	std::list<TaskScheduler_Struct> folderTaskRaw;
	Software::EnumFolderTaskScheduler(folderTaskRaw);
	for (auto i : folderTaskRaw)
	{
		Task_Information temp;
		temp.name = QString::fromStdWString(i.TaskName);
		switch (i.taskstate)
		{
		case TASK_STATE::TASK_STATE_DISABLED:
		{
			temp.state = "disabled";
			break;
		}
		case TASK_STATE::TASK_STATE_QUEUED:
		{
			temp.state = "queued";
			break;
		}
		case TASK_STATE::TASK_STATE_READY:
		{
			temp.state = "ready";
			break;
		}
		case TASK_STATE::TASK_STATE_RUNNING:
		{
			temp.state = "runnint";
			break;
		}
		case TASK_STATE::TASK_STATE_UNKNOWN:
		{
			temp.state = "state unknown";
			break;
		}
		default:
		{
			temp.state = "unknown";
			break;
		}
		}
		softwareData.folderTask.push_back(temp);
	}
	std::list<TaskScheduler_Struct> runningTaskRaw;
	Software::EnumRuningTaskScheduler(runningTaskRaw);
	for (auto i : runningTaskRaw)
	{
		Task_Information temp;
		temp.name = QString::fromStdWString(i.TaskName);
		switch (i.taskstate)
		{
		case TASK_STATE::TASK_STATE_DISABLED:
		{
			temp.state = "disabled";
			break;
		}
		case TASK_STATE::TASK_STATE_QUEUED:
		{
			temp.state = "queued";
			break;
		}
		case TASK_STATE::TASK_STATE_READY:
		{
			temp.state = "ready";
			break;
		}
		case TASK_STATE::TASK_STATE_RUNNING:
		{
			temp.state = "runnint";
			break;
		}
		case TASK_STATE::TASK_STATE_UNKNOWN:
		{
			temp.state = "state unknown";
			break;
		}
		default:
		{
			temp.state = "unknown";
			break;
		}
		}
		softwareData.runningTask.push_back(temp);
	}
	std::vector<ConnInfo> tcpRaw;
	Software::GetTcpConnect(tcpRaw);
	for (auto i : tcpRaw)
	{
		Connection_Information temp;
		temp.uPro = QString(QChar(i.uPro));
		temp.localIP = QString::fromStdString(i.dwLocalIp);
		temp.remoteIP = QString::fromStdString(i.dwRemoteIp);
		temp.PID = QString("%0").arg(i.nPId);
		temp.localPort = QString("%0").arg(i.nLocalPort);
		temp.remotePort = QString("%0").arg(i.nRemotePort);
		temp.state = QString::fromStdWString(i.uState);
		temp.strPath = QString::fromStdWString(i.strPath);
		softwareData.tcp.push_back(temp);
	}
	std::vector<ConnInfo> udpRaw;
	Software::GetUdpConnect(udpRaw);
	for (auto i : udpRaw)
	{
		Connection_Information temp;
		temp.uPro = QString(QChar(i.uPro));
		temp.localIP = QString::fromStdString(i.dwLocalIp);
		temp.remoteIP = QString::fromStdString(i.dwRemoteIp);
		temp.PID = QString("%0").arg(i.nPId);
		temp.localPort = QString("%0").arg(i.nLocalPort);
		temp.remotePort = QString("%0").arg(i.nRemotePort);
		temp.state = QString::fromStdWString(i.uState);
		temp.strPath = QString::fromStdWString(i.strPath);
		softwareData.udp.push_back(temp);
	}
	
}
void GetData::getHardwareGeneral(HardwareGeneral &x) const
{
	x.cpuName = CPU::GetCPUName();
	GPU::UpdateDate();
	auto gpu = GPU::GetGpuInfo();
	for (auto &i : gpu)
	{
		x.gpuName.push_back(i.GetGPUName());
	}
	auto board = DMI_SMBIOS::GetSMBIOSinfo();
	for (auto &i : board.BaseBroadinfo)
	{
		if (i.first == "BaseBroad Manufacturer")
			x.board += i.second + " ";
		else if (i.first == "BaseBroad Product")
			x.board += i.second + " ";
		else if (i.first == "BaseBroad Serial Number")
			x.board += i.second + " ";
		else if (i.first == "BaseBroad Version")
			x.board += i.second;
	}
	auto memory = Memory::GetMemoryGlobalInfomation();
	for (auto i : memory)
	{
		std::stringstream stream;
		stream << i.first;
		string result = "slot";
		result += stream.str() + "  "+i.second.ModuleManufacturer;
		x.memory.push_back(result);
	}
	auto disk = Storage::GetDiskSMARTInfo();
	for (auto i : disk)
	{
		wstring str = i.Model;
		str.push_back(' ');
		str += i.TotalDiskSize;
		str.push_back(' ');
		str.push_back('(');
		str += i.LogicalDrive;
		str.push_back(')');
		x.disk.push_back(str);
	}
}
void GetData::getCPU(CPU_Information* x) const
{
	
	x->cpuName = hardwareData.cpuInfo.cpuName;
	x->cpuSpecification = hardwareData.cpuInfo.cpuSpecification;
	x->processorID = hardwareData.cpuInfo.processorID;
	x->socketDescription = hardwareData.cpuInfo.socketDescription;
	auto currentspeed = CPU::GetCurrentClockSpeed();
	x->coreSpeed = hardwareData.cpuInfo.coreSpeed;
	x->extSpeed = hardwareData.cpuInfo.extSpeed;
	x->multiplier = x->coreSpeed / x->extSpeed;
	x->maxSpeed = 0;
	x->coreNum = hardwareData.cpuInfo.coreNum;
	x->threadNum = hardwareData.cpuInfo.threadNum;
	x->revision = hardwareData.cpuInfo.revision;
	x->manufacture = hardwareData.cpuInfo.manufacture;
	x->family = hardwareData.cpuInfo.family;
	x->model = hardwareData.cpuInfo.model;
	x->stepping = hardwareData.cpuInfo.stepping;
	x->extFamily = hardwareData.cpuInfo.extFamily;
	x->extModel = hardwareData.cpuInfo.extModel;
	x->instructionSets = hardwareData.cpuInfo.instructionSets;
	x->cache = hardwareData.cpuInfo.cache;
	x->southbridgeName = hardwareData.cpuInfo.southbridgeName;
	x->codeName = hardwareData.cpuInfo.codeName;
	x->technology = hardwareData.cpuInfo.technology;
	x->maxTDP = hardwareData.cpuInfo.maxTDP;
	x->temperature = hardwareData.cpuInfo.temperature;
	x->packageTemperature = hardwareData.cpuInfo.packageTemperature;
}
void GetData::getBoard(string& str) const
{
	for (auto &i : hardwareData.boardInfo)
	{
		str += i.title + ": " + i.value + "\r\n";
	}
}
void GetData::getBIOS(string &str) const
{
	//auto y = DMI_SMBIOS::GetSMBIOSinfo();
	for (auto i : hardwareData.biosInfo)
	{
		str += i.title +": "+ i.value + "\r\n";
	}
}
void GetData::getChipset() const
{

}
void GetData::getMemory(vector<Memory_Information> &x) const
{
	x = hardwareData.dimmInfo;
}
void GetData::getSMBIOS(vector<SMBIOS_Information> &x) const
{
	auto smbiosData = DMI_SMBIOS::GetSMBIOSinfo();
	SMBIOS_Information temp;
	if (smbiosData.BIOSinfo.begin() != smbiosData.BIOSinfo.end())
	{
		temp.title = "BIOS Information";
		for (auto &i : smbiosData.BIOSinfo)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
	}
	if (smbiosData.System_Reset.begin() != smbiosData.System_Reset.end())
	{
		temp.title = "System Reset Information";
		for (auto &i : smbiosData.System_Reset)
		{
			temp.value = QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.Portable_Battery.begin() != smbiosData.Portable_Battery.end())
	{
		temp.title = "Portable Battery Information";
		for (auto &i : smbiosData.Portable_Battery)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
	}
	if (smbiosData.Pointing_Dev.begin() != smbiosData.Pointing_Dev.end())
	{
		temp.title = "Pointing Device Information";
		for (auto &i : smbiosData.Pointing_Dev)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.GroupAssociations.begin() != smbiosData.GroupAssociations.end())
	{
		temp.title = "Group Associations Information";
		for (auto &i : smbiosData.GroupAssociations)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.System_Power_Controls.begin() != smbiosData.System_Power_Controls.end())
	{
		temp.title = "System Power Controls Information";
		for (auto &i : smbiosData.System_Power_Controls)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.BroadDevinfo.begin() != smbiosData.BroadDevinfo.end())
	{
		temp.title = "Board Device Information";
		for (auto &i : smbiosData.BroadDevinfo)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.SystemEorC.begin() != smbiosData.SystemEorC.end())
	{
		temp.title = "System Enclosure or Chassis Information";
		for (auto &i : smbiosData.SystemEorC)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.SystemConfigOption.begin() != smbiosData.SystemConfigOption.end())
	{
		temp.title = "System Config Option Information";
		for (auto &i : smbiosData.SystemConfigOption)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.Processorinfo.begin() != smbiosData.Processorinfo.end())
	{
		temp.title = "Processor Information";
		for (auto &i : smbiosData.Processorinfo)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.MemoryModinfo.begin() != smbiosData.MemoryModinfo.end())
	{
		temp.title = "Memory Mode Information";
		for (auto &i : smbiosData.MemoryModinfo)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.Hardware_Security.begin() != smbiosData.Hardware_Security.end())
	{
		temp.title = "Hardware Security Information";
		for (auto &i : smbiosData.Hardware_Security)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.MemoryCtrlinfo.begin() != smbiosData.MemoryCtrlinfo.end())
	{
		temp.title = "Memory Control Information";
		for (auto &i : smbiosData.MemoryCtrlinfo)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.BaseBroadinfo.begin() != smbiosData.BaseBroadinfo.end())
	{
		temp.title = "Base Board Information";
		for (auto &i : smbiosData.BaseBroadinfo)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.SystemEorC.begin() != smbiosData.SystemEorC.end())
	{
		temp.title = "System EorC Information";
		for (auto &i : smbiosData.SystemEorC)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.Sysyteminfo.begin() != smbiosData.Sysyteminfo.end())
	{
		temp.title = "System Information";
		for (auto &i : smbiosData.Sysyteminfo)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.SysEventLog.begin() != smbiosData.SysEventLog.end())
	{
		temp.title = "System Event Log Information";
		for (auto &i : smbiosData.SysEventLog)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	
	
	
	for (auto &i : smbiosData.Cacheinfo)
	{
		int num = 1;
		temp.title = QString("Cache Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
		num++;
	}
	for (auto&i : smbiosData.Portinfo)
	{
		int num = 1;
		temp.title = QString("Port Connector Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
		num++;
	}
	for (auto&i : smbiosData.SystemSlotinfo)
	{
		int num = 1;
		temp.title = QString("System Slots Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
		num++;
	}
	for (auto&i : smbiosData.MemoryErrinfo)
	{
		int num = 1;
		temp.title = QString("Memory Error Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
		num++;
	}
	for (auto&i : smbiosData.MemArrayMappedAddress)
	{
		
		int num = 1;
		temp.title = QString("Memory Array Mapped Address Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
		num++;
	}
	for (auto&i : smbiosData.MemDevMappedAddress)
	{
		int num = 1;
		temp.title = QString("Memory Device Mapped Address Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	if (smbiosData.OEMString.begin()!= smbiosData.OEMString.end())
	{
		temp.title = "OEM Strings Information";
		for (auto &i : smbiosData.OEMString)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	if (smbiosData.BIOSLanginfo.begin() != smbiosData.BIOSLanginfo.end())
	{
		temp.title = "BIOS Language Information";
		for (auto &i : smbiosData.BIOSLanginfo)
		{
			temp.value+= QString::fromStdString(i.first)+":  "+ QString::fromStdString(i.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		
	}
	
	for (auto&i : smbiosData.PhysicalMemoryArray)
	{
		int num = 1;
		temp.title = QString("Physical Memory Array Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first)+":"+QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}

	for (auto&i : smbiosData.MemoryDev)
	{
		int num = 1;
		temp.title = QString("Memory Device Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.PhysicalMemoryArray)
	{
		
		int num = 1;
		
		
		temp.title = QString("Memory Array Mapped Address Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.Voltage_Probe)
	{
		
		int num = 1;
		
		
		temp.title = QString("Voltage Probe Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.CoolingDev)
	{
		
		int num = 1;
		
		
		temp.title = QString("Cooling Device Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.TemperatureProbe)
	{
		
		int num = 1;
		
		
		temp.title = QString("Temperature Probe Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.BandRemoteAccess)
	{
		int num = 1;
		temp.title = QString("Band Remote Access Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.ElectricalCurrentProbe)
	{
		
		int num = 1;
		
		
		temp.title = QString("Electrical Current Probe Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.Systembootstatus)
	{
		int num = 1;
		temp.title = QString("System Boot Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.ManagementDevice)
	{
		int num = 1;
		temp.title = QString("Management Device Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.ManagementDeviceComponent)
	{
		
		int num = 1;
		
		
		temp.title = QString("Management Device Component Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.ManagementDeviceComponentThresholdData)
	{
		
		int num = 1;
		
		
		temp.title = QString("Management Device Component Threshold Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.IPMIDeviceinfo)
	{
		
		int num = 1;
		
		
		temp.title = QString("IPMI Device Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.MemoryChannel)
	{
		
		int num = 1;
		
		
		temp.title = QString("Memory Channel Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.MemoryError64Bit)
	{
		int num = 1;
		temp.title = QString("Memory Error 64bit Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.Additionalinfo)
	{
		int num = 1;
		temp.title = QString("Additional Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.SystemPowerSupply)
	{		
		int num = 1;
		temp.title = QString("System Power Supply Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.ManagementControllerHostInterface)
	{
		
		int num = 1;
		
		
		temp.title = QString("Management Controller Host Interface Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.BroadDevExtendedinfo)
	{
		
		int num = 1;
		
		
		temp.title = QString("On board Devices Extended Information #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.TPMDevice)
	{
		
		int num = 1;
		
		
		temp.title = QString("TPMDevice #%0").arg(num);
		for (auto &j : i)
		{
			temp.value = QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.Inactive)
	{
		
		int num = 1;
		
		
		temp.title = QString("Inactive #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
	for (auto&i : smbiosData.EndofTable)
	{
		int num = 1;
		temp.title = QString("End-of-Table #%0").arg(num);
		for (auto &j : i)
		{
			temp.value+= QString::fromStdString(j.first) + ":  " + QString::fromStdString(j.second) + "\r\n";
		}
		x.push_back(temp);
		temp.value.clear();
		num++;
	}
}
void GetData::getGPU(vector<GPU_Information> &x) const
{
	x = hardwareData.gpuInfo;
}
void GetData::getMonitor(string& str) const
{
	str = hardwareData.monitorInfo[0];
}
bool GetData::getEDID(QString &s) const
{
	Display::outputfile();
	QString currentdir = qApp->applicationDirPath();
	currentdir.append("\\HardWare\\EDID");
	QDir dir(currentdir);
	if (!dir.exists())
	{
		dir.mkpath(currentdir);//创建多级目录
	}

	QFile file(currentdir + "\\edid1.txt");
	if (file.open(QFile::ReadOnly | QFile::Text))
	{
		QTextStream in(&file);
		while (in.atEnd() == 0)
		{
			s = in.readAll();
		}
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}
void GetData::getStorage(vector<Disk_Information> &x) const
{
	x = hardwareData.diskInfo;
}
void GetData::getLogicalDrives(QStringList &s) const
{
	for (auto it : hardwareData.drive)
	{
		s << it;
	}
}
void GetData::getUSB(vector<USB_Tree> &x) const
{
	/*
	QString title, value = "default";
	USB_Tree temp;
	auto usbData = USB::GetAllUsbinfo();
	unsigned int num = 0;
	for (auto &i : usbData)
	{
		title = QString::fromStdWString(i.UsbRootHubInfo.UsbDeviceProperties.DeviceId);
		title.replace("\\", "_");
		temp.title = title;
		temp.value = value;
		temp.type = USB_Tree::root;
		x.push_back(temp);
		for (auto& j : i.UsbDeviceInfo.UsbHubInfo)
		{
			for (auto& p : j.UsbExternalHubInfo)
			{
				title = QString::fromStdWString(p.HubName).replace("\\", "_");
				temp.title = title;
				temp.value = value;
				temp.type = USB_Tree::hub;
				x.push_back(temp);
			}
		}
	}
	*/
	
}
void GetData::getAudio(vector<Audio_Information> &x) const
{
	x = hardwareData.audioInfo;
}
void GetData::getACPI() const
{

}
void GetData::getNet(vector<Net_Information> &x) const
{
	x = hardwareData.netInfo;
}
void GetData::getPCI(vector<PCI_Information> &x) const
{
	for (auto i : hardwareData.pciInfo)
		x.push_back(i);
}
bool GetData::getPCIconfig(const unsigned int bus, const unsigned int dev, const unsigned int fun, int x[])
{
	ULONG mbus = bus, mdev = dev, mfun = fun;
	ULONG addr = 0x80000000+(mbus<<16)+(mdev<<11)+(mfun<<8);
	DWORD output;
	for (unsigned int i = 0; i < 64; i++)
	{
		if (Ring0::WrIOPort(0xcf8, 4, addr))
			if (Ring0::RdIOPort(0xcfc, 4, output))
			{
				for (unsigned int j = 0; j < 4; j++)
				{
					x[i * 4 + j] = output & 0xff;
					output = output >> 8;
					addr++;
				}
			}
			else
				return false;
		else
			return false;
	}
}
void GetData::getPCIdescription(const unsigned int bus,const unsigned int dev,const unsigned int fun,QString &s)
{
	for (auto i : hardwareData.pciInfo)
	{
		if (i.bus == bus && i.dev == dev && i.fun == fun)
		{
			s += "Device/Vendor ID:" + QString("0x%0%1").arg(i.deviceID, 0, 16).arg(i.vendorID, 0, 16)+"\r\n";
			s += "Revision ID:" + QString("0x%0").arg(i.revisionID, 0, 16) + "\r\n";
			s += "Class Code:" + QString("0x%0%1").arg(i.baseclass, 0, 16).arg(i.subclass,0,16) + "\r\n";
			s += "Cacheline Size:" + QString("0x%0").arg(i.cachelineSize, 0, 16) + "\r\n";
			s += "Latency Timer:" + QString("0x%0").arg(i.latencyTimer, 0, 16) + "\r\n";
			s += "Interrupt Pin:" + QString("INT%0").arg(i.interruptPin, 0, 16) + "\r\n";
			s += "Interrupt Line:" + QString("IRQ%0").arg(i.interruptLine, 0, 16) + "\r\n";                      
			//s+="BAR"
		}
	}
}
bool GetData::writePCIconfig(const unsigned int bus, const unsigned int dev, const unsigned int fun, const unsigned int index, const unsigned int data)
{
	ULONG mbus = bus, mdev = dev, mfun = fun;
	ULONG addr = 0x80000000 + (mbus << 16) + (mdev << 11) + (mfun << 8) + index;
	DWORD output = data,confirm = 0;

	if (Ring0::WrIOPort(0xcf8, 4, addr))
		if (Ring0::RdIOPort(0xcfc, 4, output))
		{
			if (index / 4 == 0)
				output = output & (data | 0xffffff00);
			if (index / 4 == 1)
				output = output&(data | 0xffff00ff);
			if (index / 4 == 2)
				output = output & (data | 0xff00ffff);
			if (index / 4 == 3)
				output = output & (data | 0x00ffffff);
			if (Ring0::WrIOPort(0xcf8, 4, addr))
				if (Ring0::WrIOPort(0xcfc, 4, output))
					if (Ring0::WrIOPort(0xcf8, 4, addr))
						if (Ring0::WrIOPort(0xcfc, 4, confirm))
							if (output == confirm)
								return true;
							else
								return false;
						else
							return false;
					else
						return false;					
				else
					return false;
			else
				return false;
		}
		else
			return false;
	else
		return false;
}
void GetData::readCPUID(long long &eax, long long &ebx, long long& ecx, long long& edx)
{
	int output[4] = {0,0,0,0};
	__cpuidex(output, eax,ecx);
	eax = output[0];
	ebx = output[1];
	ecx = output[2];
	edx = output[3];
}
bool GetData::readMsrTx(const int &ecx,const int &cpu,int &eax,int &edx)
{
	DWORD input = ecx;
	DWORD64 output = 0;
	if (!Ring0::RdMsrTx(ecx, output, cpu))
		return false;
	else
	{
		eax = output & 0xffffffff;
		edx = (output >> 32) & 0xffffffff;
	}
}
bool GetData::writeMsrTx(const int &ecx, const int cpu,const int &eax, const int &edx)
{
	DWORD index = ecx;
	DWORD input = edx;
	input = eax | (input << 32);
	if (!Ring0::WrMsrTx(index, input, cpu))
		return false;
	DWORD64 output;
	Ring0::RdMsrTx(index, output, cpu);
	if ((output & 0xffffffff == eax) && ((output >> 32) & 0xffffffff == edx))
		return true;
	else
		return false;
}
bool GetData::readIO(unsigned int &addr,unsigned int &data)
{
	DWORD output = 0;
	if (Ring0::RdIOPort(addr, 1, output))
	{
		data = output;
		return true;
	}
	else
		return false;
}
int GetData::writeIO(unsigned int &addr, unsigned int &data)
{
	if (!Ring0::WrIOPort(addr, 1, data))
		return 0;//write fail
	else
	{
		DWORD output = 0;
		if (Ring0::RdIOPort(addr, 1, output))
			if (output == data)
				return 1;//success
			else
				return 2;//not equal
		else
			return 3;//read fail
	}
}
bool GetData::readMemory(const unsigned int &addr, unsigned int &data)
{
	LONGLONG maddr = addr;
	ULONG mdata = data;
	if (Ring0::RdMemory(maddr, 1, mdata))
	{
		data = mdata;
		return true;
	}
	else
		return false;
}
int GetData::writeMemory(const unsigned int &addr, const unsigned int &data)
{
	LONGLONG maddr = addr;
	ULONG mdata = data,output = 0;
	if (Ring0::WrMemory(maddr, 1, mdata))
	{
		if (Ring0::RdMemory(maddr, 1, output))
			if (output == mdata)
				return 1;//success
			else
				return 2;//not equal
		else
			return 3;//read fail
	}
	else
		return 0;//write fail
}
void GetData::getService(vector<Service_Information> &x)
{
	x = softwareData.serviceInfo;
}
void GetData::getAutoList(vector<Auto_Information> &x)
{
	x = softwareData.autolist;
}
void GetData::getFolderTask(vector<Task_Information> &x)
{
	x = softwareData.folderTask;
}
void GetData::getRunningTask(vector<Task_Information> &x)
{
	x = softwareData.runningTask;
}
void GetData::getTCP(vector<Connection_Information> &x)
{
	x = softwareData.tcp;
}
void GetData::getUDP(vector<Connection_Information> &x)
{
	x = softwareData.udp;
}
void GetData::outputHardwareReportSpecific(QTextStream &out) const
{
	QDateTime time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "CPU"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(100) << left << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "CPU Name:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.cpuName)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "CPU Core:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.coreNum)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "CPU Threads:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.threadNum)
		<< qSetFieldWidth(0) << "\r\n";

	for (auto i : hardwareData.cpuInfo.cache)
	{
		if (i.level == 1)
		{
			out << qSetFieldWidth(100) << left << QString("%0%1 size:%2KB %3way %4linesize").arg(i.type).arg(i.level).arg(i.size).arg(i.way).arg(i.lineSize)
				<< qSetFieldWidth(0) << "\r\n";
		}
		if (i.level == 2)
		{
			out << qSetFieldWidth(100) << left << QString("%0%1 size:%2MB %3way %4linesize").arg(i.type).arg(i.level).arg(i.size).arg(i.way).arg(i.lineSize)
				<< qSetFieldWidth(0) << "\r\n";
		}
		if (i.level == 3)
		{
			out << qSetFieldWidth(100) << left << QString("%0%1 size:%2MB %3way %4linesize").arg(i.type).arg(i.level).arg(i.size).arg(i.way).arg(i.lineSize)
				<< qSetFieldWidth(0) << "\r\n";
		}

	}
	out << qSetFieldWidth(20) << left << "Package Temperature:"
		<< qSetFieldWidth(30) << QString("%0").arg(hardwareData.cpuInfo.packageTemperature)
		<< qSetFieldWidth(0) << "\r\n";
	unsigned int num = 0;
	for (auto i : hardwareData.cpuInfo.temperature)
	{
		num++;
		out << qSetFieldWidth(100) << left << QString("Core%0 Temperature:%1").arg(num).arg(i)
			<< qSetFieldWidth(0) << "\r\n";
	}
	out << qSetFieldWidth(20) << "CPU SocketDesignation:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.socketDescription)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Southbridge Name:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.southbridgeName)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "CPU Manufacture:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.manufacture)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Code Name:" << qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.codeName)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "CPU Specification:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.cpuSpecification)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Family:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.family)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Model:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.model)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Stepping:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.stepping)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "ExtFamily:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.extFamily)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "ExtModel:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.extModel)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Revision:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.revision)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Technology:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.technology)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "InstructionSet:"
		<< qSetFieldWidth(80) << left << QString::fromStdString(hardwareData.cpuInfo.instructionSets)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Core Speed:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.coreSpeed)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Ext Speed:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.extSpeed)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Multiplier:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.multiplier)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Processor ID:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.processorID)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Max TDP:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.maxTDP)
		<< qSetFieldWidth(0) << "\r\n";


	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Memory"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Dimm Num:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.dimmNum)
		<< qSetFieldWidth(0) << "\r\n\r\n";
	for (auto i : hardwareData.dimmInfo)
	{
		out << qSetFieldWidth(20) << left << "Slot:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.slot)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Module Type:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.modulType)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Module Size:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.moduleSize)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Module Manufacture:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.moduleManufacture)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "DRAM Manufacture:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.dramManufacture)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Part Num:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.partNum)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Serial Num:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.serialNum)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Product Date:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.productDate)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "GFX"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0) << "\r\n";

	for (auto i : hardwareData.gpuInfo)
	{
		out << qSetFieldWidth(30) << left << "GPU Name:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.gpuName)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GPU BIOS Version:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.gpuBIOSVersion)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GPU Driver Version:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.gpuDriverVersion)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GPU Branch Version:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.gpuBranchVersion)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Temperature:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.temperature)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GPU Clock:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.gpuClock)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GPU Memory:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.gpuMemoryClock)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Usage:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.usage)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Fans:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.fans)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Dedicated Video Memory:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.dedicatedVideoMemory)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "System Video Memory:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.systemVideoMemory)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Shared System Memory:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.sharedSystemMemory)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Monitor"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0) << "\r\n";
	for (auto i : hardwareData.monitorInfo)
	{
		out << qSetFieldWidth(20) << left << "Name:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Disk"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0) << "\r\n";

	for (auto i : hardwareData.diskInfo)
	{
		out << qSetFieldWidth(30) << left << "Nominal Media Rotation Rate:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.NominalMediaRotationRate)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Buffer Size:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.BufferSize)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Nv Cache Size:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.NvCacheSize)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Logical Drive:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.LogicalDrive)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Power On Count:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.PowerOnCount)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Temperature:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.Temperature)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Host Writes:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.HostWrites)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Host Reads:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.HostReads)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GBytesErased:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.GBytesErased)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Nand Writes:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.NandWrites)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Power On Hours:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.PowerOnHours)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Total Disk Size:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.TotalDiskSize)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Serial Number:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.SerialNumber)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Firmware Rev:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.FirmwareRev)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Model:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.Model)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Max Transfer Mode:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.MaxTransferMode)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Current Transfer Mode:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.CurrentTransferMode)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Major Version:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.MajorVersion)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Minor Version:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.MinorVersion)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Interface:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.Interface)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Enclosure:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.Enclosure)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Device Nominal Form Factor:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.DeviceNominalFormFactor)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Feature:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.Feature)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Disk State:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.DiskState)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "PCI"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0) << "\r\n";
	for (auto i : hardwareData.pciInfo)
	{
		out << qSetFieldWidth(10) << left << "Bus:"
			<< qSetFieldWidth(10) << left << QString("0x%0").arg(i.bus, 0, 16)
			<< qSetFieldWidth(10) << left << "Dev:"
			<< qSetFieldWidth(10) << left << QString("0x%0").arg(i.dev, 0, 16)
			<< qSetFieldWidth(10) << left << "Fun:"
			<< qSetFieldWidth(10) << left << QString("0x%0").arg(i.fun, 0, 16)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Vendor ID:"
			<< qSetFieldWidth(10) << left << QString("0x%0").arg(i.vendorID, 0, 16)
			<< qSetFieldWidth(20) << left << "Device ID:"
			<< qSetFieldWidth(10) << left << QString("0x%0").arg(i.deviceID, 0, 16)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Net"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0) << "\r\n";
	for (auto i : hardwareData.netInfo)
	{
		out << qSetFieldWidth(20) << left << "Name:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.name)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Device Name:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.deviceName)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Media Type:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.mediaType)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "State:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.state)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Audio"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0) << "\r\n";

	for (auto i : hardwareData.audioInfo)
	{
		out << qSetFieldWidth(20) << left << "Name:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.name)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "ID:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.id)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "State:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.state)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Description:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.desc)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Audioif:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.audioif)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	out.flush();
}
void GetData::outputHardwareReportClean(QTextStream &out) const
{
	QDateTime time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "CPU"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(100) << left << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "CPU Name:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.cpuName) 
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "CPU Core:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.coreNum) 
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "CPU Threads:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.threadNum) 
		<< qSetFieldWidth(0) << "\r\n";

	for (auto i : hardwareData.cpuInfo.cache)
	{
		if (i.level == 1)
		{
			out << qSetFieldWidth(100) << left << QString("%0%1 size:%2KB %3way %4linesize").arg(i.type).arg(i.level).arg(i.size).arg(i.way).arg(i.lineSize) 
				<< qSetFieldWidth(0) << "\r\n";
		}
		if (i.level == 2)
		{
			out << qSetFieldWidth(100) << left << QString("%0%1 size:%2MB %3way %4linesize").arg(i.type).arg(i.level).arg(i.size).arg(i.way).arg(i.lineSize) 
				<< qSetFieldWidth(0) << "\r\n";
		}
		if (i.level == 3)
		{
			out << qSetFieldWidth(100) << left << QString("%0%1 size:%2MB %3way %4linesize").arg(i.type).arg(i.level).arg(i.size).arg(i.way).arg(i.lineSize) 
				<< qSetFieldWidth(0) << "\r\n";
		}

	}
	out << qSetFieldWidth(20) << left << "Package Temperature:"
		<< qSetFieldWidth(30) << QString("%0").arg(hardwareData.cpuInfo.packageTemperature)
		<< qSetFieldWidth(0) << "\r\n";
	unsigned int num = 0;
	for (auto i : hardwareData.cpuInfo.temperature)
	{
		num++;
		out << qSetFieldWidth(100) << left << QString("Core%0 Temperature:%1").arg(num).arg(i) 
			<< qSetFieldWidth(0) << "\r\n";
	}
	out << qSetFieldWidth(20) << "CPU SocketDesignation:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.socketDescription)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Southbridge Name:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.southbridgeName)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "CPU Manufacture:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.manufacture)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Code Name:" << qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.codeName) 
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "CPU Specification:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.cpuSpecification)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Family:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.family)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Model:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.model)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Stepping:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.stepping)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "ExtFamily:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.extFamily)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "ExtModel:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.extModel)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Revision:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.revision)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Technology:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.technology)
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "InstructionSet:"
		<< qSetFieldWidth(80) << left << QString::fromStdString(hardwareData.cpuInfo.instructionSets) 
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Core Speed:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.coreSpeed) 
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Ext Speed:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.extSpeed) 
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Multiplier:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.multiplier) 
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Processor ID:"
		<< qSetFieldWidth(30) << left << QString::fromStdString(hardwareData.cpuInfo.processorID) 
		<< qSetFieldWidth(0) << "\r\n";
	out << qSetFieldWidth(20) << left << "Max TDP:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.cpuInfo.maxTDP) 
		<< qSetFieldWidth(0) << "\r\n";


	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Memory"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	out << qSetFieldWidth(20) << left << "Dimm Num:"
		<< qSetFieldWidth(30) << left << QString("%0").arg(hardwareData.dimmNum)
		<< qSetFieldWidth(0) << "\r\n\r\n";
	for (auto i : hardwareData.dimmInfo)
	{
		out << qSetFieldWidth(20) << left << "Slot:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.slot) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Module Type:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.modulType)
			<< qSetFieldWidth(0)<<"\r\n";
		out << qSetFieldWidth(20) << left << "Module Size:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.moduleSize) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Module Manufacture:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.moduleManufacture) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "DRAM Manufacture:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.dramManufacture) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Part Num:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.partNum) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Serial Num:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.serialNum) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Product Date:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.productDate) 
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "GFX"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";

	for (auto i : hardwareData.gpuInfo)
	{
		out << qSetFieldWidth(30) << left << "GPU Name:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.gpuName)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GPU BIOS Version:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.gpuBIOSVersion)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GPU Driver Version:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.gpuDriverVersion)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GPU Branch Version:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i.gpuBranchVersion)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Temperature:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.temperature)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GPU Clock:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.gpuClock) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GPU Memory:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.gpuMemoryClock)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Usage:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.usage)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Fans:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.fans) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Dedicated Video Memory:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.dedicatedVideoMemory)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "System Video Memory:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.systemVideoMemory)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Shared System Memory:"
			<< qSetFieldWidth(30) << left << QString("%0").arg(i.sharedSystemMemory)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Monitor"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	for (auto i : hardwareData.monitorInfo)
	{
		out << qSetFieldWidth(20) << left << "Name:"
			<< qSetFieldWidth(30) << left << QString::fromStdString(i)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Disk"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";

	for (auto i : hardwareData.diskInfo)
	{
		out << qSetFieldWidth(30) << left << "Nominal Media Rotation Rate:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.NominalMediaRotationRate)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Buffer Size:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.BufferSize) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Nv Cache Size:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.NvCacheSize) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Logical Drive:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.LogicalDrive) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Power On Count:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.PowerOnCount) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Temperature:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.Temperature) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Host Writes:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.HostWrites) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Host Reads:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.HostReads) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "GBytesErased:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.GBytesErased) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Nand Writes:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.NandWrites) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Power On Hours:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.PowerOnHours) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Total Disk Size:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.TotalDiskSize) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Serial Number:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.SerialNumber) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Firmware Rev:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.FirmwareRev) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Model:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.Model) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Max Transfer Mode:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.MaxTransferMode) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Current Transfer Mode:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.CurrentTransferMode) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Major Version:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.MajorVersion) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Minor Version:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.MinorVersion) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Interface:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.Interface) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Enclosure:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.Enclosure) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Device Nominal Form Factor:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.DeviceNominalFormFactor) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Feature:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.Feature) 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(30) << left << "Disk State:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.DiskState) 
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "PCI"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	for (auto i : hardwareData.pciInfo)
	{
		out << qSetFieldWidth(10) << left << "Bus:"
			<< qSetFieldWidth(10) << left << QString("0x%0").arg(i.bus, 0, 16)
			<< qSetFieldWidth(10) << left << "Dev:"
			<< qSetFieldWidth(10) << left << QString("0x%0").arg(i.dev, 0, 16)
			<< qSetFieldWidth(10) << left << "Fun:"
			<< qSetFieldWidth(10) << left << QString("0x%0").arg(i.fun, 0, 16)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Vendor ID:"
			<< qSetFieldWidth(10) << left << QString("0x%0").arg(i.vendorID, 0, 16)
			<< qSetFieldWidth(20) << left << "Device ID:"
			<< qSetFieldWidth(10) << left << QString("0x%0").arg(i.deviceID, 0, 16)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Net"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	for (auto i : hardwareData.netInfo)
	{
		out << qSetFieldWidth(20) << left << "Name:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.name)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Device Name:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.deviceName)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Media Type:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.mediaType)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "State:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.state)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Audio"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";

	for (auto i : hardwareData.audioInfo)
	{
		out << qSetFieldWidth(20) << left << "Name:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.name)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "ID:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.id)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "State:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.state)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Description:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.desc)
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Audioif:"
			<< qSetFieldWidth(30) << left << QString::fromStdWString(i.audioif)
			<< qSetFieldWidth(0) << "\r\n\r\n";
	}
	out.flush();
}
void GetData::outputSoftwareReportClean(QTextStream &out) const
{
	QDateTime time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Service"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	for (auto i : softwareData.serviceInfo)
	{
		out << qSetFieldWidth(10) << left << "DisName:" 
			<< qSetFieldWidth(90) << left << i.disName 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(10) << left << "Status:" 
			<< qSetFieldWidth(90) << left <<  i.status 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(10) << left << "Start Type:" 
			<< qSetFieldWidth(90) << left << i.starttype 
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Auto Boot"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	for (auto i : softwareData.autolist)
	{
		out << qSetFieldWidth(10) << left << "Name:" 
			<< qSetFieldWidth(90) << left << i.name
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(10) << left << "Type:" 
			<< qSetFieldWidth(90) << left << i.type
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Folder Task"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	for (auto i : softwareData.folderTask)
	{
		out << qSetFieldWidth(20) << left << "Name:" 
			<< qSetFieldWidth(80) << left << i.name
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Status:" 
			<< qSetFieldWidth(80) << left << i.state
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Running Task"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	for (auto i : softwareData.runningTask)
	{
		out << qSetFieldWidth(20) << left << "Name:" 
			<< qSetFieldWidth(80) << left << i.name
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Status:" 
			<< qSetFieldWidth(80) << left << i.state
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Tcp Transmission"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	for (auto i : softwareData.tcp)
	{
		out << qSetFieldWidth(20) << left << "PID:" 
			<< qSetFieldWidth(80) << left << i.PID
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Status:" 
			<< qSetFieldWidth(80) << left << i.state
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "LocalIP:" 
			<< qSetFieldWidth(80) << left << i.localIP
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "LocalPort:" 
			<< qSetFieldWidth(80) << left << i.localPort
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "remoteIP:" 
			<< qSetFieldWidth(80) << left << i.remoteIP
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "remotePort:" 
			<< qSetFieldWidth(80) << left << i.remotePort
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Path:" 
			<< qSetFieldWidth(80) << left << i.strPath
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Udp Transmission"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	for (auto i : softwareData.udp)
	{
		out << qSetFieldWidth(20) << left << "PID:" 
			<< qSetFieldWidth(80) << left << i.PID
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Status:" 
			<< qSetFieldWidth(80) << left << i.state
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "LocalIP:" 
			<< qSetFieldWidth(80) << left << i.localIP 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "LocalPort:" 
			<< qSetFieldWidth(80) << left <<  i.localPort
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "remoteIP:" 
			<< qSetFieldWidth(80) << left << i.remoteIP
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "remotePort:" 
			<< qSetFieldWidth(80) << left << i.remotePort
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Path:" 
			<< qSetFieldWidth(80) << left << i.strPath
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	out.flush();
}
void GetData::outputSoftwareReportSpecific(QTextStream &out) const
{
	QDateTime time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Service"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";
	for (auto i : softwareData.serviceInfo)
	{
		out << qSetFieldWidth(20) << left << "Name:" 
			<< qSetFieldWidth(80) << left << i.name 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "DisName:"
			<< qSetFieldWidth(80) << left << i.disName
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Status:"
			<< qSetFieldWidth(80) << left << i.status
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Start Type:"
			<< qSetFieldWidth(80) << left << i.starttype
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Path:" 
			<< qSetFieldWidth(80) << left << i.path 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Description:" 
			<< qSetFieldWidth(80) << left << i.description 
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Auto Boot"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";

	for (auto i : softwareData.autolist)
	{
		out << qSetFieldWidth(10) << left << "Name:"
			<< qSetFieldWidth(90) << left << i.name
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(10) << left << "Data:" 
			<< qSetFieldWidth(90) << left << i.data 
			<< qSetFieldWidth(0) <<"\r\n";
		out << qSetFieldWidth(10) << left << "Type:"
			<< qSetFieldWidth(90) << left << i.type
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Folder Task"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";

	for (auto i : softwareData.folderTask)
	{
		out << qSetFieldWidth(10) << left << "Name:"
			<< qSetFieldWidth(90) << left << i.name
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(10) << left << "Status:"
			<< qSetFieldWidth(90) << left << i.state
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Running Task"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";

	for (auto i : softwareData.runningTask)
	{
		out << qSetFieldWidth(10) << left << "Name:"
			<< qSetFieldWidth(90) << left << i.name
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(10) << left << "Status:"
			<< qSetFieldWidth(90) << left << i.state
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Tcp Transmission"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";

	for (auto i : softwareData.tcp)
	{
		out << qSetFieldWidth(20) << left << "uPro:" 
			<< qSetFieldWidth(80) << left << i.uPro 
			<< qSetFieldWidth(0) <<"\r\n";
		out << qSetFieldWidth(20) << left << "PID:"
			<< qSetFieldWidth(80) << left << i.PID
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Status:"
			<< qSetFieldWidth(80) << left << i.state
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "LocalIP:"
			<< qSetFieldWidth(80) << left << i.localIP
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "LocalPort:"
			<< qSetFieldWidth(80) << left << i.localPort
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "remoteIP:"
			<< qSetFieldWidth(80) << left << i.remoteIP
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "remotePort:"
			<< qSetFieldWidth(80) << left << i.remotePort
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Path:"
			<< qSetFieldWidth(80) << left << i.strPath
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	time = QDateTime::currentDateTime();
	out << qSetFieldWidth(50) << left << "Udp Transmission"
		<< qSetFieldWidth(50) << right << time.toString()
		<< qSetFieldWidth(0) << "\r\n";
	out << "--------------------------------------------------------------------------------------------------------"
		<< qSetFieldWidth(0)<<"\r\n";

	for (auto i : softwareData.udp)
	{
		out << qSetFieldWidth(20) << left << "uPro:" 
			<< qSetFieldWidth(80) << left << i.uPro 
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "PID:"
			<< qSetFieldWidth(80) << left << i.PID
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Status:"
			<< qSetFieldWidth(80) << left << i.state
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "LocalIP:"
			<< qSetFieldWidth(80) << left << i.localIP
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "LocalPort:"
			<< qSetFieldWidth(80) << left << i.localPort
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "remoteIP:"
			<< qSetFieldWidth(80) << left << i.remoteIP
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "remotePort:"
			<< qSetFieldWidth(80) << left << i.remotePort
			<< qSetFieldWidth(0) << "\r\n";
		out << qSetFieldWidth(20) << left << "Path:"
			<< qSetFieldWidth(80) << left << i.strPath
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(0) << "\r\n";
	}
	out.flush();
}