#include <vector>
#include <algorithm>

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/TimedRobot.h>

#include <bindings/bfrc.hpp>
#include <bindings/bnavx.hpp>

class Robot : public frc::TimedRobot {
    // VM instance
    wren::VM vm;

    // Method pointers
    wren::Method wren_robotInit;
    wren::Method wren_robotPeriodic;
    wren::Method wren_autoInit;
    wren::Method wren_autoPeriodic;
    wren::Method wren_autoExit;
    wren::Method wren_teleInit;
    wren::Method wren_telePeriodic;
    wren::Method wren_teleExit;
    wren::Method wren_testInit;
    wren::Method wren_testPeriodic;
    wren::Method wren_testExit;
    wren::Method wren_simInit;
    wren::Method wren_simPeriodic;
    wren::Method wren_disabledInit;
    wren::Method wren_disabledPeriodic;
    wren::Method wren_disabledExit;

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
            "../../../../../../src/shim/wren",
            "./src/wren",
            "./src/shim/wren"
        });
        std::cout << "[shim] Wren VM Initialized" << std::endl;

        // Generate bindings
        bindings::bfrc::generate(&vm);
        // bindings::bnavx::generate(&vm); // Doesn't work on linux x86-64 :(

        // Run early init code
        vm.runFromModule("init");
        std::cout << "[shim] Ran Init Code" << std::endl;

        // Load robot code
        vm.runFromModule("robot");
        std::cout << "[shim] Loaded Robot Code" << std::endl;

        // Load wren methods
        wren_robotInit = im("robotInit()");
        wren_robotPeriodic = im("robotPeriodic()");
        wren_autoInit = im("autoInit()");
        wren_autoPeriodic = im("autoPeriodic()");
        wren_autoExit = im("autoExit()");
        wren_teleInit = im("teleInit()");
        wren_telePeriodic = im("telePeriodic()");
        wren_teleExit = im("teleExit()");
        wren_testInit = im("testInit()");
        wren_testPeriodic = im("testPeriodic()");
        wren_testExit = im("testExit()");
        wren_simInit = im("simInit()");
        wren_simPeriodic = im("simPeriodic()");
        wren_disabledInit = im("disabledInit()");
        wren_disabledPeriodic = im("disabledPeriodic()");
        wren_disabledExit = im("disabledExit()");

        if (ok) {
            try {
                wren_robotInit();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }

    wren::Method im(std::string func) {
        wren::Method method;
        try {
            method = vm.find("robot", "RobotInstance").func(func);
        } catch (wren::Exception& e) {
            std::cout << "[shim] Could Not Find RobotInstance." << func << "!" << std::endl;
            ok = false;
        }
        return method;
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

    void AutonomousExit() override {
        if (ok) {
            try {
                wren_autoExit();
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

    void TeleopExit() override {
        if (ok) {
            try {
                wren_teleExit();
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

    void TestExit() override {
        if (ok) {
            try {
                wren_testExit();
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

    void DisabledExit() override {
        if (ok) {
            try {
                wren_disabledExit();
            } catch (wren::Exception& e) {
                std::cout << e.what() << std::endl;
                ok = false;
            }
        }
    }
};

#ifndef RUNNING_FRC_TESTS
int main() {
    return frc::StartRobot<Robot>();
}
#endif

