#!/bin/sh

gcc -Wall -Wextra -pedantic -std=c99 -fsanitize=address,undefined -g $@
