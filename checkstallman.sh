#!/bin/bash
if (who | awk '{print $2}' | grep tty) > /dev/null; then
    touch ~/.loggedon
else
    rm -f ~/.loggedon
fi
