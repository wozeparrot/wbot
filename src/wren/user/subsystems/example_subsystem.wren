import "wbot/scheduler" for Scheduler

// A Subsystem is just a static class that must define the following methods:
// `name` - the name of the subsystem
// `init` - initialize the subsystem, this must call Scheduler.registerSubsystem
// `periodic` - called every scheduler tick
// `disabled` - called when the robot entered disabled state
class ExampleSubsystem {
    static name { "ExampleSubsystem" }

    static init() {
        // This must be called to register the Subsystem with the Scheduler
        Scheduler.registerSubsystem(ExampleSubsystem)
    }

    static periodic() {}

    static disabled() {}

    // A function that is called from a command
    static talk(i) {
        System.print("%(i) talked!")
    }
}