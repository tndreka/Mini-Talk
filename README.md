# Minitalk Project Documentation

## Overview

The **Minitalk** project is about creating a communication system between a **client** and a **server** using **UNIX signals**. The client sends a string to the server, which then prints out the message received. The client and the server communicate by only two signals: `SIGUSR1` and `SIGUSR2`.

### Core Features:
- The server should be started first and will output its **PID**.
- The client sends a string to the server using the server's **PID** and the string as input.
- The client and the server use **UNIX signals** (`SIGUSR1` and `SIGUSR2`) for communication.
- The server outputs the received string in real-time without needing to be restarted after every message.

## Communication Flow

### Server
- The server has to be started first. Upon startup, it prints its **PID**, which the client will use.
- It listens for incoming signals: `SIGUSR1` for `0` and `SIGUSR2` for `1`, then rebuilds the binary of the received string.
- Every signal corresponds to a bit of a character in the string, and after 8 signals, the server rebuilds an entire character and prints it out.
- The server is still open to receive and process multiple messages from different clients without restarting.

### Client
- The client takes two parameters: the **PID** of the server and the string to send.
- It converts each character of the string into its binary representation, sending each bit using either `SIGUSR1` (for `0`) or `SIGUSR2` (for `1`).
- After sending all characters, the client exits, waiting for the server to process the message.

## Signal-Based Communication

The core communication between the client and server relies on two signals:
- **`SIGUSR1`**: This can be thought of as the `0` in a binary string.
- **`SIGUSR2`**: This represents a `1` in a binary string.

The server will then listen for these signals and reconstruct the binary data into the original string. Since each character is sent in 8-bit chunks, after receiving the full sequence for each character, it prints the decoded message.

## Error Handling

Proper error handling is crucial for the proper functioning of the program. The project includes the following features:
- **Signal Handling**: The program should handle signals, and there should not be any segmentation faults or abrupt crashes.
- **Memory Management**: The program uses dynamic memory allocation; it should ensure that no memory leak occurs. For this purpose, all allocated memory is freed properly in order to avoid memory issues.
- **Robust Client-Server Communication**: The client and server should handle communication errors gracefully, ensuring that messages are properly transmitted and received.

## Features

- **PID Display**: The server displays its **PID** at startup, which is used by the client to send the string.
- **Efficient Communication**: The server is optimized for the receipt of strings as fast as possible. For example, the server should be able to accept 100 characters in less than 1 second (or any other reasonable interval).
- **Multiple Messages**: The server can accept more than one string from different clients without restarting.

## Example Use

### To run the server:
1. Compile the server and client using your build system, such as `make`.
2. Run the server:
   ```bash
   ./server
