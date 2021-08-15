import "wpilib/frc" for RobotState

import "wtypes/set" for Set

class Scheduler {
    static init() {
        __subsystems = Set.new()
        __commands = {}

        __requirements = {}

        __defaultCommands = {}
    }

    static tick() {
        // Run subsystems periodic
        for (s in __subsystems) {
            s.periodic()
        }

        // Run scheduled commands
        for (c in __commands) {
            // Check command against bot status
            if (RobotState.isDisabled() && !c.value.runsDisabled) {
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
    }

    static schedule(command) {
        // Check if the command is null
        if (command == null) return

        // Check if the command is already scheduled
        if (__commands.containsKey(command.name)) return

        // Check if the command is part of a group
        if (command.grouped) Fiber.abort("Command `%(command.name)` is part of a group and cannot be scheduled independently!")

        // Ensure that the commands required subsystems are registered
        if (!__subsystems.containsAll(command.requirements)) Fiber.abort("Command `%(command.name)` requires subsystems that are not registered!")
        
        // Check command against bot status
        if (RobotState.isDisabled() && !command.runsDisabled) return

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
                for (c in intersections) { cancel(c) }
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
}