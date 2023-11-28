FROM nginx
USER root
WORKDIR /home/
COPY ./web.sh /home/web.sh
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
RUN apt-get upgrade && apt-get update && apt-get -y install -y gcc libfcgi-dev spawn-fcgi; \
    apt-get clean && rm -rf /var/lib/apt/lists/*; \
    useradd meadowse; \
    chown -R meadowse:meadowse /home; \
    chown -R meadowse:meadowse /etc/nginx/nginx.conf; \
    chown -R meadowse:meadowse /var/cache/nginx; \
    touch /var/run/nginx.pid; \
    chown -R meadowse:meadowse /var/run/nginx.pid; \
    chmod g-s /usr/bin/expiry; \
    chmod u-s /usr/bin/newgrp; \
    chmod g-s /usr/bin/chage; \
    chmod g-s /sbin/unix_chkpwd; \
    chmod u-s /bin/mount; \
    chmod g-s /usr/bin/wall; \
    chmod u-s /bin/su; \
    chmod u-s /usr/bin/passwd; \
    chmod u-s /usr/bin/chfn; \
    chmod u-s /usr/bin/chsh; \
    chmod u-s /usr/bin/gpasswd; \
    chmod u-s /bin/umount;
USER meadowse
HEALTHCHECK --interval=5m --timeout=3s CMD curl -f http://localhost/ || exit 1
ENTRYPOINT ["sh", "./web.sh"]