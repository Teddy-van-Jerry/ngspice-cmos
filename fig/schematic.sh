#!/bin/sh

if [ -e "inv.tex" ]; then
  prefix=""
else
  prefix="fig/"
fi

for cir in and8a and8b and8c inv nand2 nand4 nand8 nor2 SR_latch_clk; do
  latexmk -pdf -cd ${prefix}${cir}_schematic.tex
  pdf2svg ${prefix}${cir}_schematic.pdf ${prefix}${cir}_schematic.svg
  latexmk -pdf -cd -C ${prefix}${cir}_schematic.tex
done

echo "Finished generating all schematic SVGs!"
