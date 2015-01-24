#!/bin/sh
set -eu
./textclip 25 examples/sample.txt > /tmp/textclip-sample.$$.out
grep -q "An ordinary" /tmp/textclip-sample.$$.out
rm /tmp/textclip-sample.$$.out
