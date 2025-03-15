# Prosody-Radix

## About

Prosody is a community driven rhythm game. It mainly focuses on 4k vsrg gameplay, but has plans to potentially support other types of key counts, gamemode, and custom unique mapping support.
Prosody-X:
 - Aria Engine Prosody: First attempt, used html 							| Currently only playable version, discontinued
 - Prosody: Used a canvas element and js 											| Focused on the editor, is like "stable" version
 - Prosody Radix: uses WASM, radix also means root in latin 	| Rebuilt for best performance and future proofing, is like "lazer" version

## Commands

### Compile
```sh
make clean && make
```
> Deletes compiled files and recompiles the web build

### Host Client
```sh
emrun --no_browser --port 8080 --hostname 0.0.0.0 ./
```
> Hosts the compiled html file to local host
