#include "Ring0Defination.h"

namespace SV_ASSIST
{
    namespace Ring0
    {
        /**********************************************************************
        *@Function				RdIOPort
        *@brief					��ȡIO Port��ֵ
        *@author				��˶
        *@param
            *@IO_Port_Addr		IN IO Port�ĵ�ַ
            *@IO_DataSize		IN IO ������ݵĴ�С 1��2��4��8��16��32bits��
            *@IO_Data			OUT �����IO Port�е�ֵ
        *@return
			*@BOOL				�Ƿ�ɹ� 1�ɹ� ����ֵ ʧ��
        **************************************************************************/
        BOOL RdIOPort(IN USHORT IO_Port_Addr, IN USHORT IO_DataSize, OUT DWORD& IO_Data);
        /**********************************************************************
        *@Function				WrIOPort
        *@brief				д��IO Port��ֵ
        *@author			��˶
        *@param
            *@IO_Data			IN ����IO Port��ֵ
            *@IO_DataSize		IN IO ������ݵĴ�С 1��2��4��8��16��32bits��
        *@IO_Port_Addr		IN ����IO Port�ĵ�ַ
        *@return
            *@BOOL				�Ƿ�ɹ� 1�ɹ� ����ֵ ʧ��
        **************************************************************************/
        BOOL WrIOPort(IN USHORT IO_Port_Addr, IN USHORT IO_DataSize, IN ULONG IO_Data);
        /**************************************************
        *@Function				RdMsrTx
        *@brief					��ȡMSR��ֵ
        *@author				��˶
        *@param
            *@Index				IN ����MSR������
            *@threadAffinityMask�����߳������еĺ���
            *@Data				OUT ���MSR��ֵ��64λ
        *@return
            *@BOOL				�Ƿ�ɹ� 1�ɹ� ����ֵ ʧ��
        ***************************************************/
        BOOL RdMsrTx(IN DWORD Index, OUT DWORD64& Data, IN DWORD threadAffinityMask);
        /**************************************************
        *@Function				WrMsrTx
        *@brief					дMSR��ֵ
        *@author				��˶
        *@param
            *@Index				IN ����MSR������
            *@threadAffinityMask�����߳������еĺ���
            *@Data				IN ��Ҫд��MSR��ֵ��64λ
        *@return
            *@BOOL				�Ƿ�ɹ� 1�ɹ� ����ֵ ʧ��
        ***************************************************/
        BOOL WrMsrTx(IN DWORD Index, IN DWORD64 Data, IN DWORD threadAffinityMask);


        /**************************************************
        *@Function				RdMsr
        *@brief					��ȡMSR��ֵ
        *@author				��˶
        *@param
            *@Index				IN ����MSR������
            *@Data				OUT ���MSR��ֵ��64λ
        *@return
            *@BOOL				�Ƿ�ɹ� 1�ɹ� ����ֵ ʧ��
        ***************************************************/
        BOOL RdMsr(IN DWORD Index, OUT DWORD64& Data);

        /**************************************************
        *@Function				WrMsr
        *@brief					дMSR��ֵ
        *@author				��˶
        *@param
            *@Index				IN ����MSR������
            *@Data				IN ��Ҫд��MSR��ֵ��64λ
        *@return
            *@BOOL				�Ƿ�ɹ� 1�ɹ� ����ֵ ʧ��
        ***************************************************/
        BOOL WrMsr(IN DWORD Index, IN DWORD64 Data);

        /**************************************************************************
        *@Function				RdMemory
        *@brief					��ȡ�ڴ��ֵ
        *@author				��˶
        *@param
            *@IO_Port_Addr		IN ����Memory�ĵ�ַ
            *@IO_DataSize		IN Memory ������ݵĴ�С 1��2��4��8��16��32bits��
            *@IO_Data			OUT �����Memory�е�ֵ
        *@return
            *@BOOL				�Ƿ�ɹ� 1�ɹ� ����ֵ ʧ��
        ***************************************************************************/
        BOOL RdMemory(IN LONGLONG Memory_Addr, IN USHORT Mem_DataSize, OUT ULONG& Memory_Data);

        /***************************************************************************
        *@Function				WrMemory
        *@brief					д���ڴ��ֵ
        *@author				��˶
        *@param
            *@IO_Data			IN ����Memory��ֵ
            *@IO_DataSize		IN Memory ������ݵĴ�С 1��2��4��8��16��32bits��
            *@IO_Port_Addr		IN ����Memory�ĵ�ַ
        *@return
            *@BOOL				�Ƿ�ɹ� 1�ɹ� ����ֵ ʧ��
        ******************************************************************************/
        BOOL WrMemory(IN LONGLONG Memory_Addr, IN USHORT Mem_DataSize, IN ULONG Memory_Data);

