#include <vector>
#include <algorithm>

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/TimedRobot.h>

#include <bindings/bfrc.hpp>

class Robot : public frc::TimedRobot {
    // VM instance
    wren::VM vm;

    // Method pointers
    wren::Method wren_robotInit;
    wren::Method wren_robotPeriodic;
    wren::Method wren_autoInit;
    wren::Method wren_autoPeriodic;
    wren::Method wren_teleInit;
    wren::Method wren_telePeriodic;
    wren::Method wren_testInit;
    wren::Method wren_testPeriodic;
    wren::Method wren_simInit;
    wren::Method wren_simPeriodic;
    wren::Method wren_disabledInit;
    wren::Method wren_disabledPeriodic;

    // Ok state
    bool ok = true;

public:
    // Set loop speed here
    Robot() : frc::TimedRobot(10_ms) {}

    void RobotInit() override {
        // Initialize wren vm
        vm = wren::VM({
            "/home/lvuser/wren",
            "/home/lvuser/wbot",
            "../../../../../../src/wren",
            "../../../../../../src/shim/wren"
        });
        std::cout << "[shim] Wren VM Initialized" << std::endl;

        // Generate bindings
        bindings::bfrc::generate(&vm);

        // Run early init code
        vm.runFromModule("init");
        std::cout << "[shim] Ran Init Code" << std::endl;

        // Load robot code
        vm.runFromModule("robot");
        std::cout << "[shim] Loaded Robot Code" << std::endl;

        // Load wren methods
        try {
            wren_robotInit = vm.find("robot", "RobotInstance").func("robotInit()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.robotInit()!" << std::endl;
            ok = false;
        }
        try {
            wren_robotPeriodic = vm.find("robot", "RobotInstance").func("robotPeriodic()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.robotPeriodic()!" << std::endl;
            ok = false;
        }
        try {
            wren_autoInit = vm.find("robot", "RobotInstance").func("autoInit()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.autoInit()!" << std::endl;
            ok = false;
        }
        try {
            wren_autoPeriodic = vm.find("robot", "RobotInstance").func("autoPeriodic()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.autoPeriodic()!" << std::endl;
            ok = false;
        }
        try {
            wren_teleInit = vm.find("robot", "RobotInstance").func("teleInit()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.teleInit()!" << std::endl;
            ok = false;
        }
        try {
            wren_telePeriodic = vm.find("robot", "RobotInstance").func("telePeriodic()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.telePeriodic()!" << std::endl;
            ok = false;
        }
        try {
            wren_testInit = vm.find("robot", "RobotInstance").func("testInit()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.testInit()!" << std::endl;
            ok = false;
        }
        try {
            wren_testPeriodic = vm.find("robot", "RobotInstance").func("testPeriodic()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.testPeriodic()!" << std::endl;
            ok = false;
        }
        try {
            wren_simInit = vm.find("robot", "RobotInstance").func("simInit()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.simInit()!" << std::endl;
            ok = false;
        }
        try {
            wren_simPeriodic = vm.find("robot", "RobotInstance").func("simPeriodic()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.simPeriodic()!" << std::endl;
            ok = false;
        }
        try {
            wren_disabledInit = vm.find("robot", "RobotInstance").func("disabledInit()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.disabledInit()!" << std::endl;
            ok = false;
        }
        try {
            wren_disabledPeriodic = vm.find("robot", "RobotInstance").func("disabledPeriodic()");
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance.disabledPeriodic()!" << std::endl;
            ok = false;
        }

        if (ok) {
            try {
                wren_robotInit();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void RobotPeriodic() override {
        if (ok) {
            try {
                wren_robotPeriodic();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void AutonomousInit() override {
        if (ok) {
            try {
                wren_autoInit();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void AutonomousPeriodic() override {
        if (ok) {
            try {
                wren_autoPeriodic();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void TeleopInit() override {
        if (ok) {
            try {
                wren_teleInit();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void TeleopPeriodic() override {
        if (ok) {
            try {
                wren_telePeriodic();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void TestInit() override {
        if (ok) {
            try {
                wren_testInit();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void TestPeriodic() override {
        if (ok) {
            try {
                wren_testPeriodic();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void SimulationInit() override {
        if (ok) {
            try {
                wren_simInit();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void SimulationPeriodic() override {
        if (ok) {
            try {
                wren_simPeriodic();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void DisabledInit() override {
        if (ok) {
            try {
                wren_disabledInit();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    void DisabledPeriodic() override {
        if (ok) {
            try {
                wren_disabledPeriodic();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif

