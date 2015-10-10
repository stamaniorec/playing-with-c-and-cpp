sudo apt-get update
sudo apt-get install build-essential git cmake cmake-curses-gui xorg-dev libgl1-mesa-dev libglu-dev
sudo apt-get install libpng-dev libcurl4-openssl-dev libfreetype6-dev libjpeg-dev libvorbis-dev libopenal-dev libphysfs-dev \
 libgtk2.0-dev libasound-dev libpulse-dev libflac-dev libdumb1-dev
sudo apt-get install exuberant-ctags dvi2ps dvipdfmx latex2html pandoc

git clone git://git.code.sf.net/p/alleg/allegro
cd allegro
git checkout 5.0
mkdir build; cd build

ccmake -DCMAKE_INSTALL_PREFIX=/usr ..

# press "c" twice and then "g"

make

# if it gives you some error (gave one to me on line 559 about some opengl support stuff and X11 and whatnot)
# look for CMakeLists.txt
# there should be a file with a size of 28-ish kb (there are a couple of others too but ignore them)
# go to line 559 and comment out the if statement there

sudo make install
