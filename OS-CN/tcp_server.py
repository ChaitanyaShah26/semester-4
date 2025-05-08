import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 12345))
server_socket.listen(1)
print("TCP Server is listening on port 12345...")

conn, addr = server_socket.accept()
print(f"Connected to {addr}")

data = conn.recv(1024).decode()
print("Client says:", data)

conn.send("Hello from TCP Server!".encode())
conn.close()