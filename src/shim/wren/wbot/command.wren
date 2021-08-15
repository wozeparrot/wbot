import "wtypes/set" for Set

class Command {
    // Command Info
    name { _name }
    requirements { _requirements }

    // Command Settings
    interruptible { _interruptible }
    interruptible=(interruptible){ _interruptible = interruptible }
    runsDisabled { _runsDisabled }
    runsDisabled=(runsDisabled) { _runsDisabled = runsDisabled }

    grouped { _grouped }
    grouped=(grouped) { _grouped = grouped }

    // called from the derived class as super(requirements, name)
    construct new(requirements, name) {
        _name = name
        _requirements = Set.new(requirements)

        _interruptible = false
        _runsDisabled = false

        _grouped = false
    }

    // called when the command is scheduled
    init() {}

    // called per scheduler tick
    execute() {}

    // called when the command ends or is cancelled
    end(interrupted) {}

    // called to determine if the command is finished or not
    isFinished() {
        return false
    }
}