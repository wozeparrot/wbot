import "wbot/command" for Command

import "user/subsystems/example_subsystem" for ExampleSubsystem

// Another ExmapleCommand2 that also requires ExampleSubsystem except that this one is interruptible
class ExampleCommand2 is Command {
  construct new() {
    // Call super with the name of the command and a list of required subsystems
    super([
      ExampleSubsystem
    ], "ExampleCommand2")

    // Use super to set command settings
    super.interruptible = true
  }

  init() {
    System.print("command2 init")
  }

  execute() {
    ExampleSubsystem.talk("command2")
  }

  end(interrupted) {
    System.print("command2 interrupted? %(interrupted)")
  }

  isFinished() { 
    return false
  }
}