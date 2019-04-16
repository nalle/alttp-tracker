# alttp-tracker

# Installation instructions
Untar the release tarball
```tar zxvf alttp-tracker.tar.gz```

Run
```
cp tracker /usr/bin/tracker
cp -R images /usr/share/tracker/images
cp tracker.desktop /usr/share/applications/
```

Now your gnome quicksearch should have the tracker as an application


# Build it manually

# Prerequisites
This has been tested on Ubuntu only, but any package equivalent in another distribution should work

```
sudo apt-get install qt5-qmake qt5-default build-essential automake make g++
```
# Building
Clone the respository then run
```
make
sudo make install
```
