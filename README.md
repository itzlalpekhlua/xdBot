# ZoBot

ZoBot is a Geode macro, replay, and gameplay utility toolkit for Geometry Dash. It is a maintained rebrand of xdBot with compatibility for existing xdBot macro files.

## Features

* Basic ClickBot.
* Practice Fixes.
* Seed Modifier.
* Noclip.
* Show Trajectory.
* Layout Mode.
* Speedhack.
* Frame Stepper.
* Safe Mode.
* Renderer.
* Instant Respawn.
* No Respawn Flash.
* No Death Effect.
* Macro saving and loading system.
* Macro Auto Saving.

## Build

Install the current Geode toolchain, then build from the repository root:

```sh
geode build
```

If you do not use the Geode CLI, configure CMake with `GEODE_SDK` pointing at your Geode SDK checkout:

```sh
cmake -B build
cmake --build build --config RelWithDebInfo
```

## Usage

* Open the menu using the Open Menu keybind or the button in the pause menu.
* Click the `Record` toggle in the menu to start recording.
* Finish a practice run of the level.
* Play the macro by clicking the `Play` toggle in the menu and entering the level.

## Credits

* Original xdBot project by Zilko.
* Thanks to Viper for the Safe Mode implementation.
* Thanks to ReplayBot for the renderer codebase.
* Thanks to CatXus and Aadam_yes for early Android testing.
