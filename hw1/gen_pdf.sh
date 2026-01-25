#!/usr/bin/env bash
pandoc  \
    -f markdown+implicit_figures \
    -V geometry:margin=.5in \
    -o $(date '+%Y%m%d-%H%M%S').pdf  $1
