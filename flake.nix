{
  description = "frc2022 dev flake";

  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  inputs.flake-utils.url = "github:numtide/flake-utils";
  inputs.flake-compat = {
    url = "github:edolstra/flake-compat";
    flake = false;
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = import nixpkgs {
          inherit system;
          config.allowUnfree = true;
        };
      in
        {
          devShell = let
            frcsimx86_64 = pkgs.writeShellScriptBin "frcsimx86_64" ''
              pkill frcUserProgram
              ./gradlew installFrcUserProgramLinuxx86-64DebugExecutable
              sed -i 's/^LD_LIBRARY_PATH="$APP_BASE_NAME\/lib"/LD_LIBRARY_PATH="$APP_BASE_NAME\/lib:$LD_LIBRARY_PATH"/g' ./build/install/frcUserProgram/linuxx86-64/debug/frcUserProgram
              sed -i '4 s/frcUserProgram\/linuxx86-64\/debug\/lib$/frcUserProgram\/linuxx86-64\/debug\/lib:$LD_LIBRARY_PATH/' ./build/gradlerio_simulateFrcUserProgramLinuxx86-64DebugExecutable.sh
              ./build/gradlerio_simulateFrcUserProgramLinuxx86-64DebugExecutable.sh
            '';
            fhs = pkgs.buildFHSUserEnv {
              name = "frc2022-env";
              targetPkgs = pkgs: with pkgs; [
                openjdk11
                gradle_6
                gcc
                gdb
                astyle

                frcsimx86_64

                zlib
                xorg.libX11
                xorg.libXt
                gtk2-x11
                libGL
              ];
              multiPkgs = null;
              profile = ''
                export PATH=$PATH:$HOME/.gradle/toolchains/frc/2021/roborio/bin/
              '';
            };
            in
            fhs.env;
        }
    );
}
