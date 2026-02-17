while(true) {
    int client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0) continue;

    std::string body = "Served by backend: " + std::string(hostname) + "\n";

    std::string response = "HTTP/1.1 200 OK\r\n";
    response += "Content-Type: text/plain\r\n";
    response += "Content-Length: " + std::to_string(body.length()) + "\r\n";
    response += "Connection: close\r\n\r\n";
    response += body;

    send(client_fd, response.c_str(), response.length(), 0);
    close(client_fd);
}
