# Music experiment project
This is a C++ project where several sheet musics are given for each instrument and, as outcome, a audio file is generated accordingly.

## How to compile and execute
This project resorts to CMake to make it possible to compile.

### Automatic compilation and execution
You can compile and execute the project by resorting to the shell file *execute.sh*:

```bash
cd music_experiment # Go to the music experiment folder
./execute.sh
```

### Manual compilation and execution
In order to compile the project manually, the steps needed are the following:

```bash
cd music_experiment # Go to the music experiment folder
mkdir -p build
cd build
cmake ..
make
```

Having this done, the only thing left is executing the program

```bash
./music_experiment
```
