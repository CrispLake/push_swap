FROM debian:latest

RUN apt update && apt upgrade -y && apt install -y make build-essential

RUN mkdir /push_swap
COPY . /push_swap/

WORKDIR /push_swap

RUN make