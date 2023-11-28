FROM nginx

USER root

COPY ./web.c /home/web.c
COPY ./web.sh /home/web.sh
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf

RUN apt-get update ; \
    apt-get install -y gcc spawn-fcgi libfcgi-dev;

WORKDIR /home/

ENTRYPOINT ["sh", "./web.sh"]