import "ffi/frc" for DriverStation

import "wtypes/set" for Set
import "wtypes/queue" for Queue

class Scheduler {
    static init() {
        // Holds subsystems
        __subsystems = Set.new()
        // Holds commands
        __commands = {}
        // Holds triggers
        __triggers = []

        // Map of command required subsystems
        __requirements = {}

        // Holds the default commands to run for subsystems
        __defaultCommands = {}

        // Check if the `disabled` subsystem method has already been run
        __ranSubsystemDisabled = false

        // Queues and flag to make sure that no changes happen during a tick
        __inTick = false
        __toCancel = Queue.new()
        __toSchedule = Queue.new()
    }

    static tick() {
        __inTick = true

        // Check to see if we are running the `disabled` subsystem method this loop
        var runSubsystemDisabled = false
        if (DriverStation.isDisabled()) {
            runSubsystemDisabled = !__ranSubsystemDisabled
            __ranSubsystemDisabled = true
        } else {
            runSubsystemDisabled = false
            __ranSubsystemDisabled = false
        }

        // Run subsystems periodic
        for (s in __subsystems) {
            // run `disabled` method if flag set
            if (runSubsystemDisabled) {
                s.disabled()
            }

            s.periodic()
        }

        // Check triggers
        for (t in __triggers) {
            t.check()
        }

        // Run scheduled commands
        for (c in __commands) {
            // Check command against bot status
            if (DriverStation.isDisabled() && !c.value.runsDisabled) {
                cancel(c.value)
                continue
            }

            // Call command execute function
            c.value.execute()

            // Check if command is finished
            if (c.value.isFinished()) {
                c.value.end(false)

                // Remove command
                __commands.remove(c.key)

                // Remove requirements
                for (r in c.value.requirements) {
                    __requirements.remove(r)
                }
            }
        }

        // Schedule default commands for subsystems without commands
        for (s in __subsystems) {
            if (!__requirements.containsKey(s) && __defaultCommands.containsKey(s)) {
                schedule(__defaultCommands[s])
            }
        }

        __inTick = false

        // Schedule and cancel all queued items
        var item = __toCancel.pop()
        while (item) {
            cancel(item)
            item = __toCancel.pop()
        }
        item = __toSchedule.pop()
        while (item) {
            schedule(item)
            item = __toSchedule.pop()
        }
    }

    static schedule(command) {
        // Check if we are in a tick
        if (__inTick) {
            __toSchedule.push(command)
            return
        }

        // Check if the command is null
        if (command == null) return

        // Check if the command is already scheduled
        if (__commands.containsKey(command.name)) return

        // Check if the command is part of a group
        if (command.grouped) Fiber.abort("Command `%(command.name)` is part of a group and cannot be scheduled independently!")

        // Ensure that the commands required subsystems are registered
        if (!__subsystems.containsAll(command.requirements)) Fiber.abort("Command `%(command.name)` requires subsystems that are not registered!")
        
        // Check command against bot status
        if (DriverStation.isDisabled() && !command.runsDisabled) return

        // Check command requirements collisions
        var isDisjoint = true
        var allInterruptible = true
        var intersections = []
        for (r in __requirements) {
            if (command.requirements.contains(r.key)) {
                isDisjoint = false
                allInterruptible = allInterruptible && r.value.interruptible
                intersections.add(r.value)
            }
        }

        // Schedule command and call its init function
        if (isDisjoint || allInterruptible) {
            if (allInterruptible) {
                for (c in intersections) {
                    cancel(c)
                }
            }

            // Call command init function
            command.init()

            __commands[command.name] = command

            // Add requirements
            for (r in command.requirements) {
                __requirements[r] = command
            }
        }
    }

    static cancel(command) {
        // Check if we are in a tick
        if (__inTick) {
            __toCancel.push(command)
            return
        }

        // Check if the command is null
        if (command == null) return

        // Check if the command is actually scheduled
        if (!__commands.containsKey(command.name)) return

        // Call command end function
        command.end(true)

        // Remove command
        __commands.remove(command.name)

        // Remove requirements
        for (r in command.requirements) {
            __requirements.remove(r)
        }
    }

    static setDefaultCommand(subsystem, command) {
        // Check if the command is part of a group
        if (command.grouped) Fiber.abort("Command `%(command.name)` is part of a group and cannot be scheduled independently!")

        // Ensure that the commands required subsystems are registered
        if (!__subsystems.containsAll(command.requirements)) Fiber.abort("Command `%(command.name)` requires subsystems that are not registered!")

        // Ensure that the command actually requires subsystem
        if (!command.requirements.contains(subsystem)) Fiber.abort("Command `%(command.name)` does not require subsystem %(subsystem.name)!")

        __defaultCommands[subsystem] = command
    }

    static getDefaultCommand(subsystem) {
        return __defaultCommands[subsystem]
    }

    static removeDefaultCommand(subsystem) {
        __defaultCommands.remove(subsystem)
    }

    static registerSubsystem(subsystem) {
        __subsystems.add(subsystem)
    }

    static addTrigger(trigger) {
        __triggers.add(trigger)
    }

    static removeTrigger(trigger) {
        __triggers.remove(trigger)
    }
}