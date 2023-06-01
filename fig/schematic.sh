#!/bin/sh

if [ -e "inv.tex" ]; then
    prefix=""
else
    prefix="fig/"
fi

latexmk -pdf -cd ${prefix}inv_schematic.tex
pdf2svg ${prefix}inv_schematic.pdf ${prefix}inv_schematic.svg
latexmk -pdf -cd -C ${prefix}inv_schematic.tex