        /*************************************************
        *@Function				ReadPci
        *@brief					��PCI���ÿռ������
        *@author				��˶
        *@param
            *@bus				IN ����bus��ֵ
            *@dev				IN ����dev��ֵ
            *@func				IN ����func��ֵ
            *@pci_config		OUT ���Pci���ÿռ������
        *@return
            *@BOOL				�Ƿ�ɹ� 1�ɹ� ����ֵ ʧ��
        **************************************************/
        BOOL ReadPci(IN USHORT bus, IN USHORT dev, IN USHORT func, OUT PCI_COMMON_CONFIG& pci_config);

        /*************************************************
        *@Function				WritePci
        *@brief					дPCI���ÿռ������
        *@author				��˶
        *@param
            *@bus				IN ����bus��ֵ
            *@dev				IN ����dev��ֵ
            *@func				IN ����func��ֵ
            *@offset			IN ����Ҫд��ƫ������ֵ
            *@Data				IN ����Ҫд�����ݵ�ֵ
        *@return
            *@BOOL				�Ƿ�ɹ� 1�ɹ� ����ֵ ʧ��
        **************************************************/
        BOOL WritePci(IN USHORT bus, IN USHORT dev, IN USHORT func, IN UCHAR offset, IN ULONG Data);

        /**************************************************
        *@Function					GetECData
        *@brief						��ȡEC����Ϣ
        *@author					��˶
        *@param
			*@Embedded_Controller_Data	OUT EC 256�ֽڵ���Ϣ
        *@return
			*@BOOL					��ȡ�Ƿ�ɹ�
        ***************************************************/
        BOOL GetECData(Embedded_Controller_Data& EC_Data);

        /***************************************************
        *@Function					SetECData
        *@brief						����EC����Ϣ
        *@author					��˶
        *@param
			*@EC_Addr				IN Ҫ���õ�EC�ĵ�ַ
			*@EC_Write_Data			IN Ҫ���õ�EC������
        *@return
			*@BOOL					�����Ƿ�ɹ�
        ****************************************************/
        BOOL SetECData(BYTE EC_Addr, BYTE EC_Write_Data);
        /***************************************************
        *@Function					GetSMbusBaseAddr
        *@brief						��ȡSMBUS����ַ
        *@author					��˶
        *@param
			*@VendorID				IN Chip�ĳ�����
			*@SMbusBaseAddress		OUT SMBUS����ַ
		*@return
			*@BOOL					�����Ƿ�ɹ�
        ****************************************************/
        BOOL GetSMbusBaseAddr(const USHORT VendorID, USHORT& SMbusBaseAddress);

        /***************************************************
        *@Function					GetPCIVendorID
        *@brief						��ȡChip������
        *@author					��˶
        *@param
        *@return
        *@USHORT					����pci���ţ���1022��8086��1106
        ****************************************************/
        USHORT GetPCIVendorID();

		/**************************************************************
		*@Function				GetPCIEInfo
		*@brief					��ȡPCIE Configuration Space
		*@author				��˶
		*@param
			*@PCIE_BaseAddress	IN PCIE�ڴ��ַ
			*@Data				INOut PCIE���ÿռ�����
			*@DataSize			INOut PCIE���ÿռ��С4096
		*@return
			*@BOOL				��ȡConfiguration Space�Ƿ�ɹ�
		****************************************************************/
		BOOL GetPCIEInfo(const ULONGLONG PCIE_BaseAddress, ULONG bus, ULONG dev, ULONG func, PVOID& Data, size_t DataSize);

		/***************************************************
		*@Function					GetPCIDeviceName
		*@brief						��ȡPci������
		*@author					��˶
		*@param
			*@VenderID				����ID��
			*@DeviceID				�豸ID��
			*@VenderName			���������
			*@DeviceName			����豸��
		*@return
			*@USHORT				����pci���ţ���1022��8086��1106
		****************************************************/
		BOOL GetPCIDeviceName(USHORT VenderID, USHORT DeviceID, std::string& VenderName, std::string& DeviceName);

		/***************************************************
		*@Function					GetAllPciInfo
		*@brief						��ȡȫ����PCI���ÿռ���Ϣ
		*@author					��˶
		*@param
		*@return
			*@Pci_All_Config_Space	Pci�豸
		****************************************************/
		const Pci_All_Config_Space& GetAllPciInfo();

		/***************************************************
		*@Function					PCIstringToBDF
		*@brief						pci�ַ�ת����bus dev func
		*@author					��˶
		*@param
			*@pcistring				�����pci�ַ���
			*@bus					����bus��
			*@dev					����dev��
			*@func					����func��
		*@return
			*@BOOL					�Ƿ�ɹ�
		****************************************************/
		const BOOL PCIstringToBDF(const std::wstring& pcistring, ULONG &bus, ULONG &dev, ULONG &func);
    }
}