import "wbot/command" for Command

import "user/subsystems/example_subsystem" for ExampleSubsystem

// An ExampleCommand that requires ExampleSubsystem
class ExampleCommand is Command {
    construct new() {
        // Call super with the name of the command and a list of required subsystems
        super([
        ExampleSubsystem
        ], "ExampleCommand")
    }

    init() {
        System.print("command init")
    }

    execute() {
        ExampleSubsystem.talk("command")
    }

    end(interrupted) {
        System.print("command interrupted? %(interrupted)")
    }

    isFinished() { 
        return false
    }
}