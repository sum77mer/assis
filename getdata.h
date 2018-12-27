#ifndef GETDATA_H
#define GETDATA_H
#include <string>
#include <vector>
#include <map>
#include <QString>
#include <QStandardItemModel>
#include <QTextStream>
//#include <Windows.h>
using std::string;
using std::wstring;
using std::vector;
class GetData
{
public:
	GetData();
	//~GetData();
	void initialize();
	void update();	
public:
	//CPU_Information cpuInfo
	struct HardwareGeneral
	{
		string cpuName;
		vector<string> gpuName;
		vector<string> memory;
		string board;
		vector<wstring> disk;
	};
	struct Cache
	{
		char type;
		unsigned int level;
		unsigned int size;
		unsigned int way;
		unsigned int lineSize;
		unsigned int partition;
		unsigned int set;

	};
	struct CPU_Information
	{
		unsigned int cpuNum;
		unsigned int coreNum;
		unsigned int threadNum;
		string cpuName;
		string manufacture;
		string codeName;
		string socketDescription;
		string cpuSpecification;
		unsigned int family;
		unsigned int model;
		unsigned int stepping;
		unsigned int extFamily;
		unsigned int extModel;
		unsigned int revision;
		unsigned int technology;
		string instructionSets;
		string southbridgeName;
		vector<Cache> cache;
		double coreSpeed;
		double extSpeed;
		double multiplier;
		double maxSpeed;
		string processorID;
		unsigned int maxTDP;
		double packageTemperature;
		vector<double> temperature;
	};
	struct Memory_Information {
		unsigned int slot;
		string modulType;
		size_t moduleSize;
		string moduleManufacture;
		string dramManufacture;
		string partNum;
		string serialNum;
		string productDate;
	};
	struct GPU_Information{
		string gpuName;
		string gpuBIOSVersion;
		string gpuDriverVersion;
		string gpuBranchVersion;
		int temperature;
		double gpuClock;
		double gpuMemoryClock;
		unsigned long usage;
		unsigned long fans;
		unsigned int dedicatedVideoMemory;
		unsigned int systemVideoMemory;
		unsigned int sharedSystemMemory;
	};
	struct Monitor_Information{};
	struct Board_Information{};
	struct Chipset_Information{};
	struct BIOS_Information{
	};
	struct Disk_Information{
		//SMART_ATTRIBUTE		Attribute[30];
		//SMART_THRESHOLD		Threshold[30];
		bool				IsSsd;
		std::wstring		NominalMediaRotationRate;
		std::wstring		BufferSize;
		std::wstring		NvCacheSize;
		std::wstring		LogicalDrive;
		std::wstring		PowerOnCount;
		std::wstring		Temperature;
		std::wstring		HostWrites;
		std::wstring		HostReads;
		std::wstring		GBytesErased;
		std::wstring		NandWrites;
		std::wstring		PowerOnHours;
		std::wstring		TotalDiskSize;
		std::wstring		SerialNumber;
		std::wstring		FirmwareRev;
		std::wstring		Model;
		std::wstring		MaxTransferMode;
		std::wstring		CurrentTransferMode;
		std::wstring		MajorVersion;
		std::wstring		MinorVersion;
		std::wstring		Interface;
		std::wstring		Enclosure;
		std::wstring		DeviceNominalFormFactor;
		std::wstring		Feature;
		std::wstring		DiskState;
	};
	struct USB_Information{};
	struct USB_Tree {
		enum USB_TYPE{
			root = 0,hub,device
		}type;
		QString title;
		QString value;
	};
	struct SMBIOS_Information {
		QString title;
		QString value;
	};
	struct PCI_Information {
		unsigned int  bus;
		unsigned int dev;
		unsigned int fun;
		unsigned int vendorID;
		unsigned int deviceID;
		unsigned int command;
		unsigned int status;
		unsigned int revisionID;
		unsigned int classCode;
		unsigned int cachelineSize;
		unsigned int latencyTimer;
		unsigned int interruptPin;
		unsigned int interruptLine;
		unsigned int baseclass;
		unsigned int subclass;
	};
	struct Net_Information {
		wstring name;
		wstring deviceName;
		wstring mediaType;
		wstring state;
	};
	struct Audio_Information{
		wstring id;
		wstring state;
		wstring name;
		wstring desc;
		wstring audioif;
	};
	struct Keyboard_Information{};
	struct Mouse_Information{};
	struct TitleValue {
		string title;
		string value;
	};
	struct HardwareInfo {
		vector<TitleValue> boardInfo;
		vector<TitleValue> biosInfo;
		Chipset_Information chipsetInfo;

