import "wbot/scheduler" for Scheduler

// Runs commands on certain states of triggers
class Trigger {
    construct new() {
        // Trigger states
        _triggered = false

        // Holds trigger check functions
        _triggers = []

        // Setup command lists
        _activeCommands = []
        _activeContinuousCommands = []
        _activeOnceCommands = []
        _inactiveCommands = []
        _activeCancelCommands = []
    }

    on(trigger) {
        _triggers.add(trigger)
        return this
    }

    whenActive(command) {
        _activeCommands.add(command)
        return this
    }

    whenActiveContinuous(command) {
        _activeContinuousCommands.add(command)
        return this
    }

    whenActiveOnce(command) {
        _activeOnceCommands.add(command)
        return this
    }

    whenInactive(command) {
        _inactiveCommands.add(command)
        return this
    }

    whenActiveCancel(command) {
        _activeCancelCommands.add(command)
        return this
    }

    end() { this }

    check() {
        var prevTriggered = _triggered
        _triggered = true

        // Check state of triggers
        for (trigger in _triggers) {
            if (!trigger.call()) {
                _triggered = false
                break
            }
        }

        // Check if we are on a state change
        var stateJustChanged = false
        if (prevTriggered != _triggered) stateJustChanged = true

        // Schedule commands
        if (_triggered) {
            if (stateJustChanged) {
                // Schedule _activeCommands
                for (c in _activeCommands) Scheduler.schedule(c)
                // Schedule _activeOnceCommands
                for (c in _activeOnceCommands) Scheduler.schedule(c)
                // Cancel _activeCancelCommands
                for (c in _activeCancelCommands) Scheduler.cancel(c)
            }
            // Schedule _activeContinuousCommands
            for (c in _activeContinuousCommands) Scheduler.schedule(c)
        } else {
            if (stateJustChanged) {
                // Schedule _inactiveCommands
                for (c in _inactiveCommands) Scheduler.schedule(c)
                // Cancel _activeContinuousCommands
                for (c in _activeContinuousCommands) Scheduler.cancel(c)
                // Cancel _activeOnceCommands
                for (c in _activeOnceCommands) Scheduler.cancel(c)
            }
        }
    }
}
