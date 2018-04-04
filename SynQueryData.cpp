#include "SynQueryData.h"

CSynQueryData::CSynQueryData(const wstring& wszNamespace, const wstring& wszWQLQuery) : CSynQuery(wszNamespace, wszWQLQuery)
{
	class_name.reserve(1000);
	class_data.reserve(1000);
}

CSynQueryData::~CSynQueryData(void)
{
}

HRESULT CSynQueryData::DealWithSingleItem( CComBSTR bstrName, CComVariant Value, CIMTYPE type, LONG lFlavor )
{
    HRESULT hr = WBEM_S_NO_ERROR; 
    switch ( Value.vt ) {
        case VT_UNKNOWN : {
            DealWithUnknownTypeItem(bstrName, Value, type, lFlavor);
            }break;
        default: {
            PrintfItem(bstrName, Value, type, lFlavor);
        };
    }
    return hr;
}

HRESULT CSynQueryData::DealWithUnknownTypeItem( CComBSTR bstrName, CComVariant Value, CIMTYPE type, LONG lFlavor )
{
    HRESULT hr = WBEM_S_NO_ERROR;
    if ( NULL == Value.punkVal ) {
        return hr;
    }
    // object����ת����IWbemClassObject�ӿ�ָ�룬ͨ����ָ��ö����������
    CComPtr<IWbemClassObject> pObjInstance = (IWbemClassObject*)Value.punkVal;
    hr = pObjInstance->BeginEnumeration(WBEM_FLAG_LOCAL_ONLY);
    do {
        CHECKHR(hr);
        CComBSTR bstrNewName;
        CComVariant NewValue;
        CIMTYPE newtype;
        LONG lnewFlavor = 0;
        hr = pObjInstance->Next(0, &bstrNewName, &NewValue, &newtype, &lnewFlavor);
        CHECKHR(hr);
        PrintfItem(bstrNewName, NewValue, newtype, lnewFlavor);
    }while ( WBEM_S_NO_ERROR == hr );
    hr = pObjInstance->EndEnumeration();
    return WBEM_S_NO_ERROR;
}

VOID CSynQueryData::PrintfItem( CComBSTR bstrName, CComVariant Value, CIMTYPE type, LONG lFlavor )
{
   // wprintf(L"%s\t",bstrName.m_str);
	class_name.emplace_back(_com_util::ConvertBSTRToString(bstrName.m_str));
    switch ( Value.vt ){
        case VT_BSTR: {
               // wprintf(L"%s",Value.bstrVal);  
				class_data.emplace_back(_com_util::ConvertBSTRToString(Value.bstrVal));
            }break;
        case VT_I1:
        case VT_I2:
        case VT_I4:
        case VT_I8:	
        case VT_INT: {
               // wprintf(L"0x%08x",Value.intVal); 
				class_data.emplace_back(to_string((long long)Value.intVal));
            }break;
        case VT_UI8:
        case VT_UI1:	
        case VT_UI2:
        case VT_UI4:
        case VT_UINT:{
               // wprintf(L"0x%08x",Value.intVal);  
				class_data.emplace_back(to_string((unsigned long long)Value.intVal));
            }break;
        case VT_BOOL:{
				//wprintf(L"%s", Value.boolVal ? L"TRUE" : L"FASLE" );
                Value.boolVal ? (class_data.emplace_back( "TRUE")): (class_data.emplace_back ( "FALSE"));
            }break;
        case VT_NULL: {
        }break;
        default:{
				class_data.emplace_back( "");
				//ATLASSERT(FALSE);
                };
    }
    //wprintf(L"\n");
}


vector<string> CSynQueryData::ClassData()
{
	return class_data;
}

vector<string> CSynQueryData::ClassName()
{
	return class_name;
}
