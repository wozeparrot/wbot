import "wbot/command" for Command

// Another ExmapleCommand3 that is called from a trigger
class ExampleCommand3 is Command {
    construct new() {
        // Call super with the name of the command and a list of required subsystems
        super([
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