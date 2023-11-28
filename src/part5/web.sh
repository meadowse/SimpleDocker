#!/bin/bash
gcc web.c -lfcgi -o web
service nginx start
spawn-fcgi -p 8080 -n ./web
/bin/bash