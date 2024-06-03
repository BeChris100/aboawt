#include <Android/BatteryManager.h>

#define PID_INVALID (-5)

namespace Android::Battery {

    int JAR_APP_PROCESS_PID = PID_INVALID;

    static BroadcastReceiverCallback  g_broadcastCallback = nullptr;

    std::string ActionAsString(int action) {
        switch (action) {
            case ACTION_BAT_CHANGE:
                return "Battery state changed";
            case ACTION_BAT_LOW:
                return "Battery low";
            case ACTION_BAT_OK:
                return "Battery state OK";
            case ACTION_CHARGING:
                return "Charging";
            case ACTION_DISCHARGING:
                return "Discharging";
            default:
                return "Action unknown";
        }
    }

    BatteryFileStruct FromFile(std::string filePath) {
        return BatteryFileStruct{};
    }

    void OnBroadcastReceive(BroadcastReceiverCallback callback) {
        g_broadcastCallback = callback;
    }

    void TriggerBroadcast(const Android::Battery::BroadcastStruct& broadcast) {
        if (g_broadcastCallback)
            g_broadcastCallback(broadcast);
    }

}