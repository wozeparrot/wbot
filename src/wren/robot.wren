import "ffi/frc" for DriverStation
import "ffi/frc" for GenericHID_JoystickHand

import "wbot/scheduler" for Scheduler

import "user/robot_container" for RobotContainer

// Users should not initialization code in this class directly
// Robot initialization code should go in RobotContainer instead
class Robot {
    // Should only contain Scheduler.init()
    construct new() { Scheduler.init() }

    // Called when the robot is first started up
    robotInit() {
        // Instantiate the RobotContainer
        _robotContainer = RobotContainer.new()
    }

    // Called every robot tick
    robotPeriodic() {
        // Call the Scheduler tick so that stuff actually runs
        Scheduler.tick()
    }

    // Called when robot enters auto mode
    autoInit() {
        // Get auto command from the container
        _autoCommand = _robotContainer.getAutoCommand()
        // Schedule auto command
        Scheduler.schedule(_autoCommand)
    }

    // Called every auto tick
    autoPeriodic() {}

    // Called when robot exits auto mode
    autoExit() {}

    // Called when robot enters teleop mode
    teleInit() {
        // Cancel the maybe running auto command
        Scheduler.cancel(_autoCommand)

        // Get teleop command from the container
        _teleopCommand = _robotContainer.getTeleopCommand()
        // Schedule teleop command
        Scheduler.schedule(_teleopCommand)
    }

    // Called every teleop tick
    telePeriodic() {}

    // Called when robot exits teleop mode
    teleExit() {}

    // Called when robot enters test mode
    testInit() {}

    // Called every test tick
    testPeriodic() {}

    // Called when robot exits test mode
    testExit() {}

    // Called when the simulator is started
    simInit() {}

    // Called every tick when being simulated
    simPeriodic() {}

    // Called when robot enters disabled mode
    disabledInit() {}

    // Called every disabled tick
    disabledPeriodic() {}

    // Called when robot exits disabled mode
    disabledExit() {}
}

// Create a instance of Robot for the shim code to work
var RobotInstance = Robot.new()
