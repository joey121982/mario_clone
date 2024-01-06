# CURRENT STATUS: VERY EARLY DEVELOPMENT

# Mario Clone by [@joey12198](https://github.com/joey121982/) and [@cosminbrn](https://github.com/cosminbrn)

## Prerequisites

To be able to build this project, you will need to install
``` cmake ```, ``` SDL2 ``` <br>
If you're on windows you will also need
``` mingw32 ```, ``` mingw32-make ```  with working path configurations

## Building

### Linux:

#### How to Build With Script:

Simply just run ``` ./build.sh ``` in the root folder, the script will do the rest for you. 
(at the end it will ask if you want to run the game, if something went wrong, please enter "n")

#### How to Build Manually:

in your terminal, from the root of the project, run

```bash
cmake .
```

and then

```bash
make
```

### Windows:

First, you have to download SDL2 from [here](https://github.com/libsdl-org/SDL/releases/tag/release-2.28.5) and then copy the files inside the "x86_64-w64-mingw32" into a directory inside the root of the project, called "SDL2"
It should look like this: 
* mario_clone/SDL2/bin
* mario_clone/SDL2/include
* ...

If you encounter any issues with linking libraries, you can manually add libraries to the "mario_clone/include" directory

After doing this you have two options to compile:
* Either you manually run ``` cmake . -G "MinGW Makefiles" ``` and then ``` mingw32-make ```
* Or you can use the ``` winbuild.ps1 ``` powershell script to do the above automatically.

## Running

* If on windows, you can just run the "game.exe" file inside the <b>build</b> directory.
* If on linux, run ```./build/game``` from the directory you built in.

### Controls:

For now, the controls are not customizable.
* A or LEFT ARROW / W or RIGHT ARROW - runs left / right
* SPACE / W / UP ARROW - jumps





