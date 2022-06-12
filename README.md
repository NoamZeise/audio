# audio
Easy cross platform audio header, using portaudio and libsndfile

## dependancies
- [portaudio](http://files.portaudio.com/docs/v19-doxydocs/tutorial_start.html)
- [libsndfile](http://www.mega-nerd.com/libsndfile/#Download)


## setup

### windows

* download [libsndfile](http://www.mega-nerd.com/libsndfile/#Download) compile and put in your lib and include directories, and distrubute dll with your binaries

* download [portaudio](http://files.portaudio.com/docs/v19-doxydocs/compile_windows.html) compile and put in your lib and include directories, and distrubute dll with your binaries

### linux with aptitude
```
$ sudo apt-get install libsndfile1-dev libasound-dev portaudio19-dev
```

## example use code
```
//start manager -> inits nessecary libraries
Audio::Manager manager;

//            audio path     loop?  volume
manager.Play("gamemusic.ogg", true, 0.8f);

while(gameActive)
{
  if(playerhit)
    manager.Play("hitsound.wav", false, 0.4f);

   if(pause)
    manager.SetVolume("gamemusic.ogg", 0.1f);
   if(unpasue)
    manager.SetVolume("gamemusic.ogg", 0.8f);

   if(cutscene)
    manager.Pause("gamemusic.ogg");
   if(cutsceneEnd)
    manager.Resume("gamemusic.ogg");

   if(playerdead)
   {
    manager.StopAll();
    manager.Play("deathmusic.ogg", true, 0.7f);
   }
   if(respawned)
   {
    if(manager.Playing("deathmusic.ogg")
     manager.Stop("deathmusic.ogg");
    manager.Play("gamemusic.ogg", true, 0.8f);
   }
}
```
