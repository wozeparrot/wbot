import "wbot/command" for Command

import "user/subsystems/example_subsystem" for ExampleSubsystem

// Another ExmapleCommand3 that is called from a trigger
class ExampleCommand3 is Command {
    construct new() {
        // Call super with the name of the command and a list of required subsystems
        super([
            ExampleSubsystem
        ], "ExampleCommand3")
    }

    init() {
        System.print("command3 init")
    }

    execute() {}

    end(interrupted) {
        System.print("command3 interrupted? %(interrupted)")
    }

    isFinished() {
        return true
    }
}
