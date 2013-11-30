Oblikue-strategies
==================

Information
-----------
Oblikue-strategies is a plasmoid that displays a random draw from Brian Eno 
and Peter Schmidt's Oblique Strategies. It is [GNOME applet](http://gnome-look.org/content/show.php/Oblique+Strategies?content=78405) fork.

Build instructions
------------------
Global installation:

    cd /where/your/applet/is/installed
    mkdir build && cd build
    cmake -DCMAKE_INSTALL_PREFIX=`kde4-config --prefix` -DCMAKE_BUILD_TYPE=Release ../
    make
    sudo make install
Installation only for current user:

    cd /where/your/applet/is/installed
    mkdir build && cd build
    cmake -DCMAKE_INSTALL_PREFIX=`kde4-config --localprefix` -DCMAKE_BUILD_TYPE=Release ../
    make
    make install

Restart plasma to load the applet:

    kquitapp plasma-desktop && sleep 2 && plasma-desktop
or view it with:

    plasmoidviewer oblikue-strategies

You might need to run kbuildsycoca4 in order to get the .desktop file recognized:

    kbuildsycoca4 &> /dev/null

Additional information
======================

Links
-----
* Plasmoid on [kde-look](http://kde-look.org/content/show.php/oblikue-strategies?content=160503)
* Archlinux [AUR](https://aur.archlinux.org/packages/kdeplasma-applets-oblikuestrategies/) package
