#!/usr/bin/env bash

help(){
    echo markdown to pdf wrapper, based on pandoc
    echo usage: $0 markdown_file.md
}

if [ $# -eq 0 ]; then
    echo -e '\nerror: no arguments provided\n'
    help
    exit 1
fi

pandoc  \
    -f markdown+implicit_figures \
    -V geometry:margin=.5in \
    -o $(date '+%Y%m%d-%H%M%S').pdf  $1
