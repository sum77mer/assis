#pragma once
#include <windows.h>
#include <comdef.h>
#include <wbemidl.h>
#include <comutil.h>
#include <atlbase.h>
#include <atlcom.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>  

#define CHECKHR(x) \
    if ( FAILED((x))) break; \

#define CHECKWMIHR(x) \
    if ( (x) != WBEM_S_NO_ERROR ) break; \

using namespace std;

class CWMI  
{  
public:  
	CWMI();  
	~CWMI(void);  //���� 
public:  
	HRESULT ExcuteFun();  
protected:  
	VOID SetNamespace(wstring wstrNamespace);  //�����ռ�����
private:  
	HRESULT InitialCom();  //��ʼ��COM��
	HRESULT SetComSecLevels();  //���ý���COM��ȫ��Ϣ
	HRESULT ObtainLocator2WMI(CComPtr<IWbemLocator>& pLoc);  // ����������COM������
	HRESULT Connect2WMI(CComPtr<IWbemLocator> pLoc,CComPtr<IWbemServices>& pSvc);  //����WMI�����ռ�
	HRESULT SetProxySecLevels(CComPtr<IWbemServices> pSvc);  //����WMI���ӵİ�ȫ�ȼ�
	virtual HRESULT Excute(CComPtr<IWbemServices> pSvc) = 0;  
private:  
	wstring m_wstrNamespace;  
}; 