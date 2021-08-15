import "wbot/scheduler" for Scheduler

// A Subsystem is just a static class that must define:
// `name` - the name of the subsystem
// `init` - initialize the subsystem
// `periodic` - called every scheduler tick
class ExampleSubsystem {
  static name { "ExampleSubsystem" }

  static init() {
    // This must be called to register the Subsystem with the Scheduler
    Scheduler.registerSubsystem(ExampleSubsystem)
  }

  static periodic() {}

  // A function that is called from a command
  static talk(i) {
    System.print("%(i) talked!")
  }
}