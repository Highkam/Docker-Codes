FROM ubuntu:20.04

RUN apt-get update && \
    apt-get install -y build-essential

WORKDIR /app

COPY main.cpp .

RUN g++ -o main main.cpp

CMD ["./main"]

