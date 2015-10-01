#!/bin/sh
set -eu
./textclip 25 examples/sample.txt > /tmp/textclip-sample.$$.out
grep -q "An ordinary" /tmp/textclip-sample.$$.out
rm /tmp/textclip-sample.$$.out

# Running with no provided file should also succeed.
printf "An ordinary paragrap\n" | ./textclip 30 > /dev/null

./textclip --help | grep -q Usage
