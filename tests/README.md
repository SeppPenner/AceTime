# Unit Tests

You can run most of these unit tests on an Arduino board (tested on
Nano, Pro Micro, ESP8266 and ESP32). But it is often far faster to run them on a
Linux or MacOS machine.

## Running Tests on Linux or MacOS

Prerequisites:

* Install GNU Make.
    * Ubuntu Linux: `$ sudo apt install make`
    * MacOS: `/usr/bin/make` - version 3.81 seems to be already installed on my machine
    * MacOS + Brew: `$ brew install make` - installs as `/usr/local/bin/gmake`
* Install `g++` or `clang++` compiler on your Linux or MacOS machine.
    * Ubuntu Linux: `$ sudo apt install g++-7` (I think)
    * MacOS: `/usr/bin/c++` - I don't remember how I got `clang++` installed on
      my machine, maybe I installed XCode?
    * MacOS + Brew: `$ brew install llvm` (??) - Not sure, I don't seem to have
      this installed.
* Install [AUnit](https://github.com/bxparks/AUnit) as a sibling project to
  AceTime.
  * `$ (cd ../../..; git clone https://github.com/bxparks/AUnit)`

Compile the unit test programs using the following `make` commands (or run
the equivalent one-line shell commands shown in the `Makefile`):

* `$ make clean`
* `$ make tests`

Run all the unit tests sequentially, piping the output to `less`:
* `$ make runtests | less`

Look for the word `failed` in the output. These should all say `0 failed`, like
this:

```
TestRunner summary: 231 passed, 0 failed, 0 skipped, 0 timed out, out of 231
test(s).
```
