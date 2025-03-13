# Prosody-Radix

## About

Prosody is a community driven rhythm game. It mainly focuses on 4k vsrg gameplay, but has plans to potentially support other types of key counts, gamemode, and custom unique mapping support.
Prosody-X:
 - Aria Engine Prosody: First attempt, used html 							| Currently only playable version, discontinued
 - Prosody: Used a canvas element and js 											| Focused on the editor, is like "stable" version
 - Prosody Radix: uses WASM, radix also means root in latin 	| Rebuilt for best performance and future proofing, is like "lazer" version

## Compile Command

```sh
emcc main.c -o index.html -s USE_GLFW=3 -s WASM=1 \
	-I /storage/emulated/0/Prosody-Radix/raylib/src \
	 -L /storage/emulated/0/Prosody-Radix/raylib/src \
	 -lraylib.web -s ERROR_ON_UNDEFINED_SYMBOLS=0
```