FROM debian:buster
RUN apt-get update && apt-get install -y nginx vim openssl wget
COPY /script.sh /
RUN chmod 777 script.sh
CMD ["bash", "script.sh"]
