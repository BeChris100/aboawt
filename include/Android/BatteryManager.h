#ifndef ABOAWT_BATTERY_H
#define ABOAWT_BATTERY_H

#include <string>
#include <map>

namespace Android::Battery {

    extern int JAR_APP_PROCESS_PID;

    enum IntentAction {
        ACTION_CHARGING = 0, // android.os.action.CHARGING
        ACTION_DISCHARGING = 1, // android.os.action.DISCHARGING
        ACTION_BAT_LOW = 2, // android.intent.action.BATTERY_LOW
        ACTION_BAT_OK = 3, // android.intent.action.BATTERY_OKAY
        ACTION_BAT_CHANGE = 4 // android.intent.action.BATTERY_CHANGED
    };

    enum BatteryChargeType {
        CHARGE_USB = 0,
        CHARGE_DOCK = 1,
        CHARGE_POWER = 2,
        CHARGE_WIRELESS = 3
    };

    enum BatteryChargeStatus {
        CHARGING = 0,
        DISCHARGING = 1,
        FULL = 2,
        NOT_CHARGING = 3,
        UNKNOWN = -1
    };

    struct BatteryFileStruct {
        int levelPercentage;
        BatteryChargeStatus status;
        BatteryChargeType* chargeType; // can return null, if device is not in charging state
    };

    struct BroadcastStruct {
        int action;
        std::string data;
        std::map<std::string, std::string> extras;
    };

    typedef void (*BroadcastReceiverCallback)(const Android::Battery::BroadcastStruct& broadcast);

    std::string ActionAsString(int action);

    BatteryFileStruct FromFile(std::string filePath);

    void OnBroadcastReceive(BroadcastReceiverCallback callback);

    void TriggerBroadcast(const BroadcastStruct& broadcast);

}

#endif //ABOAWT_BATTERY_H
