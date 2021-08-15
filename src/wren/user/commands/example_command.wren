import "wbot/command" for Command

import "user/subsystems/example_subsystem" for ExampleSubsystem

// An ExampleCommand that requires ExampleSubsystem
class ExampleCommand is Command {
    construct new(controller) {
        // Call super with the name of the command and a list of required subsystems
        super([
        ExampleSubsystem
        ], "ExampleCommand")

        // Pass in controller
        _controller = controller
    }

    init() {
        System.print("command init")
    }

    execute() {
        ExampleSubsystem.talk("command: %(_controller.getX(0))") // TODO: wait for alpha-3 to switch back to wren XboxController
    }

    end(interrupted) {
        System.print("command interrupted? %(interrupted)")
    }

    isFinished() { 
        return false
    }
}