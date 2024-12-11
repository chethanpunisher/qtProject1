#ifndef OPERATION_H
#define OPERATION_H

#include <QString>
#include <xlsxdocument.h>

//states define
#define ENTRY_STATE 0x00
#define PARAMETERS_CONFIG 0x01
#define COM_CONFIG 0x02
#define START_OPERATION 0x04
#define STOP_OPERATION 0x08
#define SAVE_OPERATION 0x16
#define OPEN_FILE_OPERATION 0x32
#define CALIBRATION 0x64

#define devInitState 0
#define devStartState 1
#define devStopState 2
#define devCalibrationState 3
#define devManualMode 4

static bool parametersConfig;
static bool comConfig;
static bool saveEn;

static int deviceState = 0;

static int devState = 0;

struct Operation {
    QString sampleName;
    int frequency;
    int stopCycle;
    int amplitude;
    int setPoint;
    QString fileName;
    bool excelSaveFlg = false;
    QXlsx::Document *xlsx;
    bool excelUpdateFlag = false;
    int excX = 0;
    int index = -1;
    int columnCount = 0;
};

struct ProcessCondition {
    bool comConfigFlg = false;
    bool parametersConfigFlg = false;
    bool startFlg = false;
    bool idealFlg = false;
};


#endif // OPERATION_H
