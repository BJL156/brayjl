# brayjl
brayjl engine

# about
The brayjl engine is meant to be an engine that I can use in order to make games without the need of having to set everything up from scratch again when I just want to get to the game making part of my application.

As it currently stands, it only supports Windows with VS2022 as those are the tools that I personally use to make applications.

# features (present and future)
- logging
- 2D rendering (soon)
- text (soon)
- keyboard/mouse inputs (soon)
- collision detection (soon)

# structure
## projects
The engine is seperated into one solution in VS2022 with two seperate projects: one for the engine itself (`brayjl`), and one for the sandbox (the game).

The engine is built into a static library file which the sandbox project then references in order to use the engine's functionality. The sandbox project is built into an executable file which is what will be run for the final product. From the initialization phase to the destruction phase, a log file will be written into a `log.txt`. The same information from the log file is found in CMD during the runtime of the application.

Nothing in the engine project needs to be looked into when developing an application unless if the user wants to alter the engine code to suit their style. Just rebuild the engine project.

## engine project
The `brayjl.hpp` file includes every part of the engine inside of it. There are two folders the `brayjl` folder which contains the engine's core, and the `platform` folder which contains more platform specific parts of the engine such as window handling, and graphics APIs (only supported one is OpenGL).

## sandbox project
The sandbox project contains the `log.txt` file inside of it. With the `Sandbox` class that is used for the application.

# install
Installation was designed to be very easy with this engine.
First clone the repository:
```
git clone https://github.com/BJL156/brayjl
```
After change directories into the newly created `brayjl` folder:
```
cd brayjl
```
Then finally to build the project run the `setup.bat`:
```
setup.bat
```
Lastly, execute victory dance as the project is completely setup at this point.
