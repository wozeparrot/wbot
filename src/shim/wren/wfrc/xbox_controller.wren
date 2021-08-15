import "ffi/frc" for GenericHID

class XboxController {
    // Creates the GenericHID inner object
    construct new(port) {
        _hid = GenericHID.new(port)
    }

    // XboxController methods
    getLeftX() { _hid.getRawAxis(this.Axis_LeftX) }
    getLeftY() { _hid.getRawAxis(this.Axis_LeftY) }
    getRightX() { _hid.getRawAxis(this.Axis_RightX) }
    getRightY() { _hid.getRawAxis(this.Axis_RightY) }

    getLeftTrigger() { _hid.getRawAxis(this.Axis_LeftTrigger) }
    getRightTrigger() { _hid.getRawAxis(this.Axis_RightTrigger) }

    getLeftBumper() { _hid.getRawButton(this.Button_LeftBumper) }
    getLeftBumperPressed() { _hid.getRawButtonPressed(this.Button_LeftBumper) }
    getLeftBumperReleased() { _hid.getRawButtonReleased(this.Button_LeftBumper) }

    getRightBumper() { _hid.getRawButton(this.Button_RightBumper) }
    getRightBumperPressed() { _hid.getRawButtonPressed(this.Button_RightBumper) }
    getRightBumperReleased() { _hid.getRawButtonReleased(this.Button_RightBumper) }

    getLeftStick() { _hid.getRawButton(this.Button_LeftStick) }
    getLeftStickPressed() { _hid.getRawButtonPressed(this.Button_LeftStick) }
    getLeftStickReleased() { _hid.getRawButtonReleased(this.Button_LeftStick) }

    getRightStick() { _hid.getRawButton(this.Button_RightStick) }
    getRightStickPressed() { _hid.getRawButtonPressed(this.Button_RightStick) }
    getRightStickReleased() { _hid.getRawButtonReleased(this.Button_RightStick) }

    getA() { _hid.getRawButton(this.Button_A) }
    getAPressed() { _hid.getRawButtonPressed(this.Button_A) }
    getAReleased() { _hid.getRawButtonReleased(this.Button_A) }

    getB() { _hid.getRawButton(this.Button_B) }
    getBPressed() { _hid.getRawButtonPressed(this.Button_B) }
    getBReleased() { _hid.getRawButtonReleased(this.Button_B) }

    getX() { _hid.getRawButton(this.Button_X) }
    getXPressed() { _hid.getRawButtonPressed(this.Button_X) }
    getXReleased() { _hid.getRawButtonReleased(this.Button_X) }

    getY() { _hid.getRawButton(this.Button_Y) }
    getYPressed() { _hid.getRawButtonPressed(this.Button_Y) }
    getYReleased() { _hid.getRawButtonReleased(this.Button_Y) }

    getBack() { _hid.getRawButton(this.Button_Back) }
    getBackPressed() { _hid.getRawButtonPressed(this.Button_Back) }
    getBackReleased() { _hid.getRawButtonReleased(this.Button_Back) }

    getStart() { _hid.getRawButton(this.Button_Start) }
    getStartPressed() { _hid.getRawButtonPressed(this.Button_Start) }
    getStartReleased() { _hid.getRawButtonReleased(this.Button_Start) }

    // IDs for different inputs
    Button_LeftBumper { 5 }
    Button_RightBumper { 6 }
    Button_LeftStick { 9 }
    Button_RightStick { 10 }
    Button_A { 1 }
    Button_B { 2 }
    Button_X { 3 }
    Button_Y { 4 }
    Button_Back { 7 }
    Button_Start { 8 }

    Axis_LeftX { 0 }
    Axis_LeftY { 1 }
    Axis_RightX { 4 }
    Axis_RightY { 5 }
    Axis_LeftTrigger { 2 }
    Axis_RightTrigger { 3 }
}