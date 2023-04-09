FROM ubuntu:latest as build
RUN apt update -y
RUN apt install g++ -y

WORKDIR /app

COPY ./project /app



