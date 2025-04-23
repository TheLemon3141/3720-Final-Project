FROM janvik/oatpp:latest

WORKDIR /
ADD . /cardREST
WORKDIR ./cardREST

RUN make testServer
RUN ./testServer

EXPOSE 8100 8100

RUN make cardServer
ENTRYPOINT ["./cardServer"]

# Used to allow for connection to container so can use commandline
#ENTRYPOINT ["sleep", "infinity"]