# audio
Easy cross platform audio header, using portaudio and libsndfile

## dependancies
- [portaudio](http://files.portaudio.com/docs/v19-doxydocs/tutorial_start.html)
- [libsndfile](http://www.mega-nerd.com/libsndfile/#Download)

## setup

building is done with cmake, so you can have this as a submodule of your project and call add_subdirectory in a parent directory CMake file.

If you want to build the demo pass "-DBUILD_DEMO=true" when running CMake

### windows

* download [libsndfile](http://www.mega-nerd.com/libsndfile/#Download) compile and put in your lib and include directories, and distrubute dll with your binaries

* download [portaudio](http://files.portaudio.com/docs/v19-doxydocs/compile_windows.html) compile and put in your lib and include directories, and distrubute dll with your binaries

### linux with aptitude
```
$ sudo apt-get install libsndfile1-dev libasound-dev portaudio19-dev
```


## TODO

- change from string dict to more efficient reference system, ie an audio resource id.