		unsigned int cpuNum;
		CPU_Information cpuInfo;

		unsigned int dimmNum;
		vector<Memory_Information> dimmInfo;

		unsigned int gfxcardNum;
		vector<GPU_Information> gpuInfo;

		unsigned int monitorNum;
		vector<string> monitorInfo;

		unsigned int diskNum;
		vector<Disk_Information> diskInfo;
		vector<QString> drive;

		vector<PCI_Information> pciInfo;

		unsigned int netDevNum;
		vector<Net_Information> netInfo;

		unsigned int audioDevNum;
		vector<Audio_Information> audioInfo;

		unsigned int mouseNum;
		vector<Mouse_Information> mouseInfo;

		unsigned int keyboardNum;
		vector<Keyboard_Information> keyboardInfo;
	};
	struct Service_Information {
		QString name;
		QString disName;
		QString starttype;
		QString status;
		QString path;
		QString description;
	};
	struct Auto_Information {
		QString type;
		QString name;
		QString data;
	};
	struct Task_Information {
		QString name;
		QString state;
	};
	struct Connection_Information {
		QString state;
		QString localIP;
		QString remoteIP;
		QString localPort;
		QString remotePort;
		QString PID;
		QString strPath;
		QString uPro;
	};
	struct SoftwareInfo{
		vector<Service_Information> serviceInfo;
		vector<Task_Information> folderTask;
		vector<Task_Information> runningTask;
		vector<Auto_Information> autolist;
		vector<Connection_Information> tcp;
		vector<Connection_Information> udp;
	};
public:
	void updateAll();
	void updateHardware();
	void updateSoftware();
	void getHardwareGeneral(HardwareGeneral &) const;
	void getCPU(CPU_Information*) const;
	void getGPU(vector<GPU_Information> &) const;
	void getBoard(string&) const;
	void getBIOS(string& )const;
	void getChipset() const;
	void getMemory(vector<Memory_Information> &) const;
	void getSMBIOS(vector<SMBIOS_Information> &) const;
	bool getEDID(QString &s) const;
	void getAudio(vector<Audio_Information>&) const;
	void getACPI() const;
	void getNet(vector<Net_Information> &) const;
	void getUSB(vector<USB_Tree> &) const;
	void getMonitor(string&) const;
	void getStorage(vector<Disk_Information> &) const;
	void getLogicalDrives(QStringList &s) const;
	void getPCI(vector<PCI_Information> &) const;
	bool getPCIconfig(const unsigned int, const unsigned int,const unsigned int,int[]);
	void getPCIdescription(const unsigned int bus, const unsigned int dev, const unsigned int fun, QString &);
	bool writePCIconfig(const unsigned int, const unsigned int, const unsigned int, const unsigned int, unsigned int data);
	void readCPUID(long long &eax, long long &ebx, long long &ecx, long long &edx);
	bool readMsrTx(const int &ecx,const int &cpu,int &eax,int &edx);
	bool writeMsrTx(const int &ecx, const int cpu,const int &eax, const int &edx);
	bool readIO(unsigned int &addr, unsigned int &data);
	int writeIO(unsigned int &addr, unsigned int &data);
	bool readMemory(const unsigned int &addr, unsigned int &data);
	int writeMemory(const unsigned int &addr, const unsigned int &data);

	void getService(vector<Service_Information> &x);
	void getAutoList(vector<Auto_Information> &x);
	void getFolderTask(vector<Task_Information> &x);
	void getRunningTask(vector<Task_Information> &x);
	void getTCP(vector<Connection_Information> &x);
	void getUDP(vector<Connection_Information> &);

	void outputHardwareReportSpecific(QTextStream &s) const;
	void outputHardwareReportClean(QTextStream &s) const;
	void outputSoftwareReportSpecific(QTextStream &s) const;
	void outputSoftwareReportClean(QTextStream &s) const;
	private:
		HardwareInfo hardwareData = {};
		SoftwareInfo softwareData = {};
};

#endif 