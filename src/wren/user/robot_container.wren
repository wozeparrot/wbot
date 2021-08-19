import "wbot/scheduler" for Scheduler

import "wfrc/xbox_controller" for XboxController

import "user/subsystems/example_subsystem" for ExampleSubsystem
import "user/commands/example_command" for ExampleCommand
import "user/commands/example_command_2" for ExampleCommand2

// User RobotContainer class
// This is where subsystem initialization and button to command bindings should go
class RobotContainer {
    // Initializes the RobotContainer
    // Most robot setup should be done here
    construct new() {
        // Setup controller
        _controller = XboxController.new(0)

        // Subsystem initialization
        ExampleSubsystem.init()
        // Set default command for subsystem
        Scheduler.setDefaultCommand(ExampleSubsystem, ExampleCommand.new(_controller))
    }

    // Returns the command to run for auto mode
    getAutoCommand() { ExampleCommand2.new() }
}