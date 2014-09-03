Name: Jacob Schreiner
Platform: Ubuntu 14.04 (3.13.0-35-generic)
Problems: Turns out some of my .so files were placed into /usr/lib/x86_64-linux-gnu/. I assume this is because of 64-bit nonsense and just made a simple symbolic link to the listed shared objects in /usr/lib. Also NVidia likes to install their own version of libGL as well as the mesa version i had. I thought NVidia's might be better, but it failed to link things so i switched over to mesa's. Finally, the packages described are slightly inaccurate. Package name was freeglut3-dev. I was easly able to find it using "apt-cache search freeglut".
Citations:
