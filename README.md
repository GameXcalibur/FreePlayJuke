FreePlayJuke
============

This is a jukebox in qt i was working on. I still work on it but not too often because i started a new jukebox which 
i am writing in c++ and sdl. So i decided to make this opensource and see what happens with it. 

To see the media being displayed, add a folder to the release directory and name it 'Media'. In this file add all 
the artists with a '-' following the album name. eg. "Psy-Gentlemen". In this file add all the mp3`s. My 
original plan with the mp3 name format was "01-Gentlemen". The reason for this was, on an album the tracks are in order
(numerically) and if you were not to use the nummbers the songs would sort alphabetically which would change the 
order in which the songs were displayed. However the format of the files and folders are all up to 'You' the contributors.
in the same folder as the mp3, be sure to also have a png with the name coverart. Like so: 'coverart.png'. This will 
display the coverart on the button. This image will also be used when you open the album, the image will be enlarged 
and the songs will be next to it in a scrollable list. This list is scrollable by means of an up button and a down
button and the text/title of the songs are displayed on buttons which increase/decrease the index number when pressed
which prints the text of the next song on the list.

I used a stacked widget for this project. On the first page you would see a video player looking 'thing'. This was
my original idea when i started the project, to make a media player. This functions 100%, well sorta there are a couple 
bugs here and there. You could develope more on that aspect if you would like, maybe implementing a 'play music video'
feature? Well it is all up to you, the contributors.

This jukebox already has a working, fully tested queue and a fully functional equalizer. This jukebox uses "libvlc" so
be sure to get download the libraries to actually run/build the source. 
