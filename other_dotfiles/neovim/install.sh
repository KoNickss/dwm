#!/bin/sh
install -d ~/.config/nvim/
cp ./init.vim ~/.config/nvim/init.vim
./neoport setup
./neoport color install arcticicestudio/nord-vim
./neoport color set nord
./neoport install neoclide/coc.nvim
./neoport install dense-analysis/ale
./neoport install preservim/nerdtree
./neoport install arrufat/vala.vim
./neoport install vim-airline/vim-airline
./neoport install vim-airline/vim-airline-themes
./neoport install mhinz/vim-startify
./neoport update
./neoport --help
