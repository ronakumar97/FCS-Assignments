import BaseHTTPServer, SimpleHTTPServer
import ssl

localhost = 'localhost'
port = 4443
file = './server.pem'
httpd = BaseHTTPServer.HTTPServer((localhost, port), SimpleHTTPServer.SimpleHTTPRequestHandler)
httpd.socket = ssl.wrap_socket (httpd.socket, certfile=file, server_side=True)
httpd.serve_forever()