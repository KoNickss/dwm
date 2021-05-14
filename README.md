# DWM
My build of dwm, patched with tilegap, alpha and with some of my own personal source code modifications to make this look and feel like home.
Also includes my other buids and configs in `other_dotfiles`, basically you can steal my look with just this repo

# Main rices:


## Frost
<img src=media/frost.png>
Commit ID: https://github.com/KoNickss/dwm/tree/bff875873589bcd96785b9b765d8accf2d9370f4


## Mitochondria
<img src=media/mitochondria.png>
Commit ID: https://github.com/KoNickss/dwm/tree/f6a87e3387447c80b2b4477eac82a89a79fe80de

## StackOS
<img src=media/stackos.png>
Commit ID: https://github.com/KoNickss/dwm/tree/efd4f1c707a4f9698cdb2ab45735eafaf6531fa1

## StackOS Pro

<img src=media/stackpro.png>
Commit ID: https://github.com/KoNickss/dwm/tree/e8fb61792a3b5e3ce43bd70166e1da069b8fa4de

# How to apply rice
If you want to apply an older rice, just do `git checkout ID` where ID is the long string at the end of the URL for the rice

Next build dwm, do `make clean install` with root priviliges in the git root

To apply the other dotfiles, simply move them in their place in the filesystem (most configs are named with the path i.e. /foo/bar/foobar.conf would be foo-bar-foobar.conf)

If that rice contains transparency, you will need picom-tryone-git (it's on github and the AUR)

Don't forget to add the .xnintrcdwm (to ~/), .dwminit if neccesary (also to ~/), and Xsession file to be able to load dwm from a login manager

Any issue? Create an issue on the gh page or message me

<3
