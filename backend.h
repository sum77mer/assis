#ifndef BACK_END_H
#define BACK_END_H
#pragma warning (disable:4483)
#ifndef _ATL_NATIVE_INITIALIZATION
#define _ATL_NATIVE_INITIALIZATION
#include <QObject>
#include <QString>
#include "cpuid.h"

class Back_End : public QObject,public Info_out
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString family READ family WRITE setFamily NOTIFY familyChanged)
    Q_PROPERTY(QString Model READ Model WRITE setModel NOTIFY ModelChanged)
    Q_PROPERTY(QString Stepping READ Stepping WRITE setStepping NOTIFY SteppingChanged)
    Q_PROPERTY(QString Ext_Family READ Ext_Family WRITE setExt_Family NOTIFY Ext_FamilyChanged)
    Q_PROPERTY(QString Ext_Model READ Ext_Model WRITE setExt_Model NOTIFY Ext_FamilyChanged)
    Q_PROPERTY(QString Name READ Name WRITE setName NOTIFY NameChanged)
    Q_PROPERTY(QString CurrentClockSpeed READ CurrentClockSpeed WRITE setCurrentClockSpeed NOTIFY CurrentClockSpeedChanged)
    Q_PROPERTY(QString ExtClock READ ExtClock WRITE setExtClock NOTIFY ExtClockChanged)
    Q_PROPERTY(QString Manufacturer READ Manufacturer WRITE setManufacturer NOTIFY ManufacturerChanged)
    Q_PROPERTY(QString Core READ Core WRITE setCore NOTIFY CoreChanged)
    Q_PROPERTY(QString Thread READ Thread WRITE setThread NOTIFY ThreadChanged)
    Q_PROPERTY(QString ProcessorID READ ProcessorID WRITE setProcessorID NOTIFY ProcessorIDChanged)
    Q_PROPERTY(QString Revision READ Revision WRITE setRevision NOTIFY RevisionChanged)
    Q_PROPERTY(QString MaxClockSpeed READ MaxClockSpeed WRITE setMaxClockSpeed NOTIFY MaxClockSpeedChanged)
    Q_PROPERTY(QString sockedDesignation READ sockedDesignation WRITE setSockedDesignation NOTIFY sockedDesignationChanged)
    Q_PROPERTY(QString UpgradeMethod READ UpgradeMethod WRITE setUpgradeMethod NOTIFY UpgradeMethodChanged)
    Q_PROPERTY(QString Feature_info READ Feature_info WRITE setFeature_info NOTIFY Feature_infoChanged)
    Q_PROPERTY(QString CPU_Type READ CPU_Type WRITE setCPU_Type NOTIFY CPU_TypeChanged)
    Q_PROPERTY(QString Architecture READ Architecture WRITE setArchitecture NOTIFY ArchitectureChanged)
    Q_PROPERTY(QString Code_Name READ Code_Name WRITE setCode_Name NOTIFY Code_NameChanged)
    Q_PROPERTY(QString socket_Packeage READ socket_Packeage WRITE setSocket_Packeage NOTIFY socket_PackeageChanged)
    Q_PROPERTY(QString Cache_TLB READ Cache_TLB WRITE setCache_TLB NOTIFY Cache_TLBChanged)
    Q_PROPERTY(QString cache READ cache WRITE setCache NOTIFY cacheChanged)
    Q_PROPERTY(QString C_STATE_info READ C_STATE_info WRITE setC_STATE_info NOTIFY C_STATE_infoChanged)

public:
    explicit Back_End(QObject *parent = nullptr);
    //BackEnd();

    QString userName();
    void setUserName(const QString &userName);

    QString family();
    void setFamily(const QString &userName);

    QString Model();
    void setModel(const QString &userName);

    QString Stepping();
    void setStepping(const QString &userName);

    QString Ext_Family();
    void setExt_Family(const QString &userName);

    QString Ext_Model();
    void setExt_Model(const QString &userName);

    QString Name();
    void setName(const QString &userName);

    QString CurrentClockSpeed();
    void setCurrentClockSpeed(const QString &userName);

    QString ExtClock();
    void setExtClock(const QString &userName);

    QString Manufacturer();
    void setManufacturer(const QString &userName);

    QString Core();
    void setCore(const QString &userName);

    QString Thread();
    void setThread(const QString &userName);

    QString ProcessorID();
    void setProcessorID(const QString &userName);

    QString Revision();
    void setRevision(const QString &userName);

    QString MaxClockSpeed();
    void setMaxClockSpeed(const QString &userName);

    QString sockedDesignation();
    void setSockedDesignation(const QString &userName);

    QString UpgradeMethod();
    void setUpgradeMethod(const QString &userName);

    QString Feature_info();
    void setFeature_info(const QString &userName);

    QString CPU_Type();
    void setCPU_Type(const QString &userName);

    QString Architecture();
    void setArchitecture(const QString &userName);

    QString Code_Name();
    void setCode_Name(const QString &userName);

    QString socket_Packeage();
    void setSocket_Packeage(const QString &userName);

    QString Cache_TLB();
    void setCache_TLB(const QString &userName);

    QString cache();
    void setCache(const QString &userName);

    QString C_STATE_info();
    void setC_STATE_info(const QString &userName);

signals:
    void userNameChanged();
    void familyChanged();
    void ModelChanged();
    void SteppingChanged();
    void Ext_FamilyChanged();
    //void Ext_FamilyChanged();
    void NameChanged();
    void CurrentClockSpeedChanged();
    void ExtClockChanged();
    void ManufacturerChanged();
    void CoreChanged();
    void ThreadChanged();
    void ProcessorIDChanged();
    void RevisionChanged();
    void MaxClockSpeedChanged();
    void sockedDesignationChanged();
    void UpgradeMethodChanged();
    void Feature_infoChanged();
    void CPU_TypeChanged();
    void ArchitectureChanged();
    void Code_NameChanged();
    void socket_PackeageChanged();
    void Cache_TLBChanged();
    void cacheChanged();
    void C_STATE_infoChanged();


private:
    QString m_userName="intel cpu";
};

#endif
#endif
