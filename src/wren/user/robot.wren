import "wpilib/frc" for DriverStation, XboxController, PowerDistribution, PneumaticsControlModule, Solenoid, DoubleSolenoid
import "wpilib/frc" for GenericHID_JoystickHand

import "wbot/scheduler" for Scheduler

import "user/subsystems/example_subsystem" for ExampleSubsystem
import "user/commands/example_command" for ExampleCommand
import "user/commands/example_command_2" for ExampleCommand2

class Robot {
    // Should only contain Scheduler.init()
    // Other robot initialization should go in robotInit()
    construct new() { Scheduler.init() }

    robotInit() {
        // Make sure stuff works
        System.print("DS Attached?   : %(DriverStation.isDSAttached())")
        DriverStation.waitForData(0.5)
        System.print("DS Bus Voltage : %(DriverStation.getBatteryVoltage())")

        _controller = XboxController.new(0)
        System.print("A Btn Status   : %(_controller.getAButtonPressed())")

        _pdp = PowerDistribution.new(0)
        System.print("PDP Voltage    : %(_pdp.getVoltage())")
        System.print("PDP Temp       : %(_pdp.getTemperature())")
        System.print("PDP Current    : %(_pdp.getCurrent(0))")
        System.print("PDP TCurrent   : %(_pdp.getTotalCurrent())")
        System.print("PDP TPower     : %(_pdp.getTotalPower())")
        System.print("PDP TEnergy    : %(_pdp.getTotalEnergy())")

        _pcm = PneumaticsControlModule.new(0)
        _pcm.setClosedLoopControl(true)
        System.print("PCM CLC        : %(_pcm.getClosedLoopControl())")
        _sol = Solenoid.new(_pcm, 0)
        _sol.toggle()
        System.print("Sol Status     : %(_sol.get())")
        _dsol = DoubleSolenoid.new(_pcm, 1, 2)
        _dsol.set(2)
        _dsol.toggle()
        System.print("DSol Status    : %(_dsol.get())")

        // Subsystem initialization
        ExampleSubsystem.init()

        // Command creation
        _exampleCommand = ExampleCommand.new()
        _exampleCommand2 = ExampleCommand2.new()
    }

    robotPeriodic() {
        Scheduler.tick()
    }

    autoInit() {
        System.print("auto")

        Scheduler.schedule(_exampleCommand2)
    }

    autoPeriodic() {}

    teleInit() {
        System.print("tele")
        System.print("DS Alliance    : %(DriverStation.getAlliance())")
        System.print("DS Station     : %(DriverStation.getLocation())")

        Scheduler.schedule(_exampleCommand)
    }

    telePeriodic() {
        // System.print("Joystick X     : %(_controller.getX(GenericHID_JoystickHand.Left))")
    }

    testInit() {}

    testPeriodic() {}

    simInit() {}

    simPeriodic() {}

    disabledInit() {}

    disabledPeriodic() {}
}

var RobotInstance = Robot.new()
