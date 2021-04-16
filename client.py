import socket
clientSocket = socket.socket()
clientSocket.connect(("localhost",6969))
name = input("Enter you name to be shown at server ")
clientSocket.send(bytes(name,"utf-8"))
# clientSocket.send(bytes("Client: -1","utf-8"))
print(clientSocket.recv(1024).decode())