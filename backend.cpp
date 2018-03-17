#include "backend.h"

Back_End::Back_End(QObject *parent) :
    QObject(parent)//,Info_out()
//Back_End::BackEnd()
{
}
QString Back_End::userName()
{  
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Name);
    return m_userName;
}
QString Back_End::family()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = cpudata.Family;
    return m_userName;
}
QString Back_End::Model()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = cpudata.Model;
    return m_userName;
}
QString Back_End::Stepping()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = cpudata.Stepping;
    return m_userName;
}
QString Back_End::Ext_Family()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = cpudata.Ext_Family;
    return m_userName;
}
QString Back_End::Ext_Model()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = cpudata.Ext_Model;
    return m_userName;
}
QString Back_End::Name()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Name);
    return m_userName;
}
QString Back_End::CurrentClockSpeed()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.CurrentClockSpeed);
    return m_userName;
}
QString Back_End::ExtClock()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.ExtClock);
    return m_userName;
}
QString Back_End::Manufacturer()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Manufacturer);
    return m_userName;
}
QString Back_End::Core()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Core);
    return m_userName;
}
QString Back_End::Thread()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Thread);
    return m_userName;
}
QString Back_End::ProcessorID()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.ProcessorID);
    return m_userName;
}
QString Back_End::Revision()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Revision);
    return m_userName;
}
QString Back_End::MaxClockSpeed()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.MaxClockSpeed);
    return m_userName;
}
QString Back_End::sockedDesignation()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.SocketDesignation);
    return m_userName;
}
QString Back_End::UpgradeMethod()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.UpgradeMethod);
    return m_userName;
}
QString Back_End::Feature_info()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Name);
    return m_userName;
}
QString Back_End::CPU_Type()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.CPU_Type);
    return m_userName;
}
QString Back_End::Architecture()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Architecture);
    return m_userName;
}
QString Back_End::Code_Name()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Code_Name);
    return m_userName;
}
QString Back_End::socket_Packeage()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Socket_Packeage);
    return m_userName;
}
QString Back_End::Cache_TLB()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Name);
    return m_userName;
}
QString Back_End::cache()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Name);
    return m_userName;
}
QString Back_End::C_STATE_info()
{
    Info_out cpuinfo;
    CPUID_Data cpudata;
    cpuinfo.excute_CPUID();
    cpudata=cpuinfo.RES_DATA;
    m_userName = QString::fromStdString(cpudata.Name);
    return m_userName;
}

void Back_End::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit userNameChanged();
}
void Back_End::setFamily(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit familyChanged();
}
void Back_End::setModel(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit ModelChanged();
}
void Back_End::setStepping(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit SteppingChanged();
}
void Back_End::setExt_Family(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit Ext_FamilyChanged();
}
void Back_End::setExt_Model(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit Ext_FamilyChanged();
}
void Back_End::setName(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit NameChanged();
}
void Back_End::setCurrentClockSpeed(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit CurrentClockSpeedChanged();
}
void Back_End::setExtClock(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit ExtClockChanged();
}
void Back_End::setManufacturer(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit ManufacturerChanged();
}

void Back_End::setCore(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit CoreChanged();
}
void Back_End::setThread(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit ThreadChanged();
}
void Back_End::setProcessorID(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit ProcessorIDChanged();
}
void Back_End::setRevision(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit RevisionChanged();
}
void Back_End::setMaxClockSpeed(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit MaxClockSpeedChanged();
}
void Back_End::setSockedDesignation(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit sockedDesignationChanged();
}
void Back_End::setUpgradeMethod(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit UpgradeMethodChanged();
}
void Back_End::setFeature_info(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit Feature_infoChanged();
}
void Back_End::setCPU_Type(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit CPU_TypeChanged();
}
void Back_End::setArchitecture(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit ArchitectureChanged();
}
void Back_End::setCode_Name(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit Code_NameChanged();
}
void Back_End::setSocket_Packeage(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit socket_PackeageChanged();
}
void Back_End::setCache_TLB(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit Cache_TLBChanged();
}
void Back_End::setCache(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit cacheChanged();
}
void Back_End::setC_STATE_info(const QString &userName)
{
    if (userName == m_userName)
        return;
    emit C_STATE_infoChanged();
}
