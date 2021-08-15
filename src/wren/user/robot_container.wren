import "user/subsystems/example_subsystem" for ExampleSubsystem
import "user/commands/example_command" for ExampleCommand
import "user/commands/example_command_2" for ExampleCommand2

// User RobotContainer class
// This is where subsystem initialization and button to command bindings should go
class RobotContainer {
    // Getters for Commands
    exampleCommand { _exampleCommand }
    exampleCommand2 { _exampleCommand2 }

    // Initializes the RobotContainer
    // Most robot setup should be done here
    construct new() {
        // Subsystem initialization
        ExampleSubsystem.init()

        // Command creation
        _exampleCommand = ExampleCommand.new()
        _exampleCommand2 = ExampleCommand2.new()
    }

    // Returns the command to run for auto mode
    getAutoCommand() { _exampleCommand2 }
}