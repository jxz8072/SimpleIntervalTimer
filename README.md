# SimpleIntervalTime

Here's a simple command line interval countdown timer application,
which turned out to be a bit more difficult than I originally thought. 
I created this application in an attempt to self-study C++ on a mac. 
Here are some of the lessons I learned when creating this application:

+ Sound is a lot more complicated to play using C++ (when compared to
  C# or Python).I had to download and install SDL. And even then, I
  wasn't able to configure SDL_audio to play the sound correctly, so
  I had to download and install SDL_Mixer library as well.

+ I originally used pthreads for the countdown, but oddly enough, 
  pthreads caused my application to hang only when the -framework
  flag was set during compilation. I couldn't figure out why that
  was the case, so I ended up using STL treads instead (and now my
  application works).

+ pthreads vs stl threads - From what I could gleam off of stackoverflow,
  stl threads have a higher abstraction level than pthreads, and are 
  easier to use. Pthreads (or POSIX threads) would be better to use if I
  wanted my application to be cross-compatible with different OS's. This 
  application is for my personal use, so I don't think compatibility is
  going to be an issue.

+ string::npos is a constant value for -1, and is used for the end of 
  strings. Using string::find however, must've returned a different 
  type for -1 than the one for string::npos, because they returned different
  values (18446744073709551615 and 4294967295, respectively). stringUtil.cpp
  shows the location of where this came into play, and I believe the values
  are there because I'm using a 64-bit based mac. 

Maybe I'll add a front-end later, I've been meaning to learn Qt...
