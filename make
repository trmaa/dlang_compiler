#!/bin/bash

function install() {
	cp dlang /usr/bin/dlang
	cp dcompiler /usr/bin/dcompiler
	cp dtokenizer /usr/bin/dtokenizer
}

function build() {
	gcc compiler.c -o dcompiler
	gcc tokenizer.c -o dtokenizer
}

for call in $@; do $call; done
