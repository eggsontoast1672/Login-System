# Login System

A simple login system using Sqlite3.

## Overview

Okay, so this project is really dumb and stupid. I came up with it while
sitting around my house during a three-day weekend. The whole point of it was
just to test out a system for getting input on the terminal.

## Building

The build process is pretty standard. Just create a build directory, generate a
build system with CMake, and compile. Keep in mind that there is no installing
functionality bundled in, but I doubt that's an issue since this program
doesn't have any legitimate functionality anyway.

## Extending

If you want to add new user accounts, there's an array of users within
`backend.c` that you can add to. The format is `{"username", "password"}`.

## License

This is public domain software. Do with it as you please.
