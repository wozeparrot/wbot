# wbot

An experiment to get [wren](https://wren.io)  running on FRC bots.

Tries to map as closely as possible to the original wpilib api. The largest difference so far is that the scheduler will check if a command is finished **first** before it executes the command.
