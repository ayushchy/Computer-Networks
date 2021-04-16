import socket
s=socket.socket()
print("Socket Created")
s.bind(("localhost",6969))
s.listen(3)
print("Waiting for connections")

while True:
 clientSocket, addr = s.accept()
 clientName = clientSocket.recv(1024).decode()
 
 if clientName=="Ayush":
     print("Connection established with ", addr,clientName)
     clientSocket.send(bytes('Welcome to the server: ayushchy','utf-8'))
 
 if clientName=="Chirru":
     print("Connection established with ", addr,clientName)
     clientSocket.send(bytes('Welcome to the server: Chirru','utf-8'))
 
 if clientName=="Gaurav":
     print("Connection established with ", addr,clientName)
     clientSocket.send(bytes('Welcome to the server: GK-17','utf-8'))
 
 clientSocket.close()