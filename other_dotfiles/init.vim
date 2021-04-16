set relativenumber
set wrap!
nnoremap <C-f> :NERDTreeToggle<CR>
nnoremap <C-t> :terminal<CR>
nnoremap o o<Esc>
nnoremap d "_d
xnoremap d "_d
vnoremap d "_d
nnoremap x "_x
set tabstop=4
set shiftwidth=4
set smarttab
set mouse=a
color nord

call plug#begin('~/.config/nvim/ports')

Plug 'mhinz/vim-startify'
Plug 'neoclide/coc.nvim'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'arrufat/vala.vim'
Plug 'preservim/nerdtree'
Plug 'ap/vim-css-color'

call plug#end()

let g:airline_theme='deus'
