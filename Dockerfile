FROM joshwyant/gcc-cross
WORKDIR /tmp
ENV DEBIAN_FRONTEND noninteractive
RUN apt update
RUN apt install xorriso grub-imageboot -y

CMD ["make", "-j16"]